import numpy as np
import matplotlib.pyplot as plt
from sys import exit




data = np.loadtxt("out.dat")

plt.plot(data[:,0])
plt.plot(data[:,1])
plt.show()
