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