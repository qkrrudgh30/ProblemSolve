#pragma once

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Larry's Array ���� ���� ���� �Ǻ� �Լ�
string larrysArray(vector<int> A) {
    int Length = A.size();

    // ������ ��� ȸ�� �۾��� �����Ͽ� ���� �õ�
    for (int i = 0; i <= Length - 3; i++) 
    {
        while (A[i + 1] < A[i] || A[i + 2] < A[i + 1]) // i, i+1, i+2�� �� ���ڰ� ���ĵ��� �ʾҴٸ�
        {
            // ���������� ȸ��
            rotate(A.begin() + i, A.begin() + i + 1, A.begin() + i + 3);
            if (is_sorted(A.begin(), A.end()) == true) 
            {
                return "YES";
            }
            // �� �̻� ȸ���� �Ұ����� ��� break
            if (A[i] <= A[i + 1] && A[i + 1] <= A[i + 2]) 
            {
                break;
            }
        }
    }

    // �迭�� ������ ���ĵǾ����� Ȯ��
    if (is_sorted(A.begin(), A.end()) == true)
    {
        return "YES";
    }
    else 
    {
        return "NO";
    }
}

