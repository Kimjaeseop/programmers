#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
	int prev = 10;

	for (int i : arr) {
		if (i != prev)
			answer.push_back(i);

		prev = i;
	}

    return answer;
}

int main(void)
{
	vector<int> V;

	V = solution({1,1,3,3,0,1,1});

	for (int i : V)
		cout << i << " ";
	cout << endl;

	return 0;
}
