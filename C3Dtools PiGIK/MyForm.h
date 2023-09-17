#pragma once

#include "MyReq.h"

#include <Poco/StreamCopier.h>
#include <Poco/InflatingStream.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/JSON/Parser.h>
#include <Poco/Path.h>
#include <Poco/URI.h>
#include <iostream>
#include <string>


using namespace Poco;
using namespace Poco::Net;

namespace $safeprojectname$ {

	using namespace System;
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
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ login_btn;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->login_btn = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(367, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(389, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->login_btn);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Location = System::Drawing::Point(28, 109);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(405, 183);
			this->panel1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(92, 68);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(214, 20);
			this->textBox1->TabIndex = 0;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(92, 111);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(214, 20);
			this->textBox2->TabIndex = 1;
			// 
			// login_btn
			// 
			this->login_btn->Location = System::Drawing::Point(158, 145);
			this->login_btn->Name = L"login_btn";
			this->login_btn->Size = System::Drawing::Size(75, 23);
			this->login_btn->TabIndex = 2;
			this->login_btn->Text = L"Login";
			this->login_btn->UseVisualStyleBackColor = true;
			this->login_btn->Click += gcnew System::EventHandler(this, &MyForm::login_btn_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Narrow", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(13, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(146, 23);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Login to C3DTools :";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(92, 50);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(60, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"User Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(92, 95);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(53, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Password";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(454, 339);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->label1->Text = "OK!!1";
	}

	private: System::Void login_btn_Click(System::Object^ sender, System::EventArgs^ e) {
		

		// creating a json object to send to the server
		JSON::Object bodyObj;
		bodyObj.set("username", "Raj");
		bodyObj.set("password", 20);

		std::ostringstream ss;

		bodyObj.stringify(ss);

		std::string body;
		body = ss.str();


		// Create a URI
		URI uri("http://localhost:5001/API/login");

		// Create a session
		HTTPClientSession session(uri.getHost(), uri.getPort());

		// Set connection to keepalive
		session.setKeepAlive(true);

		// Choose the http request method
		HTTPRequest request(HTTPRequest::HTTP_POST, uri.getPath(),HTTPMessage::HTTP_1_1);

		// Add headers
		request.setContentType("application/json");

		request.setContentLength(body.length());

		// send request
		std::ostream& o = session.sendRequest(request) << body;
		

		JSON::Object resObj;
		resObj.stringify(o);

		HTTPResponse response;

		// this line is where you get your response
		std::istream& s = session.receiveResponse(response);

		std::stringstream ss2;
		Poco::InflatingInputStream inflater(s, Poco::InflatingStreamBuf::STREAM_GZIP);
		StreamCopier::copyStream(inflater, ss2);


		int a = 0;
		//Poco::JSON::Parser parser;
		//Poco::JSON::Object::Ptr ret = parser.parse(s).extract<Poco::JSON::Object::Ptr>();

		// (*ret) will contain all the members in a json structure returned
		//if ((*ret).get("success") != true) {
		//	std::cout << "Failed to upload: " << (*ret).get("message").toString();
		//	return;
		//}


		
	}
};
}
