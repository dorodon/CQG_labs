#include "TokenCounter.h"
#include <iostream>

TokenCounter::TokenCounter(const std::string &i_substr)
{
	substr = i_substr;
	buffer = "";
	count = 0;
}

TokenCounter::~TokenCounter()
{
}

size_t TokenCounter::GetTokenCount() const
{
	return count;
}

void TokenCounter::operator()(char c)
{
	if (substr == "") return;
	if (buffer.length() < substr.length())
		buffer.push_back(c);
	if (buffer.length() == substr.length())
	{
		if (buffer != substr)
			buffer.erase(0, 1);
		else
		{
			count++;
			buffer.clear();
		}
	}
}