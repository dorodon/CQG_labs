#include <iostream>
#include <algorithm>
#include "TokenCounter.h"
#include <cassert>

int main()
{
    TokenCounter counter1("aa");
    TokenCounter counter2("aab");
    TokenCounter counter3("aba");
    TokenCounter counter4("a");

    std::string str1 = "aabaabaa";  //3 2 2 6
    std::string str2 = "baaababa";  //1 1 1 5
    std::string str3 = "baaaababa"; //2 1 1 6
    std::string str4 = "aba";       //0 0 0 0

    assert(for_each(str1.begin(), str1.end(), counter1).GetTokenCount() == 3);
    assert(for_each(str1.begin(), str1.end(), counter2).GetTokenCount() == 2);
    assert(for_each(str1.begin(), str1.end(), counter3).GetTokenCount() == 2);
    assert(for_each(str1.begin(), str1.end(), counter4).GetTokenCount() == 6);

    assert(for_each(str2.begin(), str2.end(), counter1).GetTokenCount() == 1);
    assert(for_each(str2.begin(), str2.end(), counter2).GetTokenCount() == 1);
    assert(for_each(str2.begin(), str2.end(), counter3).GetTokenCount() == 1);
    assert(for_each(str2.begin(), str2.end(), counter4).GetTokenCount() == 5);

    assert(for_each(str3.begin(), str3.end(), counter1).GetTokenCount() == 2);
    assert(for_each(str3.begin(), str3.end(), counter2).GetTokenCount() == 1);
    assert(for_each(str3.begin(), str3.end(), counter3).GetTokenCount() == 1);
    assert(for_each(str3.begin(), str3.end(), counter4).GetTokenCount() == 6);

    assert(for_each(str4.begin(), str4.end(), counter1).GetTokenCount() == 0);
    assert(for_each(str4.begin(), str4.end(), counter2).GetTokenCount() == 0);
    assert(for_each(str4.begin(), str4.end(), counter3).GetTokenCount() == 0);
    assert(for_each(str4.begin(), str4.end(), counter4).GetTokenCount() == 0);

    return 0;
}