#pragma once

#include <iostream>
#include <vector>

using namespace std;

class CDFS2D
{
	enum { INVALID = -1 };

public:
	CDFS2D(const size_t InVR = INVALID, const size_t InVC = INVALID)
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
			cout << "Invalid VR or VC." << endl;
		}
	}
	
	~CDFS2D()
	{
		AdjacentMatrix.clear();
		VisitMatrix.clear();
	}

	void InvokeDFS2D()
	{
		if (INVALID == VR || INVALID == VC)
		{
			cout << "Invalid VR or VC." << endl;
			return;
		}

		for (size_t i = 1; i <= VR; ++i)
		{
			for (size_t j = 1; j <= VC; ++j)
			{
				if (false == VisitMatrix[i][j] && 1 == AdjacentMatrix[i][j])
				{
					DFS2D(i, j);
				}
			}
		}
	}

private:
	void DFS2D(const size_t CurrentVR, const size_t CurrentVC)
	{
		size_t NextVR, NextVC;

		VisitMatrix[CurrentVR][CurrentVC] = true;

		for (size_t DirectionIndex = 0; DirectionIndex < 4; ++DirectionIndex)
		{
			NextVR = CurrentVR + DirectionMatrix[DirectionIndex][0];
			NextVC = CurrentVC + DirectionMatrix[DirectionIndex][1];

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
				cout << CurrentVR << ", " << CurrentVC << " -> " << NextVR << ", " << NextVC << endl;
				DistanceMatrix[NextVR][NextVC] = DistanceMatrix[CurrentVR][CurrentVC] + 1;
				DFS2D(NextVR, NextVC);
			}
		}
	}

public:
	vector<vector<int>> AdjacentMatrix;
	vector<vector<bool>> VisitMatrix;

	vector<vector<int>> DistanceMatrix;

	size_t VR;
	size_t VC;

	int DirectionMatrix[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
};
