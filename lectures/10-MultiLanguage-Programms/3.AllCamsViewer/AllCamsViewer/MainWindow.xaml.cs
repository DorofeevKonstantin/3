using Accord.Video.DirectShow;
using OpenCvSharp;
using System;
using System.IO;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;
using System.Windows.Media.Imaging;

namespace AllCamsViewer
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : System.Windows.Window
    {
        private bool end = false;
        private int cameraCount = 0;
        private VideoCapture[] captures;
        private Mat[] frames;
        private Image[] images;
        private Viewbox[] viewboxes;
        private WriteableBitmap[] writeableBitmaps;
        public MainWindow()
        {
            InitializeComponent();
        }
        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            var videoDevices = new FilterInfoCollection(FilterCategory.VideoInputDevice);
            cameraCount = videoDevices.Count;
            string fileName = "webcams.txt";
            if (File.Exists(fileName))
                File.Delete(fileName);
            foreach (var videoDevice in videoDevices)
            {
                File.AppendAllText(fileName, videoDevice.Name + " | " + videoDevice.MonikerString + Environment.NewLine);
                var videoCaptureDevice = new VideoCaptureDevice(videoDevice.MonikerString);
                var capabilities = videoCaptureDevice.VideoCapabilities;
                foreach (var capabilitie in capabilities)
                {
                    File.AppendAllText(fileName, capabilitie.FrameSize.Width + "x" + capabilitie.FrameSize.Height + " " + capabilitie.AverageFrameRate + " fps" + Environment.NewLine);
                }
            }
            captures = new VideoCapture[cameraCount];
            frames = new Mat[cameraCount];
            viewboxes = new Viewbox[cameraCount];
            images = new Image[cameraCount];
            writeableBitmaps = new WriteableBitmap[cameraCount];
        }

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            end = true;
            for (int i = 0; i < cameraCount; ++i)
            {
                captures[i].Release();
            }
        }
        private void ShowButton_Click(object sender, RoutedEventArgs e)
        {
            ShowButton.Visibility = Visibility.Collapsed;
            int i = 0;
            for (i = 0; i < cameraCount; ++i)
            {
                captures[i] = new VideoCapture(i);
                frames[i] = new Mat(new OpenCvSharp.Size(captures[i].FrameWidth, captures[i].FrameHeight), MatType.CV_8UC3);
                viewboxes[i] = new Viewbox();
                images[i] = new Image();
                writeableBitmaps[i] = new WriteableBitmap(captures[i].FrameWidth, captures[i].FrameHeight, 96, 96, PixelFormats.Bgr24, null);
                images[i].Source = writeableBitmaps[i];
                viewboxes[i].Child = images[i];
                CamerasUniformGrid.Children.Add(viewboxes[i]);
            }
            while (end == false)
            {
                for (i = 0; i < cameraCount; ++i)
                {
                    if (captures[i].Read(frames[i]))
                    {
                        writeableBitmaps[i].WritePixels(new Int32Rect(0, 0, captures[i].FrameWidth, captures[i].FrameHeight), frames[i].Data,
                            captures[i].FrameWidth * captures[i].FrameHeight * 3, captures[i].FrameWidth * 3);
                        images[i].Source = writeableBitmaps[i];
                    }
                    else
                        images[i].Source = null;
                }
                Cv2.WaitKey(1);
            }
        }
    }
}