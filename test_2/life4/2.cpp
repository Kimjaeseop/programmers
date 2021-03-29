#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int test = 0;

	while (1) {
		test = 0;
		for (auto iter = scoville.begin() + (answer*2); iter != scoville.end(); iter++) {
			if (*iter < K) {
				test = 1;
				break;
			}
		}

		if (!test)
			return answer;

		if (scoville.size() - (answer*2) < 3)
			return -1;

		//cout << "test : " << test << endl;
		//cout << answer << endl;

		sort(scoville.begin()+(answer*2), scoville.end());

		/*
		for (auto iter = scoville.begin() + (answer*2); iter != scoville.end(); iter++)
			cout << *iter << " ";
		cout << endl;
		*/

		scoville.push_back(scoville[0 + (answer*2)] + (scoville[1 + (answer*2)] * 2));
		answer++;

		/*
		for (auto iter = scoville.begin() + (answer*2); iter != scoville.end(); iter++)
			cout << *iter << " ";
		cout << endl;
		*/

		//sleep(1);

	}
}

int main(void)
{
	// heap으로 풀어야하는듯:
	cout << solution({1, 2, 3, 9, 10, 12}, 7) << endl;

	return 0;
}
