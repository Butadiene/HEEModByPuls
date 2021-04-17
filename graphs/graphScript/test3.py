# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import matplotlib.collections as mc
import numpy as np
from matplotlib.animation import FuncAnimation

# グラフとして描画するデータ
fig, ax1 = plt.subplots(1, 1)

ax2 = ax1.twinx()
m_num = 80
data = pd.read_csv('data/testdatav2/test001_80_245.csv',header=None)
data2 = -1*pd.read_csv('data/testdatav2/test001_80_245_sin.csv',header=None)
def update(frame):
    ax1.cla() # ax をクリア
    ax2.cla() # ax をクリア
    focusTime = 2+frame/50


    datay = data.iloc[int(focusTime/(0.0108))]

    print(datay)

    len = 6400*6*2*3.14/m_num

    x = np.arange(0,len,len/128)
    ax1.set_xlabel('position[km]')
    ax1.set_ylabel('density')
    ax1.set_ylim(0,5)
    ax1.plot(x,datay,color = (0,0,1),label = "density", linewidth=4)

    datay2 = data2.iloc[int(focusTime/(0.0108))]
    ax2.set_ylabel('-ULF waves')
    ax2.plot(x, datay2,color=(0,1,0),label = "-ULF waves", linewidth=4)
    h1, l1 = ax1.get_legend_handles_labels()
    h2, l2 = ax2.get_legend_handles_labels()
    ax1.legend(h1+h2, l1+l2, loc='upper right')

anim = FuncAnimation(fig, update, frames=range(225), interval=100)
anim.save("c02.gif", writer="imagemagick")
plt.close()
#plt.show()