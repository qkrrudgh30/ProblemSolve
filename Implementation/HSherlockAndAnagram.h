/*

�� ���ڿ��� ������ �ֳʱ׷�(anagram)�̶��, 
�� ���ڿ��� ���ڵ��� ��迭�Ͽ� �ٸ� ���ڿ��� ���� �� �ִ� ����Դϴ�. 
�־��� ���ڿ����� �ֳʱ׷��� �Ǵ� �κ� ���ڿ� ���� ������ ���ϴ� ���α׷��� �ۼ��ϼ���.

�Լ� ����
	int sherlockAndAnagrams(string s) �Լ��� �ۼ��մϴ�. 
	�� �Լ��� ���ڿ� s�� �Է¹޾�, �ֳʱ׷��� �Ǵ� �κ� ���ڿ� ���� ������ ��ȯ�մϴ�.

�Է� ����
	ù ��° �ٿ� ���� q�� �־����ϴ�. (������ ����)
	���� q���� �ٿ� ���ڿ� s�� �־����ϴ�.

��� ����
	�������� �ֳʱ׷��� �Ǵ� �κ� ���ڿ� ���� ������ ����մϴ�.

����
	�Է� ���� 1
		2
		abba
		abcd
	��� ���� 1
		4
		0
	����
		ù ��° ���� abba������ �ֳʱ׷� ���� [a, a], [ab, ba], [b, b], [abb, bba]�� �� 4���� �ֽ��ϴ�.
		�� ��° ���� abcd�� �ֳʱ׷� ���� �����ϴ�.

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

