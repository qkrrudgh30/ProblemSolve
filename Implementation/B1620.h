#pragma once

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

void Solve(int N, int M, const vector<string>& pokemonList, const vector<string>& queries) 
{
    // 포켓몬 이름 -> 번호 맵 생성
    unordered_map<string, int> MonstersMap;
    for (int i = 0; i < N; ++i) 
    {
        MonstersMap[pokemonList[i]] = i + 1;
    }

    // 질의 처리
    for (const string& Query : queries) 
    {
        if (isdigit(Query[0]) == true) 
        {
            int Index = stoi(Query) - 1;
            cout << pokemonList[Index] << endl;
        }
        else 
        {
            cout << MonstersMap[Query] << endl;
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<string> pokemonList(N);
    for (int i = 0; i < N; ++i) {
        cin >> pokemonList[i];
    }

    vector<string> queries(M);
    for (int i = 0; i < M; ++i) {
        cin >> queries[i];
    }

    Solve(N, M, pokemonList, queries);

    return 0;
}
