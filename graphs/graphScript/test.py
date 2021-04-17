# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import matplotlib.collections as mc
import numpy as np

# グラフとして描画するデータ
fig, ax = plt.subplots(1, 1)

m_num = 80

data = pd.read_csv('data/testdatav2/test001_80_270.csv',header = None)
plt.imshow(data, cmap=plt.cm.get_cmap("jet"), interpolation='nearest',aspect = 500, extent=[0,6400*6*2*3.14/m_num,0.0036*2000,0])

ax.set_xlabel('position[km]')
ax.set_ylabel('Time[T=ULFWavePeriod]')


x = np.arange(0, 6400*6*2*3.14/m_num, 2)
y = x*0+3.05
#ax.plot(x, y, color=(1,0,0), linewidth=4)

y = x*0+3.35
#ax.plot(x, y, color=(0,1,0), linewidth=4)

y = x*0+4.05
#ax.plot(x, y, color=(0,1,1), linewidth=4)


N = 10 # 線の数
x = np.linspace(-1, 1, N)

# 線のリスト : [(x0, y0), (x1, y1)]が1つの線
lines = [[(0, (i+1)), (6400*6*2*3.14/m_num, i)] for i in range(N)]
lc = mc.LineCollection(lines, colors=(1,1,1), linewidths=1,linestyles = "dotted")
#ax.add_collection(lc)

fig.text(1, 0, 'WhiteLine:ULF Waves Top', ha='right')
plt.colorbar()






plt.show()