#include <string>
#include <vector>
#include <cmath>

#include <iostream>

using namespace std;

int solution(int n) {
	vector<int> V;
    int answer = 0;
	int std = 1;

	while (1) {
		std *= 3;

		if (std > n)
			break;
	}

	std /= 3;

	while (n > 0) {
		V.push_back(n / std);
		n %= std;

		std /= 3;
	}

	for (int i = V.size()-1; i >= 0; i--) 
		answer += (pow(3, i) * V[i]);

    return answer;
}

int main(void)
{
	cout << solution(45) << endl;
	cout << solution(125) << endl;

	return 0;
}
