
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
