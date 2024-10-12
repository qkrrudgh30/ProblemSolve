/*
���� ����(lexicographical order)�� ���ڿ��� ������ �� �Ϲ������� ����ϴ� ���ĺ� �����Դϴ�. 
���ڿ��� ��迭�Ͽ� ���� ���ڿ����� �� ū ���ڿ��� �����, 
���߿��� ���� ������ ���� ���� ���ڿ��� ã�� ���� ��ǥ�Դϴ�.

�־��� �ܾ�� �Ϻ� �Ǵ� ��� ���ڸ� ��ȯ�Ͽ� ���ο� �ܾ �����ϼ���. 
�� ���ο� �ܾ�� ���� �� ���� ������ �����ؾ� �մϴ�:

���� �ܾ�� ���� ������ Ŀ�� �մϴ�.
���� ������ �����ϴ� �ܾ� �߿��� ���� ������ ���� ���� �ܾ�� �մϴ�.
����
�Է�: w = "dkhc"
������ ���� ū �ܾ�: "hcdk"
�Լ� ����
biggerIsGreater �Լ��� �ۼ��ϼ���. �� �Լ��� ���� �Ű������� �޽��ϴ�:

string w: �ܾ�
��ȯ��:

�־��� ������ �����ϴ� �ܾ ��ȯ�մϴ�. �������� �ʴٸ� "no answer"�� ��ȯ�մϴ�.

����
�Է� ���� 1
5
ab
bb
hefg
dhck
dkhc
��� ���� 1
ba
no answer
hegf
dhkc
hcdk

*/

#pragma once

#include <string>
#include <algorithm>

std::string biggerIsGreater(std::string w) {
	if (std::next_permutation(w.begin(), w.end()) == true)
	{
		return w;
	}
	else
	{
		return std::string("no answer");
	}
}
