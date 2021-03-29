#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(string p) {
	string answer = "";
	string u, v;
	int i;
	int open, close;
	int count = 0, right = 0;

	u = v = "";

	if (p.size() == 0)
		return answer;

	for (int i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			count++;
		else if (p[i] == ')')
			count--;

		if (count == -1)
			break;
	}

	if (count == 0)
		return p;

	i = open = close = count = right = 0;

	for (i = 0; i < p.size(); i++) {
		if (p[i] == '(')
			open++;
		else if(p[i] == ')')
			close++;

		u += p[i];

		if (open == close)
			break;
	}

	++i;
	for (; i < p.size(); i++) {
		v += p[i];
	}

	for (int i = 0; i < u.size(); i++) {
		if (u[i] == '(')
			count++;
		else if (u[i] == ')')
			count--;

		if (count < 0)
			right = -1;
	}
	
	if (right == 0) {
		u += solution(v);
		return u;
	}

	answer += '(';
	answer += solution(v);
	answer += ')';

	if (u.size() > 0)
		u.erase(0, 1);

	if (u.size() > 0)
		u.erase(u.end()-1, u.end());

	reverse(u.begin(), u.end());
	answer += u;

	return answer;
}

int main(void)
{
	cout << solution("(()())()") << endl;
	cout << solution(")(") << endl;
	cout << solution("()))((()") << endl;
	cout << solution("(())") << endl;

	return 0;
}
