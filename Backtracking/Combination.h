#pragma once

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class CCombination
{
	enum { INVALID = -1 };

public:
	CCombination(const size_t InN = INVALID, const size_t InR = INVALID)
		: N(InN)
		, R(InR)
	{
		if (N != INVALID)
		{
			InputVector.resize(N);
			VisitVector.resize(N, false);
		}
		else
		{
			cout << "Invalid N." << endl;
		}

		if (R != INVALID)
		{
			ResultVector.resize(R);
		}
		else
		{
			cout << "Invalid R." << endl;
		}
	}

	~CCombination()
	{
		InputVector.clear();
		ResultVector.clear();
		VisitVector.clear();
	}

	void InvokeCombinationSimulation()
	{
		if (INVALID == N || INVALID == R)
		{
			cout << "Invalid N or R." << endl;
			return;
		}

		SimulateCombination(0, 0);
	}

	size_t Factorial(const size_t InN)
	{
		if (0 == InN)
		{
			return 1;
		}

		return InN * Factorial(InN - 1);
	}

	size_t CountCombination(const size_t InN, const size_t InR)
	{
		// nCr = nPr / r! = n! / ((n-r)! * r!)
		return Factorial(InN) / (Factorial(InN - InR) * Factorial(InR));
	}

private:
	void SimulateCombination(const size_t CurrentN, const size_t CurrentR)
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
			for (size_t i = CurrentN; i < N; ++i)
			{
				if (true == VisitVector[i])
				{
					continue;
				}

				ResultVector[CurrentR] = InputVector[i];
				VisitVector[i] = true;
				SimulateCombination(i, CurrentR + 1);
				VisitVector[i] = false;
			}
		}
	}

public:
	vector<T> InputVector;
	vector<T> ResultVector;
	vector<bool> VisitVector;

	size_t N;
	size_t R;

};
