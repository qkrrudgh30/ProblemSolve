#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CRepeatedCombination
{
	enum { INVALID = -1 };

public:
	CRepeatedCombination(const size_t InN = INVALID, const size_t InR = INVALID)
		: N(InN)
		, R(InR)
	{
		if (N != INVALID && R != INVALID)
		{
			InputVector.resize(N);
			ResultVector.resize(R);
		}
		else
		{
			cout << "Invalid N or R." << endl;
		}
	}

	~CRepeatedCombination()
	{
		InputVector.clear();
		ResultVector.clear();
	}

	void InvokeRepeatedCombination()
	{
		if (INVALID == N || INVALID == R)
		{
			cout << "Invalid N or R." << endl;
			return;
		}

		SimulateRepeatedCombination(0, 0);
	}

	size_t Factorial(const size_t InN)
	{
		if (0 == InN)
		{
			return 1;
		}

		return InN * Factorial(InN - 1);
	}

	size_t CountRepeatedCombination(const size_t InN, const size_t InR)
	{
		// nHr = n-1+rCr = n-1+rPr / r! = (n-1+r)! / ((n-1)! * r!)
		return Factorial(InN - 1 + InR) / (Factorial(InN - 1) * Factorial(InR));
	}

private:
	void SimulateRepeatedCombination(const size_t CurrentN, const size_t CurrentR)
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
				ResultVector[CurrentR] = InputVector[i];
				SimulateRepeatedCombination(i, CurrentR + 1);
			}
		}
	}

public:
	vector<int> InputVector;
	vector<int> ResultVector;

	size_t N;
	size_t R;

};
