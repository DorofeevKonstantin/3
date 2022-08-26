#include "MyForm.h"

int WinMain()
{
	FromDesigner::MyForm^ myForm = gcnew FromDesigner::MyForm;
	System::Windows::Forms::Application::Run(myForm);
	return 0;
}