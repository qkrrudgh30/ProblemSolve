/*

1부터 n까지의 자연수로 이루어진 배열 p가 주어졌을 때,
|p[i]−i|=k를 만족하는 배열을 절대 순열이라고 정의합니다.
p[i]는 p의 i번째 위치의 값을 의미합니다 (1-based 인덱스).

주어진 n과 k에 대해, 사전 순으로 가장 작은 절대 순열을 출력하세요. 
절대 순열을 만들 수 없으면 -1을 출력합니다.

함수 설명
    absolutePermutation 함수를 작성하세요. 이 함수는 다음 매개변수를 받습니다:
        int n: 자연수의 상한값
        int k: 각 요소의 값과 인덱스 간의 절대 차이
        반환값: 조건을 만족하는 순열을 배열로 반환하거나, 불가능할 경우 {-1}을 반환합니다.

입력 형식
    첫 번째 줄에 쿼리 수 t가 주어집니다.
    각 쿼리는 두 개의 정수 n과 k로 이루어져 있습니다.

제약 조건
    1≤t≤10
    1≤n≤10
    0≤k<n

예제
    입력 예제 1
        3
        2 1
        3 0
        3 2

    출력 예제 1
        2 1
        1 2 3
        -1

    예제 설명
    첫 번째 쿼리: n=2, k=1인 경우, [2,1]이 절대 순열입니다.
    두 번째 쿼리: k=0인 경우, 자연순 배열 자체가 절대 순열입니다.
    세 번째 쿼리: n=3, k=2인 경우, 절대 순열을 만들 수 없으므로 -1을 출력합니다.

*/

#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> Permutation(n);
    iota(Permutation.begin(), Permutation.end(), 1);

    // next_permutation을 통해 순열을 탐색하며 절대 순열 찾기
    do {
        bool bIsAbsolutePermutation = true;

        for (int i = 0; i < n; i++) 
        {
            if (abs(Permutation[i] - (i + 1)) != k) 
            {
                bIsAbsolutePermutation = false;
                break;
            }
        }

        if (bIsAbsolutePermutation == true)
        {
            return Permutation;
        }

    } while (next_permutation(Permutation.begin(), Permutation.end()));

    return { -1 };
}

vector<int> absolutePermutation2(int n, int k) {
    vector<int> Result;

    // Result[i] - i = k, Result[i] = i + k 혹은 Result[i] = i + k여야함. 
    
    if (k > 0 && n % (2 * k) != 0) 
    {
        return { -1 };
    }

    Result.resize(n);

    // k 단위로 절대 순열을 생성합니다.
    for (int i = 1; i <= n; i++) {
        if ((i - 1) / k % 2 == 0) {
            Result[i - 1] = i + k;
        }
        else {
            Result[i - 1] = i - k;
        }
    }

    return Result;
}
