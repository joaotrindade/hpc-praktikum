#!/usr/bin/python
import matplotlib.pyplot as pyp
import pylab
import numpy as np
#Plot between x : Problem size, y: computatinal time (OpenMP and Non-OpenMP)
#sh seq_vs_parallel_diff_prob_sizes_vs_matrix_size.sh
# Use numpy to load the data contained in the file
# file1.txt into a 2-D array called data
# 0 1
# 1 2
# 4 5
# Note: remove the newline from last line of txt files

file3_data = np.loadtxt('./generated_data/log_openmp_eff_vs_threads.txt')
file4_data = np.loadtxt('./generated_data/log_openmp_speedup_vs_threads.txt')

#file5_data = np.loadtxt('./generated_data/log_openmp_ideal_eff.txt')
#file6_data = np.loadtxt('./generated_data/log_openmp_ideal_speedup.txt')

# plot the first column as x, and second column as y
# use pylab to plot x and y as red circles
# third parameter in plot is color, change it according to your need
#p1 = pyp.plot(file1_data[:,0], file1_data[:,1], 'ro')
p3 = pyp.plot(file3_data[:,0], file3_data[:,1], 'g')
p4 = pyp.plot(file4_data[:,0], file4_data[:,1], 'r')
#p5 = pyp.plot(file5_data[:,0], file5_data[:,1], 'c')
#p6 = pyp.plot(file6_data[:,0], file6_data[:,1], 'b')
        
pylab.title('Weak Scaling')
pylab.xlabel('Number of threads')
#pylab.ylabel('Computation Time(second)')

pylab.grid(True)

#let python select the best position for legend
#pyp.legend([p3[0],p4[0],p5[0],p6[0]], ['Efficiency', 'Speedup', 'Ideal Eff', 'Ideal speedup'], 'best', numpoints=1)
pyp.legend([p3[0],p4[0]], ['Efficiency', 'Speedup'], 'best', numpoints=1)

pyp.savefig("./generated_plots/10.png")

# show the plot on the screen
pylab.show()




