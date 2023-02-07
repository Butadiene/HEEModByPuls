# ライブラリのインポート
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
fig = plt.figure()
ax1 = fig.add_subplot(1, 1, 1)  
m_num = 60
focusTime = 0.7

deltat = 0.0036
len = 6400*6*2*3.14/m_num

x = np.arange(0,len,len/128)
data = pd.read_csv( "data/testdtv/1t2.csv",header=None)
datay = np.ndarray.flatten(pd.DataFrame(data.loc[int(focusTime/(deltat))]).to_numpy())
print(datay)
colors = [(0,0,1),(0,1,0)]
labels = ["42.0keV","50.3keV"]
ax1.plot(x,datay,color = (0,1,0),label = labels[1], linewidth=2)

h1, l1 = ax1.get_legend_handles_labels()
ax1.legend(h1, l1, loc='upper right')

plt.show()