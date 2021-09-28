#pragma once
#include <iostream>
class TokenCounter
{
private: 
	std::string substr;
	std::string buffer;
	size_t count;

public:
	TokenCounter(const std::string &i_substr);
	~TokenCounter();
	size_t GetTokenCount() const;
	void operator()(char c);
};