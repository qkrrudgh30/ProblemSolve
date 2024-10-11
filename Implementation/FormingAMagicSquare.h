#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

bool CheckMagicSquare(vector<int>& InSquare)
{
    int MagicConstant = 15;
    return (InSquare[0] + InSquare[1] + InSquare[2] == MagicConstant &&
        InSquare[3] + InSquare[4] + InSquare[5] == MagicConstant &&
        InSquare[6] + InSquare[7] + InSquare[8] == MagicConstant &&
        InSquare[0] + InSquare[3] + InSquare[6] == MagicConstant &&
        InSquare[1] + InSquare[4] + InSquare[7] == MagicConstant &&
        InSquare[2] + InSquare[5] + InSquare[8] == MagicConstant &&
        InSquare[0] + InSquare[4] + InSquare[8] == MagicConstant &&
        InSquare[2] + InSquare[4] + InSquare[6] == MagicConstant);
}

int CalculateCost(vector<vector<int>>& InSquare, vector<int>& InMagicSquare)
{
    int cost = 0;
    for (int i = 0; i < 3; i++) 
    {
        for (int j = 0; j < 3; j++) 
        {
            cost += abs(InSquare[i][j] - InMagicSquare[i * 3 + j]);
        }
    }
    return cost;
}

int formingMagicSquare(vector<vector<int>> s) {
    vector<int> Digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    int MinCost = INT_MAX;

    // 1���� 9������ ���ڵ�� ������ ��� ���� ����
    do {
        // ���� ���������� Ȯ��
        if (CheckMagicSquare(Digits) == true)
        {
            // ��� ��� �� �ּ� ��� ����
            int CalculatedCost = CalculateCost(s, Digits);
            MinCost = min(MinCost, CalculatedCost);
        }
    } while (next_permutation(Digits.begin(), Digits.end())); // ������ ��� ����

    return MinCost;
}
