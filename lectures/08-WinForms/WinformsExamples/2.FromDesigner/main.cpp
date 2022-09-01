#include "MyForm.h"

int WinMain()
{
	My2FromDesigner::MyForm^ myForm = gcnew My2FromDesigner::MyForm;
	System::Windows::Forms::Application::Run(myForm);
	return 0;
}