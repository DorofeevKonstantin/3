#include "MyForm.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

int WinMain()
{
	
	Example::MyForm^ f = gcnew Example::MyForm;
	System::Windows::Forms::Application::Run(f);
	
	/*
	System::Windows::Forms::Form^ myform = gcnew System::Windows::Forms::Form;
	myform->Width = 1000;
	myform->Height = 500;
	myform->StartPosition = FormStartPosition::CenterScreen;

	Button^ b1 = gcnew Button;
	b1->Text = " нопанька";
	b1->Location = Point(50, 50);

	PictureBox^ pb = gcnew PictureBox;
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(pb))->BeginInit();
	pb->Location = System::Drawing::Point(12, 12);
	pb->Enabled = true;
	Graphics^ g = pb->CreateGraphics();

	myform->Controls->Add(b1);
	myform->Controls->Add(pb);

	Pen^ redPen = gcnew Pen(Color::FromArgb(255, 0, 0));
	g->DrawLine(redPen, 0, 0, 200, 200);

	System::Windows::Forms::Application::Run(myform);
	*/
	return 0;
}