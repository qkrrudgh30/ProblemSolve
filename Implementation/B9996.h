#pragma once

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void Solve(int N, const string& pattern, const vector<string>& files) {
    size_t StartMarkPosition = pattern.find('*');
    string PrefixString = pattern.substr(0, StartMarkPosition);
    string SuffixString = pattern.substr(StartMarkPosition + 1);

    for (const string& FileName : files) 
    {
        if (FileName.size() < PrefixString.size() + SuffixString.size()) 
        {
            cout << "NE" << endl;
        }
        else 
        {
            if (FileName.substr(0, PrefixString.size()) == PrefixString &&
                FileName.substr(FileName.size() - SuffixString.size()) == SuffixString) 
            {
                cout << "DA" << endl;
            }
            else 
            {
                cout << "NE" << endl;
            }
        }
    }
}

int main() {
    int N;
    cin >> N;
    string pattern;
    cin >> pattern;

    vector<string> files(N);
    for (int i = 0; i < N; ++i) {
        cin >> files[i];
    }

    Solve(N, pattern, files);

    return 0;
}
