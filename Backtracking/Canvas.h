/*
BJ2309

왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 
일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.
아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 
뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.
아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

중복 없음.
키의 합 -> 순서가 중요하지 않음. 조합.

*/

/* 
CU2608

정보 동아리 회장을 선출하려고 한다.

올해는 단일 후보만 등록하여 찬반 투표를 실시하였다.

n명의 학생이 O, X로 의사 표현을 한다면 나올 수 있는 경우를 모두 출력하시오. -> 2개 중 R개를 뽑는다.

예를 들어 2명이 투표하는 경우 나올 수 있는 경우는

OO

OX ->

XO -> 순서가 중요하다 -> 순열.

XX -> 중복이 가능하다 -> 중복 순열.

이다.

*/

/*
CU2651

극장에 n개의 빈 좌석이 있다.

k명의 관객들이 영화를 보기 위해서 왔다.

이 관객들이 n개의 좌석에 앉을 수 있는 서로 다른 방법의 수를 구하는 프로그램을 작성하시오.

서로 다른 방법의 수 -> 1번자리 2번자리 앉으나, 2번자리 1번자리 앉으나 둘다 1번 2번 착석한거라 동일시 하겠다 -> 조합.

같은 자리에 두명이 앉지는 못함. -> 중복이 아님.

(단, k명의 사람을 서로 구분하지 않는다.)

*/

/*
P외계어사전

PROGRAMMERS-962 행성에 불시착한 우주비행사 머쓱이는 외계행성의 언어를 공부하려고 합니다. 
알파벳이 담긴 배열 spell과 외계어 사전 dic이 매개변수로 주어집니다. 
spell에 담긴 알파벳을 한번씩만 모두 사용한 단어가 dic에 존재한다면 1,
존재하지 않는다면 2를 return하도록 solution 함수를 완성해주세요.

한번씩만 모두 사용한 단어 -> 중복 안됨. 단어라서 순서가 중요하므로 순열.

*/

/*
P옹알이(1)

머쓱이는 태어난 지 6개월 된 조카를 돌보고 있습니다. 
조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음을 최대 한 번씩 사용해 조합한(이어 붙인) 발음밖에 하지 못합니다. 
문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

최대 한 번씩 사용해 -> 중복 안됨.
단어이기 때문에 순서가 중요함 -> 순열.
*/

/*
P삼총사

한국중학교에 다니는 학생들은 각자 정수 번호를 갖고 있습니다. 
이 학교 학생 3명의 정수 번호를 더했을 때 0이 되면 3명의 학생은 삼총사라고 합니다. 
예를 들어, 5명의 학생이 있고, 각각의 정수 번호가 순서대로 -2, 3, 0, 2, -5일 때, 
첫 번째, 세 번째, 네 번째 학생의 정수 번호를 더하면 0이므로 세 학생은 삼총사입니다. 
또한, 두 번째, 네 번째, 다섯 번째 학생의 정수 번호를 더해도 0이므로 세 학생도 삼총사입니다. 
따라서 이 경우 한국중학교에서는 두 가지 방법으로 삼총사를 만들 수 있습니다.
한국중학교 학생들의 번호를 나타내는 정수 배열 number가 매개변수로 주어질 때, 
학생들 중 삼총사를 만들 수 있는 방법의 수를 return 하도록 solution 함수를 완성하세요.

사람이므로 중복 안됨.
순서는 중요하지 않음 -> 조합.

*/

/*
P구슬을 나누는 경우의 수

머쓱이는 구슬을 친구들에게 나누어주려고 합니다. 
구슬은 모두 다르게 생겼습니다. 머쓱이가 갖고 있는 구슬의 개수 balls와 친구들에게 나누어 줄 구슬 개수 share이 매개변수로 주어질 때, 
balls개의 구슬 중 share개의 구슬을 고르는 가능한 모든 경우의 수를 return 하는 solution 함수를 완성해주세요.
제한사항
1 ≤ balls ≤ 30
1 ≤ share ≤ 30
구슬을 고르는 순서는 고려하지 않습니다. -> 조합
share ≤ balls

구슬이 모두 다르게 생겼다 -> 중복 없음.

공식으로 풀리지 않음. 일일히 세야하거나, 5C3을 5C2로 바꾸는 노력이 필요함. 

*/

/*

P두 개 뽑아서 더하기

정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 
만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

서로 다른 인덱스 -> 중복 X
더하면 어차피 같으므로 순서는 상관 없음 -> 조합

*/

#pragma once

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class CCombination
{
	enum { INVALID = -1 };

public:
	CCombination(const size_t InN = INVALID, const size_t InR = INVALID)
		: N(InN)
		, R(InR)
	{
		if (N != INVALID && R != INVALID)
		{
			InputVector.resize(N);
			ResultVector.resize(R);
			VisitVector.resize(N);
		}
		else
		{
			cout << "Invalid N or R." << endl;
		}
	}

	~CCombination()
	{
		InputVector.clear();
		ResultVector.clear();
		VisitVector.clear();
	}

	void InvokeCombinationSimulation()
	{
		if (INVALID == N || INVALID == R)
		{
			cout << "Invalid N or R." << endl;
			return;
		}

		SimulationCombination(0, 0);
	}

	size_t Factorial(const size_t InN)
	{
		if (0 == InN)
		{
			return 1;
		}

		return InN * Factorial(InN - 1);
	}

	size_t CountCombination(const size_t InN, const size_t InR)
	{
		// nCr = nPr / r! = n! / ((n-r)!*r!)
		return Factorial(InN) / (Factorial(InN - InR) * Factorial(InR));
	}

private:
	void SimulationCombination(const size_t CurrentN, const size_t CurrentR)
	{
		if (R == CurrentR)
		{
			if (accumulate(ResultVector.begin(), ResultVector.end(), 0) == 100)
			{
				for (size_t i = 0; i < R; ++i)
				{
					cout << ResultVector[i] << endl;
				}

				exit(0);
			}
		}
		else
		{
			for (size_t i = CurrentN; i < N; ++i)
			{
				if (true == VisitVector[i])
				{
					continue;
				}

				ResultVector[CurrentR] = InputVector[i];
				VisitVector[i] = true;
				SimulationCombination(i, CurrentR + 1);
				VisitVector[i] = false;
			}
		}
	}

public:
	vector<int> InputVector;
	vector<int> ResultVector;
	vector<bool> VisitVector;

	size_t N;
	size_t R;

};

