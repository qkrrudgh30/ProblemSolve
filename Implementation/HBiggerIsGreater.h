/*
사전 순서(lexicographical order)는 문자열을 정렬할 때 일반적으로 사용하는 알파벳 순서입니다. 
문자열을 재배열하여 원래 문자열보다 더 큰 문자열을 만들고, 
그중에서 사전 순으로 가장 작은 문자열을 찾는 것이 목표입니다.

주어진 단어에서 일부 또는 모든 문자를 교환하여 새로운 단어를 생성하세요. 
이 새로운 단어는 다음 두 가지 조건을 만족해야 합니다:

원래 단어보다 사전 순으로 커야 합니다.
위의 조건을 만족하는 단어 중에서 사전 순으로 가장 작은 단어여야 합니다.
예시
입력: w = "dkhc"
가능한 다음 큰 단어: "hcdk"
함수 설명
biggerIsGreater 함수를 작성하세요. 이 함수는 다음 매개변수를 받습니다:

string w: 단어
반환값:

주어진 조건을 만족하는 단어를 반환합니다. 가능하지 않다면 "no answer"를 반환합니다.

예제
입력 예제 1
5
ab
bb
hefg
dhck
dkhc
출력 예제 1
ba
no answer
hegf
dhkc
hcdk

*/

#pragma once

#include <string>
#include <algorithm>

std::string biggerIsGreater(std::string w) {
	if (std::next_permutation(w.begin(), w.end()) == true)
	{
		return w;
	}
	else
	{
		return std::string("no answer");
	}
}
