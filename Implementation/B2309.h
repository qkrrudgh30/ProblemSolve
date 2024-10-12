#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve(vector<int> heights) 
{
    sort(heights.begin(), heights.end());    

    do {
        int Sum = 0;
        for (int i = 0; i < 7; ++i)
        {
            Sum += heights[i];
        }

        if (Sum == 100)
        {
            break;
        }
    } while (next_permutation(heights.begin(), heights.end()));
    
    for (int i = 0; i < 7; ++i)
    {
        cout << heights[i] << "\n";
    }
}

int main() 
{
    vector<int> heights(9);

    for (int i = 0; i < 9; ++i) 
    {
        cin >> heights[i];
    }

    Solve(heights);

    return 0;
}
