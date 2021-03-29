#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#include <iostream>

#define max(a, b) a > b ? a : b

using namespace std;

int max_depth;
int MAX;

void BFS(vector<int> V, int n, int depth) {
	for (int i = 1; i <= n; i++) {
		if (V[i] != 2)
			continue;

		if (i != 1 && V[i-1] == 0) {
			V[i-1] = V[i] = 1;
			BFS(V, n, depth+1);
			V[i-1] = 0;
			V[i] = 2;
		}
		if (i != n && V[i+1] == 0) {
			V[i+1] = V[i] = 1;
			BFS(V, n, depth+1);
			V[i+1] = 0;
			V[i] = 2;
		}
	}

	int cnt = 0;

	for (int i : V)
		if (i >= 1)
			cnt++;

	MAX = max(cnt, MAX);

	return ;
}

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> V;
	V.resize(n + 1, 1);

	max_depth = reserve.size();

	V[0] = 0;
	for (int i : lost)
		V[i] = 0;

	for (int i : reserve)
		V[i] += 1;

	BFS(V, n, 0);

	cout << MAX << endl;

	return MAX;
}

int main(void)
{
	solution(5, {2, 4}, {1, 3, 5});
	max_depth = MAX = 0;
	solution(5, {2, 4}, {3});
	max_depth = MAX = 0;
	solution(3, {3}, {1});

	return 0;
}
