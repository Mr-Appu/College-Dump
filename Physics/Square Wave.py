#Square Wave (frequency = 3.6)
import numpy as np
import matplotlib.pyplot as plt
import math


def square(frequency,amplitude,x):  #Square Function 
    s = 0
    for n in range(21):
        s += math.sin((2*n + 1)*x*frequency ) / (2*n + 1)
    return amplitude*s   

Domain = np.arange(-2*np.pi, 2*np.pi, 0.01) #Domain = [-2pi,2pi]

Frequency = 3.6
Amplitude = 1

Range = []
for i in Domain:
    Range.append(square(Frequency,Amplitude,i))
Range=np.array(Range) #Converting list to numpy-array

plt.plot(Domain, Range)

plt.title('Square Wave', color='r')
plt.xlabel('x'+ r'$\rightarrow$')
plt.ylabel('f(x) '+ r'$\rightarrow$')

plt.grid()
plt.axhline(y=0, color='k')
plt.axvline(x=0, color='k')

plt.show()
