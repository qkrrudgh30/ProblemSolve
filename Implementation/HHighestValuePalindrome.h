/*

회문(palindrome)은 왼쪽에서 읽으나 오른쪽에서 읽으나 같은 문자열을 뜻합니다. 
예를 들어 madam 또는 0110과 같은 문자열입니다.
숫자 문자열이 주어졌을 때, 특정 개수만큼 숫자를 변경하여 가장 큰 숫자로 이루어진 회문을 만들어야 합니다. 
단, 주어진 변경 가능 횟수 안에서만 변경할 수 있습니다. 
문자열의 길이는 변경할 수 없으며, 높은 자리수에서부터 숫자를 바꿔야 합니다.
문자열로 표현된 숫자와 최대 변경 가능 횟수가 주어졌을 때,
가장 큰 회문을 만들어야 합니다. 
만약 주어진 제약 하에 회문을 만들 수 없다면 -1을 반환합니다.

함수 설명
	highestValuePalindrome 함수는 다음과 같은 매개변수를 갖습니다:
		string s: 숫자를 문자열로 표현한 값
		int n: 문자열의 길이
		int k: 최대 변경 가능 횟수
		반환값: 가장 큰 값의 회문을 표현하는 문자열을 반환하거나, 
				제약을 충족할 수 없는 경우 -1을 반환합니다.

입력 형식
	첫 번째 줄에 두 개의 정수 n과 k가 공백으로 구분되어 주어집니다.
	두 번째 줄에 n자리 숫자로 이루어진 문자열 s가 주어집니다.

제약 사항
	문자열 s의 각 문자는 0에서 9 사이의 숫자입니다.

예제 입력 및 출력
	입력 예시 0
	4 1
	3943
	출력 예시 0
	3993

	입력 예시 1
	6 3
	092282
	출력 예시 1
	992299

	입력 예시 2
	4 1
	0011
	출력 예시 2
	-1

*/

#pragma once

#include <string>
#include <vector>

std::string highestValuePalindrome(std::string s, int n, int k) {
    std::vector<bool> bModified(n, false);

    for (size_t i = 0; i < n / 2; ++i)
    {
        if (s[i] != s[n - i - 1]) 
        {
            s[i] = s[n - i - 1] = std::max(s[i], s[n - i - 1]);
            bModified[i] = true;
            --k;
        }
    }

    if (k < 0) 
    {
        return "-1";
    }

    for (size_t i = 0; i < n / 2 && 0 < k; ++i)
    {
        if (s[i] != '9') 
        {
            if (bModified[i] == true && 1 <= k) 
            {
                s[i] = s[n - i - 1] = '9';
                --k;
            }
            else if (bModified[i] == false && 2 <= k)
            {
                s[i] = s[n - i - 1] = '9';
                k -= 2;
            }
        }
    }

    if (n % 2 == 1 && 0 < k) 
    {
        s[n / 2] = '9';
    }

    return s;
}
