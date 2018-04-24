﻿#pragma once
#include"AddItem.h"
#include"Functions.h"
#include<vector>

//Global variable
std::vector <std::vector<std::string>> information;

namespace ToDoList {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListView^  listView1;
	protected:
	private: System::Windows::Forms::ColumnHeader^  columnHeader1;
	private: System::Windows::Forms::ColumnHeader^  columnHeader2;
	private: System::Windows::Forms::ColumnHeader^  columnHeader3;
	private: System::Windows::Forms::ColumnHeader^  columnHeader4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(4) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4
			});
			this->listView1->FullRowSelect = true;
			this->listView1->Location = System::Drawing::Point(12, 12);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(535, 612);
			this->listView1->TabIndex = 0;
			this->listView1->UseCompatibleStateImageBehavior = false;
			this->listView1->View = System::Windows::Forms::View::Details;
			this->listView1->ColumnClick += gcnew System::Windows::Forms::ColumnClickEventHandler(this, &Form1::listView1_ColumnClick);
			this->listView1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::listView1_SelectedIndexChanged);
			this->listView1->Enter += gcnew System::EventHandler(this, &Form1::listView1_Enter);
			// 
			// columnHeader1
			// 
			this->columnHeader1->Text = L"Date";
			this->columnHeader1->Width = 123;
			// 
			// columnHeader2
			// 
			this->columnHeader2->Text = L"Name";
			this->columnHeader2->Width = 129;
			// 
			// columnHeader3
			// 
			this->columnHeader3->Text = L"Priority";
			this->columnHeader3->Width = 98;
			// 
			// columnHeader4
			// 
			this->columnHeader4->Text = L"Description";
			this->columnHeader4->Width = 123;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->button1->Location = System::Drawing::Point(553, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 200);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Add new item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(760, 12);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(200, 200);
			this->button2->TabIndex = 2;
			this->button2->Text = L"More info";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(553, 218);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(134, 59);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Delete item";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// Form1
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(120, 120);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(972, 636);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"To Do List";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//Atslēdz, lai lietotājs nevar neko darīt kamēr pievieno jaunu informāciju
		this->Enabled = false;
		//Izveido un parāda jaunu form priekš informācijas ievades
		//Tā izskatīsies labāk nekā piepildīt galveno form ar dažādiem text boxiem
		ToDoList::AddItem addItemForm;
		addItemForm.ShowDialog();
		//Pēc form aizstaisīšanas galvenais form atkal tiek ieslēgts
		this->Enabled = true;

		//Pārnes saņemto informāciju (ja tāda ir) uz listview.
		//Iztīra visu no listview, lai tas neatkārtotos divas reizes
		std::vector<std::string> list;
		std::string buffer;
		ifstream file("list.txt");
		int i = 0;

		information.clear();
		while (!file.eof()) {
			getline(file, buffer);
			if (buffer == "") { break; }
			std::vector<std::string> text;
			text = seperateItems(buffer, "|");
			information.push_back(text);
			i++;
		}
		file.close();

		updateListView(listView1, information);
	}
private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (this->listView1->SelectedItems->Count == 1) {
		button2->Enabled = true; //More info poga varēs tikai parādīt informāciju par vienu lietu
	}
	else {
		button2->Enabled = false;
	}
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	//TODO: Make a form for more info and display it there from the list
}
private: System::Void listView1_Enter(System::Object^  sender, System::EventArgs^  e) {
	information.clear();
	std::vector<std::string> list;
	std::string buffer;
	ifstream file("list.txt");
	int i = 0;

	while (!file.eof()) {
		//TODO:Hold all the items held in the file to a vector (2d).After that do data work and output to listview
		getline(file, buffer);
		if (buffer == "") { break; }
		std::vector<std::string> text;
		text = seperateItems(buffer, "|");
		information.push_back(text);
		i++;
	}
	file.close();

	updateListView(listView1, information);
}
private: System::Void listView1_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e) {
	MessageBox::Show(e->Column.ToString()); //Tells which column was clicked
	MessageBox::Show(this->listView1->FocusedItem->Index.ToString());
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	//Dzes ara no saraksta
	listView1->SelectedItems[0]->Remove();

	//Vector update
	information.clear();
	for (int i = 0; i < listView1->Items->Count; i++) {
		std::vector<std::string > items;
		items.push_back(convertToStdString(listView1->Items[i]->Text));
		for (int j = 1; listView1->Columns->Count > j; j++) {
			items.push_back(convertToStdString(listView1->Items[i]->SubItems[j]->Text));
		}
		information.push_back(items);
	}
	//TODO:Name un description goes back and forth
	//File update
	ofstream list ("list.txt");

	for (int i = 0; i < information.size(); i++) {
		for (int j = 0; j < information.at(i).size() - 1; j++) {
			list << information.at(i).at(j) << "|";
		}
		list << information.at(i).at(information.at(i).size()-1) << endl;
	}
	information.clear();
}
};
}