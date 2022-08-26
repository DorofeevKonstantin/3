#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>

using namespace std;
using namespace cv;
using namespace cv::face;

void drawPolyline(Mat& im, const vector<Point2f>& landmarks, const int start, const int end, bool isClosed = false)
{
    vector<Point> points;
    for (int i = start; i <= end; i++)
        points.push_back(cv::Point(landmarks[i].x, landmarks[i].y));
    polylines(im, points, isClosed, Scalar(255, 0, 0), 1, 16);
}
void drawLandmarks(Mat& im, vector<Point2f>& landmarks)
{
    if (landmarks.size() == 68)
    {
        drawPolyline(im, landmarks, 0, 16);           // Jaw line
        drawPolyline(im, landmarks, 17, 21);          // Left eyebrow
        drawPolyline(im, landmarks, 22, 26);          // Right eyebrow
        drawPolyline(im, landmarks, 27, 30);          // Nose bridge
        drawPolyline(im, landmarks, 30, 35, true);    // Lower nose
        drawPolyline(im, landmarks, 36, 41, true);    // Left eye
        drawPolyline(im, landmarks, 42, 47, true);    // Right Eye
        drawPolyline(im, landmarks, 48, 59, true);    // Outer lip
        drawPolyline(im, landmarks, 60, 67, true);    // Inner lip
    }
    else
    {
        for (int i = 0; i < landmarks.size(); i++)
            circle(im, landmarks[i], 3, Scalar(255, 0, 0), FILLED);
    }
}

int main()
{
    CascadeClassifier faceDetector("haarcascade_frontalface_alt2.xml");
    Ptr<Facemark> facemark = FacemarkLBF::create();
    facemark->loadModel("lbfmodel.yaml");
    VideoCapture cam(0);
    Mat frame, gray;
    while (cam.read(frame))
    {
        vector<Rect> faces;
        cvtColor(frame, gray, COLOR_BGR2GRAY);
        faceDetector.detectMultiScale(gray, faces);
        vector<vector<Point2f>> landmarks;
        bool success = facemark->fit(frame, faces, landmarks);
        if (success)
        {
            for (int i = 0; i < landmarks.size(); i++)
                drawLandmarks(frame, landmarks[i]);
        }
        imshow("Facial Landmark Detection", frame);
        if (waitKey(1) == 27) break;
    }
    return 0;
}