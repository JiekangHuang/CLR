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
	int idx_x, idx_y;
	//棋盤地圖(紀錄所有棋盤上的棋子位置)
	static array<array<bool>^> ^map;

public:
	Piece(int x, int y, int idx_x, int idx_y);
	Piece() {}
	//初始化棋子內容
	void Init_Data(Const_Piece ^const_data);
	void Init();

	System::Drawing::Image ^Get_Image();
	String ^Get_Color();
	int Get_Power();
	int Get_idx_x();
	int Get_idx_y();

	bool Is_Open();
	bool Is_Move(Piece ^cur);
	bool Is_My(String ^cur_pyer);
	bool Is_Empty();
	bool Back_Is_Empty();

	void Open();
	void Move(Piece ^cur);
	void Clear();
	void Remove();
	Piece ^Select();
	Piece ^Attack(Piece ^victim);

	void Set_Data(Piece ^from);
};
