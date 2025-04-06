n = int(input())    
stack = []

lines = []
 
for i in range(n):
    param = input()

    if param == 'add':
        if not lines or lines[-1][0] != 'add':
            lines.append(['add', 1])
        else:
            lines[-1][1] += 1
    else:
        lines.append(param.split())

ok = 1
for line in lines:
    if line[0] == 'add':
        if not stack:
            stack.push(('add', 1))
        elif stack[-1][0] == 'add':
            stack[-1][1] += line[1]
        else:
            stack.append(('add', stack.pop()[1] * line[1]))

        if stack[-1][1] > 2<<32 - 1:
            ok = 0
            break
    elif param == ['end']:
        if stack[-1][0] == 'for':
            stack.pop()
    else:
        stack.append(line)

if not ok:
    print('OVERFLOW!!!')
else:
    x = 0
    for line in stack:
        x += line[1]
        if x > 2<<32 - 1:
            print('OVERFLOW!!!')
            break

if ok:
    print(x)
# The code above is a solution to the problem from the following link:
# https://codeforces.com/problemset/problem/1175/B
