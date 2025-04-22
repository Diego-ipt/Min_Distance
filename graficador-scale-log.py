import pandas as pd
import matplotlib
import matplotlib.pyplot as plt

# open a csv file
df2 = pd.read_csv('dyv_analisis.csv')
df = pd.read_csv('bf_analisis.csv')

# graphic each line
# plot(x=values, y=values, label, points marker)
plt.plot(df['n'], df['t_mean'], label='Brute Force', marker='o')
plt.plot(df2['n'], df2['t_mean'], label='Divide and Conquer', marker='s')

# x=labels and y=labels
plt.ylabel('Running time (nanoseconds)')
plt.xlabel('Input time (log(2^n))')

# log=scale
plt.yscale('log')

# show legend
plt.legend()

# save graphic in a file
plt.savefig('plot_2^n_log.png')