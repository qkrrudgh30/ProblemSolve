/*

���ڷ� ǥ���� �ð��� ���� �ܾ�� ��ȯ�մϴ�.
��Ȯ�� �ð��� ���: o' clock�� ����մϴ�.
�������� 30�� �������� �ð��� past�� ����մϴ�.
30�� ������ �ð��� to�� ����մϴ�.
�Ʒ� ���Ŀ� ���� �ð��� �ܾ�� ��ȯ�Ͽ� ����ϼ���.
����
    1���� "minute"��, 2�� �̻��� "minutes"�� ǥ���մϴ�.
    15���� "quarter", 30���� "half"�� ǥ���մϴ�.

�Լ� ����
    timeInWords �Լ��� �ۼ��ϼ���. �� �Լ��� ���� �Ű������� �޽��ϴ�:
        int h: �ð�
        int m: ��
        ��ȯ��: �־��� �ð��� �ܾ�� ǥ���� ���ڿ��� ��ȯ�մϴ�.

�Է� ����
    ù ��: �ð�(h)
    ��° ��: ��(m)

���� ����
    1��h��12
    0��m<60

����
    �Է� ���� 1
        5
        47
    ��� ���� 1
        thirteen minutes to six

    �Է� ���� 2
        3
        00
    ��� ���� 2
        three o' clock

    �Է� ���� 3
        7
        15
    ��� ���� 3
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