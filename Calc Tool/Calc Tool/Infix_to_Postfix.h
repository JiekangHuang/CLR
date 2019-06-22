#include <string>
#include <stack>
#include <vector>
#include <sstream>

bool opGreaterEqual(char top, char ch)
{
	return (top == '*' || top == '/') >= (ch == '*' || ch == '/');
}

std::vector<std::string> Infix_Postfix(std::string str)
{
	std::stack<std::string> st;
	std::vector<std::string> ans;

	int len = str.length();
	for (int i = 0; i < len; i++)
	{
		std::stringstream ss;
		std::string temp;
		char ch = str[i];
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		{
			while (!st.empty() && st.top() != "(")
			{
				if (opGreaterEqual(st.top()[0], ch))
				{
					ans.push_back(st.top());
					st.pop();
				}
				else
					break;
			}
			ss << ch;
			ss >> temp;
			st.push(temp);
		}
		else if (ch == '(')
		{
			ss << ch;
			ss >> temp;
			st.push(temp);
		}
		else if (ch == ')')
		{
			while (!st.empty() && st.top() != "(")
			{
				ans.push_back(st.top());
				st.pop();
			}
			if (!st.empty())
				st.pop();
		}
		else
		{
			while (str[i] == '.' || (str[i] >= 48 && str[i] <= 57))
				temp += str[i++];
			--i;
			ans.push_back(temp);
		}
	}
	while (!st.empty())
	{
		ans.push_back(st.top());
		st.pop();
	}
	return ans;
}