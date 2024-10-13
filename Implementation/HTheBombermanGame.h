/*

봄버맨은 직사각형 그리드에서 활동합니다. 각 셀에는 폭탄이 있거나 비어있습니다. 각 폭탄은 설치된 후 정확히 3초 후에 폭발합니다. 폭발 시 해당 폭탄과 인접한 네 방향의 셀이 모두 제거됩니다. 인접한 셀에 있는 폭탄도 파괴되며, 폭발은 연쇄되지 않습니다.

봄버맨의 활동 순서는 다음과 같습니다:
초기 상태에서 폭탄이 무작위로 설치되어 있습니다.
1초가 지나면 봄버맨은 아무것도 하지 않습니다.
2초가 지나면 비어 있는 모든 셀에 폭탄을 설치하여 그리드를 완전히 채웁니다.
3초가 지나면 3초 전에 설치된 모든 폭탄이 폭발합니다.
이후 2초마다 3, 4단계를 반복합니다.
초기 상태에서 n초 후의 그리드 상태를 구하세요.

함수 설명
    bomberMan 함수를 작성하세요. 이 함수는 다음 매개변수를 받습니다:
        int n: 초 단위의 시간
        vector<string> grid: 폭탄이 설치된 초기 상태의 그리드
        반환값:n초 후의 그리드 상태를 문자열 배열로 반환합니다.

입력 형식
    첫 줄: 세 개의 정수 r, c, n
    r개의 줄에 폭탄이 설치된 초기 상태가 주어집니다. '.'는 빈 셀, 'O'는 폭탄이 설치된 셀을 나타냅니다.

제약 조건
    1≤r,c≤200
    1≤n≤10

예제
    입력 예제 1
    6 7 3
    .......
    ...O...
    ....O..
    .......
    OO.....
    OO.....

    출력 예제 1
    OOO.OOO
    OO...OO
    OOO...O
    ..OO.OO
    ...OOOO
    ...OOOO

*/

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