#pragma once

#include "Date.h"
#include "Exercise.h"

public ref class Workout
{
public:

	Workout();

	Date^ m_Date;
	System::Collections::Generic::List<Exercise^> m_Exercises;
};
