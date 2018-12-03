#include "Exercise.h"


WeightRepSet::WeightRepSet(const WeightRepSet^ &aCopier)
{
	weight = aCopier->weight;
	numReps = aCopier->numReps;
	numSets = aCopier->numSets;
}

Exercise::Exercise()
{
	m_WeightRepSet = gcnew System::Collections::Generic::List<WeightRepSet^>();
}

Exercise::Exercise(const Exercise^ &aCopier)
{
	m_Name = aCopier->m_Name;
	m_WeightRepSet = aCopier->m_WeightRepSet;
}

// Adds a specific weight, number of reps and number of sets to an exercise
void Exercise::AddWeightRepSet(short aWeight, short aReps, short aSets)
{
	WeightRepSet^ weightRepSet;
	weightRepSet->SetWeight(aWeight);
	weightRepSet->SetReps(aReps);
	weightRepSet->SetSets(aSets);

	m_WeightRepSet.Add(weightRepSet);
}

// Adds a WeightRepSet to the exercise
void Exercise::AddWeightRepSet(WeightRepSet^ aWeightRepSet)
{
	m_WeightRepSet.Add(aWeightRepSet);
}

void Exercise::SetWeightRepSet(System::Collections::Generic::List<WeightRepSet^> aWeightRepSet)
{
	m_WeightRepSet.Clear();

	for (int i = 0; i < aWeightRepSet.Count; i++)
	{
		m_WeightRepSet.Add(aWeightRepSet[i]);
	}
}

System::Collections::Generic::List<WeightRepSet^> Exercise::GetWeightRepSet()
{
	return m_WeightRepSet;
}