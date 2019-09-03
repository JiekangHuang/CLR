#include "Board.h"

Board::Board()
{
	Loca_c = gcnew array<int>(Col);
	Loca_r = gcnew array<int>(Row);

	for (int i = 0; i < Col; i++)
		Loca_c[i] = static_x + i * add_x;
	for (int i = 0; i < Row; i++)
		Loca_r[i] = static_y + i * add_y;

	int idx = 0;
	L_dead = gcnew array<dead^>(16);
	R_dead = gcnew array<dead^>(16);

	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 2; j++)
		{
			L_dead[idx] = gcnew dead(_Lstatic_x + _add_x * j, _static_y + _add_y * i);
			R_dead[idx] = gcnew dead(_Rstatic_x + _add_x * j, _static_y + _add_y * i);
			++idx;
		}

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
	this->Init();
}
Board::~Board()
{
	for (int r = 0; r < Row; r++)
		for (int c = 0; c < Col; c++)
			delete piece[r][c];
	delete curPyShow;
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

	for (int r = 0; r < Row; r++)
		for (int c = 0; c < Col; c++)
			this->piece[r][c] = gcnew Piece(r, c);

	//建立32個亂數
	Random^ Rand = gcnew Random();

	cliext::vector<int> vec;
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
}
void Board::Action(int x, int y)
{
	if (x > Loca_c[0] && x < Loca_c[7] + (Loca_c[7] - Loca_c[6]) && y>Loca_r[0] && y < Loca_r[3] + (Loca_r[3] - Loca_r[2]))
	{
		int r = -1, c = -1;
		for (int i = 0; i < Col; i++)
			if (x > Loca_c[i])
				c = i;
		for (int i = 0; i < Row; i++)
			if (y > Loca_r[i])
				r = i;
		if (!this->pre_piece->Back_Is_Empty() && pre_piece->Is_My(cur_pyer) && this->pre_piece->Is_Move(r, c))
		{
			this->pre_piece->Move(r, c);
			this->Exch(pre_piece);
		}
	}
}
void Board::Action(Piece ^cur)
{
	Piece^ cur_piece = cur;
	if (!cur_piece->Is_Open())
	{
		cur_piece->Open();
		this->Exch(cur_piece);
		if (!pre_piece->Back_Is_Empty())
			pre_piece->Clear();
	}
	else if (this->pre_piece->Back_Is_Empty())
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
		else if (this->pre_piece->Attack(cur_piece))
		{
			int x, y;
			if (cur_piece->Get_Color() == "red")
			{
				x = this->L_dead[16 - this->rNum]->x;
				y = this->L_dead[16 - this->rNum]->y;
				this->rNum--;
			}
			else
			{
				x = this->R_dead[16 - this->bNum]->x;
				y = this->R_dead[16 - this->bNum]->y;
				this->bNum--;
			}
			cur_piece->Location = Point(x, y);
			cur_piece->Size = System::Drawing::Size(50, 50);
			this->pre_piece->Move(cur_piece->Get_row(), cur_piece->Get_col());
			this->Exch(cur_piece);
			this->Is_Win();
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