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
