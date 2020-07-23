import numpy as np
import matplotlib.pyplot as plt
from sys import exit

data = np.loadtxt("gr.dat")
gr = data[:,1]
r = data[:,0]

rmax = max(r)/2.
plt.plot(r,gr)
plt.xlim([0,rmax])
plt.show()


