#pragma once
#include "expression.h"
#include <msclr/marshal_cppstd.h>


namespace Calculator_Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Xml::Serialization;
	



	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{

	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  textBox2;

	protected:

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::TextBox^  textBox1;

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  postLabel;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->postLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(479, 314);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 28);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Evaluate";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::AliceBlue;
			this->textBox2->Location = System::Drawing::Point(13, 35);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox2->Size = System::Drawing::Size(499, 203);
			this->textBox2->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(255, 249);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 28);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Clear";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(357, 249);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(91, 28);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::LightSteelBlue;
			this->textBox1->Location = System::Drawing::Point(13, 317);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(458, 22);
			this->textBox1->TabIndex = 4;
			this->textBox1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyUp);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(458, 249);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(91, 28);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Load";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(13, 295);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(188, 17);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Enter your expression (infix):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(12, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(56, 17);
			this->label2->TabIndex = 10;
			this->label2->Text = L"History:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(13, 346);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 17);
			this->label3->TabIndex = 12;
			this->label3->Text = L"postfix:";
			// 
			// postLabel
			// 
			this->postLabel->AutoSize = true;
			this->postLabel->BackColor = System::Drawing::Color::Transparent;
			this->postLabel->Location = System::Drawing::Point(58, 347);
			this->postLabel->Name = L"postLabel";
			this->postLabel->Size = System::Drawing::Size(0, 17);
			this->postLabel->TabIndex = 13;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SlateGray;
			this->ClientSize = System::Drawing::Size(587, 378);
			this->Controls->Add(this->postLabel);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->IsMdiContainer = true;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->Text = L"Expression Calculator";
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ enteredExpression = "";
		String^ postfixExpression = "";

		enteredExpression = textBox1->Text;
	
		
		try{
			string converted_Exp = msclr::interop::marshal_as< string >(enteredExpression); // convert from String^ to string
			Expression exp = Expression(converted_Exp);

			String^ post = gcnew String(exp.toPostfix().c_str()); // from string to String^
			postLabel->Text = post;

			String^ result = exp.evaluate().ToString();		

			if (textBox2->Text == "")
				textBox2->Text = enteredExpression + "=" + result;
			else{
				textBox2->Text = textBox2->Text + " \r\n" + enteredExpression + "=" + result;

			} 
		
			textBox1->Text = "";

		}
		catch (...){

			MessageBox::Show("Syntax error , Pls try again");
		}




	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	
			 textBox2->Text = "";
	}

			

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {



		String^ pathSelected = "";
		SaveFileDialog^ sd = gcnew SaveFileDialog;
		sd->ShowDialog();
		pathSelected = sd->InitialDirectory + sd->FileName + ".txt" ;

		StreamWriter^ sw = gcnew StreamWriter(pathSelected);
		sw->Write(textBox2->Text);
		sw->Close();




	}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {

	String^ pathSelected = "";
	String^ readed = "";
	OpenFileDialog^ ofd = gcnew OpenFileDialog;
	ofd->ShowDialog();
	pathSelected = ofd->InitialDirectory + ofd->FileName ;

	StreamReader^ sr = gcnew StreamReader(pathSelected);

	textBox2->Text = File::ReadAllText(pathSelected);

	


	

}
private: System::Void textBox1_KeyUp(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {

	if (e->KeyCode == Keys::Enter){ // to get get result when enter is pressed

	
	String^ enteredExpression = "";
	String^ postfixExpression = "";

	enteredExpression = textBox1->Text;
	textBox1->Text = "";


	try{
		string converted_Exp = msclr::interop::marshal_as< string >(enteredExpression); // convert from String^ to string
		Expression exp = Expression(converted_Exp);

		String^ post = gcnew String(exp.toPostfix().c_str()); // from string to String^
		postLabel->Text = post;

		String^ result = exp.evaluate().ToString();

		if (textBox2->Text == "")
			textBox2->Text = enteredExpression + "=" + result;
		else{
			textBox2->Text = textBox2->Text + " \r\n" + enteredExpression + "=" + result;

		}

		textBox1->Text = "";


	}
	catch (...){

		MessageBox::Show("Syntax error , Pls try again");
	}

}
}
};
}


