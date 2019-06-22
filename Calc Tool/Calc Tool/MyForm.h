#pragma once

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
		String ^str_in;
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
	private: System::Windows::Forms::Button^  Reverse;
	protected:

	protected:

	private: System::Windows::Forms::Button^  one;
	private: System::Windows::Forms::Button^  four;
	private: System::Windows::Forms::Button^  seven;

	private: System::Windows::Forms::Button^  CE;
	private: System::Windows::Forms::Button^  zero;
	private: System::Windows::Forms::Button^  two;
	private: System::Windows::Forms::Button^  five;
	private: System::Windows::Forms::Button^  eight;

	private: System::Windows::Forms::Button^  C;
	private: System::Windows::Forms::Button^  Decimal_point;
	private: System::Windows::Forms::Button^  three;
	private: System::Windows::Forms::Button^  six;
	private: System::Windows::Forms::Button^  nine;

	private: System::Windows::Forms::Button^  del;
	private: System::Windows::Forms::Button^  equal;
	private: System::Windows::Forms::Button^  ad;

	private: System::Windows::Forms::Button^  less;

	private: System::Windows::Forms::Button^  Multiply_by;

	private: System::Windows::Forms::Button^  Divide_by;
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
			this->Reverse = (gcnew System::Windows::Forms::Button());
			this->one = (gcnew System::Windows::Forms::Button());
			this->four = (gcnew System::Windows::Forms::Button());
			this->seven = (gcnew System::Windows::Forms::Button());
			this->CE = (gcnew System::Windows::Forms::Button());
			this->zero = (gcnew System::Windows::Forms::Button());
			this->two = (gcnew System::Windows::Forms::Button());
			this->five = (gcnew System::Windows::Forms::Button());
			this->eight = (gcnew System::Windows::Forms::Button());
			this->C = (gcnew System::Windows::Forms::Button());
			this->Decimal_point = (gcnew System::Windows::Forms::Button());
			this->three = (gcnew System::Windows::Forms::Button());
			this->six = (gcnew System::Windows::Forms::Button());
			this->nine = (gcnew System::Windows::Forms::Button());
			this->del = (gcnew System::Windows::Forms::Button());
			this->equal = (gcnew System::Windows::Forms::Button());
			this->ad = (gcnew System::Windows::Forms::Button());
			this->less = (gcnew System::Windows::Forms::Button());
			this->Multiply_by = (gcnew System::Windows::Forms::Button());
			this->Divide_by = (gcnew System::Windows::Forms::Button());
			this->ans = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			//
			// Reverse
			//
			this->Reverse->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Reverse->Location = System::Drawing::Point(12, 342);
			this->Reverse->Name = L"Reverse";
			this->Reverse->Size = System::Drawing::Size(60, 60);
			this->Reverse->TabIndex = 9;
			this->Reverse->Text = L"+-";
			this->Reverse->UseVisualStyleBackColor = true;
			this->Reverse->Click += gcnew System::EventHandler(this, &MyForm::Reverse_Click);
			//
			// one
			//
			this->one->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->one->Location = System::Drawing::Point(12, 276);
			this->one->Name = L"one";
			this->one->Size = System::Drawing::Size(60, 60);
			this->one->TabIndex = 8;
			this->one->Text = L"1";
			this->one->UseVisualStyleBackColor = true;
			this->one->Click += gcnew System::EventHandler(this, &MyForm::one_Click);
			//
			// four
			//
			this->four->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->four->Location = System::Drawing::Point(12, 210);
			this->four->Name = L"four";
			this->four->Size = System::Drawing::Size(60, 60);
			this->four->TabIndex = 7;
			this->four->Text = L"4";
			this->four->UseVisualStyleBackColor = true;
			this->four->Click += gcnew System::EventHandler(this, &MyForm::four_Click);
			//
			// seven
			//
			this->seven->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->seven->Location = System::Drawing::Point(12, 144);
			this->seven->Name = L"seven";
			this->seven->Size = System::Drawing::Size(60, 60);
			this->seven->TabIndex = 6;
			this->seven->Text = L"7";
			this->seven->UseVisualStyleBackColor = true;
			this->seven->Click += gcnew System::EventHandler(this, &MyForm::seven_Click);
			//
			// CE
			//
			this->CE->BackColor = System::Drawing::Color::Silver;
			this->CE->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CE->Location = System::Drawing::Point(12, 78);
			this->CE->Name = L"CE";
			this->CE->Size = System::Drawing::Size(60, 60);
			this->CE->TabIndex = 5;
			this->CE->Text = L"CE";
			this->CE->UseVisualStyleBackColor = false;
			this->CE->Click += gcnew System::EventHandler(this, &MyForm::CE_Click);
			//
			// zero
			//
			this->zero->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zero->Location = System::Drawing::Point(78, 342);
			this->zero->Name = L"zero";
			this->zero->Size = System::Drawing::Size(60, 60);
			this->zero->TabIndex = 14;
			this->zero->Text = L"0";
			this->zero->UseVisualStyleBackColor = true;
			this->zero->Click += gcnew System::EventHandler(this, &MyForm::zero_Click);
			//
			// two
			//
			this->two->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->two->Location = System::Drawing::Point(78, 276);
			this->two->Name = L"two";
			this->two->Size = System::Drawing::Size(60, 60);
			this->two->TabIndex = 13;
			this->two->Text = L"2";
			this->two->UseVisualStyleBackColor = true;
			this->two->Click += gcnew System::EventHandler(this, &MyForm::two_Click);
			//
			// five
			//
			this->five->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->five->Location = System::Drawing::Point(78, 210);
			this->five->Name = L"five";
			this->five->Size = System::Drawing::Size(60, 60);
			this->five->TabIndex = 12;
			this->five->Text = L"5";
			this->five->UseVisualStyleBackColor = true;
			this->five->Click += gcnew System::EventHandler(this, &MyForm::five_Click);
			//
			// eight
			//
			this->eight->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->eight->Location = System::Drawing::Point(78, 144);
			this->eight->Name = L"eight";
			this->eight->Size = System::Drawing::Size(60, 60);
			this->eight->TabIndex = 11;
			this->eight->Text = L"8";
			this->eight->UseVisualStyleBackColor = true;
			this->eight->Click += gcnew System::EventHandler(this, &MyForm::eight_Click);
			//
			// C
			//
			this->C->BackColor = System::Drawing::Color::Silver;
			this->C->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->C->Location = System::Drawing::Point(78, 78);
			this->C->Name = L"C";
			this->C->Size = System::Drawing::Size(60, 60);
			this->C->TabIndex = 10;
			this->C->Text = L"C";
			this->C->UseVisualStyleBackColor = false;
			this->C->Click += gcnew System::EventHandler(this, &MyForm::C_Click);
			//
			// Decimal_point
			//
			this->Decimal_point->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Decimal_point->Location = System::Drawing::Point(144, 342);
			this->Decimal_point->Name = L"Decimal_point";
			this->Decimal_point->Size = System::Drawing::Size(60, 60);
			this->Decimal_point->TabIndex = 19;
			this->Decimal_point->Text = L".";
			this->Decimal_point->UseVisualStyleBackColor = true;
			this->Decimal_point->Click += gcnew System::EventHandler(this, &MyForm::Decimal_point_Click);
			//
			// three
			//
			this->three->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->three->Location = System::Drawing::Point(144, 276);
			this->three->Name = L"three";
			this->three->Size = System::Drawing::Size(60, 60);
			this->three->TabIndex = 18;
			this->three->Text = L"3";
			this->three->UseVisualStyleBackColor = true;
			this->three->Click += gcnew System::EventHandler(this, &MyForm::three_Click);
			//
			// six
			//
			this->six->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->six->Location = System::Drawing::Point(144, 210);
			this->six->Name = L"six";
			this->six->Size = System::Drawing::Size(60, 60);
			this->six->TabIndex = 17;
			this->six->Text = L"6";
			this->six->UseVisualStyleBackColor = true;
			this->six->Click += gcnew System::EventHandler(this, &MyForm::six_Click);
			//
			// nine
			//
			this->nine->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->nine->Location = System::Drawing::Point(144, 144);
			this->nine->Name = L"nine";
			this->nine->Size = System::Drawing::Size(60, 60);
			this->nine->TabIndex = 16;
			this->nine->Text = L"9";
			this->nine->UseVisualStyleBackColor = true;
			this->nine->Click += gcnew System::EventHandler(this, &MyForm::nine_Click);
			//
			// del
			//
			this->del->BackColor = System::Drawing::Color::Silver;
			this->del->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->del->Location = System::Drawing::Point(144, 78);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(60, 60);
			this->del->TabIndex = 15;
			this->del->Text = L"del";
			this->del->UseVisualStyleBackColor = false;
			this->del->Click += gcnew System::EventHandler(this, &MyForm::del_Click);
			//
			// equal
			//
			this->equal->BackColor = System::Drawing::Color::Silver;
			this->equal->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->equal->Location = System::Drawing::Point(210, 342);
			this->equal->Name = L"equal";
			this->equal->Size = System::Drawing::Size(60, 60);
			this->equal->TabIndex = 24;
			this->equal->Text = L"=";
			this->equal->UseVisualStyleBackColor = false;
			this->equal->Click += gcnew System::EventHandler(this, &MyForm::equal_Click);
			//
			// ad
			//
			this->ad->BackColor = System::Drawing::Color::Silver;
			this->ad->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ad->Location = System::Drawing::Point(210, 276);
			this->ad->Name = L"ad";
			this->ad->Size = System::Drawing::Size(60, 60);
			this->ad->TabIndex = 23;
			this->ad->Text = L"+";
			this->ad->UseVisualStyleBackColor = false;
			this->ad->Click += gcnew System::EventHandler(this, &MyForm::ad_Click);
			//
			// less
			//
			this->less->BackColor = System::Drawing::Color::Silver;
			this->less->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->less->Location = System::Drawing::Point(210, 210);
			this->less->Name = L"less";
			this->less->Size = System::Drawing::Size(60, 60);
			this->less->TabIndex = 22;
			this->less->Text = L"-";
			this->less->UseVisualStyleBackColor = false;
			this->less->Click += gcnew System::EventHandler(this, &MyForm::less_Click);
			//
			// Multiply_by
			//
			this->Multiply_by->BackColor = System::Drawing::Color::Silver;
			this->Multiply_by->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Multiply_by->Location = System::Drawing::Point(210, 144);
			this->Multiply_by->Name = L"Multiply_by";
			this->Multiply_by->Size = System::Drawing::Size(60, 60);
			this->Multiply_by->TabIndex = 21;
			this->Multiply_by->Text = L"x";
			this->Multiply_by->UseVisualStyleBackColor = false;
			this->Multiply_by->Click += gcnew System::EventHandler(this, &MyForm::Multiply_by_Click);
			//
			// Divide_by
			//
			this->Divide_by->BackColor = System::Drawing::Color::Silver;
			this->Divide_by->Font = (gcnew System::Drawing::Font(L"Bahnschrift", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Divide_by->Location = System::Drawing::Point(210, 78);
			this->Divide_by->Name = L"Divide_by";
			this->Divide_by->Size = System::Drawing::Size(60, 60);
			this->Divide_by->TabIndex = 20;
			this->Divide_by->Text = L"/";
			this->Divide_by->UseVisualStyleBackColor = false;
			this->Divide_by->Click += gcnew System::EventHandler(this, &MyForm::Divide_by_Click);
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
			this->Controls->Add(this->equal);
			this->Controls->Add(this->ad);
			this->Controls->Add(this->less);
			this->Controls->Add(this->Multiply_by);
			this->Controls->Add(this->Divide_by);
			this->Controls->Add(this->Decimal_point);
			this->Controls->Add(this->three);
			this->Controls->Add(this->six);
			this->Controls->Add(this->nine);
			this->Controls->Add(this->del);
			this->Controls->Add(this->zero);
			this->Controls->Add(this->two);
			this->Controls->Add(this->five);
			this->Controls->Add(this->eight);
			this->Controls->Add(this->C);
			this->Controls->Add(this->Reverse);
			this->Controls->Add(this->one);
			this->Controls->Add(this->four);
			this->Controls->Add(this->seven);
			this->Controls->Add(this->CE);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion
	private: System::Void nine_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "9";
		ans->Text = str_in;
	}
	private: System::Void ad_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "+";
		ans->Text = str_in;
	}
	private: System::Void less_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "-";
		ans->Text = str_in;
	}
	private: System::Void Multiply_by_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "*";
		ans->Text = str_in;
	}
	private: System::Void Divide_by_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "/";
		ans->Text = str_in;
	}
	private: System::Void Decimal_point_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += ".";
		ans->Text = str_in;
	}
	private: System::Void three_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "3";
		ans->Text = str_in;
	}
	private: System::Void six_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "6";
		ans->Text = str_in;
	}
	private: System::Void equal_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void del_Click(System::Object^  sender, System::EventArgs^  e) {
		if (!str_in->Empty)
			str_in = str_in->Remove(0, 1);
		ans->Text = "";
		ans->Text = str_in;
	}
	private: System::Void zero_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "0";
		ans->Text = str_in;
	}
	private: System::Void two_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "2";
		ans->Text = str_in;
	}
	private: System::Void five_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "5";
		ans->Text = str_in;
	}
	private: System::Void eight_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "8";
		ans->Text = str_in;
	}
	private: System::Void C_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in = "";
		ans->Text = "0";
	}
	private: System::Void Reverse_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void one_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "1";
		ans->Text = str_in;
	}
	private: System::Void four_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "4";
	}
	private: System::Void seven_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in += "7";
		ans->Text = str_in;
	}
	private: System::Void CE_Click(System::Object^  sender, System::EventArgs^  e) {
		str_in = "";
		ans->Text = "0";
	}
	};
}
