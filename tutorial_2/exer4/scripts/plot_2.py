#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

#Plot between x : Problem size, y: computatinal time (Weak Scaling OpenMP and Non-OpenMP)
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file1_data = np.loadtxt('log_non_opemp_time_vs_prblmSize.txt')
file2_data = np.loadtxt('log_openmp_time_prlm_sz.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
#p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'ro')
p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'r')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
        
pylab.title('Weak Scaling: Comptation time vs problem size')
pylab.xlabel('Matrix input size N(n*n)*(n*n)')
pylab.ylabel('Time(second)')

pylab.grid(True)

#let python select the best position for legend
pyp.legend([p1[0],p2[0]], ['No OpenMP','OpenMP'], 'best', numpoints=1)

pyp.savefig("./generated_plots/sacaling_Seq_VS_Para.png")

# show the plot on the screen
pylab.show()




