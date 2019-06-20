#pragma once

#include <vector>
#include "Piece.h"
#include "Const_Piece.h"

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
	//��������
	array<PictureBox^> ^L_dead;
	array<PictureBox^> ^R_dead;

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

public:
	Board();
	//��l�ƴѽL(�~�P)
	void Init(void);
	//Ĳ�o�Ѥl
	void Action(int idx_x, int idx_y);
	//�����o�^�X(���H)
	void Exch(Piece ^first);
	//�Ǧ^�Ѥl���󪺶��X
	array<array<Piece^>^> ^Get_Piece();
	//�Ǧ^���a��ܪ���
	Button ^Get_curPyShow();
	//�O�_��Ĺ
	bool Is_Win();
	//
	array<PictureBox^> ^Get_L_dead();
	array<PictureBox^> ^Get_R_dead();
};
