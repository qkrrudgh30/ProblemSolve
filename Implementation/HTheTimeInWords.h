/*

숫자로 표현된 시간을 영어 단어로 변환합니다.
정확한 시각일 경우: o' clock을 사용합니다.
정각에서 30분 전까지의 시간은 past를 사용합니다.
30분 이후의 시간은 to를 사용합니다.
아래 형식에 맞춰 시간을 단어로 변환하여 출력하세요.
조건
    1분은 "minute"로, 2분 이상은 "minutes"로 표현합니다.
    15분은 "quarter", 30분은 "half"로 표현합니다.

함수 설명
    timeInWords 함수를 작성하세요. 이 함수는 다음 매개변수를 받습니다:
        int h: 시간
        int m: 분
        반환값: 주어진 시간을 단어로 표현한 문자열을 반환합니다.

입력 형식
    첫 줄: 시간(h)
    둘째 줄: 분(m)

제약 조건
    1≤h≤12
    0≤m<60

예제
    입력 예제 1
        5
        47
    출력 예제 1
        thirteen minutes to six

    입력 예제 2
        3
        00
    출력 예제 2
        three o' clock

    입력 예제 3
        7
        15
    출력 예제 3
        quarter past seven

*/

#pragma once

#include <string>
#include <vector>

using namespace std;

string timeInWords(int h, int m) {
    vector<string> numbers = { "", "one", "two", "three", "four", "five", "six",
                              "seven", "eight", "nine", "ten", "eleven", "twelve",
                              "thirteen", "fourteen", "quarter", "sixteen", "seventeen",
                              "eighteen", "nineteen", "twenty", "twenty one", "twenty two",
                              "twenty three", "twenty four", "twenty five", "twenty six",
                              "twenty seven", "twenty eight", "twenty nine", "half" };

    if (m == 0) 
    {
        return numbers[h] + " o' clock";
    }
    else if (m == 15 || m == 30) 
    {
        return numbers[m] + " past " + numbers[h];
    }
    else if (m < 30) 
    {
        return numbers[m] + (m == 1 ? " minute past " : " minutes past ") + numbers[h];
    }
    else if (m == 45) 
    {
        return numbers[60 - m] + " to " + numbers[h % 12 + 1];
    }
    else 
    {
        return numbers[60 - m] + ((60 - m) == 1 ? " minute to " : " minutes to ") + numbers[h % 12 + 1];
    }
}