/*
정수 n의 팩토리얼, 즉 n!은 다음과 같이 정의됩니다: n!=n×(n−1)×(n−2)×⋯×1
주어진 정수 n에 대해 팩토리얼 값을 계산하고 출력하세요.

예를 들어, n=5인 경우, 5!=5×4×3×2×1=120이 됩니다.

예시
입력 예시 1
	5
출력 예시 1
	120
*/

#pragma once

#include <stack>

void ProductForFactorial(std::stack<int>& InReversedResult, int InNumber)
{
	std::stack<int> NewReversedResult;
	int Carry = 0;

	while (InReversedResult.empty() == false)
	{
		int Digit = InReversedResult.top();
		InReversedResult.pop();

		int Product = Digit * InNumber + Carry;
		int NewDigit = (Product) % 10;
		Carry = (Product) / 10;

		NewReversedResult.push(NewDigit);
	}

	while (0 < Carry)
	{
		NewReversedResult.push(Carry % 10);
		Carry /= 10;
	}

	while (NewReversedResult.empty() == false)
	{
		InReversedResult.push(NewReversedResult.top());
		NewReversedResult.pop();
	}
}

void extraLongFactorials(int n) {
	std::stack<int> ReversedResult;
	ReversedResult.push(1);

	for (int i = 2; i <= n; ++i)
	{
		ProductForFactorial(ReversedResult, i);
	}

	std::stack<int> Result;
	while (ReversedResult.empty() == false)
	{
		Result.push(ReversedResult.top());
		ReversedResult.pop();
	}

	while (Result.empty() == false)
	{
		printf("%d", Result.top());
		Result.pop();
	}
	printf("\n");
}
