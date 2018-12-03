#pragma once

#include "Date.h"
#include "Exercise.h"

class Workout
{
public:
	void SetDate(Date aDate);
	Date GetDate();

	void AddExercise(Exercise aExercise);
	void SetExercises(std::vector<Exercise> aExercises);
	std::vector<Exercise> GetExercise();
private:
	Date m_Date;
	std::vector<Exercise> m_Exercises;
};
