#pragma once

#include <iostream>
#include <string>

using namespace std;

void Solve(const string& input) 
{
    string ResultString;

    for (char Character : input) 
    {
        if ('A' <= Character && Character <= 'Z') 
        {
            ResultString += (Character - 'A' + 13) % 26 + 'A';
        }
        else if ('a' <= Character && Character <= 'z') 
        {
            ResultString += (Character - 'a' + 13) % 26 + 'a';
        }
        else 
        {
            ResultString += Character;
        }
    }

    cout << ResultString << endl;
}

int main() {
    string input;
    getline(cin, input); // 전체 입력을 한 줄로 받음

    Solve(input);

    return 0;
}
