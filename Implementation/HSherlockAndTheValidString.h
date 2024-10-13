/*

�ȷ��� ���ڿ��� ��� ���ڰ� ������ Ƚ����ŭ ��Ÿ���� ��ȿ�ϴٰ� �����մϴ�. 
����, �� ���ڸ� �����Ͽ� ������ ���ڰ� ������ Ƚ���� ��Ÿ���� �� �� ������ ��ȿ�ϴٰ� �����մϴ�. 
���ڿ� s�� �־����� ��, ���ڿ��� ��ȿ�ϸ� "YES"��, �׷��� ������ "NO"�� ��ȯ�ϴ� �Լ��� �ۼ��ϼ���.

�Լ� ����
	isValid �Լ��� ������ ���� �Ű������� �����ϴ�:
		string s: �Է� ���ڿ�
		��ȯ ��: ���ڿ��� ��ȿ�ϸ� "YES", ��ȿ���� ������ "NO"�� ��ȯ�մϴ�.

�Է� ����
	���ڿ� s�� �־����ϴ�.

���� ����
	���ڿ� s�� ���ĺ� �ҹ��ڷθ� �̷���� �ֽ��ϴ�.

���� �Է� �� ���
	�Է� ���� 0
		aabbcd
	��� ���� 0
		NO

	�Է� ���� 1
		aabbccddeefghi
	��� ���� 1
		NO

	�Է� ���� 2
		abcdefghhgfedecba
	��� ���� 2
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
