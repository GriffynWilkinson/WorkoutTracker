#pragma once

#include "Date.h"
#include "Exercise.h"

ref class Workout
{
public:

	Workout(const Workout^ &aCopier);

	void SetDate(Date^ aDate);
	Date^ GetDate();

	void AddExercise(Exercise^ aExercise);
	void SetExercises(System::Collections::Generic::List<Exercise^> aExercises);
	System::Collections::Generic::List<Exercise^> GetExercise();
private:
	Date^ m_Date;
	System::Collections::Generic::List<Exercise^> m_Exercises;
};
