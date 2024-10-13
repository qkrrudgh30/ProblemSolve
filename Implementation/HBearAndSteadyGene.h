/*

유전자 문자열이 주어졌을 때, 
각각의 문자가 문자열 내에 같은 횟수로 등장하는 문자열을 "안정적"이라고 합니다. 
예를 들어, GAGA, TGAT 등은 모두 안정적입니다.
곰 유전학을 연구하는 과학자 Limak는 주어진 유전자 문자열을 안정적으로 만들기 위해 
한 부분 문자열을 선택하고, 그 부분 문자열을 다른 문자열로 바꾸는 방법을 찾고자 합니다. 
주어진 문자열에서 안정적인 문자열로 만들기 위해 대체해야 하는 최소 부분 문자열의 길이를 구하세요.

예시
	입력: 8, GAAATAAA
	출력: 5
	설명: "AAATA" 부분 문자열을 "TTCCG"으로 대체하면 안정적인 문자열인 GTTCCGAA가 됩니다. 
		대체된 부분 문자열의 길이는 5입니다.

함수 설명
	함수 steadyGene를 완성하세요. 이 함수는 다음과 같은 매개변수를 가집니다:
		gene: 유전자를 나타내는 문자열
		반환값: 최소 부분 문자열의 길이 (안정적인 문자열을 만들기 위해)

제약조건
	문자열의 길이 n은 4로 나누어 떨어집니다.
	문자열은 대문자 알파벳 A, C, T, G로만 구성되어 있습니다.

*/

#pragma once

#include <string>
#include <unordered_map>

int steadyGene(std::string gene) {
    int GeneStringLength = gene.length();
    int IdealCount = GeneStringLength / 4;
    std::unordered_map<char, int> GeneCountMap;

    for (char c : gene) 
    {
        ++GeneCountMap[c];
    }

    int MinGeneStringLength = GeneStringLength;
    int left = 0, right = 0;

    // 슬라이딩 윈도우를 사용하여 유전자 문자열 내의 최소 부분 문자열을 찾는다
    while (right < GeneStringLength) 
    {
        --GeneCountMap[gene[right]];
        ++right;

        // 모든 문자의 개수가 이상적으로 만족될 때까지 왼쪽 포인터를 이동한다
        while (GeneCountMap['A'] <= IdealCount && GeneCountMap['C'] <= IdealCount &&
               GeneCountMap['G'] <= IdealCount && GeneCountMap['T'] <= IdealCount) 
        {
            MinGeneStringLength = std::min(MinGeneStringLength, right - left);
            ++GeneCountMap[gene[left]];
            ++left;
        }
    }

    return MinGeneStringLength;
}
