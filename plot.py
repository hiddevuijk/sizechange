import numpy as np
import matplotlib.pyplot as plt
from sys import exit

data = np.loadtxt("gr.dat")
gr = data[:,1]
r = data[:,0]
print(sum(gr))

plt.plot(r,gr)
plt.show()


