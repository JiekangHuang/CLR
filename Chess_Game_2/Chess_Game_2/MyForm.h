#pragma once

namespace ChessGame2 {
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
	public:
		PictureBox ^newbox;
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
	private: System::Windows::Forms::Button^  button1;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
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
			this->reset->TabIndex = 2;
			this->reset->Text = L"重新開始";
			this->reset->UseVisualStyleBackColor = false;
			this->reset->Click += gcnew System::EventHandler(this, &MyForm::reset_Click);
			//
			// button1
			//
			this->button1->Location = System::Drawing::Point(1078, 585);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 64);
			this->button1->TabIndex = 3;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			//
			// MyForm
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1184, 661);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->reset);
			this->Cursor = System::Windows::Forms::Cursors::Hand;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Chess Game";
			this->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Mouse_Click);
			this->ResumeLayout(false);
		}
#pragma endregion
	private: System::Void reset_Click(System::Object^  sender, System::EventArgs^  e)
	{
		newbox = gcnew PictureBox;
		newbox->Location = Point(100, 100);
		newbox->Size = System::Drawing::Size(95, 90);
		newbox->BackgroundImageLayout = ImageLayout::Stretch;
		newbox->SizeMode = PictureBoxSizeMode::StretchImage;
		newbox->Image = System::Drawing::Image::FromFile("Image\\1-1.png");
		Controls->Add(newbox);
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Controls->Remove(newbox);
		//Controls->Clear();
		//delete newbox;
	}
	private: System::Void Exit_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Close();
	}
	private: System::Void Mouse_Click(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		int static_x = 171, static_y = 137, add_x = 107, add_y = 99;
		array<int> ^arr_x = gcnew array<int>(8);
		array<int> ^arr_y = gcnew array<int>(4);
		for (int i = 0; i < 8; i++)
			arr_x[i] = static_x + i * add_x;
		for (int i = 0; i < 4; i++)
			arr_y[i] = static_y + i * add_y;
		int r, c;
		for (int i = 0; i < 8; i++)
			if (e->X > arr_x[i])
				c = i;
		for (int i = 0; i < 4; i++)
			if (e->Y > arr_y[i])
				r = i;
		MessageBox::Show(r + "-" + c);
	}
	};
}
