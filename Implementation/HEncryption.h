/*
영어 텍스트를 다음과 같은 암호화 방식으로 암호화해야 합니다.
먼저, 공백을 제거합니다. 제거 후 텍스트의 길이를 L이라고 합니다.
그런 다음, 텍스트를 행과 열로 이루어진 그리드에 씁니다. 그리드의 행과 열은 다음 조건을 만족합니다:
rows×columns≥L
rows≤columns≤rows+1
조건을 만족하는 여러 그리드가 있을 경우 최소 면적의 그리드를 선택합니다.

암호화된 메시지는 각 열의 문자를 차례로 추출한 후, 각 열의 텍스트를 공백으로 구분하여 만듭니다.
예시
입력: "haveaniceday"
공백을 제거하면 "haveaniceday"가 되고, 길이는 12입니다.
그리드 크기를 계산하면 ≈3.46이므로 3×4 크기의 그리드가 선택됩니다.
have
anic
eday
암호화된 메시지는 각 열의 문자를 차례로 추출하여 "hae and via ecy"입니다.

함수 설명
encryption 함수를 작성하세요. 이 함수는 다음 매개변수를 받습니다:

string s: 암호화할 문자열
반환값:

공백으로 구분된 암호화된 문자열을 반환합니다.
제약 조건
    - 1≤length of s≤81
    - s는 소문자와 공백으로만 이루어져 있습니다.

예제
입력 예제 1
haveaniceday
출력 예제 1
hae and via ecy

입력 예제 2
feedthedog
출력 예제 2
fto ehg ee dd

*/

#pragma once

#include <string>
#include <cmath>


std::string encryption(std::string s) {
	s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

	size_t StringLength = s.length();
	size_t RowCount = static_cast<size_t>(std::floor(std::sqrt(StringLength)));
	size_t ColumnCount = static_cast<size_t>(std::ceil(std::sqrt(StringLength)));
	if (RowCount * ColumnCount < StringLength)
	{
		RowCount = ColumnCount;
	}

	std::string Result;
	for (size_t j = 0; j < ColumnCount; ++j)
	{
		for (size_t i = 0; i < RowCount; ++i)
		{
			size_t D1Index = i * ColumnCount + j;
			if (D1Index < StringLength)
			{
				Result += s[D1Index];
			}
		}

		if (j < ColumnCount - 1)
		{
			Result += " ";
		}
	}

	return Result;
}
