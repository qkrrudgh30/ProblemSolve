#pragma once

#include <string>
#include <vector>

using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    int GR = G.size(), GC = G[0].size();
    int PR = P.size(), PC = P[0].size();

    // 그리드의 각 위치에서 패턴이 시작하는지 확인
    for (int i = 0; i <= GR - PR; i++) 
    {
        for (int j = 0; j <= GC - PC; j++) 
        {
            bool bFound = true;

            // 현재 위치에서 패턴이 존재하는지 검사
            for (int x = 0; x < PR && bFound; x++) 
            {
                for (int y = 0; y < PC; y++) 
                {
                    if (G[i + x][j + y] != P[x][y]) 
                    {
                        bFound = false;
                        break;
                    }
                }
            }

            if (bFound == true) 
            {
                return "YES";
            }
        }
    }

    return "NO";
}