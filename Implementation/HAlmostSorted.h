#pragma once

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// �迭�� ������������ ������ �� �ִ��� �˻��ϴ� �Լ�
void almostSorted(vector<int> arr) {
    int Length = arr.size();
    vector<int> SortedArr = arr;
    sort(SortedArr.begin(), SortedArr.end());

    if (arr == SortedArr) 
    {
        cout << "yes" << endl;
        return;
    }

    // Swap�� �˻��ϱ� ���� �ε��� ã��
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

    // Swap ������ ���
    swap(arr[Left], arr[Right]);
    if (arr == SortedArr) {
        cout << "yes" << endl;
        cout << "swap " << Left + 1 << " " << Right + 1 << endl;
        return;
    }

    // Reverse�� �˻��ϱ� ���� ���� �� Reverse
    swap(arr[Left], arr[Right]);
    reverse(arr.begin() + Left, arr.begin() + Right + 1);
    if (arr == SortedArr) {
        cout << "yes" << endl;
        cout << "reverse " << Left + 1 << " " << Right + 1 << endl;
        return;
    }

    // ���� �Ұ����� ���
    cout << "no" << endl;
}
