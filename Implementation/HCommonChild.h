/*

두 문자열이 주어졌을 때, 한 문자열의 일부 문자를 삭제하여 다른 문자열을 형성할 수 있다면, 
이 문자열을 다른 문자열의 "자식 문자열"이라고 합니다. 
문자의 순서는 변경할 수 없습니다. 
두 개의 길이가 동일한 문자열이 주어졌을 때, 
두 문자열 모두로부터 만들 수 있는 가장 긴 자식 문자열의 길이를 구하세요.

예시
	예시 1:
	입력: HARRY, SALLY
	출력: 2
	설명: 가장 긴 공통 자식 문자열은 AY로 길이는 2입니다.
	예시 2:

	입력: AA, BB
	출력: 0
	설명: 두 문자열은 공통된 문자가 없으므로 길이는 0입니다.

함수 설명
	함수 commonChild를 완성하세요. 이 함수는 다음과 같은 매개변수를 가집니다:
		s1: 첫 번째 문자열
		s2: 두 번째 문자열
		반환값: 두 문자열의 가장 긴 공통 자식 문자열의 길이를 나타내는 정수

제약조건
	두 문자열의 길이는 1 ≤ |s1|, |s2| ≤ 500 입니다.
	모든 문자는 대문자이며, ASCII [A-Z] 범위 내에 있습니다.

*/

#pragma once

#include <string>
#include <vector>

int commonChild(std::string s1, std::string s2) {
	int n = s1.size();
	std::vector<std::vector<int>> DP(n + 1, std::vector<int>(n + 1, 0));

	for (int i = 1; i <= n; ++i) 
	{
		for (int j = 1; j <= n; ++j) 
		{
			if (s1[i - 1] == s2[j - 1]) 
			{
				DP[i][j] = DP[i - 1][j - 1] + 1;
			}
			else 
			{
				DP[i][j] = std::max(DP[i - 1][j], DP[i][j - 1]);
			}
		}
	}

	return DP[n][n];
}