#include "MyForm.h"

using namespace ChessGame;

[STAThreadAttribute]

int main(array<System::String ^> ^arge)
{
	//�إߥ��󱱨���e�A���ҥ� windows xp ��ı�ĪG

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	//�إߥD�����ð���
	Application::Run(gcnew MyForm());

	return 0;
}