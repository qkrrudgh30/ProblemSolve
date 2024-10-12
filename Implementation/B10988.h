#pragma once

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void Solve(const string& str) 
{
    string ReversedStr = str;
    reverse(ReversedStr.begin(), ReversedStr.end());

    if (str == ReversedStr) 
    {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

int main() 
{
    string str;
    cin >> str;

    Solve(str);

    return 0;
}
