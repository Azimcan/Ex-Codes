import numpy as np
import math
import cmath
import matplotlib.pyplot as plt

from scipy.integrate import quad

L = 1
x_eksen = np.linspace(-10, 10, num=1000)
y_eksen = np.linspace(0, 0, num=1000)


def ck_counter(L, k):
	return (1/2*math.pi)*quad(lambda x: (7*x**2+5*x+1)*cmath.e**(-1j*k*x), np.inf, np.inf)[0]

ck = ck_counter(L, 1)
print(ck)

y_target = (7*x_eksen**2+5*x_eksen+1)

def y_result_calc(x, k, L):
    y_result = []
    result = 0
    for x_n in x:
        for x in range(1, k):
            result += quad(lambda k: ck_counter(L, k)*cmath.e**(1j*k*x_n, np.inf, np.inf))
        y_result.append(result)
        result = 0
    
    return y_result


y_result = y_result_calc(x_eksen, 2, L)

plt.plot(x_eksen, y_target)
plt.plot(x_eksen, y_result)
plt.plot(x_eksen, y_eksen) #x ekseni
plt.plot(y_eksen, x_eksen) #x eksen

plt.ylim(-10, 10)
plt.xlim(-4, 4)

cnums = np.arange(5) + 1j * np.arange(6,11)
X = [x.real for x in cnums]
Y = [x.imag for x in cnums]
plt.scatter(X,Y, color='red')
plt.show()



