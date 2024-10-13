/*

������ ���ڿ��� �־����� ��, 
������ ���ڰ� ���ڿ� ���� ���� Ƚ���� �����ϴ� ���ڿ��� "������"�̶�� �մϴ�. 
���� ���, GAGA, TGAT ���� ��� �������Դϴ�.
�� �������� �����ϴ� ������ Limak�� �־��� ������ ���ڿ��� ���������� ����� ���� 
�� �κ� ���ڿ��� �����ϰ�, �� �κ� ���ڿ��� �ٸ� ���ڿ��� �ٲٴ� ����� ã���� �մϴ�. 
�־��� ���ڿ����� �������� ���ڿ��� ����� ���� ��ü�ؾ� �ϴ� �ּ� �κ� ���ڿ��� ���̸� ���ϼ���.

����
	�Է�: 8, GAAATAAA
	���: 5
	����: "AAATA" �κ� ���ڿ��� "TTCCG"���� ��ü�ϸ� �������� ���ڿ��� GTTCCGAA�� �˴ϴ�. 
		��ü�� �κ� ���ڿ��� ���̴� 5�Դϴ�.

�Լ� ����
	�Լ� steadyGene�� �ϼ��ϼ���. �� �Լ��� ������ ���� �Ű������� �����ϴ�:
		gene: �����ڸ� ��Ÿ���� ���ڿ�
		��ȯ��: �ּ� �κ� ���ڿ��� ���� (�������� ���ڿ��� ����� ����)

��������
	���ڿ��� ���� n�� 4�� ������ �������ϴ�.
	���ڿ��� �빮�� ���ĺ� A, C, T, G�θ� �����Ǿ� �ֽ��ϴ�.

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

    // �����̵� �����츦 ����Ͽ� ������ ���ڿ� ���� �ּ� �κ� ���ڿ��� ã�´�
    while (right < GeneStringLength) 
    {
        --GeneCountMap[gene[right]];
        ++right;

        // ��� ������ ������ �̻������� ������ ������ ���� �����͸� �̵��Ѵ�
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
