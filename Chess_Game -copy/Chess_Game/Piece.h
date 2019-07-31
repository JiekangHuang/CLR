#pragma once
#include "Const_Piece.h"
#include <vcclr.h>
#include <cmath>

using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

ref class Piece :PictureBox
{
private:
	//行列數
#define Row 4
#define	Col 8

	//棋子圖片
	System::Drawing::Image ^image;
	//棋子顏色
	String ^color;
	//棋子大小
	int power;
	//是否為空棋
	bool empty;
	//棋子開/蓋狀態
	bool open;
	//棋子在棋盤上的位置
	int row, col;
	//棋盤地圖(紀錄所有棋盤上的棋子位置)
	static array<array<bool>^> ^map;
	//定義棋子start位置&間格大小
	const int static_x = 171, static_y = 137, add_x = 107, add_y = 99;

	static array<int> ^Loca_c;
	static array<int> ^Loca_r;

public:
	Piece(int r, int c);
	Piece() {}
	//初始化棋子內容
	void Init_Data(Const_Piece ^const_data);
	void Init();

	System::Drawing::Image ^Get_Image();
	String ^Get_Color();
	int Get_Power();
	int Get_col();
	int Get_row();

	bool Is_Open();
	bool Is_Move(int r, int c);
	bool Is_My(String ^cur_pyer);
	bool Back_Is_Empty();

	void Open();
	void Move(int r, int c);
	void Clear();
	Piece ^Select();
	bool Attack(Piece ^victim);
	void Swch(int &a, int&b);
};
