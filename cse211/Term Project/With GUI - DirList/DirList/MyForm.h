#pragma once
#include "ItemInfo.h"

namespace DirList {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	using namespace DirList;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: DirList::NodeList^ list;
	private: bool s0, s1, s2;
	private: int last,lastS;

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
	private: System::Windows::Forms::ListView^  lvw;
	protected:
	private: System::Windows::Forms::ColumnHeader^  colFileName;
	private: System::Windows::Forms::ColumnHeader^  colType;
	private: System::Windows::Forms::ColumnHeader^  colSize;
	private: System::Windows::Forms::FolderBrowserDialog^  fbd;
	private: System::Windows::Forms::Label^  lblPath;
	private: System::Windows::Forms::Button^  btn;
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
				 this->lvw = (gcnew System::Windows::Forms::ListView());
				 this->colFileName = (gcnew System::Windows::Forms::ColumnHeader());
				 this->colType = (gcnew System::Windows::Forms::ColumnHeader());
				 this->colSize = (gcnew System::Windows::Forms::ColumnHeader());
				 this->fbd = (gcnew System::Windows::Forms::FolderBrowserDialog());
				 this->lblPath = (gcnew System::Windows::Forms::Label());
				 this->btn = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // lvw
				 // 
				 this->lvw->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->lvw->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
					 this->colFileName, this->colType,
						 this->colSize
				 });
				 this->lvw->FullRowSelect = true;
				 this->lvw->GridLines = true;
				 this->lvw->Location = System::Drawing::Point(0, 0);
				 this->lvw->Margin = System::Windows::Forms::Padding(2);
				 this->lvw->Name = L"lvw";
				 this->lvw->Size = System::Drawing::Size(904, 517);
				 this->lvw->TabIndex = 0;
				 this->lvw->UseCompatibleStateImageBehavior = false;
				 this->lvw->View = System::Windows::Forms::View::Details;
				 this->lvw->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &MyForm::lvw_ColumnClick);
				 this->lvw->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::lvw_KeyDown);
				 // 
				 // colFileName
				 // 
				 this->colFileName->Text = L"File Name";
				 this->colFileName->Width = 400;
				 // 
				 // colType
				 // 
				 this->colType->Text = L"Type";
				 this->colType->Width = 150;
				 // 
				 // colSize
				 // 
				 this->colSize->Text = L"Size (byte)";
				 this->colSize->Width = 300;
				 // 
				 // lblPath
				 // 
				 this->lblPath->AutoSize = true;
				 this->lblPath->Location = System::Drawing::Point(11, 532);
				 this->lblPath->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->lblPath->Name = L"lblPath";
				 this->lblPath->Size = System::Drawing::Size(27, 13);
				 this->lblPath->TabIndex = 1;
				 this->lblPath->Text = L"N/A";
				 // 
				 // btn
				 // 
				 this->btn->Location = System::Drawing::Point(788, 524);
				 this->btn->Margin = System::Windows::Forms::Padding(2);
				 this->btn->Name = L"btn";
				 this->btn->Size = System::Drawing::Size(105, 24);
				 this->btn->TabIndex = 2;
				 this->btn->Text = L"Select Folder";
				 this->btn->UseVisualStyleBackColor = true;
				 this->btn->Click += gcnew System::EventHandler(this, &MyForm::btn_Click);
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(900, 552);
				 this->Controls->Add(this->btn);
				 this->Controls->Add(this->lblPath);
				 this->Controls->Add(this->lvw);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
				 this->Margin = System::Windows::Forms::Padding(2);
				 this->MaximizeBox = false;
				 this->Name = L"MyForm";
				 this->Text = L"DirList";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void btn_Click(System::Object^  sender, System::EventArgs^  e) {

		fbd->ShowDialog(this);
		lblPath->Text = fbd->SelectedPath;
		if (list == nullptr) list = gcnew NodeList(); else list->Clear();

		try
		{
			DirectoryInfo ^ dirInfo = gcnew DirectoryInfo(fbd->SelectedPath);
			if (dirInfo->Exists) // make sure directory exists
			{
				array< FileInfo ^ > ^ files = dirInfo->GetFiles();
				for (int i = 0; i < files->Length; i++)
				{
					if(!files[i]->Attributes.HasFlag(FileAttributes::Hidden))//if not hiddenfile -> add
						list->Add(gcnew ItemInfo(files[i]->Name, files[i]->Extension, files[i]->Length));
				}
				
				array< DirectoryInfo ^ > ^ subDirs = dirInfo->GetDirectories();
				for (int i = 0; i < subDirs->Length; i++)
				{
					list->Add(gcnew ItemInfo(subDirs[i]->Name, "<DIR>", 0));
				}

				s0 = true;
				s1 = true;
				s2 = true;

			}
		}
		catch (Exception^ a) { }
		finally
		{
			FillList(0, s0);
			last = 0;
			lastS = s0;
		}
	}
	private: System::Void lvw_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e) {
		lvw->Items->Clear();

		if (e->Column == 0) {
			FillList(0, s0);
			lastS = s0;
			s0 = !s0;
		}

		else if (e->Column == 1) {
			FillList(1, s1);
			lastS = s1;
			s1 = !s1;
		}
		else if (e->Column == 2) {
			FillList(2, s2);
			lastS = s2;
			s2 = !s2;
		}
		last = e->Column;
	}

	

	private: void FillList(int col, bool asc)
	{
		lvw->Items->Clear();

		if (col == 0)
		{
			Node^ current = asc ? list->NameHead : list->NameTail;
			while (current != nullptr)
			{
				ListViewItem^ lvi = lvw->Items->Add(current->Item->FileName);
				lvi->SubItems->Add(current->Item->TypeName);
				lvi->SubItems->Add(current->Item->ByteSize? current->Item->ByteSize.ToString():"");
				current = asc ? current->NameNext : current->NamePrev;
			}
		}
		else if (col == 1)
		{
			Node^ current = asc ? list->TypeHead : list->TypeTail;
			while (current != nullptr)
			{
				ListViewItem^ lvi = lvw->Items->Add(current->Item->FileName);
				lvi->SubItems->Add(current->Item->TypeName);
				lvi->SubItems->Add(current->Item->ByteSize ? current->Item->ByteSize.ToString() : "");
				current = asc ? current->TypeNext : current->TypePrev;
			}
		}
		else if (col == 2)
		{
			Node^ current = asc ? list->SizeHead : list->SizeTail;
			while (current != nullptr)
			{
				ListViewItem^ lvi = lvw->Items->Add(current->Item->FileName);
				lvi->SubItems->Add(current->Item->TypeName);
				lvi->SubItems->Add(current->Item->ByteSize ? current->Item->ByteSize.ToString() : "");
				current = asc ? current->SizeNext : current->SizePrev;
			}
		}
		
	}

	private: System::Void lvw_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Delete && lvw->Items->Count!=0 && lvw->SelectedItems->Count!=0) {
			for (int i = 0; i < lvw->SelectedItems->Count; i++)
			{
				String^ fileName = lvw->SelectedItems[i]->Text;
				list->Remove(fileName);
			}
		
			FillList(last, lastS);

		}
	}
};
}
