#pragma once

public ref struct WeightRepSet
{
public:

	WeightRepSet();
	WeightRepSet(const WeightRepSet^ &aCopier);

	void SetWeight(short aWeight) { weight = aWeight; }
	short GetWeight() { return weight; }

	void SetReps(short aReps) { numReps = aReps; }
	short GetReps() { return numReps; }

	void SetSets(short aSets) { numSets = aSets; }
	short GetSets() { return numSets; }
private:
	short weight = 0;
	short numReps = 1;
	short numSets = 1;
};

public ref class Exercise
{
public:
	System::String^ m_Name;
	void AddWeightRepSet(short aWeight, short aReps, short aSets);
	void AddWeightRepSet(WeightRepSet^ aWeightRepSet);
	void SetWeightRepSet(System::Collections::Generic::List<WeightRepSet^> aWeightRepSet);
	System::Collections::Generic::List<WeightRepSet^> m_WeightRepSet;
};