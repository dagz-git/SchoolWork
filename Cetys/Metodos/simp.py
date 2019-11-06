def f(x):
	return x**2

def f2(x):
	return x**3

def simp(a, b, n, x):

    x = f(a) + f(b)
    h = (b - a) / n

    for i in range(1, n):
        if i % 2 == 0:
            x = x + (2 * f((a + i) * h))
            print(x)
        else:
            x = x + (4 * f((a + i) * h))
            print(x)

    return (h / 3) * x

print(simp(0,4,4,0))
#print("----------------------")

def simp2(a, b, n, x):

    x = f2(a) + f2(b)
    h = (b - a) / n

    for i in range(1, n):

        if i % 3 == 0:
            x = x + (2 * f2((a + i) * h))
            print(x)
        else:
            x = x + (3 * f2((a + i) * h))
            print(x)

    return ((3 * h) / 8) * x

print(simp2(0, 3, 6, 0))


