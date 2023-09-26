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
	//std::string URL = "https://c3dtools.com:443/API";
	std::vector<std::vector<std::string>> log;

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
	private: System::Windows::Forms::CheckBox^ checkbox_ascii_point;

	private: System::Windows::Forms::CheckBox^ checkbox_mot;
	private: System::Windows::Forms::CheckBox^ checkbox_trc;
	private: System::Windows::Forms::Button^ button_browse;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::FolderBrowserDialog^ folderBrowserDialog1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::ListBox^ logs;
	public: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private:

	private: System::Windows::Forms::ProgressBar^ progressBar1;
	private: System::Windows::Forms::CheckBox^ checkbox_YUP;
	private: System::Windows::Forms::CheckBox^ checkbox_ascii_analog;
	private: System::Windows::Forms::TextBox^ textBox_path;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::ComponentModel::IContainer^ components;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		int timer_counter = 0;
		String^ anim_temp;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->token = (gcnew System::Windows::Forms::TextBox());
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->main_panel = (gcnew System::Windows::Forms::Panel());
			this->checkbox_ascii_analog = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_YUP = (gcnew System::Windows::Forms::CheckBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->logs = (gcnew System::Windows::Forms::ListBox());
			this->log_panel = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->log_list = (gcnew System::Windows::Forms::ListBox());
			this->button_process = (gcnew System::Windows::Forms::Button());
			this->checkbox_ascii_point = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_mot = (gcnew System::Windows::Forms::CheckBox());
			this->checkbox_trc = (gcnew System::Windows::Forms::CheckBox());
			this->button_browse = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox_path = (gcnew System::Windows::Forms::TextBox());
			this->folderBrowserDialog1 = (gcnew System::Windows::Forms::FolderBrowserDialog());
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
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
			this->main_panel->Controls->Add(this->checkbox_ascii_analog);
			this->main_panel->Controls->Add(this->checkbox_YUP);
			this->main_panel->Controls->Add(this->progressBar1);
			this->main_panel->Controls->Add(this->panel2);
			this->main_panel->Controls->Add(this->log_panel);
			this->main_panel->Controls->Add(this->button_process);
			this->main_panel->Controls->Add(this->checkbox_ascii_point);
			this->main_panel->Controls->Add(this->checkbox_mot);
			this->main_panel->Controls->Add(this->checkbox_trc);
			this->main_panel->Controls->Add(this->button_browse);
			this->main_panel->Controls->Add(this->label1);
			this->main_panel->Controls->Add(this->textBox_path);
			this->main_panel->Enabled = false;
			this->main_panel->Location = System::Drawing::Point(13, 85);
			this->main_panel->Name = L"main_panel";
			this->main_panel->Size = System::Drawing::Size(557, 352);
			this->main_panel->TabIndex = 3;
			// 
			// checkbox_ascii_analog
			// 
			this->checkbox_ascii_analog->AutoSize = true;
			this->checkbox_ascii_analog->Location = System::Drawing::Point(358, 59);
			this->checkbox_ascii_analog->Name = L"checkbox_ascii_analog";
			this->checkbox_ascii_analog->Size = System::Drawing::Size(89, 17);
			this->checkbox_ascii_analog->TabIndex = 11;
			this->checkbox_ascii_analog->Text = L"ASCII-Analog";
			this->checkbox_ascii_analog->UseVisualStyleBackColor = true;
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
			// checkbox_ascii_point
			// 
			this->checkbox_ascii_point->AutoSize = true;
			this->checkbox_ascii_point->Location = System::Drawing::Point(266, 59);
			this->checkbox_ascii_point->Name = L"checkbox_ascii_point";
			this->checkbox_ascii_point->Size = System::Drawing::Size(85, 17);
			this->checkbox_ascii_point->TabIndex = 5;
			this->checkbox_ascii_point->Text = L"ASCII-Points";
			this->checkbox_ascii_point->UseVisualStyleBackColor = true;
			// 
			// checkbox_mot
			// 
			this->checkbox_mot->AutoSize = true;
			this->checkbox_mot->Location = System::Drawing::Point(195, 59);
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
			// textBox_path
			// 
			this->textBox_path->Enabled = false;
			this->textBox_path->Location = System::Drawing::Point(63, 25);
			this->textBox_path->Name = L"textBox_path";
			this->textBox_path->Size = System::Drawing::Size(399, 20);
			this->textBox_path->TabIndex = 0;
			// 
			// backgroundWorker1
			// 
			this->backgroundWorker1->WorkerReportsProgress = true;
			this->backgroundWorker1->WorkerSupportsCancellation = true;
			this->backgroundWorker1->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &MyForm::backgroundWorker1_DoWork);
			this->backgroundWorker1->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &MyForm::backgroundWorker1_ProgressChanged);
			this->backgroundWorker1->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &MyForm::backgroundWorker1_RunWorkerCompleted);
			// 
			// timer1
			// 
			this->timer1->Interval = 500;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
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
			this->Shown += gcnew System::EventHandler(this, &MyForm::MyForm_Shown);
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

		std::vector<std::string> output;
		_req.SendReq(URL+"/login", &param , &output);
		//_req.login(URL + "/login", &param , &output);
		
		if (output[0] == "OK") {
			this->FindForm()->Text = gcnew String(output[1].c_str());
			if (_req.write_token(msclr::interop::marshal_as< std::string >(this->token->Text))) {
				this->main_panel->Enabled = true;
			}			

		}
		else {
			this->log_list->Items->Add(gcnew String(output[1].c_str()));
			this->main_panel->Enabled = false;
		}


	}
	private: System::Void button_browse_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult _result = this->folderBrowserDialog1->ShowDialog();
		if (_result == System::Windows::Forms::DialogResult::OK) {


			System::String^ _path = this->folderBrowserDialog1->SelectedPath;
			std::string _sp = msclr::interop::marshal_as<std::string>(_path);
			std::filesystem::path _p = std::filesystem::path(_sp);



			for (std::filesystem::recursive_directory_iterator it(_p), end; it != end; ++it) {
				if (!is_directory(it->path())) {
					if (it->path().extension() == ".c3d")
						files.push_back(it->path().string());
				}
			}
			for (std::string const& filePath : files) {
				this->log_list->Items->Add(gcnew String(filePath.c_str()));
			}

			this->textBox_path->Text = _path;

			//log
			this->logs->Items->Add("Number Of Files --->  " + files.size().ToString());

		}



	}



	private: System::Void button_process_Click(System::Object^ sender, System::EventArgs^ e) {

		if (this->button_process->Text == "Run") { //Start Processing

			//clear logs
			this->logs->Items->Clear();

			// run background worker
			this->backgroundWorker1->RunWorkerAsync(1);		
			
			// Start Animate
			this->timer1->Enabled = true;

			// change to stop btn
			this->button_process->Text = "Stop";
		}
		else { // Stop Processing

			this->backgroundWorker1->CancelAsync();

			this->timer1->Enabled = false;


			// change to stop btn
			this->button_process->Text = "Run";
		}



	}



	private: System::Void backgroundWorker1_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

		int n = files.size();

		log.push_back(std::vector<std::string> {"---------------- Processing is Started ----------------" , "N"});
		for (size_t i = 0; i < n; i++)
		{
			if (this->backgroundWorker1->CancellationPending) {
				e->Cancel = true;
				break;
			}
			else {		

				std::filesystem::path p(files[i]);
				std::filesystem::path dir = p.parent_path();
				std::filesystem::path file_name = p.filename();

				log.push_back(std::vector < std::string> {"Uploading ==> " + file_name.string(), "N"});
				anim_temp = ">> Uploading ==> " + gcnew String(file_name.c_str());

				this->backgroundWorker1->ReportProgress((i+1) * (100/(n+1)));

				std::map<std::string, std::string> param;
				param["api_key"] = msclr::interop::marshal_as< std::string >(this->token->Text);
				param["TRC"] =(this->checkbox_trc->Checked == true) ? "TRUE"  : "FALSE";
				param["MOT"] = (this->checkbox_mot->Checked == true) ? "TRUE" : "FALSE";
				param["ASCII_Points"] = (this->checkbox_ascii_point->Checked == true) ? "TRUE" : "FALSE";;
				param["ASCII_Analog"] = (this->checkbox_ascii_analog->Checked == true) ? "TRUE" : "FALSE";;
				param["Y_UP"] = (this->checkbox_YUP->Checked == true) ? "TRUE" : "FALSE";

				_req.upload(URL+"/upload_process", &param, files[i], &log);
					

				
			}
		}

		// completed progress bar
		log.push_back(std::vector < std::string>{"---------------- Processing completed ----------------","N"});
		this->backgroundWorker1->ReportProgress(100);
		

	}
	private: System::Void backgroundWorker1_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
		
			this->progressBar1->Value = e->ProgressPercentage;
			for (auto i = log.begin(); i != log.end(); i++) {
				update_log(*i);
			}
			log.clear();

	}

	private: System::Void backgroundWorker1_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {

		this->button_process->Text = "Run";
		this->timer1->Enabled = false;
	}

	void update_log(std::vector<std::string> msg) {

		// First parameter indicate to the message
		// second parameter detemine the text color

		
		this->logs->Items->Add(">> " + gcnew String(msg[0].c_str()));
		this->logs->SelectedIndex = this->logs->Items->Count -1;
	}

