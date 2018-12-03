#include "Workout.h"

void Workout::SetDate(Date aDate)
{
	m_Date = aDate;
}

Date Workout::GetDate()
{
	return m_Date;
}

void Workout::AddExercise(Exercise aExercise)
{
	m_Exercises.push_back(aExercise);
}

void Workout::SetExercises(std::vector<Exercise> aExercises)
{
	m_Exercises = aExercises;
}

std::vector<Exercise> Workout::GetExercise()
{
	return m_Exercises;
}