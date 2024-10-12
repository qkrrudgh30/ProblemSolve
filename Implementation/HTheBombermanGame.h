#pragma once

#include <vector>
#include <string>

using namespace std;

// 폭발 후의 그리드 상태를 반환하는 함수
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

    // 2초일 때 모든 셀이 폭탄으로 가득 찬 상태
    vector<string> FullBombGrid(grid.size(), string(grid[0].size(), 'O'));

    // 3초일 때 초기 폭탄이 폭발한 상태
    vector<string> StateAfterFirstDetonation = detonate(grid);

    // 5초일 때 첫 폭발 이후의 폭발 상태
    vector<string> StateAfterSecondDetonation = detonate(StateAfterFirstDetonation);

    // n이 2초 간격으로 반복되므로 n % 4에 따라 결과 결정
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