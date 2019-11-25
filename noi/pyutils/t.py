def getsum(x):
    s = 0
    for v in x:
        s += v
    return s
    
x = [1, 2, 100]
for v in x:
    print('{}'.format(v))

print(getsum(x))

