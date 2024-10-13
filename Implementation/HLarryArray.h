/*

Larry는 자연수 순열을 받았습니다. 
이 배열을 주어진 연산을 이용해 오름차순으로 정렬할 수 있는지 판단해야 합니다. 연산은 다음과 같습니다:

인접한 3개의 요소를 선택하여 A[i], A[i+1], A[i+2]를 A[i+1], A[i+2], A[i]로 회전시킬 수 있습니다.
주어진 배열을 이 연산을 이용하여 오름차순으로 정렬할 수 있다면 "YES"를, 불가능하다면 "NO"를 출력하세요.

함수 설명
    larrysArray 함수는 다음 매개변수를 받습니다:
        vector<int> A: 배열
        반환값: 배열을 정렬할 수 있으면 "YES"를, 그렇지 않으면 "NO"를 반환합니다.

입력 형식
    첫 줄에 테스트 케이스의 수 t가 주어집니다.
    각 테스트 케이스는 두 줄로 구성됩니다:
    배열의 길이 n 
    배열 A

제약 조건
    1≤t≤10
    3≤n≤1000
    배열 A는 1부터 n까지의 자연수 순열입니다.

예제
    입력 예제 1
        3
        3
        3 1 2
        4
        1 3 4 2
        5
        1 2 3 5 4

    출력 예제 1
        YES
        YES
        NO

*/

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

