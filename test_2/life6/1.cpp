#include <iostream>
#include <cmath>

using namespace std;

// 모르겠다 규칙을 모르겠어

// 최대공약수, 최소공배수 유클리드
int gcd(int a, int b) {
	int c;

	while (b != 0) {
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

long long solution(int w,int h) {
    long long answer = 1;
	int gcd_num = gcd(w, h);
	int SIZE = w * h;

	if (w == h) 
		answer = w;
	else if (w != gcd_num && h != gcd_num) {
		w /= gcd_num;
		h /= gcd_num;

		answer = SIZE - ceil(sqrt(pow(w, 2) + pow(h, 2))) * gcd_num;
	}
	else 
		answer = SIZE - ceil(sqrt(pow(w, 2) + pow(h, 2)));

    return answer > 0 ? answer : 0;
}

int main(void)
{
	cout << solution(8, 12) << endl;
	cout << solution(2, 2) << endl;

	return 0;
}
