#pragma once

#include <iostream>
#include <vector>

using namespace std;

void Solve(string Characters)
{
    vector<size_t> Count(26, 0);
    for (char Character : Characters)
    {
        ++Count[Character - 'a'];
    }

    for (size_t i = 0; i < 26; ++i)
    {
        cout << Count[i] << " ";
    }
}

int main()
{
    string str;

    cin >> str;

    Solve(str);

    return 0;
}
