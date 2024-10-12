#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) 
{
    ranked.erase(unique(ranked.begin(), ranked.end()), ranked.end());
    vector<int> ResultRank;
    int Count = ranked.size();

    int i = Count - 1;
    for (int CurrentPlayerScore : player) 
    {
        while (0 <= i && ranked[i] <= CurrentPlayerScore)
        {
            --i;
        }
        ResultRank.push_back(i + 2); // ranked ���ʹ� 0���� ���� �ϹǷ� +1, ���� ranked ���Ͱ� ����־ �ڵ����� 1���� �Ǵ� ��쿡 n�� -1 �̹Ƿ� ������ ���� +1.
    }

    return ResultRank;
}
