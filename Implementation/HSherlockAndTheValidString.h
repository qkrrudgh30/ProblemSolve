/*

셜록은 문자열이 모든 문자가 동일한 횟수만큼 나타나면 유효하다고 생각합니다. 
또한, 한 문자를 제거하여 나머지 문자가 동일한 횟수로 나타나게 할 수 있으면 유효하다고 생각합니다. 
문자열 s가 주어졌을 때, 문자열이 유효하면 "YES"를, 그렇지 않으면 "NO"를 반환하는 함수를 작성하세요.

함수 설명
	isValid 함수는 다음과 같은 매개변수를 갖습니다:
		string s: 입력 문자열
		반환 값: 문자열이 유효하면 "YES", 유효하지 않으면 "NO"를 반환합니다.

입력 형식
	문자열 s가 주어집니다.

제약 사항
	문자열 s는 알파벳 소문자로만 이루어져 있습니다.

예제 입력 및 출력
	입력 예시 0
		aabbcd
	출력 예시 0
		NO

	입력 예시 1
		aabbccddeefghi
	출력 예시 1
		NO

	입력 예시 2
		abcdefghhgfedecba
	출력 예시 2
		YES

*/

#pragma once

#include <string>
#include <unordered_map>

std::string isValid(std::string s) {
    std::unordered_map<char, int> FrequencyMap;

    for (char c : s) 
    {
        ++FrequencyMap[c];
    }

    std::unordered_map<int, int> FrequencyCountMap;
    for (auto& entry : FrequencyMap) 
    {
        ++FrequencyCountMap[entry.second];
    }

    if (FrequencyCountMap.size() == 1) 
    {
        return "YES";
    }
    else if (FrequencyCountMap.size() == 2) 
    {
        auto it = FrequencyCountMap.begin();
        int LeftFrequency = it->first;
        int LeftCount = it->second;
        it++;
        int RightFrequency = it->first;
        int RightCount = it->second;

        if ((LeftFrequency == 1 && LeftCount == 1) || (RightFrequency == 1 && RightCount == 1)) 
        {
            return "YES";
        }
        if ((abs(LeftFrequency - RightFrequency) == 1) && (LeftCount == 1 || RightCount == 1)) 
        {
            return "YES";
        }
    }

    return "NO";
}
