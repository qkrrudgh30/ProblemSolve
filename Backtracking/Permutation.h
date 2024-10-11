#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CPermutation
{
	enum { INVALID = -1 };

public:
	CPermutation(const size_t InN = INVALID, const size_t InR = INVALID)
		: N(InN)
		, R(InR)
	{
		if (N != INVALID && R != INVALID)
		{
			InputVector.resize(N);
			ResultVector.resize(R);
			VisitVector.resize(N);
		}
		else
		{
			cout << "Invalid N or R." << endl;
		}
	}

	~CPermutation()
	{
		InputVector.clear();
		ResultVector.clear();
		VisitVector.clear();
	}

	void InvokePermutationSimulation()
	{
		if (INVALID == N || INVALID == R)
		{
			cout << "Invalid N or R." << endl;
		}

		SimulatePermutation(0);
	}

	size_t Factorial(const size_t InN)
	{
		if (0 == InN)
		{
			return 1;
		}

		return InN * Factorial(InN - 1);
	}

	size_t CountPermutation(const size_t InN, const size_t InR)
	{
		// nPr = n! / (n - r)!
		return Factorial(InN) / Factorial(InN - InR);
	}

private:
	void SimulatePermutation(const size_t CurrentR)
	{
		if (R == CurrentR)
		{
			for (size_t i = 0; i < R; ++i)
			{
				cout << ResultVector[i];
			}
			cout << endl;
		}
		else
		{
			for (size_t i = 0; i < N; ++i)
			{
				if (true == VisitVector[i])
				{
					continue;
				}

				ResultVector[CurrentR] = InputVector[i];
				VisitVector[i] = true;
				SimulatePermutation(CurrentR + 1);
				VisitVector[i] = false;
			}
		}
	}

public:
	vector<int> InputVector;
	vector<int> ResultVector;
	vector<bool> VisitVector;

	size_t N;
	size_t R;

};
