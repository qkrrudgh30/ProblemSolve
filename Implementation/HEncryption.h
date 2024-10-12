#pragma once

#include <string>

using namespace std;

string encryption(string s)
{
    // Step 1: ���� ����
    s.erase(remove(s.begin(), s.end(), ' '), s.end());
    size_t StringLength = s.length();

    // Step 2: ��� �� ���
    size_t RowCount = floor(sqrt(StringLength));
    size_t ColumnCount = ceil(sqrt(StringLength));
    if (RowCount * ColumnCount < StringLength)
    {
        RowCount = ColumnCount;
    }

    // Step 3: �׸��忡 ���� �߰� �� �� ���� ��ȣȭ
    string EncryptedString;
    for (size_t col = 0; col < ColumnCount; ++col)
    {
        for (size_t row = 0; row < RowCount; ++row)
        {
            size_t i = row * ColumnCount + col;
            if (i < StringLength)
            {
                EncryptedString += s[i];
            }
        }

        if (col < ColumnCount - 1)
        {
            EncryptedString += ' ';
        }
    }

    return EncryptedString;
}
