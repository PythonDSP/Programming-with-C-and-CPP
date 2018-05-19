# plot_uniform_dist.py
# plot the data generated by file 'uniform_distribution.c'

import matplotlib.pyplot as plt
import numpy as np

f = open(r'uniform_data.txt', 'r').read()  # read file
data_string = f.split(",")   # split content of file on ','
data_list = []
for d in data_string:
    try:
        data_list.append(float(d))  # convert string-value to float and store in list
    except ValueError as error:
        continue   

# numpy array is required for calculating 'mean' and variance of distributions
data_array = np.array(data_list, 'float')  # convert python-list to numpy-array

print("Minimum value (a) = ", min(data_array))  # show minimum value of data_array
print("Maximum value (b) = ", max(data_array))  # show maximum value of data_array

 # Calculate mean and variance : a = min value , b = max value
print("Mean (a+b)/2 = ", data_array.mean())  # mean
print("Variance [(b-a)^2]/12 = ", data_array.var())  # variance 

plt.hist(data_array, 20)  # Histogram with 20 bins
plt.show()

# Outputs: 
# Minimum value (a) =  0.0
# Maximum value (b) =  0.999939
# Mean value =  0.50144555508     i.e. (1+0)/2
# Mean value =  0.0832357216637   i.e. ( (1-0)^2 /12 )