#pragma once

#include <vector>
#include "Piece.h"
#include "Const_Piece.h"

ref class Board :Form
{
private:
#define Chess_num 32
	//棋盤行列數
#define Row 4
#define	Col 8

	//建立棋子原始資料
	array<Const_Piece^> ^init_piece;
	//建立棋子
	array<array<Piece^>^> ^piece;
	//建立當前玩家顯示
	Button ^curPyShow;
	//死掉的棋
	array<PictureBox^> ^L_dead;
	array<PictureBox^> ^R_dead;

	//定義棋子start位置&間格大小
	const int static_x = 171, static_y = 137, add_x = 107, add_y = 99;
	//定義死掉的棋子start位置&間格大小
	const int _Rstatic_x = 1045, _Lstatic_x = 34, _static_y = 114, _add_x = 56, _add_y = _add_x;

	//紅黑棋數量
	int rNum, bNum;
	//Current player
	String ^cur_pyer;
	//Previous select piece
	Piece ^pre_piece;
	//第一次翻棋
	bool isFirst;

public:
	Board();
	//初始化棋盤(洗牌)
	void Init(void);
	//觸發棋子
	void Action(int idx_x, int idx_y);
	//結束這回合(換人)
	void Exch(Piece ^first);
	//傳回棋子物件的集合
	array<array<Piece^>^> ^Get_Piece();
	//傳回玩家顯示物件
	Button ^Get_curPyShow();
	//是否有贏
	bool Is_Win();
	//
	array<PictureBox^> ^Get_L_dead();
	array<PictureBox^> ^Get_R_dead();
};
