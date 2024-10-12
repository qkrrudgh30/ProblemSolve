#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Solve(int N, int K, const vector<int>& temperatures) 
{
    // K일 동안의 합 계산
    int CurrentMaxSum = 0;
    for (int i = 0; i < K; ++i) 
    {
        CurrentMaxSum += temperatures[i];
    }

    // 최대합 초기화
    int MaxSum = CurrentMaxSum;

    // 슬라이딩 윈도우를 통해 K일 동안의 합 계산 및 최대합 업데이트
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
