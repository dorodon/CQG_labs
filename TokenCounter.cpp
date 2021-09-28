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
	//std::cout << c;
	//std::cout << buffer.length();
	//std::cout << substr.length();
	if (buffer.length() < substr.length())
	{
		buffer.push_back(c);
		//std::cout << "<: " << buffer << "\n";
	}	
	if (buffer.length() == substr.length())
	{
		if (buffer != substr)
		{
			//std::cout << "!=: " << buffer << " ";
			buffer.erase(0, 1);
			//std::cout << "-> " << buffer << "\n";
		}
		else
		{
			count++;
			//std::cout << "=: " << buffer << " ";
			//std::cout << count;
			buffer.erase(0, substr.length());
			//std::cout << "-> " << buffer << "\n";
		}
	}
}