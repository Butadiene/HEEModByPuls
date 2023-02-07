# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import matplotlib.collections as mc
import numpy as np

# グラフとして描画するデータ
fig, ax = plt.subplots(1, 1)

m_num = 10
dt = 0.003
steps = 1000

data = pd.read_csv('data/testdtv2/0t2.csv',header = None)

plt.subplots_adjust(left=0, right=1,  bottom=0.1, top=0.95)

aspfactor = 0.8*1.0/6.0/2.0*(0.0072/dt)*(1000/steps)
plt.imshow(data, cmap=plt.cm.get_cmap("jet"), interpolation='nearest',aspect = aspfactor*10000*50/m_num, extent=[0,6400*6*2*3.14/m_num,dt*steps,0])#, vmin = 0, vmax = 3)

ax.set_xlabel('position[km]')
ax.set_ylabel('Time[T=ULFWavePeriod]')


x = np.arange(0, 6400*6*2*3.14/m_num, 2)
y = x*0+2.5
#ax.plot(x, y, color=(1,0,1), linewidth=5)

y = x*0+5.5

#ax.plot(x, y, color=(1,0,1), linewidth=4)

y = x*0+4.05
#ax.plot(x, y, color=(0,1,1), linewidth=4)


N = 10 # 線の数
x = np.linspace(-1, 1, N)

# 線のリスト : [(x0, y0), (x1, y1)]が1つの線
#lines = [[(0, i), (6400*6*2*3.14/m_num, i+1)] for i in range(N)]
lines = [[(6400*6*2*3.14/m_num, i-0.5), (0, i+0.5)] for i in range(N)]

lc = mc.LineCollection(lines, colors=(1,1,1), linewidths=1)
ax.add_collection(lc)

#fig.text(1, 0, 'WhiteLine:ULF BWaves Bottom', ha='right')
plt.colorbar()





plt.savefig("km10W-503.jpg")
plt.show()
