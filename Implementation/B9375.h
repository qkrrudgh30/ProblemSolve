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

    size_t CaseCount = 1; // ����� ���� unsigned int64�� �ϴ°� ����.
    for (const auto& ClotheType : ClotheTypes) 
    {
        CaseCount *= (ClotheType.second + 1); // �ش� ������ ���� �ʴ� ��쵵 ����
    }

    cout << CaseCount - 1 << endl; // �ּ� �ϳ� �̻��� �ǻ� ����
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

