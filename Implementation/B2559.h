#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve(int N, int K, const vector<int>& temperatures) 
{
    // K�� ������ �� ���
    int CurrentMaxSum = 0;
    for (int i = 0; i < K; ++i) 
    {
        CurrentMaxSum += temperatures[i];
    }

    // �ִ��� �ʱ�ȭ
    int MaxSum = CurrentMaxSum;

    // �����̵� �����츦 ���� K�� ������ �� ��� �� �ִ��� ������Ʈ
    for (int i = K; i < N; ++i) 
    {
        CurrentMaxSum = CurrentMaxSum - temperatures[i - K] + temperatures[i];
        MaxSum = max(MaxSum, CurrentMaxSum);
    }

    cout << MaxSum << endl;
}

int main() {
    int N, K;
    cin >> N >> K;

    vector<int> temperatures(N);
    for (int i = 0; i < N; ++i) {
        cin >> temperatures[i];
    }

    Solve(N, K, temperatures);

    return 0;
}
