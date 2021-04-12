# ライブラリのインポート
import matplotlib.pyplot as plt
import numpy as np

# グラフとして描画するデータ
x = np.array([1,2,3,4])
y = np.array([2,3,4,5])
#memo https://ai-gaminglife.hatenablog.com/entry/2019/04/29/204841
# https://qiita.com/ryoi084/items/c4339996c50c0cf39df4
# グラフを描画
plt.plot(x, y)
plt.show()