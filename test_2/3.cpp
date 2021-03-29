#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int main(void)
{
	m[1]++;
	m[3]++;

	for (int i = 1; i <= 3; i++) {
		if (m[i] > 0)
			cout << i << endl;
	}

	return 0;
}
