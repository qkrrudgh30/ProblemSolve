#pragma once


#include <iostream>

using namespace std;

void findSmallestAllOnesMultiple(int n) 
{
    int Number = 1;  // �ʱ� ���� 1�� ����
    int Length = 1;  // �ڸ����� ������ ����

    while (Number % n != 0) 
    {  // �������� 0�� �� ������ �ݺ�
        Number = (Number * 10 + 1) % n; // ���ο� '111...1' ���� �� ������ ����
        ++Length; // �ڸ��� ����
    }

    cout << Length << endl; // n�� ����� �� ���� �ڸ��� ���
}

int main() {
    int n;

    while (cin >> n) { // ���� ���� �׽�Ʈ ���̽��� ����
        findSmallestAllOnesMultiple(n);
    }

    return 0;
}
