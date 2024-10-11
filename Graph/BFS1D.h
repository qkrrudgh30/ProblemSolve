#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CBFS1D
{
	enum { INVALID = -1 };

public:
	CBFS1D(const size_t InV = INVALID)
		: V(InV)
	{
		if (V != INVALID)
		{
			AdjacentMatrix.resize(V + 1, vector<int>(V + 1, 0));
			VisitVector.resize(V + 1, false);

			ParentVector.resize(V + 1, 0);
			DistanceVector.resize(V + 1, 0);
		}
		else
		{
			cout << "Invalid V." << endl;
		}
	}

	~CBFS1D()
	{
		AdjacentMatrix.clear();
		VisitVector.clear();
	}

	void InvokeBFS1D()
	{
		if (INVALID == V)
		{
			cout << "Invalid V." << endl;
			return;
		}

		BFS1D(1);
	}

private:
	void BFS1D(const size_t StartV)
	{
		VisitVector[StartV] = true;
		AdjacentQueue.push(StartV);
		while (0 != AdjacentQueue.size())
		{
			size_t CurrentV = AdjacentQueue.front();
			AdjacentQueue.pop();
			for (size_t NextV = 1; NextV <= V; ++NextV)
			{
				if (false == VisitVector[NextV] && 1 == AdjacentMatrix[CurrentV][NextV])
				{
					VisitVector[CurrentV] = true;
					AdjacentQueue.push(NextV);
					cout << CurrentV << " -> " << NextV << endl;

					ParentVector[NextV] = CurrentV;
					DistanceVector[NextV] = DistanceVector[CurrentV] + 1;
				}
			}
		}
	}

public:
	vector<vector<int>> AdjacentMatrix;
	vector<bool> VisitVector;

	vector<size_t> ParentVector;
	vector<size_t> DistanceVector;

	size_t V;

	queue<size_t> AdjacentQueue;

};