private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	//read key from file

}
private: System::Void MyForm_Shown(System::Object^ sender, System::EventArgs^ e) {
	this->token->Text = gcnew String(_req.read_token().c_str());
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		

	

	switch (timer_counter)
	{
	case 0:
	{
		int index = this->logs->Items->IndexOf(anim_temp);
		if (index>-1)
			this->logs->Items[index] = anim_temp + ".";
		break;
	}
	case 1:
	{	
		int index = this->logs->Items->IndexOf(anim_temp+".");
		if (index > -1)
			this->logs->Items[index] = anim_temp + "..";
		break;
	}
	case 2:
	{
		int index = this->logs->Items->IndexOf(anim_temp + "..");
		if (index > -1)
			this->logs->Items[index] = anim_temp + "...";
		break;
	}
	case 3:
	{
		int index = this->logs->Items->IndexOf(anim_temp + "...");
		if (index > -1)
			this->logs->Items[index] = anim_temp + "....";
		break;
	}
	case 4:
	{
		int index = this->logs->Items->IndexOf(anim_temp + "....");
		if (index > -1)
			this->logs->Items[index] = anim_temp + ".....";
		break;
	}
	case 5:
	{
		int index = this->logs->Items->IndexOf(anim_temp + ".....");
		if (index > -1)
			this->logs->Items[index] = anim_temp + "......";
		break;
	}
	case 6:
	{
		int index = this->logs->Items->IndexOf(anim_temp + "......");
		if (index > -1)
			this->logs->Items[index] = anim_temp + ".......";
		break;
	}
	case 7:
	{
		int index = this->logs->Items->IndexOf(anim_temp + ".......");
		if (index > -1)
			this->logs->Items[index] = anim_temp + "........";
		break;
	}
	case 8:
	{
		int index = this->logs->Items->IndexOf(anim_temp + "........");
		if (index > -1)
			this->logs->Items[index] = anim_temp;
		timer_counter = -1;
		break;
	}
	default:
		break;
	}


	timer_counter++;


}
};

};







