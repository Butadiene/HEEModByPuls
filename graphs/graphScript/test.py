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

data = pd.read_csv('data/testdatav9/t1.csv',header = None)
plt.imshow(data, cmap=plt.cm.get_cmap("jet"), interpolation='nearest',aspect = 800*50/m_num, extent=[0,6400*6*2*3.14/m_num,0.0036*2000,0])

ax.set_xlabel('position[km]')
ax.set_ylabel('Time[T=ULFWavePeriod]')


x = np.arange(0, 6400*6*2*3.14/m_num, 2)
y = x*0+2.5
ax.plot(x, y, color=(1,0,1), linewidth=5)

y = x*0+5.5

#ax.plot(x, y, color=(1,0,1), linewidth=4)

y = x*0+4.05
#ax.plot(x, y, color=(0,1,1), linewidth=4)


N = 10 # 線の数
x = np.linspace(-1, 1, N)

# 線のリスト : [(x0, y0), (x1, y1)]が1つの線
lines = [[(0, i), (6400*6*2*3.14/m_num, i+1)] for i in range(N)]
#lines = [[(0, i+1), (6400*6*2*3.14/m_num, i)] for i in range(N)]
lc = mc.LineCollection(lines, colors=(1,1,1), linewidths=2)
ax.add_collection(lc)

fig.text(1, 0, 'WhiteLine:ULF EWaves Bottom', ha='right')
plt.colorbar()






plt.show()