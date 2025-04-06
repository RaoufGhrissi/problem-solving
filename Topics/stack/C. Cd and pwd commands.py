n = int(input())    
stack = []
 
for i in range(n):
    param = input().split()
 
    if param == ['pwd']:
        print('/' + '/'.join(stack) + '/' if stack else '/')
    else:
        path = param[1]
        parts = [part for part in path.split('/') if part]
        if path[0] == '/':
            stack = []
        
        for part in parts:
            if part == '..':
                stack.pop()
            else:
                stack.append(part)