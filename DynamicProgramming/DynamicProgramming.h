#pragma once

#include <iostream>
#include <vector>

using namespace std;

class DynamicProgramming
{
	enum { INVALID = -1 };

public:
	DynamicProgramming(const size_t InMemoizationSize = INVALID)
	{
		if (InMemoizationSize != INVALID)
		{
			Memoization1D.resize(InMemoizationSize + 1, 0);
			Memoization2D.resize(InMemoizationSize + 1, vector<int>(InMemoizationSize + 1, 0));
		}
		else
		{
			cout << "Invalid InMemoizationSize." << endl;
		}
	}

	~DynamicProgramming()
	{
		Memoization1D.clear();
	}

	int DP(const size_t InN)
	{
		if (1 == InN)
		{
			return 1;
		}

		if (2 == InN)
		{
			return 1;
		}

		if (0 != Memoization1D[InN])
		{
			return Memoization1D[InN];
		}

		return Memoization1D[InN] = DP(InN - 1) + DP(InN - 2);
	}
	
	int DP2(const size_t InN)
	{
		if (1 == InN)
		{
			return 1;
		}

		if (2 == InN)
		{
			return 2;
		}

		if (Memoization1D[InN] != 0)
		{
			return Memoization1D[InN];
		}

		return Memoization1D[InN] = DP2(InN - 1) + DP(InN - 2);
	}

	int DP3(const size_t InN)
	{
		if (1 == InN)
		{
			return 1;
		}

		if (2 == InN)
		{
			return 3;
		}

		if (3 == InN)
		{
			return 5;
		}

		if (Memoization1D[InN] != 0)
		{
			return Memoization1D[InN];
		}

		return Memoization1D[InN] = (DP3(InN - 1) + DP(InN - 2)) % 10007;
	}

	int DP4(const size_t InN)
	{
		if (0 == InN)
		{
			return 1;
		}

		if (InN % 2 == 1)
		{
			return 0;
		}

		if (3 == InN)
		{
			return 3;
		}

		if (Memoization1D[InN] != 0)
		{
			return Memoization1D[InN];
		}

		int Result = 3 * DP4(InN - 2);
		for (size_t i = 4; i <= InN; i += 2)
		{
			Result += 2 * DP4(InN - i);
		}

		return Memoization1D[InN] = Result;
	}

	int DP5(const size_t InN)
	{
		/*
		if (Memoization1D[InN] != 0)
		{
			return Memoization1D[InN];
		}

		if (0 == InN)
		{
			return Memoization1D[InN] = 1;
		}

		if (1 == InN)
		{
			return Memoization1D[InN] = 2;
		}

		if (2 == InN)
		{
			return Memoization1D[InN] = 7;
		}

		if (3 == InN)
		{
			return Memoization1D[InN] = 22;
		}

		int Result = 2 * DP5(InN - 1) + 3 * DP5(InN - 2);
		for (size_t i = 3; i <= InN; ++i)
		{
			Result += 2 * DP5(InN - i) % 100000007;
		}

		return Memoization1D[InN] = Result;
		*/

		Memoization2D[0][0] = 1;
		Memoization2D[1][0] = 2;
		Memoization2D[2][0] = 7;
		for (size_t i = 3; i <= InN; ++i)
		{
			Memoization2D[i][1] = Memoization2D[i-1][1] + Memoization2D[i-3][0];
			Memoization2D[i][0] = 2*Memoization2D[i][1] + 
		}
	}

public:
	vector<int> Memoization1D;

	vector<vector<int>> Memoization2D;

};