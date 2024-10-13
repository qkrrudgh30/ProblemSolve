/*

매디슨은 장난감을 좋아하는 소녀입니다. 
그녀의 친구 메이슨은 장난감 제조 공장에서 일하며 H×W 크기의 2D 보드를 가지고 있습니다. 
각 셀 (i,j)에는 정수 A[i][j]가 적혀 있으며, 
이 수는 해당 셀에 쌓인 1x1x1 크기의 큐브 개수를 나타냅니다.

장난감의 가격은 3D 모형의 표면적에 따라 결정됩니다. 
각 큐브의 표면적을 계산하여 이 3D 모형의 전체 표면적을 구하세요.

입력 형식
    첫 번째 줄에 보드의 높이 H와 너비 W가 공백으로 구분되어 주어집니다.
    다음 H줄에 각 셀의 큐브 개수 A[i][j]가 공백으로 구분되어 주어집니다.

출력 형식
    장난감의 총 표면적을 한 줄로 출력합니다.

제약 조건
    1≤H,W≤100
    1≤A[i][j]≤100

예제
입력 예제 1
    1 1
    1
출력 예제 1
    6

입력 예제 2
    3 3
    1 3 4
    2 2 3
    1 2 4
출력 예제 2
    60

*/

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
