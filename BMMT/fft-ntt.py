w = 4 
q = 17

a = [1, 3, 2, 0]
ax = lambda x: 2*x**2 + 3*x + 1

b = [5, 1, 0, 0]
bx = lambda x: x + 5



def w_mod(i, j):
	return 4**(i*j)%q

def katsayi_counter(f, w, q):
	F = []
	for i in range(0, w):
		a_n = 0
		for j in range(0, w):
			a_n += w_mod(i, j)*f[j]
		F.append(a_n%q)
	return F

A = katsayi_counter(a, w, q)
B = katsayi_counter(b, w, q)
print(A)
print(B)

c = []
for i in range(0, w):
	c.append((A[i]*B[i])% q)

print(c)


def c_counter(c, w, q):
	C = []
	for i in range(0, w):
		a_n = 0
		for j in range(0, w):
			a_n += w_mod(-i, j)*c[j]
		C.append(1/4*(a_n%q))
	return C

C = c_counter(c, w, q)

print(C)










