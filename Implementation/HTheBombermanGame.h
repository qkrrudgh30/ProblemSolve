#pragma once

#include <vector>
#include <string>

using namespace std;

// ���� ���� �׸��� ���¸� ��ȯ�ϴ� �Լ�
vector<string> detonate(const vector<string>& InGrid) 
{
    int RowCount = InGrid.size();
    int ColumnCount = InGrid[0].size();
    vector<string> newGrid(RowCount, string(ColumnCount, 'O'));

    for (int i = 0; i < RowCount; i++) 
    {
        for (int j = 0; j < ColumnCount; j++) 
        {
            if (InGrid[i][j] == 'O') 
            {
                newGrid[i][j] = '.';
                if (i > 0) newGrid[i - 1][j] = '.';
                if (i < RowCount - 1) newGrid[i + 1][j] = '.';
                if (j > 0) newGrid[i][j - 1] = '.';
                if (j < ColumnCount - 1) newGrid[i][j + 1] = '.';
            }
        }
    }
    return newGrid;
}

vector<string> bomberMan(int n, vector<string> grid) {
    if (n == 1)
    {
        return grid;
    }

    // 2���� �� ��� ���� ��ź���� ���� �� ����
    vector<string> FullBombGrid(grid.size(), string(grid[0].size(), 'O'));

    // 3���� �� �ʱ� ��ź�� ������ ����
    vector<string> StateAfterFirstDetonation = detonate(grid);

    // 5���� �� ù ���� ������ ���� ����
    vector<string> StateAfterSecondDetonation = detonate(StateAfterFirstDetonation);

    // n�� 2�� �������� �ݺ��ǹǷ� n % 4�� ���� ��� ����
    if (n % 4 == 1) 
    {
        return StateAfterSecondDetonation;
    }
    else if (n % 4 == 3) 
    {
        return StateAfterFirstDetonation;
    }
    else 
    {
        return FullBombGrid;
    }
}