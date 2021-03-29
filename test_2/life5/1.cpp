#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

typedef struct node {
	string city;
	node *prev;
	node *next;
} NODE;

int SIZE;
void append(NODE **head, string city) {
	if (*head == NULL) {
		(*head) = (NODE *)calloc(1, sizeof(NODE));
		(*head)->next = (*head)->prev = NULL;
		(*head)->city = city;
		return ;
	}

	NODE *tmp = (*head);

	while (tmp->next != NULL) {
		tmp = tmp->next;
	}

	NODE *newNode = (NODE *)calloc(1, sizeof(NODE));
	newNode->city = city;
	newNode->prev = tmp;
	newNode->next = NULL;

	tmp->next = newNode;
}

void printLinkedlist(NODE *head) {
	NODE *tmp = head;

	while (tmp != NULL) {
		cout << tmp->city << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int checkList(NODE **head, string city, int cacheSize) {
	NODE *tmp = (*head);

	if (SIZE < cacheSize) {
		SIZE++;
		append(head, city);
		return -1;
	}

	while (tmp != NULL) {
		if (tmp->city == city) {
			NODE *a = tmp;

			while (tmp->next != NULL) 
				tmp = tmp->next;

			NODE *b = tmp;
			swap(a->city, b->city);

			return 1;
		}

		tmp = tmp->next;
	}

	(*head) = (*head)->next;
	append(head, city);
	return -1;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
	int ret;
	NODE *head = NULL;

	for (string s : cities) {
		ret = checkList(&head, s, cacheSize);

		if (ret == -1)
			answer += 5;
		else
			answer += 1;

//		printLinkedlist(head);
	}

//	printLinkedlist(head);

    return answer;
}

int main(void)
{
	cout << solution(3, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"}) << endl;
	SIZE = 0;
	cout << solution(3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}) << endl;

	return 0;
}
