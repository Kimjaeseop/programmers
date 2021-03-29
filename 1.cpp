#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
	stack<int> S;
	queue<int> board_queue[30];

	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[j][i] != 0)
				board_queue[i].push(board[j][i]);

	for (int i : moves) {
		if (board_queue[i-1].empty())
			continue;

		if (!S.empty() && S.top() == board_queue[i-1].front()) {
			S.pop();
			answer++;
		} else
			S.push(board_queue[i-1].front());

		board_queue[i-1].pop();
	}

    return answer*2;
}

int main(void)
{
	cout << solution({{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}}, {1,5,3,5,1,2,1,4}) << endl;

	return 0;
}
