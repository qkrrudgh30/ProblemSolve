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
            Stack.pop(); // ¦�� �̷�� ��� ����
        }
        else 
        {
            Stack.push(W); // ¦�� �̷��� ���ϸ� ���ÿ� �߰�
        }
    }

    return Stack.empty() == true; // ������ ��� ������ ���� �ܾ�
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
