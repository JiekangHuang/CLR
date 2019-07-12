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
	int idx_x, idx_y;
	//�ѽL�a��(�����Ҧ��ѽL�W���Ѥl��m)
	static array<array<bool>^> ^map;

public:
	Piece(int x, int y, int idx_x, int idx_y);
	Piece() {}
	//��l�ƴѤl���e
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
