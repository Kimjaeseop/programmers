def solution(new_id):
	answer = ''
	new_id = new_id.lower()

	'''
	for i in range(len(new_id)):
		if new_id[i] == '.' or (new_id[i] >= 'a' and new_id[i] <= 'z') or (new_id[i] >= '0' and new_id[i] <= '9') or new_id[i] == '-' or new_id[i] == '_' or new_id[i] == '.':
			answer += new_id[i]

	answer.replace('..', '.', 1)
	'''

	for c in new_id:
		if c.isalpha() or c.isdigit() or c in ['-', '_', '.']:
			answer += c
	
	while '..' in answer:
		answer = answer.replace('..', '.')

	'''
	tmp = ''
	tmp += answer[0]

	for i in range(1, len(answer)):
		if answer[i] == '.' and tmp[-1] == answer[i]:
			continue

		tmp += answer[i]
	'''
	
	answer = answer.strip('.')

	if len(answer) == 0:
		answer += 'a'
	
	if len(answer) >= 16:
		answer = answer[:15]

	answer = answer.rstrip('.')

	while len(answer) <= 2:
		answer += answer[-1]

	return answer

def main():
	print(solution("...!@BaT#*..y.abcdefghijklm"))
	print(solution("z-+.^."))
	print(solution("=.="))
	print(solution("123_.def"))
	print(solution("abcdefghijklmn.p"))

main()
