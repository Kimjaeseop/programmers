#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> nums) {
    int answer = -1;
	int sum = 0;
	vector<int> offset;
	vector<int> arr;

	for (int i : nums)
		sum += i;

	for (int i = 0; i < nums.size() - 3; i++)
		offset.push_back(0);

	for (int i = 0; i < 3; i++) 
		offset.push_back(1);

	arr.resize(sum);
	for (int i = 2; i <= sum + 1; i++) {
		for (int j = 2; ; j++) {
			if (i * j > sum)
				break;

			arr[i*j] = 1;
		}
	}

	do {
		sum = 0;

		for (int i = 0; i < offset.size(); i++) {
			if (offset[i] == 1)
				sum += nums[i];
		}

		if (arr[sum] == 0)
			answer++;
	} while (next_permutation(offset.begin(), offset.end()));

    return answer + 1;
}

int main(void)
{
	cout << solution({1, 2, 3, 4}) << endl;
	cout << solution({1, 2, 7, 6, 4}) << endl;

	return 0;
}
