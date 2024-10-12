#pragma once

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Factoricl(stack<int>& InResult, int InNumber)
{
    stack<int> TempStack;
    int Carry = 0;

    while (InResult.empty() == false)
    {
        int Digit = InResult.top();
        InResult.pop();

        int Product = Digit * InNumber + Carry;
        TempStack.push(Product % 10);
        Carry = Product / 10;
    }

    while (0 < Carry)
    {
        TempStack.push(Carry % 10);
        Carry /= 10;
    }

    while (TempStack.empty() == false)
    {
        InResult.push(TempStack.top());
        TempStack.pop();
    }
}

void extraLongFactorials(int n)
{
    stack<int> ReversedResult;
    ReversedResult.push(1);

    for (int i = 2; i <= n; ++i)
    {
        Factoricl(ReversedResult, i);
    }

    vector<int> Result;
    while (ReversedResult.empty() == false)
    {
        Result.push_back(ReversedResult.top());
        ReversedResult.pop();
    }

    size_t ResultSize = Result.size();
    for (int i = ResultSize - 1; i >= 0; --i)
    {
        cout << Result[i];
    }
    cout << endl;
}
