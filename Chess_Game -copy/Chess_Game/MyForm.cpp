#include "MyForm.h"

using namespace ChessGame;

[STAThreadAttribute]

int main(array<System::String ^> ^arge)
{
	//建立任何控制項之前，先啟用 windows xp 視覺效果

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//建立主視窗並執行
	Application::Run(gcnew MyForm());

	return 0;
}