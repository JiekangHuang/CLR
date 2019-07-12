#include "Piece.h"

Piece::Piece(int x, int y, int idx_x, int idx_y)
{
	this->Location = Point(x, y);
	this->Size = System::Drawing::Size(95, 90);
	this->BackgroundImageLayout = ImageLayout::Stretch;
	this->SizeMode = PictureBoxSizeMode::StretchImage;
	this->Name = idx_x.ToString() + idx_y.ToString();
	this->idx_x = idx_x;
	this->idx_y = idx_y;
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
		{
			map[i][j] = true;
		}

	this->image = nullptr;
	this->color = "";
	this->power = -1;
	this->open = false;
	this->BackColor = Color::Transparent;
	this->Image = System::Drawing::Image::FromFile("Image\\close.png");
}

Piece ^Piece::Attack(Piece ^victim)
{
	Piece ^dead = gcnew Piece();
	dead->Set_Data(victim);

	if (this->Get_Power() != 1)
	{
		if (this->Is_Move(victim))
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
			{
				victim->Set_Data(this);
				return dead;
			}
		}
	}
	else
	{
		int sum = 0;
		int this_x = this->Get_idx_x();
		int this_y = this->Get_idx_y();
		int vic_x = victim->Get_idx_x();
		int vic_y = victim->Get_idx_y();
		if (this_x == vic_x)
		{
			if (this_y > vic_y)
			{
				this_y = this_y ^ vic_y;
				vic_y = this_y ^ vic_y;
				this_y = this_y ^ vic_y;
			}
			for (int i = this_y + 1; i < vic_y; i++)
				if (map[this_x][i] == true)
					++sum;
		}
		else if (this_y == vic_y)
		{
			if (this_x > vic_x)
			{
				this_x = this_x ^ vic_x;
				vic_x = this_x ^ vic_x;
				this_x = this_x ^ vic_x;
			}
			for (int i = this_x + 1; i < vic_x; i++)
				if (map[i][this_y] == true)
					++sum;
		}
		if (sum == 1)
		{
			victim->Set_Data(this);
			return dead;
		}
	}
	return nullptr;
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

void Piece::Remove()
{
	this->BackColor = Color::Transparent;
	this->Image = nullptr;
	this->color = "";
	this->power = -1;
	map[this->Get_idx_x()][this->Get_idx_y()] = false;
}

bool Piece::Is_Empty()
{
	return this->Image == nullptr;
}

bool Piece::Back_Is_Empty()
{
	return this->BackColor == Color::Transparent;
}

bool Piece::Is_Move(Piece ^ cur)
{
	int sum = abs(this->Get_idx_x() - cur->Get_idx_x()) + abs(this->Get_idx_y() - cur->Get_idx_y());
	return sum == 1;
}

void Piece::Move(Piece ^cur)
{
	cur->Set_Data(this);
	this->Remove();
	map[cur->Get_idx_x()][cur->Get_idx_y()] = true;
}

void Piece::Set_Data(Piece ^from)
{
	this->Image = from->Get_Image();
	this->color = from->Get_Color();
	this->power = from->Get_Power();
}
Image ^Piece::Get_Image()
{
	return this->Image;
}
String ^Piece::Get_Color()
{
	return this->color;
}
int Piece::Get_Power()
{
	return this->power;
}
int Piece::Get_idx_x()
{
	return this->idx_x;
}
int Piece::Get_idx_y()
{
	return this->idx_y;
}