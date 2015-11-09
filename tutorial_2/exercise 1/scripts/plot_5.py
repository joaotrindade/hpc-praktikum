#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np

#sh strong/weak.sh
# for reduction
#Plot between x : Number of threads, y: computatinal time and efficiency and speedup , ideal speedup, ideal eff(scaling)
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file1_data = np.loadtxt('./generated_data/log_r_eff_vs_threads.txt')
file2_data = np.loadtxt('./generated_data/log_r_time_vs_threads.txt')
file3_data = np.loadtxt('./generated_data/log_r_speedup_vs_threads.txt')
#file4_data = np.loadtxt('./generated_data/log_openmp_ideal_speedup.txt')
file5_data = np.loadtxt('./generated_data/log_r_ideal_eff.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'r')
p2 = pyp.plot(file2_data[:,0], file2_data[:,1], 'g')
p3 = pyp.plot(file3_data[:,0], file3_data[:,1], 'b')
#p4 = pyp.plot(file4_data[:,0], file4_data[:,1], 'y')
p5 = pyp.plot(file5_data[:,0], file5_data[:,1], 'm')
        
pylab.title('Weak Scaling')
pylab.xlabel('Number of threads')
#pylab.ylabel('Computational Time(second)')

pylab.grid(True)

#let python select the best position for legend
#pyp.legend([p1[0],p2[0],p3[0],p4[0],p5[0]], ['Efficiency', 'Computation time(sec)', 'Speedup','Ideal speedup', 'Ideal Efficiency'], 'best', numpoints=1)
pyp.legend([p1[0],p2[0],p3[0],p5[0]], ['Efficiency', 'Computation time(sec)', 'Speedup', 'Ideal Efficiency'], 'best', numpoints=1)

pyp.savefig("./generated_plots/strong_red.png")

# show the plot on the screen
pylab.show()




