/*

정수 배열이 주어집니다. 
배열을 오름차순으로 정렬하기 위해 다음 두 가지 연산 중 하나만 한 번 사용할 수 있습니다:
두 요소를 교환합니다.
연속된 부분 배열을 뒤집습니다.
주어진 배열을 오름차순으로 정렬할 수 있는지 확인하고, 
가능하다면 어떤 연산을 사용해야 하는지 출력합니다. 
만약 두 가지 방법 모두 가능하다면, **교환(swap)**을 우선합니다.

출력 형식
    배열이 이미 정렬되어 있으면, "yes"만 출력합니다.
    배열을 정렬할 수 있다면 "yes"와 함께 필요한 연산을 출력합니다:
    "swap l r": l번째와 r번째 요소를 교환합니다 (1-based 인덱스).
    "reverse l r": l번째부터 r번째 요소까지 뒤집습니다 (1-based 인덱스).
    어떤 방법으로도 정렬할 수 없다면 "no"를 출력합니다.

함수 설명
    almostSorted 함수는 다음 매개변수를 받습니다:
        vector<int> arr: 정렬을 시도할 배열
        출력: 결과를 출력하고, 반환값은 없습니다.

예제
    입력 예제 1
        2
        4 2
    출력 예제 1
        yes
        swap 1 2

    입력 예제 2
        3
        3 1 2
    출력 예제 2
        no

    입력 예제 3
        6
        1 5 4 3 2 6
    출력 예제 3
        yes
        reverse 2 5

*/

#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 배열을 오름차순으로 정렬할 수 있는지 검사하는 함수
void almostSorted(vector<int> arr) {
    int Length = arr.size();
    vector<int> SortedArr = arr;
    sort(SortedArr.begin(), SortedArr.end());

    if (arr == SortedArr) 
    {
        cout << "yes" << endl;
        return;
    }

    // Swap을 검사하기 위해 인덱스 찾기
    int Left = -1, Right = -1;
    for (int i = 0; i < Length; i++) 
    {
        if (arr[i] != SortedArr[i]) 
        {
            if (Left == -1) 
            {
                Left = i;
            }
            Right = i;
        }
    }

    // Swap 가능한 경우
    swap(arr[Left], arr[Right]);
    if (arr == SortedArr) {
        cout << "yes" << endl;
        cout << "swap " << Left + 1 << " " << Right + 1 << endl;
        return;
    }

    // Reverse를 검사하기 위해 복구 후 Reverse
    swap(arr[Left], arr[Right]);
    reverse(arr.begin() + Left, arr.begin() + Right + 1);
    if (arr == SortedArr) {
        cout << "yes" << endl;
        cout << "reverse " << Left + 1 << " " << Right + 1 << endl;
        return;
    }

    // 정렬 불가능한 경우
    cout << "no" << endl;
}
