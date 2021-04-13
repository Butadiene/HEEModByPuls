# ライブラリのインポート
import pandas as pd
import matplotlib as mpl
import matplotlib.pyplot as plt
from matplotlib.colors import Normalize # Normalizeをimport
import numpy as np

# グラフとして描画するデータ
fig, ax = plt.subplots(1, 1)

data = pd.read_csv('data/testdata/focus_mnum120.csv')
plt.imshow(data, cmap=plt.cm.get_cmap("jet"), interpolation='nearest',aspect = 0.05)
plt.colorbar()

ax.yaxis.set_major_formatter(mpl.ticker.FuncFormatter(lambda x, pos: x*0.0036))








plt.show()