#include "Board.h"

Board::Board()
{
	{
		this->curPyShow = gcnew Button();
		this->curPyShow->Size = System::Drawing::Size(145, 55);
		this->curPyShow->Font = (gcnew System::Drawing::Font(L"標楷體", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(136)));
		this->curPyShow->ForeColor = System::Drawing::Color::White;
		this->curPyShow->Location = System::Drawing::Point(520, 55);
		this->curPyShow->Name = L"Current_player";
		this->curPyShow->TabIndex = 0;
	}
	init_piece = gcnew array<Const_Piece^>(32);
	{
		this->init_piece[0] = (gcnew Const_Piece(Image::FromFile("Image\\1-1.png"), "red", 6));
		this->init_piece[1] = (gcnew Const_Piece(Image::FromFile("Image\\1-2.png"), "red", 5));
		this->init_piece[2] = (gcnew Const_Piece(Image::FromFile("Image\\1-2.png"), "red", 5));
		this->init_piece[3] = (gcnew Const_Piece(Image::FromFile("Image\\1-3.png"), "red", 4));
		this->init_piece[4] = (gcnew Const_Piece(Image::FromFile("Image\\1-3.png"), "red", 4));
		this->init_piece[5] = (gcnew Const_Piece(Image::FromFile("Image\\1-4.png"), "red", 3));
		this->init_piece[6] = (gcnew Const_Piece(Image::FromFile("Image\\1-4.png"), "red", 3));
		this->init_piece[7] = (gcnew Const_Piece(Image::FromFile("Image\\1-5.png"), "red", 2));
		this->init_piece[8] = (gcnew Const_Piece(Image::FromFile("Image\\1-5.png"), "red", 2));
		this->init_piece[9] = (gcnew Const_Piece(Image::FromFile("Image\\1-6.png"), "red", 1));
		this->init_piece[10] = (gcnew Const_Piece(Image::FromFile("Image\\1-6.png"), "red", 1));
		this->init_piece[11] = (gcnew Const_Piece(Image::FromFile("Image\\1-7.png"), "red", 0));
		this->init_piece[12] = (gcnew Const_Piece(Image::FromFile("Image\\1-7.png"), "red", 0));
		this->init_piece[13] = (gcnew Const_Piece(Image::FromFile("Image\\1-7.png"), "red", 0));
		this->init_piece[14] = (gcnew Const_Piece(Image::FromFile("Image\\1-7.png"), "red", 0));
		this->init_piece[15] = (gcnew Const_Piece(Image::FromFile("Image\\1-7.png"), "red", 0));
		this->init_piece[16] = (gcnew Const_Piece(Image::FromFile("Image\\2-1.png"), "black", 6));
		this->init_piece[17] = (gcnew Const_Piece(Image::FromFile("Image\\2-2.png"), "black", 5));
		this->init_piece[18] = (gcnew Const_Piece(Image::FromFile("Image\\2-2.png"), "black", 5));
		this->init_piece[19] = (gcnew Const_Piece(Image::FromFile("Image\\2-3.png"), "black", 4));
		this->init_piece[20] = (gcnew Const_Piece(Image::FromFile("Image\\2-3.png"), "black", 4));
		this->init_piece[21] = (gcnew Const_Piece(Image::FromFile("Image\\2-4.png"), "black", 3));
		this->init_piece[22] = (gcnew Const_Piece(Image::FromFile("Image\\2-4.png"), "black", 3));
		this->init_piece[23] = (gcnew Const_Piece(Image::FromFile("Image\\2-5.png"), "black", 2));
		this->init_piece[24] = (gcnew Const_Piece(Image::FromFile("Image\\2-5.png"), "black", 2));
		this->init_piece[25] = (gcnew Const_Piece(Image::FromFile("Image\\2-6.png"), "black", 1));
		this->init_piece[26] = (gcnew Const_Piece(Image::FromFile("Image\\2-6.png"), "black", 1));
		this->init_piece[27] = (gcnew Const_Piece(Image::FromFile("Image\\2-7.png"), "black", 0));
		this->init_piece[28] = (gcnew Const_Piece(Image::FromFile("Image\\2-7.png"), "black", 0));
		this->init_piece[29] = (gcnew Const_Piece(Image::FromFile("Image\\2-7.png"), "black", 0));
		this->init_piece[30] = (gcnew Const_Piece(Image::FromFile("Image\\2-7.png"), "black", 0));
		this->init_piece[31] = (gcnew Const_Piece(Image::FromFile("Image\\2-7.png"), "black", 0));
	}
	piece = gcnew array<array<Piece^>^>(4);
	for (int i = 0; i < Row; i++)
		piece[i] = gcnew array<Piece^>(8);

	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
			this->piece[i][j] = (gcnew Piece(static_x + add_x * j, static_y + add_y * i, i, j));

	int idx = 0;
	L_dead = gcnew array<PictureBox^>(16);
	R_dead = gcnew array<PictureBox^>(16);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 2; j++)
		{
			L_dead[idx] = gcnew PictureBox;
			L_dead[idx]->Location = System::Drawing::Point(_Lstatic_x + _add_x * j, _static_y + _add_y * i);
			L_dead[idx]->Size = System::Drawing::Size(50, 50);
			L_dead[idx]->BackColor = Color::Transparent;
			L_dead[idx]->BackgroundImageLayout = ImageLayout::Stretch;
			L_dead[idx]->SizeMode = PictureBoxSizeMode::StretchImage;

			R_dead[idx] = gcnew PictureBox;
			R_dead[idx]->Location = Point(_Rstatic_x + _add_x * j, _static_y + _add_y * i);
			R_dead[idx]->Size = System::Drawing::Size(50, 50);
			R_dead[idx]->BackColor = Color::Transparent;
			R_dead[idx]->BackgroundImageLayout = ImageLayout::Stretch;
			R_dead[idx]->SizeMode = PictureBoxSizeMode::StretchImage;
			++idx;
		}

	this->Init();
}
void Board::Init(void)
{
	this->curPyShow->BackColor = Color::Tan;
	this->curPyShow->Text = L"當前玩家";

	this->rNum = 16;
	this->bNum = 16;
	this->cur_pyer = "";
	this->pre_piece = gcnew Piece();
	this->isFirst = true;

	//建立32個亂數
	Random^ Rand = gcnew Random();

	std::vector<int> vec;
	int s_num = Chess_num - 1, idx = 0;;
	for (int i = 0; i < Chess_num; i++)
		vec.push_back(i);
	for (int i = Chess_num - 1; i > 0; i--)
	{
		int rand_n = Rand->Next(s_num);
		vec.at(i) = vec.at(i) ^ vec.at(rand_n);
		vec.at(rand_n) = vec.at(i) ^ vec.at(rand_n);
		vec.at(i) = vec.at(i) ^ vec.at(rand_n);
		--s_num;
	}
	for (int i = 0; i < Row; i++)
		for (int j = 0; j < Col; j++)
		{
			this->piece[i][j]->Init();
			this->piece[i][j]->Init_Data(this->init_piece[vec.at(idx++)]);
		}
	for (int i = 0; i < 16; i++)
	{
		this->L_dead[i]->Image = nullptr;
		this->R_dead[i]->Image = nullptr;
	}
}
void Board::Action(int idx_x, int idx_y)
{
	Piece^ cur_piece = this->piece[idx_x][idx_y];

	if (!cur_piece->Is_Open())
	{
		cur_piece->Open();
		this->Exch(cur_piece);
		if (!pre_piece->Is_Empty())
			pre_piece->Clear();
	}
	else if (this->pre_piece->Is_Empty())
	{
		if (cur_piece->Is_My(cur_pyer))
			this->pre_piece = cur_piece->Select();
	}
	else
	{
		if (cur_piece->Is_My(cur_pyer))
		{
			this->pre_piece->Clear();
			this->pre_piece = cur_piece->Select();
		}
		else if (cur_piece->Is_Empty())
		{
			if (this->pre_piece->Is_Move(cur_piece))
			{
				this->pre_piece->Move(cur_piece);
				this->Exch(cur_piece);
			}
		}
		else
		{
			Piece^ dead = this->pre_piece->Attack(cur_piece);
			if (dead != nullptr)
			{
				this->pre_piece->Remove();
				this->Exch(cur_piece);
				if (dead->Get_Color() == "red")
				{
					this->L_dead[16 - this->rNum]->Image = dead->Image;
					this->rNum--;
				}
				else
				{
					this->R_dead[16 - this->bNum]->Image = dead->Image;
					this->bNum--;
				}
				if (this->Is_Win())
					this->Init();
			}
		}
	}
}
void Board::Exch(Piece ^ first)
{
	if (this->isFirst)
		this->cur_pyer = first->Get_Color();
	if (this->cur_pyer == "red")
	{
		this->cur_pyer = "black";
		this->curPyShow->BackColor = Color::Black;
	}
	else
	{
		this->cur_pyer = "red";
		this->curPyShow->BackColor = Color::Red;
	}
	this->isFirst = false;
}
array<array<Piece^>^>^ Board::Get_Piece()
{
	return this->piece;
}
Button^ Board::Get_curPyShow()
{
	return this->curPyShow;
}

bool Board::Is_Win()
{
	if (rNum == 0)
	{
		MessageBox::Show("黑軍獲勝 !!");
		return true;
	}
	else if (bNum == 0)
	{
		MessageBox::Show("紅軍獲勝 !!");
		return true;
	}
	return false;
}
array<PictureBox^>^ Board::Get_L_dead()
{
	return this->L_dead;
}
array<PictureBox^>^ Board::Get_R_dead()
{
	return this->R_dead;
}