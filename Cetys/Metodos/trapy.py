def f(x):
	return x **2  

def trap(a,b ,n ,g):
	h = (b-a)/n
	g = f(a)+f(b)
	for x in range(1,n):
		g += g + (2* f(x) * h)
		print (x)
	return (h/2)*x

print(trap(0,4,4,0))
