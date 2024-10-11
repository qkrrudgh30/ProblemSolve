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
        ResultRank.push_back(i + 2); // ranked 벡터는 0부터 시작 하므로 +1, 만약 ranked 벡터가 비어있어서 자동으로 1위가 되는 경우에 n은 -1 이므로 보정을 위해 +1.
    }

    return ResultRank;
}
