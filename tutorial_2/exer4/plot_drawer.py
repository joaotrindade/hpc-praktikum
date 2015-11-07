#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove blank lines in txt files

file1_data = np.loadtxt('file1.txt')
file2_data = np.loadtxt('file2.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
#p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'ro')
p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'r')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
        
pylab.title('Simple cosine')
pylab.xlabel('time (s)')
pylab.ylabel('cos(4t)')

pylab.grid(True)

#let python select the best position for legend
pyp.legend([p1[0],p2[0]], ['Mon','Tue'], 'best', numpoints=1)

pyp.savefig("MyFirstPlot.png")

# show the plot on the screen
pylab.show()




