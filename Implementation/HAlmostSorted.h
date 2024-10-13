/*

���� �迭�� �־����ϴ�. 
�迭�� ������������ �����ϱ� ���� ���� �� ���� ���� �� �ϳ��� �� �� ����� �� �ֽ��ϴ�:
�� ��Ҹ� ��ȯ�մϴ�.
���ӵ� �κ� �迭�� �������ϴ�.
�־��� �迭�� ������������ ������ �� �ִ��� Ȯ���ϰ�, 
�����ϴٸ� � ������ ����ؾ� �ϴ��� ����մϴ�. 
���� �� ���� ��� ��� �����ϴٸ�, **��ȯ(swap)**�� �켱�մϴ�.

��� ����
    �迭�� �̹� ���ĵǾ� ������, "yes"�� ����մϴ�.
    �迭�� ������ �� �ִٸ� "yes"�� �Բ� �ʿ��� ������ ����մϴ�:
    "swap l r": l��°�� r��° ��Ҹ� ��ȯ�մϴ� (1-based �ε���).
    "reverse l r": l��°���� r��° ��ұ��� �������ϴ� (1-based �ε���).
    � ������ε� ������ �� ���ٸ� "no"�� ����մϴ�.

�Լ� ����
    almostSorted �Լ��� ���� �Ű������� �޽��ϴ�:
        vector<int> arr: ������ �õ��� �迭
        ���: ����� ����ϰ�, ��ȯ���� �����ϴ�.

����
    �Է� ���� 1
        2
        4 2
    ��� ���� 1
        yes
        swap 1 2

    �Է� ���� 2
        3
        3 1 2
    ��� ���� 2
        no

    �Է� ���� 3
        6
        1 5 4 3 2 6
    ��� ���� 3
        yes
        reverse 2 5

*/

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
