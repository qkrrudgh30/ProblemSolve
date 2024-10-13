/*

Larry�� �ڿ��� ������ �޾ҽ��ϴ�. 
�� �迭�� �־��� ������ �̿��� ������������ ������ �� �ִ��� �Ǵ��ؾ� �մϴ�. ������ ������ �����ϴ�:

������ 3���� ��Ҹ� �����Ͽ� A[i], A[i+1], A[i+2]�� A[i+1], A[i+2], A[i]�� ȸ����ų �� �ֽ��ϴ�.
�־��� �迭�� �� ������ �̿��Ͽ� ������������ ������ �� �ִٸ� "YES"��, �Ұ����ϴٸ� "NO"�� ����ϼ���.

�Լ� ����
    larrysArray �Լ��� ���� �Ű������� �޽��ϴ�:
        vector<int> A: �迭
        ��ȯ��: �迭�� ������ �� ������ "YES"��, �׷��� ������ "NO"�� ��ȯ�մϴ�.

�Է� ����
    ù �ٿ� �׽�Ʈ ���̽��� �� t�� �־����ϴ�.
    �� �׽�Ʈ ���̽��� �� �ٷ� �����˴ϴ�:
    �迭�� ���� n 
    �迭 A

���� ����
    1��t��10
    3��n��1000
    �迭 A�� 1���� n������ �ڿ��� �����Դϴ�.

����
    �Է� ���� 1
        3
        3
        3 1 2
        4
        1 3 4 2
        5
        1 2 3 5 4

    ��� ���� 1
        YES
        YES
        NO

*/

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

