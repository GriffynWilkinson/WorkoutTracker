#include "Workout.h"

Workout::Workout(const Workout^ &aCopier)
{
	m_Date = aCopier->m_Date;
	m_Exercises = aCopier->m_Exercises;
}

void Workout::SetDate(Date^ aDate)
{
	m_Date = aDate;
}

Date^ Workout::GetDate()
{
	return m_Date;
}

void Workout::AddExercise(Exercise^ aExercise)
{
	for (int i = 0; i < m_Exercises.Count; i++)
	{
		// if we already have an exercise with this name, just add the new weight rep sets
		if (m_Exercises[i]->m_Name == aExercise->m_Name)
		{
			for (int j = 0; j < aExercise->GetWeightRepSet().Count; j++)
			{
				m_Exercises[i]->AddWeightRepSet(aExercise->GetWeightRepSet[j]);
			}
		}
	}

	m_Exercises.Add(aExercise);
}

void Workout::SetExercises(System::Collections::Generic::List<Exercise^> aExercises)
{
	m_Exercises = aExercises;
}

System::Collections::Generic::List<Exercise^> Workout::GetExercise()
{
	return m_Exercises;
}