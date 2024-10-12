#pragma once

#include <vector>

using namespace std;

int surfaceArea(vector<vector<int>> A) {
    int H = A.size();
    int W = A[0].size();
    int ResultArea = 0;

    for (int i = 0; i < H; ++i) 
    {
        for (int j = 0; j < W; ++j) 
        {
            // 기본적으로 위쪽과 아래쪽의 표면적 (2를 더함)
            ResultArea += 2;

            // 현재 셀의 높이
            int CurrentDepth = A[i][j];

            // 왼쪽 셀과의 차이
            if (j == 0) 
            {
                ResultArea += CurrentDepth; // 왼쪽 면 노출
            }
            else {
                ResultArea += max(0, CurrentDepth - A[i][j - 1]);
            }

            // 오른쪽 셀과의 차이
            if (j == W - 1) 
            {
                ResultArea += CurrentDepth; // 오른쪽 면 노출
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i][j + 1]);
            }

            // 위쪽 셀과의 차이
            if (i == 0) 
            {
                ResultArea += CurrentDepth; // 위쪽 면 노출
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i - 1][j]);
            }

            // 아래쪽 셀과의 차이
            if (i == H - 1) 
            {
                ResultArea += CurrentDepth; // 아래쪽 면 노출
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i + 1][j]);
            }
        }
    }

    return ResultArea;
}
