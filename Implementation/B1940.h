#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//@TODO: Combination으로도 가능함.

void Solve(int N, int M, const vector<int>& materials) 
{
    vector<int> SortedMaterials = materials;
    sort(SortedMaterials.begin(), SortedMaterials.end());

    int LeftPointer = 0;
    int RightPointer = N - 1;
    int WeaponCount = 0;

    while (LeftPointer < RightPointer) 
    {
        int Sum = SortedMaterials[LeftPointer] + SortedMaterials[RightPointer];

        if (Sum == M) 
        {
            WeaponCount++;
            LeftPointer++;
            RightPointer--;
        }
        else if (Sum < M) 
        {
            LeftPointer++;
        }
        else 
        {
            RightPointer--;
        }
    }

    cout << WeaponCount << endl;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<int> materials(N);
    for (int i = 0; i < N; ++i) {
        cin >> materials[i];
    }

    Solve(N, M, materials);

    return 0;
}