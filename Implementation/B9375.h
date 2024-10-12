#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

void Solve(int n) {
    unordered_map<string, int> ClotheTypes;

    for (int i = 0; i < n; ++i) 
    {
        string ClotheName, ClotheType;
        cin >> ClotheName >> ClotheType;
        ClotheTypes[ClotheType]++;
    }

    size_t CaseCount = 1; // 경우의 수는 unsigned int64로 하는게 좋음.
    for (const auto& ClotheType : ClotheTypes) 
    {
        CaseCount *= (ClotheType.second + 1); // 해당 종류를 입지 않는 경우도 포함
    }

    cout << CaseCount - 1 << endl; // 최소 하나 이상의 의상 착용
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        Solve(n);
    }
    return 0;
}

