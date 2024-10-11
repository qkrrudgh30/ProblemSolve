#pragma once

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class CBFS2D
{
	enum { INVALID = -1 };

public:
	CBFS2D(const size_t InVR = INVALID, const size_t InVC = INVALID)
		: VR(InVR)
		, VC(InVC)
	{
		if (VR != INVALID && VC != INVALID)
		{
			AdjacentMatrix.resize(VR + 1, vector<int>(VC + 1, 0));
			VisitMatrix.resize(VR + 1, vector<bool>(VC + 1, false));

			DistanceMatrix.resize(VR + 1, vector<int>(VC + 1, 0));
		}
		else
		{
			cout << "Invalid VR or VC" << endl;
		}
	}

	~CBFS2D()
	{
		AdjacentMatrix.clear();
		VisitMatrix.clear();

		DistanceMatrix.clear();
	}

	void InvokeBFS2D()
	{
		if (INVALID == VR || INVALID == VC)
		{
			cout << "Invalid VR or VC" << endl;
			return;
		}

		for (size_t i = 1; i < VR; ++i)
		{
			for (size_t j = 1; j < VC; ++j)
			{
				if (false == VisitMatrix[i][j] && 0 != AdjacentMatrix[i][j])
				{
					BFS2D(i, j);
				}
			}
		}
	}

private:
	void BFS2D(const size_t StartVR, const size_t StartVC)
	{
		VisitMatrix[StartVR][StartVC] = true;
		pair<size_t, size_t> AdjacentQueuePair(StartVR, StartVC);
		AdjacentQueue.push(AdjacentQueuePair);
		while (0 != AdjacentQueue.size())
		{
			size_t CurrentVR = AdjacentQueue.front().first;
			size_t CurrentVC = AdjacentQueue.front().second;
			AdjacentQueue.pop();

			for (size_t DirectionIndex = 0; DirectionIndex < 4; ++DirectionIndex)
			{
				size_t NextVR = CurrentVR + DirectionMatrix[DirectionIndex][0];
				size_t NextVC = CurrentVC + DirectionMatrix[DirectionIndex][1];

				if (NextVR < 1 || VR < NextVR ||
					NextVC < 1 || VC < NextVC)
				{
					continue;
				}

				if (true == VisitMatrix[NextVR][NextVC])
				{
					continue;
				}

				if (1 == AdjacentMatrix[NextVR][NextVC])
				{
					VisitMatrix[NextVR][NextVC] = true;
					cout << CurrentVR << ", " << CurrentVC << " -> " << NextVR << ", " << NextVC << endl;
					pair<size_t, size_t> NextVPair(NextVR, NextVC);
					AdjacentQueue.push(NextVPair);

					DistanceMatrix[NextVR][NextVC] = DistanceMatrix[CurrentVR][CurrentVC] + 1;
				}
			}
		}
	}

public:
	vector<vector<int>> AdjacentMatrix;
	vector<vector<bool>> VisitMatrix;

	vector<vector<int>> DistanceMatrix;

	size_t VR;
	size_t VC;

	queue<pair<size_t, size_t>> AdjacentQueue;

	int DirectionMatrix[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

};