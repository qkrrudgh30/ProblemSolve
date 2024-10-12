#pragma once

#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

void makePalindrome(const string& name) {
    vector<int> AlphabetCounts(26, 0);
    for (char Alphabet : name) 
    {
        ++AlphabetCounts[Alphabet - 'A'];
    }

    size_t OddCount = 0;
    char OddCountAlphabat = 0;
    for (int i = 0; i < 26; ++i) 
    {
        if (AlphabetCounts[i] % 2 != 0) 
        {
            OddCount++;
            OddCountAlphabat = 'A' + i;
        }
    }

    if (1 < OddCount) 
    {
        cout << "I'm Sorry Hansoo" << endl;
        return;
    }

    string PrefixString = "", SuffixString = "";
    for (int i = 0; i < 26; ++i) 
    {
        int HalfAlphabatCount = AlphabetCounts[i] / 2;
        PrefixString += string(HalfAlphabatCount, 'A' + i);
    }

    SuffixString = PrefixString;
    reverse(SuffixString.begin(), SuffixString.end());

    if (OddCount == 1) 
    {
        PrefixString += OddCountAlphabat;
    }

    cout << PrefixString + SuffixString << endl;
}

int main() {
    string name;
    cin >> name;
    makePalindrome(name);
    return 0;
}
