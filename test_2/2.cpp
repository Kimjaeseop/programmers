#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unistd.h>

using namespace std;

int size;
int cnt;
map<int, int> m;

void DFS(string str, string numbers, bool check[]) {
	if (m[stoi(str)] == 1) {
		cnt++;
		m[stoi(str)] = 0;
	}

	for (int i = 0; i < size; i++) {
		if (check[i] == 0) {
			check[i] = 1; str += numbers[i];
			DFS(str, numbers, check);
			check[i] = 0; numbers[numbers.size()-1] = '\0';
		}
	}
}

int solution(string numbers) {
    int n = 1;
	bool check[8] = {0,};

	size = numbers.size();
    
    for (int i = 0; i < size; i++) {
        n *= 10;
	}

    for (int i = 2; i < n; i++) {
        for (int j = 1; ; j++) {
            if (i*j > n)
                break;

            m[i*j] = 1;   
        }
    }

    for (int i = 0; i < size; i++) {
        string tmp_str = "";
        tmp_str += numbers[i];
		// 왜 tmp_str[0] = numbers[i]는 안되는거지 ?

        check[i] = true;
        DFS(tmp_str, numbers, check);
		check[i] = false;
    }

    return cnt;
}

int main(void)
{
	cout << solution("011") << endl;

	return 0;
}
