﻿#pragma once
#define defLocation reader.Get("USER", "saveLocation", "list.txt") + R"(Lists\list.txt)";
#include "AddItem.h"
#include "MoreInfo.h"
#include "Functions.h"
#include <vector>
#include "Sorting.h"
#include <algorithm>
std::vector <std::vector <std::string>> information; //Nomainīt uz klasi
std::vector <int> itemOrder;
std::vector <int> filterItemOrder;
bool isFiltered = false;


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
	public: int clickedColumn = -1;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::ToolStripMenuItem^  listsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  addNewListToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  selectListToolStripMenuItem;
	public:
	private: System::Windows::Forms::TextBox^  textBox1;
	public:
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
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fileToolStripMenuItem;


	private: System::Windows::Forms::ToolStripMenuItem^  exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  settingsToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^  changeSaveLocationToolStripMenuItem;
	private: System::Windows::Forms::FolderBrowserDialog^  folderBrowserDialog1;

	private: System::Windows::Forms::ColumnHeader^  columnHeader5;
	private: System::Windows::Forms::Timer^  timer1;


	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::ComboBox^  comboBox1;

	private: System::ComponentModel::IContainer^  components;

	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->columnHeader1 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader2 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader3 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader4 = (gcnew System::Windows::Forms::ColumnHeader());
			this->columnHeader5 = (gcnew System::Windows::Forms::ColumnHeader());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->changeSaveLocationToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->listsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->addNewListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectListToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// listView1
			// 
			this->listView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(5) {
				this->columnHeader1, this->columnHeader2,
					this->columnHeader3, this->columnHeader4, this->columnHeader5
			});
			this->listView1->FullRowSelect = true;
			this->listView1->Location = System::Drawing::Point(10, 25);
			this->listView1->Margin = System::Windows::Forms::Padding(2);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(562, 490);
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
			this->columnHeader2->DisplayIndex = 2;
			this->columnHeader2->Text = L"Name";
			this->columnHeader2->Width = 129;
			// 
			// columnHeader3
			// 
			this->columnHeader3->DisplayIndex = 3;
			this->columnHeader3->Text = L"Priority";
			this->columnHeader3->Width = 98;
			// 
			// columnHeader4
			// 
			this->columnHeader4->DisplayIndex = 4;
			this->columnHeader4->Text = L"Description";
			this->columnHeader4->Width = 170;
			// 
			// columnHeader5
			// 
			this->columnHeader5->DisplayIndex = 1;
			this->columnHeader5->Text = L"Time left";
			this->columnHeader5->Width = 75;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel));
			this->button1->Location = System::Drawing::Point(614, 39);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(160, 160);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Add new item";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(779, 39);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(160, 160);
			this->button2->TabIndex = 2;
			this->button2->Text = L"More info";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(614, 204);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(107, 47);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Delete item";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->settingsToolStripMenuItem, this->listsToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuStrip1->Size = System::Drawing::Size(981, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->exitToolStripMenuItem });
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::F4));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(134, 22);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::exitToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem
			// 
			this->settingsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->changeSaveLocationToolStripMenuItem });
			this->settingsToolStripMenuItem->Name = L"settingsToolStripMenuItem";
			this->settingsToolStripMenuItem->Size = System::Drawing::Size(61, 20);
			this->settingsToolStripMenuItem->Text = L"Settings";
			// 
			// changeSaveLocationToolStripMenuItem
			// 
			this->changeSaveLocationToolStripMenuItem->Name = L"changeSaveLocationToolStripMenuItem";
			this->changeSaveLocationToolStripMenuItem->Size = System::Drawing::Size(187, 22);
			this->changeSaveLocationToolStripMenuItem->Text = L"Change save location";
			this->changeSaveLocationToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::changeSaveLocationToolStripMenuItem_Click);
			// 
			// folderBrowserDialog1
			// 
			this->folderBrowserDialog1->SelectedPath = L"C:\\Users\\sloppynick3\\Documents\\To do list";
			// 
			// timer1
			// 
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &Form1::timer1_Tick);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Location = System::Drawing::Point(779, 206);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 45);
			this->button4->TabIndex = 5;
			this->button4->Text = L"Edit";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(614, 282);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(81, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Selected: None";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(614, 306);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(26, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Sort";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(776, 306);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(29, 13);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Filter";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(614, 322);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 9;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox1_SelectedIndexChanged);
			// 
			// textBox1
			// 
			this->textBox1->AcceptsReturn = true;
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(779, 322);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(160, 20);
			this->textBox1->TabIndex = 10;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged_1);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(617, 350);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 11;
			this->button5->Text = L"Reset";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// listsToolStripMenuItem
			// 
			this->listsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->addNewListToolStripMenuItem,
					this->selectListToolStripMenuItem
			});
			this->listsToolStripMenuItem->Name = L"listsToolStripMenuItem";
			this->listsToolStripMenuItem->Size = System::Drawing::Size(42, 20);
			this->listsToolStripMenuItem->Text = L"Lists";
			// 
			// addNewListToolStripMenuItem
			// 
			this->addNewListToolStripMenuItem->Name = L"addNewListToolStripMenuItem";
			this->addNewListToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->addNewListToolStripMenuItem->Text = L"Add new list";
			this->addNewListToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::addNewListToolStripMenuItem_Click);
			// 
			// selectListToolStripMenuItem
			// 
			this->selectListToolStripMenuItem->Name = L"selectListToolStripMenuItem";
			this->selectListToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->selectListToolStripMenuItem->Text = L"Select list";
			// 
			// Form1
			// 
			this->AcceptButton = this->button1;
			this->AutoScaleDimensions = System::Drawing::SizeF(96, 96);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Dpi;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(981, 542);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Form1";
			this->Text = L"To Do List";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) { //Add new item
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
		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			MessageBox::Show("Reader parse error");
		}
		std::string fileLocation = defLocation
			//MessageBox::Show(convertToSystemString(fileLocation));
		ifstream file(fileLocation);
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

		resetItemOrder(information, itemOrder);

		if (clickedColumn != -1) { //Ja ir sortots
			Sorting sortItem;
			std::string sortType = convertToStdString(comboBox1->Text);

			sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
		}

		if (isFiltered) {
			std::string textToFilter = convertToStdString(textBox1->Text);
			filterItemOrder.clear();
			for (int i = 0; i < itemOrder.size(); i++) {
				std::string textToCheck = information.at(itemOrder.at(i)).at(clickedColumn);
				std::transform(textToCheck.begin(), textToCheck.end(), textToCheck.begin(), ::toupper);
				std::transform(textToFilter.begin(), textToFilter.end(), textToFilter.begin(), ::toupper);
				//name.find('|') != string::npos
				if (textToCheck.find(textToFilter) != string::npos) {
					filterItemOrder.push_back(itemOrder.at(i));
				}
			}

			isFiltered = true;
		} 

		updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);

		for (i = 0; i < listView1->Items->Count; i++) {
			TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
			listView1->Items[i]->SubItems->Add(convertToSystemString(date.getTimeDifference()));
		}

	} //Add new item click 

	private: System::Void listView1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		if (this->listView1->SelectedItems->Count == 1) {
			button2->Enabled = true; //More info poga varēs tikai parādīt informāciju par vienu lietu
			button3->Enabled = true;
			button4->Enabled = true;
		}
		else if (this->listView1->SelectedItems->Count > 1) {
			//button3->Enabled = true;
			//button2->Enabled = false;

		}
		else {
			button2->Enabled = false;
			button3->Enabled = false;
			button4->Enabled = false;
		}
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) { //More info
		this->Enabled = false;

		MoreInfo^ moreInfo = gcnew MoreInfo(information.at(listView1->FocusedItem->Index));
		moreInfo->ShowDialog();
		//Pogas vajag atslēgt, jo kad aiztaisas logs, tad nekas no saraksta nav izvēlēts, bet uz pogām vēl var uzpiest
		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;
		this->Enabled = true;

	} //More info click

	private: System::Void listView1_Enter(System::Object^  sender, System::EventArgs^  e) {
		timer1->Start();
		information.clear();
		std::vector<std::string> list;
		std::string buffer;
		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			MessageBox::Show("Reader parse error");
		}
		std::string fileLocation = defLocation
			ifstream file(fileLocation);
		int i = 0;

		while (!file.eof()) {
			getline(file, buffer);
			if (buffer == "") { break; }
			std::vector<std::string> text;
			text = seperateItems(buffer, "|");
			information.push_back(text);
			i++;
		}

		if (clickedColumn == -1) {
			resetItemOrder(information, itemOrder);
		}
		else {
			Sorting sortItem;
			std::string sortType = convertToStdString(comboBox1->Text);

			sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
		}

		file.close();

		updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
		for (int i = 0; i < listView1->Items->Count; i++) {
			TimeManager date1(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
			listView1->Items[i]->SubItems->Add(convertToSystemString(date1.getTimeDifference()));
		}
	}

	private: System::Void listView1_ColumnClick(System::Object^  sender, System::Windows::Forms::ColumnClickEventArgs^  e) {
		//MessageBox::Show(e->Column.ToString()); //Tells which column was clicked
		//MessageBox::Show(this->listView1->FocusedItem->Index.ToString());

		clickedColumn = e->Column;
		label1->Text = "Selected: " + listView1->Columns[clickedColumn]->Text;
		//Set combobox parameters
		comboBox1->Items->Clear();

		comboBox1->Text = "";

		comboBox1->Enabled = true;
		textBox1->Enabled = true;

		switch (clickedColumn)
		{
		case 0:
			//Date
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		case 1:
			//Name
			comboBox1->Items->Add("A-Z");
			comboBox1->Items->Add("Z-A");
			textBox1->Enabled = true;
			break;
		case 2:
			//Priority
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		case 3:
			//Description (Nav ko kartot tapec disable)
			comboBox1->Enabled = false;
			textBox1->Enabled = true;
			break;
		case 4:
			//Time left
			comboBox1->Items->Add("High to low");
			comboBox1->Items->Add("Low to high");
			textBox1->Enabled = true;
			break;
		default:
			break;
		}
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) { //Delete item
		//Dzes ara no saraksta
		int index = this->listView1->FocusedItem->Index;
		listView1->SelectedItems[0]->Remove();

		//Vector update
		information.erase(information.begin() + itemOrder.at(index)); //Paņem vajadzīgo indeksu no itemOrder un izdēš to
		itemOrder.erase(itemOrder.begin() + index); //Pēc tam izdzēš to indeksu no itemOrder, tas nozīmē, ka var izdēst pat ja ir sortots un filtrēts


		//File update
		INIReader reader("settings.ini");
		if (reader.ParseError() < 0) {
			//Error
		}
		std::string fileLocation = defLocation
			ofstream file(fileLocation);

		for (size_t i = 0; i < information.size(); i++) {
			for (size_t j = 0; j < information.at(i).size() - 1; j++) {
				file << information.at(i).at(j) << "|";
			}
			file << information.at(i).at(information.at(i).size() - 1) << endl;
		}
		information.clear();
	} //Delete click

	private: System::Void exitToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		exit(0);
	}

	private: System::Void changeSaveLocationToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
		if (folderBrowserDialog1->ShowDialog().ToString() == "OK") {
			createIniFile(convertToStdString(folderBrowserDialog1->SelectedPath));
			MessageBox::Show("The program will now close for the changes to take effect");
			exit(0);
		}
	}

	private: System::Void toolStripComboBox1_Enter(System::Object^  sender, System::EventArgs^  e) {
		//Show list of fonts
	}

	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		for (int i = 0; i < listView1->Items->Count; i++) {
			TimeManager date(convertToStdString(listView1->Items[i]->SubItems[0]->Text));
			listView1->Items[i]->SubItems[4]->Text = convertToSystemString(date.getTimeDifference());
			if (listView1->Items[i]->SubItems[4]->Text == "Time has passed") { //Ja laiks ir pagajis, tad true
				//Make item red
			}
		}
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) { //Edit
		AddItem^ edit = gcnew AddItem(information.at(listView1->FocusedItem->Index), (int)listView1->FocusedItem->Index);
		edit->ShowDialog();

		button2->Enabled = false;
		button3->Enabled = false;
		button4->Enabled = false;

	} //Edit click
	private: System::Void comboBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		Sorting sortItem;
		std::string sortType = convertToStdString(comboBox1->Text);
		if (!isFiltered) {
			sortItem.sortItems(information, sortType, clickedColumn, itemOrder);
		}
		else {
			sortItem.sortItems(information, sortType, clickedColumn, filterItemOrder);
		}

		updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);

	};
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) { //Reset
		comboBox1->Enabled = false;
		comboBox1->Items->Clear();
		comboBox1->Text = "";
		
		textBox1->Text = "";
		textBox1->Enabled = false;

		label1->Text = "Selected: None";
		clickedColumn = -1;
		isFiltered = false;

		filterItemOrder.clear();
		resetItemOrder(information, itemOrder);

		updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
	}

private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) {
	std::string textToFilter = convertToStdString(textBox1->Text);
	filterItemOrder.clear();
	for (int i = 0; i < itemOrder.size(); i++) {
		std::string textToCheck = information.at(itemOrder.at(i)).at(clickedColumn);
		std::transform(textToCheck.begin(), textToCheck.end(), textToCheck.begin(), ::toupper);
		std::transform(textToFilter.begin(), textToFilter.end(), textToFilter.begin(), ::toupper);

		if (textToCheck.find(textToFilter) != string::npos) {
			filterItemOrder.push_back(itemOrder.at(i));
		}
	}

	isFiltered = true;
	updateListView(listView1, information, itemOrder, filterItemOrder, isFiltered);
}
private: System::Void addNewListToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) {
	
}
};
};
