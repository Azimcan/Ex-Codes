import numpy as np
import math
import matplotlib.pyplot as plt
from scipy.integrate import quad

L = 2*math.pi
x_eksen = np.linspace(-np.pi, np.pi, num=1000)
x_eksen_result = np.linspace(-np.pi*3, np.pi*3, num=1000)

#print(quad(lambda x: x**2-x, -math.pi, math.pi))

def an_counter(L, n):
	return (2/L)*quad(lambda x: (5*x**2+7*x+1)*math.cos((2*math.pi*n*x)/L), -L/2, L/2)[0]

def bn_counter(L, n):
	return (2/L)*quad(lambda x: (5*x**2+7*x+1)*math.sin((2*math.pi*n*x)/L), -L/2, L/2)[0]

def a0_counter(L):
	return (1/L)*quad(lambda x: (5*x**2+7*x+1), -L/2, L/2)[0]

y_target = (5*x_eksen**2+7*x_eksen+1)

def y_result_calc(x_eksen, k, L):
    y_result = []
    result = a0_counter(L)
    for x in x_eksen:
        for n in range(1, k):
            result += an_counter(L, n)*math.cos((2*math.pi*n*x)/L) + bn_counter(L, n)*math.sin((2*math.pi*n*x)/L)
        y_result.append(result)
        result = a0_counter(L)
    for n in range(1, k):
        print("n = ", n)
        print(a0_counter(L))
        print(an_counter(L, n))
        print(bn_counter(L, n))
    return y_result


y_result = y_result_calc(x_eksen_result, 2, L)
    
plt.plot(x_eksen, y_target)
plt.plot(x_eksen_result, y_result)



plt.xticks([-3*np.pi,-2.5*np.pi,-2*np.pi,-1.5*np.pi,-np.pi,-np.pi/2,0,np.pi/2,np.pi,1.5*np.pi,2*np.pi,2.5*np.pi,3*np.pi],["$-3\pi$",r"$-\dfrac{5\pi}{2}$","$-2\pi$",r"$-\dfrac{3\pi}{2}$","$-\pi$",r"$-\dfrac{\pi}{2}$",r"0",r"$\dfrac{\pi}{2}$","$\pi$",r"$\dfrac{3\pi}{2}$","$2\pi$",r"$\dfrac{5\pi}{2}$","$3\pi$"])
plt.grid()
plt.ylabel("y değişkeni")
plt.xlabel("x değişkeni")
plt.title("1 Terimli");
plt.figure(figsize=[16,9])
plt.show()
 





































