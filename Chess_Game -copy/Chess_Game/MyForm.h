#pragma once
#include "Board.h"
#include <vcclr.h>

namespace ChessGame {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>

	public ref class MyForm : public System::Windows::Forms::Form
	{
		//建立棋盤物件
		Board ^board;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}
	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  reset;
	private: System::Windows::Forms::Button^  Exit;

	protected:

	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->reset = (gcnew System::Windows::Forms::Button());
			this->Exit = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			//
			// reset
			//
			this->reset->BackColor = System::Drawing::Color::Tan;
			this->reset->Font = (gcnew System::Drawing::Font(L"標楷體", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->reset->ForeColor = System::Drawing::Color::DarkRed;
			this->reset->Location = System::Drawing::Point(12, 604);
			this->reset->Name = L"reset";
			this->reset->Size = System::Drawing::Size(105, 50);
			this->reset->TabIndex = 1;
			this->reset->Text = L"重新開始";
			this->reset->UseVisualStyleBackColor = false;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			//
			// Exit
			//
			this->Exit->BackColor = System::Drawing::Color::Tan;
			this->Exit->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Exit->Font = (gcnew System::Drawing::Font(L"標楷體", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->Exit->ForeColor = System::Drawing::Color::DarkRed;
			this->Exit->Location = System::Drawing::Point(1072, 604);
			this->Exit->Name = L"Exit";
			this->Exit->Size = System::Drawing::Size(105, 50);
			this->Exit->TabIndex = 2;
			this->Exit->Text = L"結束";
			this->Exit->UseVisualStyleBackColor = false;
			this->Exit->Click += gcnew System::EventHandler(this, &MyForm::Exit_Click);
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->Exit);
			this->Controls->Add(this->reset);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Chess Game";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Mouse_Click);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void reset_Click(System::Object^  sender, System::EventArgs^  e)
	{
		board->Init();
	}
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
		board = gcnew Board();
		array<array<Piece^>^>  ^piece = board->Get_Piece();
		//將棋盤上的的棋子動態加入MyForm
		for (int i = 0; i < Row; i++)
			Controls->AddRange(piece[i]);
		//將"顯示玩家物件"動態加入MyForm
		Controls->Add(board->Get_curPyShow());
		//將所有棋子物件加入Click事件集合
		for (int i = 0; i < Row; i++)
			for (int j = 0; j < Col; j++)
				piece[i][j]->Click += gcnew EventHandler(this, &MyForm::piece_Click);
	}
	private: System::Void piece_Click(System::Object^ sender, System::EventArgs^ e)
	{
		Piece ^piece = (Piece^)sender;
		board->Action(piece);
	}
	private: System::Void Mouse_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		//傳入被觸發的棋子位置
		board->Action(e->X, e->Y);
	}
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}
	};
}
