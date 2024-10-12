
#include <vector>
#include <algorithm>

std::vector<int> climbingLeaderboard(std::vector<int> ranked, std::vector<int> player) {
	std::sort(ranked.begin(), ranked.end(), [](int op1, int op2) -> bool { return op1 > op2; }); // �ߺ� ���� �� ���� �ʼ�.
	ranked.erase(std::unique(ranked.begin(), ranked.end()), ranked.end());
		// unique() �Լ��� �ڷᱸ�� ���� �ߺ� ���Ҹ� �� �ڷ� ������, �ߺ� ���ҵ��� ���� ��ġ iterator�� ��ȯ��.
		// erase() �Լ��� ���� ���� iterator�� �������� ���� ����.
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
			// ranked ���ʹ� 0���� ���� �ϹǷ� +1, ���� ranked ���Ͱ� ����־ �ڵ����� 1���� �Ǵ� ��쿡 n�� -1 �̹Ƿ� ������ ���� +1.
	}

	return ResultRank;
}
