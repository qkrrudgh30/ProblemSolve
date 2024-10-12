#pragma once

#include <iostream>
#include <stack>
#include <limits>

using namespace std;

long long modExp(long long A, long long B, long long C) {

    if (B == 0) 
    {
        return 1; // A^0 = 1 (��� ���� 0������ 1)
    }

    long long HalfValue = modExp(A, B / 2, C);
    long long ResultValue = (HalfValue * HalfValue) % C;

    if (B % 2 != 0) 
    { // B�� Ȧ���� ���
        ResultValue = (ResultValue * A) % C;
    }

    return ResultValue;
}

int main() {
    long long A, B, C;
    cin >> A >> B >> C;

    cout << modExp(A, B, C) << endl;

    return 0;
}
