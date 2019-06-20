#pragma once
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class Const_Piece :Form
{
private:
	Image ^image;
	String ^color;
	int power;

public:
	Const_Piece(Image ^image, String ^color, int power)
	{
		this->image = image;
		this->color = color;
		this->power = power;
	}
	Image ^Get_Image()
	{
		return this->image;
	}
	String ^Get_Color()
	{
		return this->color;
	}
	int Get_Power()
	{
		return this->power;
	}
};
