import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

df = pd.read_csv('forced.csv')
df2 = pd.read_csv('damped.csv')
plt.plot(df['time'], df['x-position'])

plt.savefig('forced.png')

