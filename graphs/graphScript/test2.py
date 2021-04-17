# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import matplotlib.collections as mc
import numpy as np

# グラフとして描画するデータ
fig, ax1 = plt.subplots(1, 1)

m_num = 20
focusTime = 2.5

data = pd.read_csv('data/testdatav2/test001_20_2.csv',header=None)
datay = data.iloc[int(focusTime/(0.0108))]

print(datay)

len = 6400*6*2*3.14/m_num

x = np.arange(0,len,len/128)
ax1.set_xlabel('position[km]')
ax1.set_ylabel('density')
ax1.plot(x,datay,color = (0,0,1),label = "density")

ax2 = ax1.twinx()
data2 = -1*pd.read_csv('data/testdatav2/test001_20_sinv2.csv',header=None)
datay2 = data2.iloc[int(focusTime/(0.0108))]
ax2.set_ylabel('-ULF waves')
ax2.plot(x, datay2,color=(0,1,0),label = "-ULF waves")
h1, l1 = ax1.get_legend_handles_labels()
h2, l2 = ax2.get_legend_handles_labels()
ax1.legend(h1+h2, l1+l2, loc='upper right')
plt.show()