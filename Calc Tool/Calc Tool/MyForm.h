#pragma once
#include <msclr\marshal_cppstd.h>
#include "Mybutton.h"
#include "Infix_to_Postfix.h"
#include "Postfix_Evaluation.h"

namespace CalcTool {
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
		System::String ^str;
		int static_x = 12, static_y = 78, add = 66;
		array<Mybutton^ > ^button;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
			{
				button = gcnew array<Mybutton^ >(20);
				button[0] = gcnew Mybutton(static_x + add * 0, static_y + add * 0, "CE", "oper");
				button[1] = gcnew Mybutton(static_x + add * 1, static_y + add * 0, "C", "oper");
				button[2] = gcnew Mybutton(static_x + add * 2, static_y + add * 0, "del", "oper");
				button[3] = gcnew Mybutton(static_x + add * 3, static_y + add * 0, "÷", "oper");
				button[4] = gcnew Mybutton(static_x + add * 0, static_y + add * 1, "7", "num");
				button[5] = gcnew Mybutton(static_x + add * 1, static_y + add * 1, "8", "num");
				button[6] = gcnew Mybutton(static_x + add * 2, static_y + add * 1, "9", "num");
				button[7] = gcnew Mybutton(static_x + add * 3, static_y + add * 1, "×", "oper");
				button[8] = gcnew Mybutton(static_x + add * 0, static_y + add * 2, "4", "num");
				button[9] = gcnew Mybutton(static_x + add * 1, static_y + add * 2, "5", "num");
				button[10] = gcnew Mybutton(static_x + add * 2, static_y + add * 2, "6", "num");
				button[11] = gcnew Mybutton(static_x + add * 3, static_y + add * 2, "+", "oper");
				button[12] = gcnew Mybutton(static_x + add * 0, static_y + add * 3, "1", "num");
				button[13] = gcnew Mybutton(static_x + add * 1, static_y + add * 3, "2", "num");
				button[14] = gcnew Mybutton(static_x + add * 2, static_y + add * 3, "3", "num");
				button[15] = gcnew Mybutton(static_x + add * 3, static_y + add * 3, "-", "oper");
				button[16] = gcnew Mybutton(static_x + add * 0, static_y + add * 4, "+-", "oper");
				button[17] = gcnew Mybutton(static_x + add * 1, static_y + add * 4, "0", "num");
				button[18] = gcnew Mybutton(static_x + add * 2, static_y + add * 4, ".", "oper");
				button[19] = gcnew Mybutton(static_x + add * 3, static_y + add * 4, "=", "oper");
			}
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

	protected:

	protected:

	private: System::Windows::Forms::Label^  ans;

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
			this->ans = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			//
			// ans
			//
			this->ans->AutoEllipsis = true;
			this->ans->AutoSize = true;
			this->ans->BackColor = System::Drawing::Color::DarkGray;
			this->ans->Cursor = System::Windows::Forms::Cursors::Hand;
			this->ans->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->ans->Font = (gcnew System::Drawing::Font(L"Bahnschrift Condensed", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ans->Location = System::Drawing::Point(12, 24);
			this->ans->Name = L"ans";
			this->ans->Size = System::Drawing::Size(30, 39);
			this->ans->TabIndex = 25;
			this->ans->Text = L"0";
			this->ans->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::DarkGray;
			this->ClientSize = System::Drawing::Size(282, 414);
			this->Controls->Add(this->ans);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Calc Tool";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
		Controls->AddRange(button);
		for (int i = 0; i < 20; i++)
			button[i]->Click += gcnew EventHandler(this, &MyForm::button_Click);
	}

	private: System::Void button_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//轉換物件
		Mybutton ^but = (Mybutton^)sender;
		String ^name = but->Name;

		if (name == "CE" || name == "C")
		{
			str = "";
			ans->Text = "0";
		}
		else if (name == "del")
		{
			if (!String::IsNullOrEmpty(str))
			{
				str = str->Remove(str->Length - 1);
				ans->Text = str;
			}
			if (String::IsNullOrEmpty(str))
				ans->Text = "0";
		}
		else if (name == "=")
		{
			if (!String::IsNullOrEmpty(str))
			{
				Char f = str[0];
				Char b = str[str->Length - 1];
				if (f == '+' || f == '-' || f == 215 || f == 247)
					str = str->Remove(str->Length - 1);
				if (b == '+' || b == '-' || b == 215 || b == 247)
					str = str->Remove(str->Length - 1);

				for (int i = 0; i < str->Length; i++)
				{
					if (str[i] == 215)
					{
						str = str->Remove(i, 1);
						str = str->Insert(i, "*");
					}
					else if (str[i] == 247)
					{
						str = str->Remove(i, 1);
						str = str->Insert(i, "/");
					}
				}
				std::string fs = msclr::interop::marshal_as<std::string>(str->ToString());
				std::vector<std::string> postfix;
				postfix = Infix_Postfix(fs);
				std::string str_ans = Postfix_Evaluation(postfix);
				str = gcnew String(str_ans.c_str());
			}
			ans->Text = str;
			str = "";
		}
		else if (name == "+" || name == "-" || name == "×" || name == "÷")
		{
			if (String::IsNullOrEmpty(str))
			{
				str = "0" + name;
			}
			Char b = str[str->Length - 1];
			if (b != '+' && b != '-' && b != 215 && b != 247)
				str += name;
			else
			{
				str = str->Remove(str->Length - 1);
				str += name;
			}
			ans->Text = str;
		}
		else
		{
			str += name;
			ans->Text = str;
		}
	}
	};
}
