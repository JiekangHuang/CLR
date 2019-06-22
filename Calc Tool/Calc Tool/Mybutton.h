#pragma once
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

ref class Mybutton :Button
{
private:

public:
	Mybutton(int x, int y, String ^name, String ^color);
};

Mybutton::Mybutton(int x, int y, String ^name, String ^color)
{
	if (color == "num")
		this->BackColor = SystemColors::ActiveCaption;
	else
		this->BackColor = Color::Silver;
	this->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, FontStyle::Bold, GraphicsUnit::Point,
		static_cast<System::Byte>(0)));
	this->Location = Point(x, y);
	this->Name = name;
	this->Size = System::Drawing::Size(60, 60);
	this->Text = name;
	this->TabIndex = 0;
}
