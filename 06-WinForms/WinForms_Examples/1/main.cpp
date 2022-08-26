using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

void OnClick(System::Object^ sender, System::EventArgs^ e);

int WinMain()
{
	Form^ myForm = gcnew Form();
	//myForm->Width = Screen::PrimaryScreen->Bounds.Width / 3;
	//myForm->Height = Screen::PrimaryScreen->Bounds.Height / 3;
	myForm->StartPosition = FormStartPosition::CenterScreen;
	myForm->WindowState = FormWindowState::Maximized;

	Button^ exitButton = gcnew Button();
	exitButton->Location = System::Drawing::Point(100, 50);
	exitButton->Text = "Exit";
	exitButton->Click += gcnew System::EventHandler(&OnClick);

	myForm->Controls->Add(exitButton);

	Application::Run(myForm);
	return 0;
}

void OnClick(System::Object^ sender, System::EventArgs^ e)
{
	Application::Exit();
}