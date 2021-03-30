dic = {}

def func(origin, string, course):
	if len(string) > max(course): # course에 있는 최대 코스 수보다 현재 문자열의 길이가 길다면 return
		return

	if len(string) in course: # 현재 코스의 길이가 만들고 싶은 코스의 길이에 속해 있다면 추가
		if string not in dic.keys():
			dic[string] = 1
		else:
			dic[string] += 1

	if len(origin) == 0: # 앞으로 추가할 메뉴가 없다면 return
		return

	for i in range(len(origin)): # 현재 코스 + 추가 코스
		s = string + origin[i]
		func(origin[i+1:], s, course)

def solution(orders, course):
	answer = []

	for s in orders:
		s = sorted(s)
		for i in range(len(s)):
			func(s[i+1:], s[i], course) # 재귀 함수 호출

	for c in course:
		lst = []
		for d in dic.items(): # 코스의 개수마다 많이 조합된 코스를 찾기 위한 작업
			if len(d[0]) == c:
				lst.append(d)

		if len(lst) == 0: # 해당 코스의 개수에 조합된 코스가 없다면 건너뜀
			continue

		M = max(lst, key=lambda x:x[1]) # tuple에서 second key를 기준으로 가장 큰 값을 찾는 작업

		if M[1] == 1: # 만약 가장 많이 주문된 코스가 한 번이라면 건너뜀
			continue

		for l in lst: # 리스트에서 가장 많이 주문된 코스를 모두 찾아서 정답 리스트에 추가
			if l[1] == M[1]:
				answer.append(l[0])

	return sorted(answer)

print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))
#print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]))
#print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
