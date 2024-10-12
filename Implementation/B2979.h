#pragma once

#include <iostream>
#include <vector>

void Solve(int A, int B, int C, std::vector<std::pair<int, int>> trucks)
{
    std::vector<size_t> CarCounts(100, 0u);
    for (std::pair<int, int> TimeInterval : trucks)
    {
        for (size_t i = TimeInterval.first; i < TimeInterval.second; ++i)
        {
            CarCounts[i] += 1u;
        }
    }

    size_t Fee = 0;
    for (size_t i = 0; i < 100; ++i)
    {
        switch (CarCounts[i])
        {
            case 1:
                Fee += A * 1;
            break;
            case 2:
                Fee += B * 2;
            break;
            case 3:
                Fee += C * 3;
            break;
            default:
            break;
        }
    }

    std::cout << Fee << std::endl;
}

int main() {
    int A, B, C;
    std::cin >> A >> B >> C;

    std::vector<std::pair<int, int>> trucks(3);
    for (int i = 0; i < 3; ++i) {
        std::cin >> trucks[i].first >> trucks[i].second;
    }

    Solve(A, B, C, trucks);

    return 0;
}
