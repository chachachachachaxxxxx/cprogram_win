def get(): # 输入函数
    f = input()
    value = f.split(" ")
    v = [int(i) for i in value]
    return v


def gcd(a, b): # 获取最大公约数
    if b == 0:
        return a
    return gcd(b, a % b)


def solve(a, b, m): # 判断是否有解
    g = gcd(a, b)
    # print(g)
    if m % g == 0:
        return True
    return False


def liner_mod_function(a, b): # 利用扩展欧几里得算法求解
    if b == 0:
        return [1, 0]
    y = liner_mod_function(b, a % b)
    x = [1, 1]
    x[0] = y[1]
    x[1] = y[0] - a // b * y[1]
    return x


# 求解 ax = m (mod b)
values = get()  # value[0]: a  value[1]: m  value[2]: b
a = values[0]
b = values[2]
m = values[1]
if not solve(a, b, m):
    print("无解")
else:
    x = liner_mod_function(a, b) # 求特解
    ans = x[0]
    ans *= m / gcd(a, b)
    ans %= b
    print("x={}+{}k".format(int(ans), b)) # 将特解表现成通解形式