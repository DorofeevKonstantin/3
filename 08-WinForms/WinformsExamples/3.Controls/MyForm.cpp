#include "MyForm.h"

int WinMain()
{
	My3Controls::MyForm^ myForm = gcnew My3Controls::MyForm;
	System::Windows::Forms::Application::Run(myForm);
	return 0;
}