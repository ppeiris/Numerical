#!/usr/bin/env python

import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt('poisson.dat')

figd=plt.figure()
ad = figd.add_subplot(111)
ad.grid(True)

# ad.plot(np.linspace(1,50,50), data[0][1:])
# figd.savefig('image.png',bbox_inches='tight')

for pmf_values in data: # this give us row at a time
    ad.plot(np.linspace(1,49,49), pmf_values[1:])

figd.savefig('image.png',bbox_inches='tight')




print(len(data[0][1:]))




# f = open('poisson.dat', 'r')

# print(f.read())
