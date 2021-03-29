def solution(answers):
	answer = []
	ans = [[1,2,3,4,5], [2,1,2,3,2,4,2,5], [3,3,1,1,2,2,4,4,5,5]]

	score = [0,0,0]

	std = len(answers)

	for i in range(std):
		for j in range(3):
			if ans[j][i%(len(ans[j]))] == answers[i]:
				score[j] += 1

	for i in range(len(score)):
		if max(score) == score[i]:
			answer.append(i+1)

	return answer

def main():
	print(solution([1,2,3,4,5]))
	print(solution([1,3,2,4,2]))

main()
