#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int a, int b) {
	int arr[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	string day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int days = 0;

	for (int i = 0; i < a-1; i++) 
		days += arr[i];

	days += (b + 5);

    return day[days%7-1 == -1 ? 6 : days%7-1];
}

int main(void)
{
	int a, b;
	cin >> a >> b;
	cout << solution(a, b) << endl;

	return 0;
}
