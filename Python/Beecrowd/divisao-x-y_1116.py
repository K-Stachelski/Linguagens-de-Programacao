# Dividindo X por Y - 1116

qtt = int(input()) 

for i in range(qtt):
    x, y = map(int, input().split())
    if y == 0:
        print("divisao impossivel")
    else:    
        div = x / y
        print(div)