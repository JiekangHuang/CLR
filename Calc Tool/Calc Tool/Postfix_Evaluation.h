#include <string>
#include <stack>
#include <vector>
#include <sstream>

void GetTop1_2(std::stack<std::string> &st, std::string op)
{
	std::stringstream ss;
	double arr[2], sum = 0;
	std::string temp;
	for (int i = 1; i >= 0; i--)
	{
		temp = st.top();
		st.pop();
		ss << temp;
		ss >> arr[i];
		ss.str("");
		ss.clear();
	}
	if (op == "+")
		sum = arr[0] + arr[1];
	else if (op == "-")
		sum = arr[0] - arr[1];
	else if (op == "*")
		sum = arr[0] * arr[1];
	else if (op == "/")
		sum = arr[0] / arr[1];
	ss << sum;
	ss >> temp;
	st.push(temp);
}

std::string Postfix_Evaluation(std::vector<std::string> post)
{
	std::stack<std::string> st;
	std::string str;
	int size = post.size();
	for (int i = 0; i < size; i++)
	{
		str = post.at(i);
		if (str == "+" || str == "-" || str == "*" || str == "/")
			GetTop1_2(st, str);
		else
			st.push(str);
	}
	return st.top();
}