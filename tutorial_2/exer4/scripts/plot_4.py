#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

#sh strong/weak.sh
#Plot between x : problem size, y: efficiency, speedup (scaling)
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file1_data = np.loadtxt('./generated_data/log_openmp_eff_vs_prblm_sz.txt')
file2_data = np.loadtxt('./generated_data/log_openmp_speedup_vs_prblm_sz.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'r')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
        
pylab.title('Weak Scaling')
pylab.xlabel('Number of threads')
#pylab.ylabel('Speedup')

pylab.grid(True)

#let python select the best position for legend
pyp.legend([p1[0], p2[0]], ['Efficiency', 'Speedup'], 'best', numpoints=1)

pyp.savefig("./generated_plots/sacaling_speedup_eff_VS_size.png")

# show the plot on the screen
pylab.show()




