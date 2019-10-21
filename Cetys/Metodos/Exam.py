import numpy as np
from scipy.linalg import solve


def gauss(A, b, x, n):

    L = np.tril(A)
    U = A - L
    for i in range(n):
        x = np.dot(np.linalg.inv(L), b - np.dot(U, x))
        print(str(i).zfill(3), end='')
        print(x)
    return x


def jacobi(A, b, x, n):

    D = np.diag(A)
    R = A - np.diagflat(D)

    for i in range(n):
        x = (b - np.dot(R, x)) / D
        print(str(i).zfill(3), end='')
        print(x)
    return x


'''___MAIN___'''


A = np.array([
    [4., -1., 1., 0.],
    [4., -8., 1., 2.],
    [-2., 1., 5., -1.],
    [1., -4., 3., 10.]
])
b = [7., -23., 16., -15.]
x = np.array([0, 2, 1, 1])

n = 15
print('\n')
print("-----------------------")
print("Matriz A ")
print(A)
print("-----------------------")
print("Matriz B ")
print(b)
print("-----------------------")
print("Punto Inicial")
print(x)
print("-----------------------")
print('\n')
print("Gauss - Seidel")
print(gauss(A, b, x, n))
print("Resultado")
print(solve(A, b))
print('\n')

print("---------------------------------------------")
print('\n')
print("Jacobi")
x = jacobi(A, b, x, n)
print("Resultado ")
print(solve(A, b))
print('\n')
