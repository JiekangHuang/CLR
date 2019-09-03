#pragma once

#include "Piece.h"
#include "Const_Piece.h"
#include <cliext/vector>

ref class dead
{
public:
	int x, y;
	dead(int x, int y) :x(x), y(y) {}
};
ref class Board :Form
{
private:
#define Chess_num 32
	//�ѽL��C��
#define Row 4
#define	Col 8

	//�إߴѤl��l���
	array<Const_Piece^> ^init_piece;
	//�إߴѤl
	array<array<Piece^>^> ^piece;
	//�إ߷�e���a���
	Button ^curPyShow;

	array<int> ^Loca_c;
	array<int> ^Loca_r;

	array<dead^> ^L_dead;
	array<dead^> ^R_dead;

	//�w�q�Ѥlstart��m&����j�p
	const int static_x = 171, static_y = 137, add_x = 107, add_y = 99;
	//�w�q�������Ѥlstart��m&����j�p
	const int _Rstatic_x = 1045, _Lstatic_x = 34, _static_y = 114, _add_x = 56, _add_y = _add_x;

	//���´Ѽƶq
	int rNum, bNum;
	//Current player
	String ^cur_pyer;
	//Previous select piece
	Piece ^pre_piece;
	//�Ĥ@��½��
	bool isFirst;

	//�����o�^�X(���H)
	void Exch(Piece ^first);
	//�O�_��Ĺ
	bool Is_Win();
public:
	Board();
	~Board();
	//��l�ƴѽL(�~�P)
	void Init(void);
	//Ĳ�o�Ѥl
	void Action(int x, int y);
	void Action(Piece ^cur);
	//�Ǧ^�Ѥl���󪺶��X
	array<array<Piece^>^> ^Get_Piece();
	//�Ǧ^���a��ܪ���
	Button ^Get_curPyShow();
};
