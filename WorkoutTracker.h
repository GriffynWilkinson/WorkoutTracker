#pragma once

#include <msclr\marshal_cppstd.h>
#include <sstream>
#include "Workout.h"

namespace WorkoutTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WorkoutTracker
	/// </summary>
	public ref class WorkoutTracker : public System::Windows::Forms::Form
	{
	public:
		WorkoutTracker(void)
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
		~WorkoutTracker()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  AddWorkoutButton;
	protected:
	private: System::Windows::Forms::Label^  DateLabel;
	private: System::Windows::Forms::TextBox^  DateTextBox;
	private: System::Windows::Forms::Label^  ExerciseLabel;
	private: System::Windows::Forms::TextBox^  ExerciseTextBox;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  WeightTextBox;
	private: System::Windows::Forms::TextBox^  RepsTextBox;
	private: System::Windows::Forms::Label^  RepsLabel;
	private: System::Windows::Forms::TextBox^  SetsTextBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  DateTestLabel;


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
			this->AddWorkoutButton = (gcnew System::Windows::Forms::Button());
			this->DateLabel = (gcnew System::Windows::Forms::Label());
			this->DateTextBox = (gcnew System::Windows::Forms::TextBox());
			this->ExerciseLabel = (gcnew System::Windows::Forms::Label());
			this->ExerciseTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->WeightTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RepsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->RepsLabel = (gcnew System::Windows::Forms::Label());
			this->SetsTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->DateTestLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// AddWorkoutButton
			// 
			this->AddWorkoutButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AddWorkoutButton->Location = System::Drawing::Point(946, 633);
			this->AddWorkoutButton->Name = L"AddWorkoutButton";
			this->AddWorkoutButton->Size = System::Drawing::Size(183, 90);
			this->AddWorkoutButton->TabIndex = 5;
			this->AddWorkoutButton->Text = L"Add Workout";
			this->AddWorkoutButton->UseVisualStyleBackColor = true;
			this->AddWorkoutButton->Click += gcnew System::EventHandler(this, &WorkoutTracker::AddWorkoutButton_Click);
			// 
			// DateLabel
			// 
			this->DateLabel->AutoSize = true;
			this->DateLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateLabel->Location = System::Drawing::Point(40, 33);
			this->DateLabel->Name = L"DateLabel";
			this->DateLabel->Size = System::Drawing::Size(49, 23);
			this->DateLabel->TabIndex = 1;
			this->DateLabel->Text = L"Date";
			this->DateLabel->Click += gcnew System::EventHandler(this, &WorkoutTracker::DateLabel_Click);
			// 
			// DateTextBox
			// 
			this->DateTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateTextBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->DateTextBox->Location = System::Drawing::Point(166, 30);
			this->DateTextBox->Name = L"DateTextBox";
			this->DateTextBox->Size = System::Drawing::Size(136, 32);
			this->DateTextBox->TabIndex = 0;
			this->DateTextBox->Text = L"dd/mm/yyyy";
			this->DateTextBox->TextChanged += gcnew System::EventHandler(this, &WorkoutTracker::DateTextBox_TextChanged);
			// 
			// ExerciseLabel
			// 
			this->ExerciseLabel->AutoSize = true;
			this->ExerciseLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExerciseLabel->Location = System::Drawing::Point(40, 124);
			this->ExerciseLabel->Name = L"ExerciseLabel";
			this->ExerciseLabel->Size = System::Drawing::Size(81, 23);
			this->ExerciseLabel->TabIndex = 2;
			this->ExerciseLabel->Text = L"Exercise";
			// 
			// ExerciseTextBox
			// 
			this->ExerciseTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ExerciseTextBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->ExerciseTextBox->Location = System::Drawing::Point(166, 121);
			this->ExerciseTextBox->Name = L"ExerciseTextBox";
			this->ExerciseTextBox->Size = System::Drawing::Size(203, 32);
			this->ExerciseTextBox->TabIndex = 1;
			this->ExerciseTextBox->Text = L"Exercise Name";
			this->ExerciseTextBox->TextChanged += gcnew System::EventHandler(this, &WorkoutTracker::ExerciseTextBox_TextChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(60, 179);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(61, 21);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Weight";
			// 
			// WeightTextBox
			// 
			this->WeightTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WeightTextBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->WeightTextBox->Location = System::Drawing::Point(309, 174);
			this->WeightTextBox->Name = L"WeightTextBox";
			this->WeightTextBox->Size = System::Drawing::Size(60, 29);
			this->WeightTextBox->TabIndex = 2;
			this->WeightTextBox->Text = L"0";
			this->WeightTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->WeightTextBox->TextChanged += gcnew System::EventHandler(this, &WorkoutTracker::WeightTextBox_TextChanged);
			// 
			// RepsTextBox
			// 
			this->RepsTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RepsTextBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->RepsTextBox->Location = System::Drawing::Point(309, 219);
			this->RepsTextBox->Name = L"RepsTextBox";
			this->RepsTextBox->Size = System::Drawing::Size(60, 29);
			this->RepsTextBox->TabIndex = 3;
			this->RepsTextBox->Text = L"0";
			this->RepsTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->RepsTextBox->TextChanged += gcnew System::EventHandler(this, &WorkoutTracker::RepsTextBox_TextChanged);
			// 
			// RepsLabel
			// 
			this->RepsLabel->AutoSize = true;
			this->RepsLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RepsLabel->Location = System::Drawing::Point(72, 222);
			this->RepsLabel->Name = L"RepsLabel";
			this->RepsLabel->Size = System::Drawing::Size(49, 21);
			this->RepsLabel->TabIndex = 5;
			this->RepsLabel->Text = L"Reps";
			// 
			// SetsTextBox
			// 
			this->SetsTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->SetsTextBox->ForeColor = System::Drawing::SystemColors::GrayText;
			this->SetsTextBox->Location = System::Drawing::Point(309, 267);
			this->SetsTextBox->Name = L"SetsTextBox";
			this->SetsTextBox->Size = System::Drawing::Size(60, 29);
			this->SetsTextBox->TabIndex = 4;
			this->SetsTextBox->Text = L"0";
			this->SetsTextBox->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			this->SetsTextBox->TextChanged += gcnew System::EventHandler(this, &WorkoutTracker::SetsTextBox_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(79, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 21);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Sets";
			// 
			// DateTestLabel
			// 
			this->DateTestLabel->AutoSize = true;
			this->DateTestLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DateTestLabel->ForeColor = System::Drawing::Color::Red;
			this->DateTestLabel->Location = System::Drawing::Point(456, 42);
			this->DateTestLabel->Name = L"DateTestLabel";
			this->DateTestLabel->Size = System::Drawing::Size(0, 23);
			this->DateTestLabel->TabIndex = 8;
			// 
			// WorkoutTracker
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(1174, 761);
			this->Controls->Add(this->DateTestLabel);
			this->Controls->Add(this->SetsTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->RepsTextBox);
			this->Controls->Add(this->RepsLabel);
			this->Controls->Add(this->WeightTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->ExerciseTextBox);
			this->Controls->Add(this->ExerciseLabel);
			this->Controls->Add(this->DateTextBox);
			this->Controls->Add(this->DateLabel);
			this->Controls->Add(this->AddWorkoutButton);
			this->Name = L"WorkoutTracker";
			this->Text = L"WorkoutTracker";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void DateLabel_Click(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void AddWorkoutButton_Click(System::Object^  sender, System::EventArgs^  e) {
		Workout workout;
		
		{ // Add the date of the workout
			std::string date = msclr::interop::marshal_as<std::string>(DateTextBox->Text); // msclr::interop::marshal_as<> lets me convertfrom System types to std types
			std::string segment;
			std::vector<std::string> seglist;

			std::stringstream ssDate;
			ssDate.str(date);

			while (std::getline(ssDate, segment, '/')) // this reads from date and splits it up by finding '/'. it puts the individual string into segment
			{
				seglist.push_back(segment);
			}

			// std::stoi converts a string to an int
			short day = (short)(std::stoi(seglist.at(0)));
			short month = (short)(std::stoi(seglist.at(1)));
			short year = (short)(std::stoi(seglist.at(2)));

			Date newDate;
			newDate.SetDate(day, month, year);

			workout.SetDate(newDate);

			DateTestLabel->Text = "The date of your workout was " + workout.GetDate().GetDay() + "/" + workout.GetDate().GetMonth() + "/" + workout.GetDate().GetYear() + ".";
		}

		{ // Add the Exercise
			
		}
	}

	private: System::Void DateTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		DateTextBox->ForeColor = Color::Black;
	}
	private: System::Void ExerciseTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		ExerciseTextBox->ForeColor = Color::Black;
	}
	private: System::Void WeightTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		WeightTextBox->ForeColor = Color::Black;
	}
	private: System::Void RepsTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		RepsTextBox->ForeColor = Color::Black;
	}
	private: System::Void SetsTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		SetsTextBox->ForeColor = Color::Black;
	}
	};
}