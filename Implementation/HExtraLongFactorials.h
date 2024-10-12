#pragma once

#include <iostream>
#include <stack>

using namespace std;

void Factoricl(stack<int>& InResult, int InNumber) {
    stack<int> TempStack;
    int Carry = 0;

    while (!InResult.empty()) {
        int Digit = InResult.top();
        InResult.pop();

        int Product = Digit * InNumber + Carry;
        TempStack.push(Product % 10);
        Carry = Product / 10;
    }

    while (Carry > 0) {
        TempStack.push(Carry % 10);
        Carry /= 10;
    }

    // Move results back to InResult in reverse order
    while (!TempStack.empty()) {
        InResult.push(TempStack.top());
        TempStack.pop();
    }
}

void extraLongFactorials(int n) {
    stack<int> ReversedResult;
    ReversedResult.push(1);

    for (int i = 2; i <= n; ++i) {
        Factoricl(ReversedResult, i);
    }

    // Print directly from the stack without extra copying
    stack<int> OutputStack;
    while (!ReversedResult.empty()) {
        OutputStack.push(ReversedResult.top());
        ReversedResult.pop();
    }

    while (!OutputStack.empty()) {
        cout << OutputStack.top();
        OutputStack.pop();
    }
    cout << endl;
}
