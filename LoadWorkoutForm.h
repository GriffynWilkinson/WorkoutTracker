#pragma once

namespace WorkoutTracker {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for LoadWorkout
	/// </summary>
	public ref class LoadWorkoutForm : public System::Windows::Forms::Form
	{

	public:
		LoadWorkoutForm()
		{
			InitializeComponent();

		}
		LoadWorkoutForm(Workout^% aWorkout)
		{
			InitializeComponent();

			workout = gcnew Workout();
			workout = aWorkout;
		}

	public: Workout^ workout;
			WorkoutObject^ woObject;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoadWorkoutForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  LoadLabel;
	protected:
	private: System::Windows::Forms::TextBox^  LoadTextBox;
	private: System::Windows::Forms::Button^  LoadButton;
	private: System::Windows::Forms::Label^  ErrorLabel;

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
			this->LoadLabel = (gcnew System::Windows::Forms::Label());
			this->LoadTextBox = (gcnew System::Windows::Forms::TextBox());
			this->LoadButton = (gcnew System::Windows::Forms::Button());
			this->ErrorLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// LoadLabel
			// 
			this->LoadLabel->AutoSize = true;
			this->LoadLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoadLabel->Location = System::Drawing::Point(12, 54);
			this->LoadLabel->Name = L"LoadLabel";
			this->LoadLabel->Size = System::Drawing::Size(122, 19);
			this->LoadLabel->TabIndex = 0;
			this->LoadLabel->Text = L"Workout To Load:";
			// 
			// LoadTextBox
			// 
			this->LoadTextBox->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoadTextBox->ForeColor = System::Drawing::Color::Gray;
			this->LoadTextBox->Location = System::Drawing::Point(140, 51);
			this->LoadTextBox->Name = L"LoadTextBox";
			this->LoadTextBox->Size = System::Drawing::Size(112, 26);
			this->LoadTextBox->TabIndex = 1;
			this->LoadTextBox->Text = L"dd/mm/yyyy";
			this->LoadTextBox->TextChanged += gcnew System::EventHandler(this, &LoadWorkoutForm::LoadTextBox_TextChanged);
			// 
			// LoadButton
			// 
			this->LoadButton->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoadButton->Location = System::Drawing::Point(143, 83);
			this->LoadButton->Name = L"LoadButton";
			this->LoadButton->Size = System::Drawing::Size(109, 27);
			this->LoadButton->TabIndex = 2;
			this->LoadButton->Text = L"Load Workout";
			this->LoadButton->UseVisualStyleBackColor = true;
			this->LoadButton->Click += gcnew System::EventHandler(this, &LoadWorkoutForm::LoadButton_Click);
			// 
			// ErrorLabel
			// 
			this->ErrorLabel->AutoSize = true;
			this->ErrorLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ErrorLabel->ForeColor = System::Drawing::Color::DarkRed;
			this->ErrorLabel->Location = System::Drawing::Point(13, 118);
			this->ErrorLabel->Name = L"ErrorLabel";
			this->ErrorLabel->Size = System::Drawing::Size(0, 19);
			this->ErrorLabel->TabIndex = 3;
			// 
			// LoadWorkoutForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Gray;
			this->ClientSize = System::Drawing::Size(357, 170);
			this->Controls->Add(this->ErrorLabel);
			this->Controls->Add(this->LoadButton);
			this->Controls->Add(this->LoadTextBox);
			this->Controls->Add(this->LoadLabel);
			this->Name = L"LoadWorkoutForm";
			this->Text = L"LoadWorkout";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void LoadButton_Click(System::Object^  sender, System::EventArgs^  e) {

		Boolean^ isDateOkay = CheckDateFormat(LoadTextBox->Text);

		if (isDateOkay->CompareTo(false) == 0)
		{
			ErrorLabel->Text = "Date must be in dd/mm/yyyy format";
			return;
		}

		std::string date = msclr::interop::marshal_as<std::string>(LoadTextBox->Text); // msclr::interop::marshal_as<> lets me convertfrom System types to std types

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

		String^ fileName = day + "_" + month + "_" + year + ".txt";

		try
		{
			StreamReader^ woFile = gcnew StreamReader(fileName);

			Workout^ loadedWorkout = gcnew Workout;

			loadedWorkout->m_Date->SetDate(day, month, year);

			String^ line = woFile->ReadLine();

			do
			{
				if (line == "")
				{
					Exercise^ newExercise = gcnew Exercise;
					newExercise->m_Name = woFile->ReadLine();
					line = woFile->ReadLine(); // the line should read "#lbs x # rep(s) x # sets(s)"
					do
					{
						short weight = 0;
						short reps = 0;
						short sets = 0;

						int lLoc = 0;
						int rLoc = 0;

						for (int i = 0; i < line->Length; i++)
						{
							if (line[i] == 'l') // 
							{
								lLoc = i;
								std::string sWeight;

								for (int j = 0; j < i; j++)
								{
									sWeight += line[j];
								}

								weight = (short)(std::stoi(sWeight));
							}

							if (line[i] == 'r')
							{
								rLoc = i;
								std::string sReps;

								for (int j = lLoc + 6; j < i - 1; j++)
								{
									sReps += line[j];
								}

								reps = (short)(std::stoi(sReps));
							}

							if (line[i] == 't') // we use t here as it is the only letter that is unique to set(s)
							{
								std::string sSets;

								for (int j = rLoc + 9; j < i - 3; j++)
								{
									sSets += line[j];
								}

								sets = (short)(std::stoi(sSets));
							}

						}

						newExercise->AddWeightRepSet(weight, reps, sets);

						line = woFile->ReadLine(); // the line should read "#lbs x # rep(s) x # sets(s)"

						if (woFile->EndOfStream)
						{
							break;
						}

					} while (line != String::Empty);

					loadedWorkout->m_Exercises.Add(newExercise);

				}
			} while (!woFile->EndOfStream);
	
			workout = loadedWorkout;

			woObject->SetWorkout(workout);

			this->Close();

		}
		catch (Exception^ e)
		{
			ErrorLabel->Text = "Could not load workout file";
			return;
		}
	}

	public: static System::Boolean^ CheckDateFormat(std::string aDate)
	{
		if (aDate[0] >= '0' && aDate[0] <= '9')
		{
			if (aDate[1] >= '0' && aDate[1] <= '9')
			{
				if (aDate[2] == '/')
				{
					if (aDate[3] >= '0' && aDate[3] <= '9')
					{
						if (aDate[4] >= '0' && aDate[4] <= '9')
						{
							if (aDate[5] == '/')
							{
								if (aDate[6] >= '0' && aDate[6] <= '9')
								{
									if (aDate[7] >= '0' && aDate[7] <= '9')
									{
										if (aDate[8] >= '0' && aDate[8] <= '9')
										{
											if (aDate[9] >= '0' && aDate[9] <= '9')
											{
												if (aDate[10] == NULL)
												{
													return true;
												}
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}

		return false;
	}

	public: static System::Boolean^ CheckDateFormat(String^ aDate)
	{
		std::string date = msclr::interop::marshal_as<std::string>(aDate);

		return CheckDateFormat(date);
	}
	private: System::Void LoadTextBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		LoadTextBox->ForeColor = Color::Black;
	}
};
}
