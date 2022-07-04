import numpy as np
import matplotlib.pyplot as plt
import scipy
   
x = np.linspace(-4,4,30)
simlen = int(1e6)
err = [] 

randvar = np.loadtxt('uni.dat',dtype='double')

for i in range(0,30):
	err_ind = np.nonzero(randvar < x[i])
	err_n = np.size(err_ind) 
	err.append(err_n/simlen)

def uni_cdf(x):
	if x > 1:
		return 1
	elif x < 0:
		return 0
	return x
		
vec_uni_cdf = scipy.vectorize(uni_cdf, otypes=[float])
plt.plot(x.T, err, 'o')
plt.plot(x, vec_uni_cdf(x))
plt.grid() 
plt.xlabel('$x$')
plt.ylabel('$F_U(x)$')
plt.legend(["Numerical","Theory"])
plt.savefig('uni_cdf.pdf')
plt.savefig('uni_cdf.eps')
