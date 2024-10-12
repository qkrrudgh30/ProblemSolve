#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Larry's Array 정렬 가능 여부 판별 함수
string larrysArray(vector<int> A) {
    int Length = A.size();

    // 가능한 모든 회전 작업을 수행하여 정렬 시도
    for (int i = 0; i <= Length - 3; i++) 
    {
        while (A[i + 1] < A[i] || A[i + 2] < A[i + 1]) // i, i+1, i+2의 세 숫자가 정렬되지 않았다면
        {
            // 오른쪽으로 회전
            rotate(A.begin() + i, A.begin() + i + 1, A.begin() + i + 3);
            if (is_sorted(A.begin(), A.end()) == true) 
            {
                return "YES";
            }
            // 더 이상 회전이 불가능할 경우 break
            if (A[i] <= A[i + 1] && A[i + 1] <= A[i + 2]) 
            {
                break;
            }
        }
    }

    // 배열이 완전히 정렬되었는지 확인
    if (is_sorted(A.begin(), A.end()) == true)
    {
        return "YES";
    }
    else 
    {
        return "NO";
    }
}

