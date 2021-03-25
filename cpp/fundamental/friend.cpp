#include <string.h>
#include <iostream>
class CTestString
{
public:
	CTestString()
	{
		memset(m_data, 0, 1024);
	}

	CTestString(const char *str)
	{
		memset(m_data, 0, 1024);
		strcat(m_data, str);
	}

	CTestString& operator = (const char *str)
	{
		memset(m_data, 0, 1024);
		strcat(m_data, str);
		return (*this);
	}
/*
	CTestString operator + (const char *str)
	{
		std::cout << "+1" << std::endl;
		CTestString ts = *this;
		strcat(ts.m_data, str);
		return (ts);
	}
*/
	CTestString operator + (const CTestString& rhs)
	{
		CTestString ts = *this;
		strcat(ts.m_data, rhs.m_data);
		return (ts);
	}
	const char *c_str()
	{
		return (m_data);
	}

private:
	char m_data[1024];
};

CTestString operator + (const CTestString& rhs)
{
	CTestString ts;
//	strcat(ts.m_data, str);
//	strcat(ts.m_data, rhs.m_data);
	return ts;
}


int main()
{
	CTestString ts = "abc";
	ts = "123" + ts ;
	std::cout << ts.c_str();
}
