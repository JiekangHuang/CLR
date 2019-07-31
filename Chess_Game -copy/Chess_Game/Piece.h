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
	//��C��
#define Row 4
#define	Col 8

	//�Ѥl�Ϥ�
	System::Drawing::Image ^image;
	//�Ѥl�C��
	String ^color;
	//�Ѥl�j�p
	int power;
	//�O�_���Ŵ�
	bool empty;
	//�Ѥl�}/�\���A
	bool open;
	//�Ѥl�b�ѽL�W����m
	int row, col;
	//�ѽL�a��(�����Ҧ��ѽL�W���Ѥl��m)
	static array<array<bool>^> ^map;
	//�w�q�Ѥlstart��m&����j�p
	const int static_x = 171, static_y = 137, add_x = 107, add_y = 99;

	static array<int> ^Loca_c;
	static array<int> ^Loca_r;

public:
	Piece(int r, int c);
	Piece() {}
	//��l�ƴѤl���e
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
