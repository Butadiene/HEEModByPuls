# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import matplotlib.collections as mc
import numpy as np

# グラフとして描画するデータ
fig, ax1 = plt.subplots(1, 1)

m_num = 70
focusTime = 0.4


deltat = 0.0036
#data = pd.read_csv('data/testdatav9/t1.csv',header=None)
ax1.cla() # ax をクリア

                                

#print(datay)

len = 6400*6*2*3.14/m_num

x = np.arange(0,len,len/128)
ax1.set_xlabel('position[km]')
ax1.set_ylabel('density')
ax1.set_ylim(0.0,80.0)
#ax1.set_ylim(0,5)
for i in range(2):
    path = "data/testdtv/"
    num = str(i)
    data = pd.read_csv(path+num+'t2.csv',header=None)
    datay = np.ndarray.flatten(pd.DataFrame(data.loc[int(focusTime/(deltat))]).to_numpy())
    print(datay)
    colors = [(0,0,1),(0,1,0)]#,(1,0,0),(1,1,0),(1,0,1),(0,1,1),(0,0,0),(0.2,0.2,0.2)]
    labels = ["42.0keV","50.3keV"]
    ax1.legend(labels[i])
    ax1.plot(x,datay,color = colors[i],label = labels[i], linewidth=2)



ax2 = ax1.twinx()
ax2.cla() 
data2 = -1*pd.read_csv('data/testdatav5/E_sin.csv',header=None)
datay2 = data2.iloc[int(focusTime/(deltat))]
ax2.set_ylabel('-ULF Ewaves')
#ax2.plot(x, datay2,color=(0,1,0),label = "-ULF Ewaves", linewidth=4)

data3 = pd.read_csv('data/testdtv/0B_sin2.csv',header=None)
datay3 = data3.iloc[int(focusTime/(deltat))]
ax2.set_ylabel('ULF Bwaves(normalized)')
ax2.plot(x, datay3,color=(0,1,1),label = "ULF Bwaves", linewidth=4)

h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2, loc='upper right')
plt.xticks(np.arange(0, 4000,200))
plt.grid(axis = 'x', color='b', linewidth=0.3)
plt.show()