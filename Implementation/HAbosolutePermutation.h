#pragma once

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

vector<int> absolutePermutation(int n, int k) {
    vector<int> Permutation(n);
    iota(Permutation.begin(), Permutation.end(), 1);

    // next_permutation�� ���� ������ Ž���ϸ� ���� ���� ã��
    do {
        bool bIsAbsolutePermutation = true;

        for (int i = 0; i < n; i++) 
        {
            if (abs(Permutation[i] - (i + 1)) != k) 
            {
                bIsAbsolutePermutation = false;
                break;
            }
        }

        if (bIsAbsolutePermutation == true)
        {
            return Permutation;
        }

    } while (next_permutation(Permutation.begin(), Permutation.end()));

    return { -1 };
}

vector<int> absolutePermutation2(int n, int k) {
    vector<int> Result;

    // Result[i] - i = k, Result[i] = i + k Ȥ�� Result[i] = i + k������. 
    
    if (k > 0 && n % (2 * k) != 0) 
    {
        return { -1 };
    }

    Result.resize(n);

    // k ������ ���� ������ �����մϴ�.
    for (int i = 1; i <= n; i++) {
        if ((i - 1) / k % 2 == 0) {
            Result[i - 1] = i + k;
        }
        else {
            Result[i - 1] = i - k;
        }
    }

    return Result;
}
