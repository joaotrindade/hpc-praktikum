#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

#sh strong/weak.sh
# for compare all the methods how much time they take for diff loads but same thread
#Plot between x : Number of threads, y: computatinal time and efficiency and speedup , ideal speedup, ideal eff(scaling)
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file1_data = np.loadtxt('./generated_data/log_non_opemp_time_vs_prblmSize.txt')
file2_data = np.loadtxt('./generated_data/log_c_time_prlm_sz.txt')
file3_data = np.loadtxt('./generated_data/log_r_time_prlm_sz.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'r')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
p3 = pyp.plot(file3_data[:,0], file3_data[:,1], 'b')
        
pylab.title('Comparision (No of threads = 32)')
pylab.xlabel('Number of divisions')
pylab.ylabel('Computational Time(second)')

pylab.grid(True)

#let python select the best position for legend
pyp.legend([p1[0],p2[0],p3[0]], ['Non-OpenMP', 'Critical', 'reduction'], 'best', numpoints=1)

pyp.savefig("./generated_plots/comparision.png")

# show the plot on the screen
pylab.show()




