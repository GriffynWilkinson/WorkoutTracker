#pragma once

#include <vector>
#include <string>

struct WeightRepSet
{
	short weight = 0;
	short numReps = 1;
	short numSets = 1;
};

class Exercise
{
public:
	std::string m_Name = "";
	void AddWeightRepSet(short aWeight, short aReps, short aSets);
	void AddWeightRepSet(WeightRepSet aWeightRepSet);
	void SetWeightRepSet(std::vector<WeightRepSet> aWeightRepSet);
	std::vector<WeightRepSet> GetWeightRepSet();
private:
	std::vector<WeightRepSet> m_WeightRepSet;
};