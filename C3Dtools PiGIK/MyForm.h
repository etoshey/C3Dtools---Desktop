#pragma once

#include "MyReq.h"
#include <msclr/marshal_cppstd.h>
#include <filesystem>
#include <iostream>





namespace $safeprojectname$ {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	namespace fs = std::filesystem;




	MyReq _req;
	std::vector<std::string> files;
	std::string URL = "http://localhost:5001/API";

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


	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::Label^ label3;

	private: System::Windows::Forms::Button^ login_btn;

	private: System::Windows::Forms::TextBox^ token;
	private: System::Windows::Forms::Panel^ main_panel;
	private: System::Windows::Forms::FlowLayoutPanel^ log_panel;
	private: System::Windows::Forms::ListBox^ log_list;
	private: System::Windows::Forms::Button^ button_process;
	private: System::Windows::Forms::CheckBox^ checkbox_ascii;
	private: System::Windows::Forms::CheckBox^ checkbox_mot;
	private: System::Windows::Forms::CheckBox^ checkbox_trc;
	private: System::Windows::Forms::Button^ button_browse;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ListBox^ logs;
	public: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private:

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::CheckBox^ checkbox_YUP;



	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->token = (gcnew System::Windows::Forms::TextBox());
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->main_panel = (gcnew System::Windows::Forms::Panel());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->logs = (gcnew System::Windows::Forms::ListBox());
			this->log_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->log_list = (gcnew System::Windows::Forms::ListBox());
			this->button_process = (gcnew System::Windows::Forms::Button());
			this->checkbox_ascii = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_mot = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_trc = (gcnew System::Windows::Forms::CheckBox());
			this->button_browse = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->checkbox_YUP = (gcnew System::Windows::Forms::CheckBox());
			this->panel1->SuspendLayout();
			this->main_panel->SuspendLayout();
			this->panel2->SuspendLayout();
			this->log_panel->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->token);
			this->panel1->Controls->Add(this->login_btn);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(558, 66);
			this->panel1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(8, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(38, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Token";
			// 
			// token
			// 
			this->token->Location = System::Drawing::Point(11, 25);
			this->token->Name = L"token";
			this->token->Size = System::Drawing::Size(452, 20);
			this->token->TabIndex = 0;
			this->token->Text = L"eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiIyMDk1Njc0MTI5Mzc2ODUyMiIsImlh"
				L"dCI6MTY3OTkxODM0NSwiZXhwIjoxNjc5OTIxOTQ1fQ.esx5EVT6oo1jF0ko_uZvUSlLt8dvrFynLxOrU"
				L"OkvLLY";
			// 
			// login_btn
			// 
			this->login_btn->Location = System::Drawing::Point(469, 25);
			this->login_btn->Name = L"login_btn";
			this->login_btn->Size = System::Drawing::Size(75, 23);
			this->login_btn->TabIndex = 2;
			this->login_btn->Text = L"Login";
			this->login_btn->UseVisualStyleBackColor = true;
			this->login_btn->Click += gcnew System::EventHandler(this, &MyForm::login_btn_Click);
			// 
			// main_panel
			// 
			this->main_panel->Controls->Add(this->checkbox_YUP);
			this->main_panel->Controls->Add(this->progressBar1);
			this->main_panel->Controls->Add(this->panel2);
			this->main_panel->Controls->Add(this->log_panel);
			this->main_panel->Controls->Add(this->button_process);
			this->main_panel->Controls->Add(this->checkbox_ascii);
			this->main_panel->Controls->Add(this->checkbox_mot);
			this->main_panel->Controls->Add(this->checkbox_trc);
			this->main_panel->Controls->Add(this->button_browse);
			this->main_panel->Controls->Add(this->label1);
			this->main_panel->Controls->Add(this->textBox1);
			this->main_panel->Location = System::Drawing::Point(13, 85);
			this->main_panel->Name = L"main_panel";
			this->main_panel->Size = System::Drawing::Size(557, 352);
			this->main_panel->TabIndex = 3;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(13, 327);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(530, 19);
			this->progressBar1->TabIndex = 9;
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->logs);
			this->panel2->Location = System::Drawing::Point(13, 216);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(530, 106);
			this->panel2->TabIndex = 8;
			// 
			// logs
			// 
			this->logs->BackColor = System::Drawing::SystemColors::InfoText;
			this->logs->ForeColor = System::Drawing::SystemColors::Menu;
			this->logs->FormattingEnabled = true;
			this->logs->Location = System::Drawing::Point(4, 4);
			this->logs->Name = L"logs";
			this->logs->Size = System::Drawing::Size(519, 95);
			this->logs->TabIndex = 0;
			// 
			// log_panel
			// 
			this->log_panel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->log_panel->Controls->Add(this->log_list);
			this->log_panel->Location = System::Drawing::Point(13, 93);
			this->log_panel->Name = L"log_panel";
			this->log_panel->Size = System::Drawing::Size(530, 126);
			this->log_panel->TabIndex = 7;
			// 
			// log_list
			// 
			this->log_list->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->log_list->FormattingEnabled = true;
			this->log_list->Location = System::Drawing::Point(3, 3);
			this->log_list->Name = L"log_list";
			this->log_list->Size = System::Drawing::Size(520, 108);
			this->log_list->TabIndex = 0;
			// 
			// button_process
			// 
			this->button_process->Location = System::Drawing::Point(468, 59);
			this->button_process->Name = L"button_process";
			this->button_process->Size = System::Drawing::Size(75, 23);
			this->button_process->TabIndex = 6;
			this->button_process->Text = L"Run";
			this->button_process->UseVisualStyleBackColor = true;
			this->button_process->Click += gcnew System::EventHandler(this, &MyForm::button_process_Click);
			// 
			// checkbox_ascii
			// 
			this->checkbox_ascii->AutoSize = true;
			this->checkbox_ascii->Location = System::Drawing::Point(267, 59);
			this->checkbox_ascii->Name = L"checkbox_ascii";
			this->checkbox_ascii->Size = System::Drawing::Size(53, 17);
			this->checkbox_ascii->TabIndex = 5;
			this->checkbox_ascii->Text = L"ASCII";
			this->checkbox_ascii->UseVisualStyleBackColor = true;
			// 
			// checkbox_mot
			// 
			this->checkbox_mot->AutoSize = true;
			this->checkbox_mot->Location = System::Drawing::Point(197, 59);
			this->checkbox_mot->Name = L"checkbox_mot";
			this->checkbox_mot->Size = System::Drawing::Size(53, 17);
			this->checkbox_mot->TabIndex = 4;
			this->checkbox_mot->Text = L".MOT";
			this->checkbox_mot->UseVisualStyleBackColor = true;
			// 
			// checkbox_trc
			// 
			this->checkbox_trc->AutoSize = true;
			this->checkbox_trc->Location = System::Drawing::Point(124, 59);
			this->checkbox_trc->Name = L"checkbox_trc";
			this->checkbox_trc->Size = System::Drawing::Size(51, 17);
			this->checkbox_trc->TabIndex = 3;
			this->checkbox_trc->Text = L".TRC";
			this->checkbox_trc->UseVisualStyleBackColor = true;
			// 
			// button_browse
			// 
			this->button_browse->Location = System::Drawing::Point(468, 23);
			this->button_browse->Name = L"button_browse";
			this->button_browse->Size = System::Drawing::Size(75, 23);
			this->button_browse->TabIndex = 2;
			this->button_browse->Text = L"Browse";
			this->button_browse->UseVisualStyleBackColor = true;
			this->button_browse->Click += gcnew System::EventHandler(this, &MyForm::button_browse_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(10, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Source :";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(63, 25);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(399, 20);
			this->textBox1->TabIndex = 0;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// checkbox_YUP
			// 
			this->checkbox_YUP->AutoSize = true;
			this->checkbox_YUP->Location = System::Drawing::Point(63, 59);
			this->checkbox_YUP->Name = L"checkbox_YUP";
			this->checkbox_YUP->Size = System::Drawing::Size(51, 17);
			this->checkbox_YUP->TabIndex = 10;
			this->checkbox_YUP->Text = L"Y-UP";
			this->checkbox_YUP->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(582, 440);
			this->Controls->Add(this->main_panel);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"C3Dtools.com";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->main_panel->ResumeLayout(false);
			this->main_panel->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->log_panel->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	}

	private: System::Void login_btn_Click(System::Object^ sender, System::EventArgs^ e) {


		std::map<std::string, std::string> param;
		param["api_key"] = msclr::interop::marshal_as< std::string >(this->token->Text);
		std::string responce = _req.SendReq(URL+"/login", &param);
		this->FindForm()->Text = gcnew String(responce.c_str());


	}
	private: System::Void button_browse_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult _result = this->folderBrowserDialog1->ShowDialog();
		if (_result == System::Windows::Forms::DialogResult::OK) {


			System::String^ _path = this->folderBrowserDialog1->SelectedPath;
			std::string _sp = msclr::interop::marshal_as<std::string>(_path);
			std::filesystem::path _p = std::filesystem::path(_sp);



			for (std::filesystem::recursive_directory_iterator it(_p), end; it != end; ++it) {
				if (!is_directory(it->path())) {
					if (it->path().string().find(".c3d") != std::string::npos)
						files.push_back(it->path().string());
				}
			}
			for (std::string const& filePath : files) {
				this->log_list->Items->Add(gcnew String(filePath.c_str()));
			}

			//log
			this->logs->Items->Add("Number Of Files --->  " + files.size().ToString());

		}



	}



	private: System::Void button_process_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->button_process->Text == "Run") { //Start Processing


			// run background worker
			this->backgroundWorker1->RunWorkerAsync(1);


			// change to stop btn
			this->button_process->Text = "Stop";
		}
		else { // Stop Processing

			this->backgroundWorker1->CancelAsync();



			// change to stop btn
			this->button_process->Text = "Run";
		}



	}





	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

		int n = files.size();
		for (size_t i = 0; i < n; i++)
		{
			if (this->backgroundWorker1->CancellationPending) {
				e->Cancel = true;
				break;
			}
			else {				
				this->backgroundWorker1->ReportProgress((i+1) * (100/n));

				std::map<std::string, bool> param;
				param["TRC"] =this->checkbox_trc->Checked;
				param["MOT"] = this->checkbox_mot->Checked;
				param["ASCII"] = this->checkbox_ascii->Checked;
				param["Y_UP"] = this->checkbox_YUP->Checked;

				_req.upload(URL+"/upload_process", &param, files[i]);
				Sleep(1000);
			}
		}

		// completed progress bar
		this->backgroundWorker1->ReportProgress(100);

	}
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
		
			this->progressBar1->Value = e->ProgressPercentage;
	}

	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {

		
	}
};

};







