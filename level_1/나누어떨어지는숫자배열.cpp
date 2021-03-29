#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;

	for (int i : arr)
		if (!(i % divisor))
			answer.push_back(i);

	if (!(answer.size()))
		answer.push_back(-1);
	else
		sort(answer.begin(), answer.end());

    return answer;
}

int main(void)
{
	vector<int> V;
	
	//V = solution({5, 9, 7, 10}, 5);
	//V = solution({2, 36, 1, 3}, 1);
	V = solution({3, 2, 6}, 10);

	for (int i : V)
		cout << i << " ";
	cout << endl;

	return 0;
}
