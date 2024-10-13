/*

두 문자열이 서로의 애너그램(anagram)이라면, 
한 문자열의 문자들을 재배열하여 다른 문자열을 만들 수 있는 경우입니다. 
주어진 문자열에서 애너그램이 되는 부분 문자열 쌍의 개수를 구하는 프로그램을 작성하세요.

함수 설명
	int sherlockAndAnagrams(string s) 함수를 작성합니다. 
	이 함수는 문자열 s를 입력받아, 애너그램이 되는 부분 문자열 쌍의 개수를 반환합니다.

입력 형식
	첫 번째 줄에 정수 q가 주어집니다. (쿼리의 개수)
	이후 q개의 줄에 문자열 s가 주어집니다.

출력 형식
	쿼리마다 애너그램이 되는 부분 문자열 쌍의 개수를 출력합니다.

예제
	입력 예제 1
		2
		abba
		abcd
	출력 예제 1
		4
		0
	설명
		첫 번째 쿼리 abba에서는 애너그램 쌍이 [a, a], [ab, ba], [b, b], [abb, bba]로 총 4개가 있습니다.
		두 번째 쿼리 abcd는 애너그램 쌍이 없습니다.

*/

#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>

int sherlockAndAnagrams(std::string s) {
    std::unordered_map<std::string, size_t> SubstringFrequencyMap;
    size_t StringLength = s.length();
    size_t AnagramPairCount = 0u;

    for (size_t PivotPosition = 0u; PivotPosition < StringLength; ++PivotPosition)
    {
        for (size_t EndPosition = 1u; EndPosition <= StringLength - PivotPosition; ++EndPosition)
        {
            std::string SubString = s.substr(PivotPosition, EndPosition);
            std::sort(SubString.begin(), SubString.end());
            SubstringFrequencyMap[SubString]++;
        }
    }

    for (auto& SubstringFrequency : SubstringFrequencyMap) 
    {
        size_t Frequency = SubstringFrequency.second;
        if (2u <= Frequency)
        {
            size_t Combination = (Frequency * (Frequency - 1)) / 2;
            AnagramPairCount += Combination;
        }
    }

    return AnagramPairCount;
}

