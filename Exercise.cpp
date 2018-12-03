#include "Exercise.h"

// Adds a specific weight, number of reps and number of sets to an exercise
void Exercise::AddWeightRepSet(short aWeight, short aReps, short aSets)
{
	WeightRepSet weightRepSet;
	weightRepSet.weight = aWeight;
	weightRepSet.numReps = aReps;
	weightRepSet.numSets = aSets;

	m_WeightRepSet.push_back(weightRepSet);
}

// Adds a WeightRepSet to the exercise
void Exercise::AddWeightRepSet(WeightRepSet aWeightRepSet)
{
	m_WeightRepSet.push_back(aWeightRepSet);
}

void Exercise::SetWeightRepSet(std::vector<WeightRepSet> aWeightRepSet)
{
	m_WeightRepSet = aWeightRepSet;
}

std::vector<WeightRepSet> Exercise::GetWeightRepSet()
{
	return m_WeightRepSet;
}