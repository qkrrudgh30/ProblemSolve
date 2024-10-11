#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CRepeatedPermutation
{
	enum { INVALID = -1 };

public:
	CRepeatedPermutation(const size_t InN = INVALID, const size_t InR = INVALID)
		: N(InN)
		, R(InR)
	{
		if (N != INVALID && R != INVALID)
		{
			InputVector.resize(N, 0);
			ResultVector.resize(R, 0);
		}
		else
		{
			cout << "Invalid N or R." << endl;
		}
	}

	~CRepeatedPermutation()
	{
		InputVector.clear();
		ResultVector.clear();
	}

	void InvokeRepeatedPermutation()
	{
		if (INVALID == N || INVALID == R)
		{
			cout << "Invalid N or R." << endl;
			return;
		}

		SimulateRepeatedPermutation(0);
	}

	size_t CountRepeatedPermutation(const size_t InN, const size_t InR)
	{
		if (0 == InR)
		{
			return 1;
		}

		// nPIr = n ^ r
		return InN * CountRepeatedPermutation(InN, InR - 1);
	}

private:
	void SimulateRepeatedPermutation(const size_t CurrentR)
	{
		if (R == CurrentR)
		{
			for (size_t i = 0; i < R; ++i)
			{
				cout << ResultVector[i];
			}
			cout << endl;

			return;
		}
		else
		{
			for (size_t i = 0; i < N; ++i)
			{
				ResultVector[CurrentR] = InputVector[i];
				SimulateRepeatedPermutation(CurrentR + 1);
			}
		}
	}

public:
	vector<int> InputVector;
	vector<int> ResultVector;

	size_t N;
	size_t R;

};


// 2309: 순서와 상관이 있어도 되고, 없어도 되는 문제라 순열/조합 둘다 됨. 다만 N이 작을 때는 조합이 맞음.
