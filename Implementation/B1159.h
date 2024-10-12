#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void Solve(int N, vector<string>& names) 
{
    map<char, int> FirstLetterCounts;

    // 각 성의 첫 글자를 카운트
    for (const string& name : names) 
    {
        char firstLetter = name[0];
        FirstLetterCounts[firstLetter]++;
    }

    vector<char> ResultFirstLetters;

    // 5명 이상인 성의 첫 글자를 찾음
    for (const auto& FirstLetterCount : FirstLetterCounts) 
    {
        if (FirstLetterCount.second >= 5)
        {
            ResultFirstLetters.push_back(FirstLetterCount.first);
        }
    }

    // 결과 출력
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
