dic = {}

def func(origin, string, course):
	s = ""

	if len(string) > max(course):
		return

	if len(string) in course:
		if string not in dic.keys():
			dic[string] = 1
		else:
			dic[string] += 1

	if len(origin) == 0:
		return

	for i in range(len(origin)):
		s = string
		s += origin[i]
		func(origin[i+1:], s, course)

def solution(orders, course):
	answer = []

	for s in orders:
		s = sorted(s)
		for i in range(len(s)):
			func(s[i+1:], s[i], course)

	for c in course:
		lst = []
		for d in dic.items():
			if len(d[0]) == c:
				lst.append(d)

		if len(lst) == 0:
			continue

		M = max(lst, key=lambda x:x[1])

		if M[1] == 1:
			continue

		for l in lst:
			if l[1] == M[1]:
				answer.append(l[0])

	return sorted(answer)

#print(solution(["ABCFG", "AC", "CDE", "ACDE", "BCFG", "ACDEH"], [2, 3, 4]))
#print(solution(["ABCDE", "AB", "CD", "ADE", "XYZ", "XYZ", "ACD"], [2, 3, 5]))
#print(solution(["XYZ", "XWY", "WXA"], [2, 3, 4]))
