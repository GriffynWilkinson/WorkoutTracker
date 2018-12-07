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

public ref class WorkoutObject
{
private:
	static Workout^ m_Workout;

public:
	void SetWorkout(Workout^ aWorkout)
	{
		m_Workout = aWorkout;
	}
	Workout^ GetWorkout()
	{
		return m_Workout;
	}
};
