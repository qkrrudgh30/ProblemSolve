/*

�ŵ��� �峭���� �����ϴ� �ҳ��Դϴ�. 
�׳��� ģ�� ���̽��� �峭�� ���� ���忡�� ���ϸ� H��W ũ���� 2D ���带 ������ �ֽ��ϴ�. 
�� �� (i,j)���� ���� A[i][j]�� ���� ������, 
�� ���� �ش� ���� ���� 1x1x1 ũ���� ť�� ������ ��Ÿ���ϴ�.

�峭���� ������ 3D ������ ǥ������ ���� �����˴ϴ�. 
�� ť���� ǥ������ ����Ͽ� �� 3D ������ ��ü ǥ������ ���ϼ���.

�Է� ����
    ù ��° �ٿ� ������ ���� H�� �ʺ� W�� �������� ���еǾ� �־����ϴ�.
    ���� H�ٿ� �� ���� ť�� ���� A[i][j]�� �������� ���еǾ� �־����ϴ�.

��� ����
    �峭���� �� ǥ������ �� �ٷ� ����մϴ�.

���� ����
    1��H,W��100
    1��A[i][j]��100

����
�Է� ���� 1
    1 1
    1
��� ���� 1
    6

�Է� ���� 2
    3 3
    1 3 4
    2 2 3
    1 2 4
��� ���� 2
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
