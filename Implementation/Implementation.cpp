
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const size_t MaxWordLength = 100u;
    const size_t AlphabetCount = 26u;
    vector<size_t> AlphabetCountVector;
    AlphabetCountVector.resize(AlphabetCount, 0u);

    string str;
    cin >> str;

    for (size_t i = 0; i < str.length() ; ++i)
    {
        ++AlphabetCountVector[str[i] - 'a'];
    }

    for (size_t i = 0; i < AlphabetCount; ++i)
    {
        cout << AlphabetCountVector[i] << " ";
    }
    
}
