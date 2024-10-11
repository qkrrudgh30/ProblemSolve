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
            // �⺻������ ���ʰ� �Ʒ����� ǥ���� (2�� ����)
            ResultArea += 2;

            // ���� ���� ����
            int CurrentDepth = A[i][j];

            // ���� ������ ����
            if (j == 0) 
            {
                ResultArea += CurrentDepth; // ���� �� ����
            }
            else {
                ResultArea += max(0, CurrentDepth - A[i][j - 1]);
            }

            // ������ ������ ����
            if (j == W - 1) 
            {
                ResultArea += CurrentDepth; // ������ �� ����
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i][j + 1]);
            }

            // ���� ������ ����
            if (i == 0) 
            {
                ResultArea += CurrentDepth; // ���� �� ����
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i - 1][j]);
            }

            // �Ʒ��� ������ ����
            if (i == H - 1) 
            {
                ResultArea += CurrentDepth; // �Ʒ��� �� ����
            }
            else 
            {
                ResultArea += max(0, CurrentDepth - A[i + 1][j]);
            }
        }
    }

    return ResultArea;
}
