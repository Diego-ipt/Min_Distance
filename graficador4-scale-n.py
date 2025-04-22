import pandas as pd
import matplotlib
import matplotlib.pyplot as plt

# open a csv file
df2 = pd.read_csv('dyvgrande.csv')
df = pd.read_csv('bfgrande.csv')
df4 = pd.read_csv('dyv_mejorado.csv')
df3 = pd.read_csv('bf_mejorado.csv')

# graphic each line
# plot(x=values, y=values, label, points marker)
plt.plot(df['n'], df['t_mean'], label='Brute Force', marker='o')
plt.plot(df2['n'], df2['t_mean'], label='Divide and Conquer', marker='s')
plt.plot(df3['n'], df['t_mean'], label='Improved Brute Force', marker='v')
plt.plot(df4['n'], df2['t_mean'], label='Improved Divide and Conquer', marker='x')

# x=labels and y=labels
plt.ylabel('Running time (millieseconds)')
plt.xlabel('Input size (n)')

# show legend
plt.legend()

# save graphic in a file
plt.savefig('plot_basic-VS-improved_n.png')