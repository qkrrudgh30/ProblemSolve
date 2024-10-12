/*
매직 스퀘어는 모든 행, 열, 대각선의 합이 같은 수인 3×3 행렬을 의미합니다. 
주어진 행렬 s를 매직 스퀘어로 변환하기 위해 각 숫자를 다른 숫자로 변경할 때, 변경 비용을 최소화하는 문제입니다.

1부터 9까지의 서로 다른 숫자를 사용해야 하며, 변경 비용은 | 𝑎 − 𝑏 | 입니다.
주어진 행렬 s를 최소 비용으로 매직 스퀘어로 변환하는 데 필요한 비용을 구하세요.

입력 형식
3개의 줄에 걸쳐서 각각 세 개의 정수로 이루어진 3×3 행렬 s가 주어집니다.

출력 형식
매직 스퀘어로 변환하는 데 필요한 최소 비용을 출력하세요.

제약 조건
입력은 항상 3×3 행렬입니다.

입력 예시 0
4 9 2
3 5 7
8 1 5
출력 예시 0
1

설명 0
가장 오른쪽 아래의 값을 5에서 9로 변경하면 최소 비용으로 매직 스퀘어가 됩니다.

입력 예시 1
4 8 2
4 5 7
6 1 6
출력 예시 1
4

*/

#pragma once

#include <vector>
#include <algorithm> // sort()
#include <limits> // UINT64_MAX

bool CheckMagicSquare(std::vector<int> InDigits)
{
	static const int MagicConstant = 15;
	return (InDigits[0] + InDigits[1] + InDigits[2] == MagicConstant &&
		InDigits[3] + InDigits[4] + InDigits[5] == MagicConstant &&
		InDigits[6] + InDigits[7] + InDigits[8] == MagicConstant &&
		InDigits[0] + InDigits[3] + InDigits[6] == MagicConstant &&
		InDigits[1] + InDigits[4] + InDigits[7] == MagicConstant &&
		InDigits[2] + InDigits[5] + InDigits[8] == MagicConstant &&
		InDigits[0] + InDigits[4] + InDigits[8] == MagicConstant &&
		InDigits[2] + InDigits[4] + InDigits[6] == MagicConstant);
}

int CalculateCost(std::vector<std::vector<int>>& InSquare, std::vector<int>& InMagicSquare)
{
	int Cost = 0;
	for (size_t i = 0u; i < 3; ++i)
	{
		for (size_t j = 0u; j < 3; ++j)
		{
			Cost += std::abs(InSquare[i][j] - InMagicSquare[i * 3 + j]);
		}
	}

	return Cost;
}

int formingMagicSquare(std::vector<std::vector<int>> s) {
	std::vector<int> Digits = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::sort(Digits.begin(), Digits.end()); // 순열 전에 정렬하여 모든 경우의 수를 만들어 낼 수 있게끔 함.
	size_t MinCost = UINT64_MAX;

	do {

		if (CheckMagicSquare(Digits) == true)
		{
			int CalculatedCost = CalculateCost(s, Digits);
			MinCost = MinCost < CalculatedCost ? MinCost : CalculatedCost;
		}

	} while (std::next_permutation(Digits.begin(), Digits.end())); // 순열을 계속 생성

	return MinCost;
}

