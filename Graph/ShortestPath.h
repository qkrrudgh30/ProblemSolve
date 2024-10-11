#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

class CDijkstra
{
	enum { INVALID = -1 };

	struct VertexCost
	{
		size_t BeginV;
		size_t EndV;
		int Cost;

		bool operator<(const VertexCost& In) const
		{
			return Cost < In.Cost;
		}
	};

public:
	CDijkstra(const size_t InV = INVALID, const size_t InE = INVALID)
		: V(InV)
		, E(InE)
	{
		if (V != INVALID && E != INVALID)
		{
			AdjacentMatrix.resize(V + 1, vector<int>(V + 1, INT32_MAX));
			VisitMatrix.resize(V + 1, vector<bool>(V + 1, false));
			BestCostVector.resize(V + 1, INT32_MAX);
			ParentVector.resize(V + 1, INT32_MAX);

			ShortestCost.resize(V + 1, vector<int>(V + 1, INT32_MAX));
		}
		else
		{
			cout << "Invalid V or E" << endl;
		}
	}

	~CDijkstra()
	{
		AdjacentMatrix.clear();
		VisitMatrix.clear();
	}

	void Dijkstra(const size_t StartV)
	{
		VertexCostList.push_back(VertexCost{ StartV, 0 });
		BestCostVector[StartV] = 0;
		ParentVector[StartV] = StartV;

		while (0 != VertexCostList.size())
		{
			int BestCost = INT32_MAX;
			auto BestCostIter = VertexCostList.begin();
			auto BeginIter = VertexCostList.begin();
			auto EndIter = VertexCostList.end();
			while (BeginIter != EndIter)
			{
				if (BeginIter->Cost < BestCost)
				{
					BestCost = BeginIter->Cost;
					BestCostIter = BeginIter;
				}
				++BeginIter;
			}


			size_t CurrentV = BeginIter->BeginV;
			int CurrentCost = BeginIter->Cost;

			VertexCostList.erase(BeginIter);

			if (BestCostVector[CurrentV] < CurrentCost)
			{
				continue;
			}

			for (size_t NextV = 1; NextV <= V; ++NextV)
			{
				int NextCost = BestCostVector[CurrentV] + AdjacentMatrix[CurrentV][NextV];
				if (INT32_MAX == AdjacentMatrix[CurrentV][NextV] || BestCostVector[NextV] <= NextCost)
				{
					continue;
				}

				VertexCostList.push_back(VertexCost{ CurrentV, NextV, NextCost });
				BestCostVector[NextV] = NextCost;
				ParentVector[NextV] = CurrentV;
			}
		}
	}

	void Dijkstra2(const size_t StartV)
	{
		VertexCostQueue.push(VertexCost{ StartV, 0 });
		BestCostVector[StartV] = 0;

		while (0 != VertexCostQueue.size())
		{
			size_t CurrentV = VertexCostQueue.top().BeginV;
			int CurrentCost = VertexCostQueue.top().Cost;
			VertexCostQueue.pop();

			if (BestCostVector[CurrentV] < CurrentCost)
			{
				continue;
			}

			for (size_t NextV = 1; NextV <= V; ++NextV)
			{
				int NextCost = BestCostVector[CurrentV] + AdjacentMatrix[CurrentV][NextV];
				if (INT32_MAX == AdjacentMatrix[CurrentV][NextV] || BestCostVector[NextV] <= NextCost)
				{
					continue;
				}

				VertexCostQueue.push(VertexCost{ CurrentV, NextV, NextCost });
				BestCostVector[NextV] = NextCost;
				ParentVector[NextV] = CurrentV;
			}
		}
	}

	void BellmanFord(const size_t StartV)
	{
		BestCostVector[StartV] = 0;

		for (size_t i = 1; i <= V; ++i)
		{
			for (size_t j = 1; j <= E; ++j)
			{
				size_t CurrentV = EdgeVector[j].BeginV;
				size_t NextV = EdgeVector[j].EndV;
				int Cost = EdgeVector[j].Cost;

				if (BestCostVector[CurrentV] != INT32_MAX && BestCostVector[CurrentV] + Cost < BestCostVector[NextV])
				{
					BestCostVector[NextV] = BestCostVector[CurrentV] + Cost;
				}
			}
		}

		for (size_t j = 1; j <= E; ++j)
		{
			size_t CurrentV = EdgeVector[j].BeginV;
			size_t NextV = EdgeVector[j].EndV;
			int Cost = EdgeVector[j].Cost;
			if (BestCostVector[CurrentV] != INT32_MAX && BestCostVector[CurrentV] + Cost < BestCostVector[NextV])
			{
				cout << "Negative cost cycle." << endl;
				return;
			}
		}
	}

	void FloydWarshall()
	{
		for (size_t k = 1; k <= V; ++k) // 거쳐가는 노드
		{
			for (size_t i = 1; i <= V; ++i) // 출발 노드
			{
				for (size_t j = 1; j <= V; ++j) // 도착 노드
				{
					if (ShortestCost[i][k] + ShortestCost[k][j] < ShortestCost[i][j])
					{
						ShortestCost[i][j] = ShortestCost[i][k] + ShortestCost[k][j];
						PredecessorMatrix[i][j] = k;
					}
				}
			}
		}
	}

	void PrintFloydWarshallPath(const size_t BeginV, const size_t EndV)
	{
		if (BeginV == EndV)
		{
			cout << BeginV << " -> ";
			return;
		}
		
		if (INT32_MAX == PredecessorMatrix[BeginV][EndV])
		{
			cout << "No path." << endl;
			return;
		}

		PrintFloydWarshallPath(BeginV, PredecessorMatrix[BeginV][EndV]);

		cout << EndV << " -> ";
	}

public:
	vector<vector<int>> AdjacentMatrix;
	vector<vector<bool>> VisitMatrix;

	list<VertexCost> VertexCostList;
	vector<int> BestCostVector;
	vector<size_t> ParentVector;

	priority_queue<VertexCost> VertexCostQueue;

	size_t V;
	size_t E;

	vector<VertexCost> EdgeVector;

	vector<vector<int>> ShortestCost;
	vector<vector<int>> PredecessorMatrix;
};

/*
6 9
0 3 1 10 -1 -1
3 0 -1 5 -1 -1
1 -1 0 8 4 6
10 5 8 0 -1 2
-1 -1 4 -1 0 8
-1 -1 6 2 8 0
*/