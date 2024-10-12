#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void Solve(int N, vector<string>& names) 
{
    map<char, int> FirstLetterCounts;

    // �� ���� ù ���ڸ� ī��Ʈ
    for (const string& name : names) 
    {
        char firstLetter = name[0];
        FirstLetterCounts[firstLetter]++;
    }

    vector<char> ResultFirstLetters;

    // 5�� �̻��� ���� ù ���ڸ� ã��
    for (const auto& FirstLetterCount : FirstLetterCounts) 
    {
        if (FirstLetterCount.second >= 5)
        {
            ResultFirstLetters.push_back(FirstLetterCount.first);
        }
    }

    // ��� ���
    if (ResultFirstLetters.empty() == true) 
    {
        cout << "PREDAJA" << endl;
    }
    else 
    {
        sort(ResultFirstLetters.begin(), ResultFirstLetters.end());

        for (char ResultFirstLetter : ResultFirstLetters) 
        {
            cout << ResultFirstLetter;
        }

        cout << endl;
    }
}

int main() {
    int N;
    cin >> N;

    vector<string> names(N);
    for (int i = 0; i < N; ++i) {
        cin >> names[i];
    }

    Solve(N, names);

    return 0;
}
