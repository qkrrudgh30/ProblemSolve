#include <iostream>


#include "Canvas.h"

using namespace std;

int main()
{
    size_t N = 9;
    size_t R = 7;

    CCombination C(N, R);
    for (size_t i = 0; i < N; ++i)
    {
        cin >> C.InputVector[i];
    }
    //sort(C.InputVector.begin(), C.InputVector.end());

    C.InvokeCombinationSimulation();

    return 0;
}
