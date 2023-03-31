#利用scikit-learn库函数读入波士顿房价数据集，使用pandas库对数据集进行数据预处理及分析，利用matplotlib进行一定的可视化

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_boston

boston = load_boston()#读入波士顿房价数据集
df = pd.DataFrame(boston.data,columns=boston.feature_names)#将数据集转换为pandas的DataFrame格式
df['PRICE'] = boston.target#添加一个目标变量
print(df.head())#查看数据集的前5行
print(df.describe())#查看数据集的统计信息

plt.hist(df['PRICE'],bins=100)#绘制直方图
plt.xlabel('Room')
plt.ylabel('Price')
plt.title('Histogram of House Prices')
plt.show()

plt.scatter(df['RM'],df['PRICE'])#绘制散点图
plt.xlabel('Rooms')
plt.ylabel('Price')
plt.title('Scatter of the Relationship between Rooms and Price')
plt.show()

plt.plot(df['RM'],df['PRICE'],'c')#绘制回归曲线
plt.xlabel('Rooms')
plt.ylabel('Price')
plt.title('Regression Curve of Relationship between Rooms and Price')
plt.show()

plt.bar(df['PRICE'],df['RM'],width=0.8,bottom=None,align='center')#绘制柱状图
plt.xlabel('Rooms')
plt.ylabel('Price')
plt.title('Bar of Relationship between Rooms and Price')
plt.show()
