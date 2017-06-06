#pragma once
#include "ListDir.h"
#include <msclr\marshal_cppstd.h>

namespace UI {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	
	
	public: ListDir *LD;
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
	private: System::Windows::Forms::Label^  lbl;
	protected:





	private: System::Windows::Forms::FolderBrowserDialog^  fbd;
	private: System::Windows::Forms::ListView^  lvw;
	private: System::Windows::Forms::ColumnHeader^  colFileName;
	private: System::Windows::Forms::ColumnHeader^  colType;
	private: System::Windows::Forms::ColumnHeader^  colSize;
	private: System::Windows::Forms::Button^  btn;

	protected:

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
			
			LD = new ListDir();

			this->lbl = (gcnew System::Windows::Forms::Label());
			this->fbd = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->lvw = (gcnew System::Windows::Forms::ListView());
			this->colFileName = (gcnew System::Windows::Forms::ColumnHeader());
			this->colType = (gcnew System::Windows::Forms::ColumnHeader());
			this->colSize = (gcnew System::Windows::Forms::ColumnHeader());
			this->btn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// lbl
			// 
			this->lbl->AutoSize = true;
			this->lbl->Location = System::Drawing::Point(12, 469);
			this->lbl->Name = L"lbl";
			this->lbl->Size = System::Drawing::Size(27, 13);
			this->lbl->TabIndex = 1;
			this->lbl->Text = L"N/A";
			// 
			// lvw
			// 
			this->lvw->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->colFileName, this->colType,
					this->colSize
			});
			this->lvw->FullRowSelect = true;
			this->lvw->GridLines = true;
			this->lvw->Location = System::Drawing::Point(12, 12);
			this->lvw->Name = L"lvw";
			this->lvw->Size = System::Drawing::Size(713, 451);
			this->lvw->TabIndex = 2;
			this->lvw->UseCompatibleStateImageBehavior = false;
			this->lvw->View = System::Windows::Forms::View::Details;
			// 
			// colFileName
			// 
			this->colFileName->Text = L"File Name";
			this->colFileName->Width = 307;
			// 
			// colType
			// 
			this->colType->Text = L"Type";
			this->colType->Width = 233;
			// 
			// colSize
			// 
			this->colSize->Text = L"Size (byte)";
			this->colSize->Width = 166;
			// 
			// btn
			// 
			this->btn->Location = System::Drawing::Point(613, 469);
			this->btn->Name = L"btn";
			this->btn->Size = System::Drawing::Size(113, 23);
			this->btn->TabIndex = 3;
			this->btn->Text = L"Select Folder";
			this->btn->UseVisualStyleBackColor = true;
			this->btn->Click += gcnew System::EventHandler(this, &MyForm::btn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 502);
			this->Controls->Add(this->btn);
			this->Controls->Add(this->lvw);
			this->Controls->Add(this->lbl);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btn_Click(System::Object^  sender, System::EventArgs^  e) {
		fbd->ShowDialog(this);
		lbl->Text = fbd->SelectedPath;

		try
		{
			std::string path = msclr::interop::marshal_as< std::string >(fbd->SelectedPath);			
			LD->Directory(path);
			

			/*DirectoryInfo ^ dirInfo = gcnew DirectoryInfo(fbd->SelectedPath);
			if (dirInfo->Exists) {
				array<FileInfo ^> ^files = dirInfo->GetFiles();
				for (int i = 0; i < files->Length; i++)
				{
					ListViewItem ^ lvi = lvw->Items->Add(files[i]->ToString());
					lvi->SubItems->Add("File");
					lvi->SubItems->Add(files[i]->Length.ToString());
				}

				array<DirectoryInfo ^> ^subDirs = dirInfo->GetDirectories();
				for (int i = 0; i < subDirs->Length; i++)
				{
					ListViewItem ^ lvi = lvw->Items->Add(subDirs[i]->ToString());
					lvi->SubItems->Add("Dir");
					lvi->SubItems->Add(" ");
				}
			}*/

			
		}
		finally
		{

		}
	}
};
}
