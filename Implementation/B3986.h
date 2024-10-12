#pragma once

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isGoodWord(const string& word) {
    stack<char> Stack;
    for (char W : word) 
    {
        if (Stack.empty() == false && Stack.top() == W) 
        {
            Stack.pop(); // 짝을 이루는 경우 제거
        }
        else 
        {
            Stack.push(W); // 짝을 이루지 못하면 스택에 추가
        }
    }

    return Stack.empty() == true; // 스택이 비어 있으면 좋은 단어
}

int main() {
    int N;
    cin >> N;

    int goodWordCount = 0;
    for (int i = 0; i < N; ++i) {
        string word;
        cin >> word;
        if (isGoodWord(word)) {
            ++goodWordCount;
        }
    }

    cout << goodWordCount << endl;
    return 0;
}
