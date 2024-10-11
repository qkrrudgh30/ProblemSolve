#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CDFS1D
{
	enum { INVALID = -1 };

public:
	CDFS1D(const size_t InV = INVALID)
		: V(InV)
	{
		if (V != INVALID)
		{
			AdjacentMatrix.resize(V + 1, vector<int>(V + 1, 0));
			VisitVector.resize(V + 1, false);

			ParentVector.resize(V + 1, 0);
			DistanceVector.resize(V + 1, 0);
		}
	}

	~CDFS1D()
	{
		AdjacentMatrix.clear();
		VisitVector.clear();
	}

	void DFS1D(const size_t CurrentV)
	{
		VisitVector[CurrentV] = true;

		for (size_t i = 1; i <= V; ++i)
		{
			if (true == VisitVector[i])
			{
				continue;
			}

			if (1 == AdjacentMatrix[CurrentV][i])
			{
				cout << CurrentV << " -> " << i << endl;
				ParentVector[i] = CurrentV;
				DistanceVector[i] = DistanceVector[CurrentV] + 1;
				DFS1D(i);
			}
		}
	}

public:
	vector<vector<int>> AdjacentMatrix;
	vector<bool> VisitVector;

	vector<int> ParentVector;
	vector<int> DistanceVector;

	size_t V;

};
