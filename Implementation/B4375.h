#pragma once


#include <iostream>

using namespace std;

void findSmallestAllOnesMultiple(int n) 
{
    int Number = 1;  // 초기 수를 1로 시작
    int Length = 1;  // 자릿수를 추적할 변수

    while (Number % n != 0) 
    {  // 나머지가 0이 될 때까지 반복
        Number = (Number * 10 + 1) % n; // 새로운 '111...1' 생성 후 나머지 연산
        ++Length; // 자릿수 증가
    }

    cout << Length << endl; // n의 배수가 될 때의 자릿수 출력
}

int main() {
    int n;

    while (cin >> n) { // 여러 개의 테스트 케이스를 읽음
        findSmallestAllOnesMultiple(n);
    }

    return 0;
}
