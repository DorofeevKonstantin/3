#include "MyForm.h"

using namespace System;

int WinMain()
{
	SimpleControls::MyForm^ myForm = gcnew SimpleControls::MyForm;
	System::Windows::Forms::Application::Run(myForm);
	return 0;
}