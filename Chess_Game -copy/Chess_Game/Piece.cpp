#include "Piece.h"

Piece::Piece(int r, int c)
{
	Loca_c = gcnew array<int>(Col);
	Loca_r = gcnew array<int>(Row);
	for (int i = 0; i < Col; i++)
		Loca_c[i] = static_x + i * add_x;
	for (int i = 0; i < Row; i++)
		Loca_r[i] = static_y + i * add_y;

	this->Location = Point(Loca_c[c], Loca_r[r]);
	this->Size = System::Drawing::Size(95, 90);
	this->BackgroundImageLayout = ImageLayout::Stretch;
	this->SizeMode = PictureBoxSizeMode::StretchImage;

	this->row = r;
	this->col = c;
	this->Init();
}

void Piece::Init_Data(Const_Piece ^const_data)
{
	this->image = const_data->Get_Image();
	this->color = const_data->Get_Color();
	this->power = const_data->Get_Power();
}

void Piece::Init()
{
	map = gcnew array<array<bool>^>(4);
	for (int i = 0; i < 4; i++)
		map[i] = gcnew array<bool>(8);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			map[i][j] = true;

	this->image = nullptr;
	this->color = "";
	this->power = -1;
	this->open = false;
	this->BackColor = Color::Transparent;
	this->Image = System::Drawing::Image::FromFile("Image\\close.png");
}

bool Piece::Attack(Piece ^victim)
{
	int v_r = victim->Get_row();
	int v_c = victim->Get_col();

	if (this->Get_Power() != 1)
	{
		if (this->Is_Move(v_r, v_c))
		{
			int this_p = this->Get_Power();
			int vic_p = victim->Get_Power();
			if (abs(this_p - vic_p) == 6)
			{
				this_p = this_p ^ vic_p;
				vic_p = this_p ^ vic_p;
				this_p = this_p ^ vic_p;
			}
			if (this_p >= vic_p)
				return true;
		}
	}
	else
	{
		int sum = 0;
		int this_c = this->Get_col();
		int this_r = this->Get_row();
		int vic_c = victim->Get_col();
		int vic_r = victim->Get_row();

		if (this_c == vic_c)
		{
			if (this_r > vic_r)
				Swch(this_r, vic_r);
			for (int i = this_r + 1; i < vic_r; i++)
				if (map[i][this_c] == true)
					++sum;
		}
		else if (this_r == vic_r)
		{
			if (this_c > vic_c)
				Swch(this_c, vic_c);
			for (int i = this_c + 1; i < vic_c; i++)
				if (map[this_r][i] == true)
					++sum;
		}
		if (sum == 1)
			return true;
	}
	return false;
}

void Piece::Swch(int & a, int & b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

bool Piece::Is_Open()
{
	return this->open == true;
}

void Piece::Open()
{
	this->Image = this->image;
	this->open = true;
}

void Piece::Clear()
{
	this->BackColor = Color::Transparent;
}

bool Piece::Is_My(String ^ cur_pyer)
{
	return this->color == cur_pyer;
}

Piece ^Piece::Select()
{
	this->BackColor = Color::Red;
	return this;
}

bool Piece::Back_Is_Empty()
{
	return this->BackColor == Color::Transparent;
}

int Piece::Get_col()
{
	return this->col;
}

int Piece::Get_row()
{
	return this->row;
}

bool Piece::Is_Move(int r, int c)
{
	int sum = abs(this->col - c) + abs(this->row - r);
	return sum == 1;
}

void Piece::Move(int r, int c)
{
	map[row][col] = false;
	this->Location = Point(Loca_c[c], Loca_r[r]);
	col = c;
	row = r;
	map[row][col] = true;
	this->BackColor = Color::Transparent;
}
Image ^Piece::Get_Image()
{
	return this->image;
}
String ^Piece::Get_Color()
{
	return this->color;
}
int Piece::Get_Power()
{
	return this->power;
}