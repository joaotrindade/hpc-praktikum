#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

#Plot between x : Number of threads, y: speedup (Weak OpenMP)
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file2_data = np.loadtxt('log_openmp_speedup_vs_threads.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
#p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'ro')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
        
pylab.title('Weak Scaling: speedup vs number of threads')
pylab.xlabel('Number of threads')
pylab.ylabel('Speedup')

pylab.grid(True)

#let python select the best position for legend
pyp.legend([p2[0]], ['OpenMP'], 'best', numpoints=1)

pyp.savefig("./generated_plots/sacaling_speedup_VS_threads.png")

# show the plot on the screen
pylab.show()




