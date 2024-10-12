/*
게임 플레이어가 리더보드의 상위권에 오르고 자신의 순위를 추적하고자 합니다. 
이 게임은 밀집 순위를 사용하며, 리더보드는 다음과 같이 작동합니다:

    - 최고 점수를 가진 플레이어가 1위입니다.
    - 점수가 동일한 플레이어는 같은 순위를 가지며, 그다음 순위는 바로 뒤의 순위 번호를 받습니다.

예시
    - 리더보드 점수: [100, 100, 50, 40, 40, 20, 10]
    - 플레이어의 점수: [5, 25, 50, 120]

각 게임 이후의 순위는 다음과 같습니다:
    - 점수 5: 순위 6
    - 점수 25: 순위 4
    - 점수 50: 순위 2
    - 점수 120: 순위 1

함수 설명
climbingLeaderboard 함수는 다음의 매개변수를 가집니다:
    - int ranked[n]: 리더보드 점수 리스트
    - int player[m]: 플레이어의 점수 리스트

반환값:
    - int[m]: 각 게임 후의 플레이어 순위

제약 조건
1 ≤ 𝑛, 𝑚 ≤ 2 × 10^5
0 ≤ ranked[𝑖] ≤ 10^9

ranked는 내림차순으로 정렬되어 있습니다.
player는 오름차순으로 정렬되어 있습니다.

*/

#pragma once

#include <vector>
#include <algorithm>

std::vector<int> climbingLeaderboard(std::vector<int> ranked, std::vector<int> player) {
	std::sort(ranked.begin(), ranked.end(), [](int op1, int op2) -> bool { return op1 > op2; }); // 중복 제거 전 정렬 필수.
	ranked.erase(std::unique(ranked.begin(), ranked.end()), ranked.end());
	// unique() 함수는 자료구조 내의 중복 원소를 맨 뒤로 보내고, 중복 원소들의 시작 위치 iterator를 반환함.
	// erase() 함수는 전달 받은 iterator를 기준으로 원소 삭제.
	std::vector<int> ResultRank;
	int Count = ranked.size();

	int Rank = Count - 1;
	for (int CurrentPlayerScore : player)
	{
		while (0 <= Rank && ranked[Rank] <= CurrentPlayerScore)
		{
			--Rank;
		}

		ResultRank.push_back(Rank + 2);
		// ranked 벡터는 0부터 시작 하므로 +1, 만약 ranked 벡터가 비어있어서 자동으로 1위가 되는 경우에 n은 -1 이므로 보정을 위해 +1.
	}

	return ResultRank;
}

