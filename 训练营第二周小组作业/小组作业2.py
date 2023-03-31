#代码实现线性回归（最小二乘法+梯度下降法），使用实现好的算法对房价进行预测。

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.datasets import load_boston

boston = load_boston()#读入波士顿房价数据集
df = pd.DataFrame(boston.data,columns=boston.feature_names)#将数据集转换为pandas的DataFrame格式
df['PRICE'] = boston.target#添加一个目标变量
print(df.head())#查看数据集的前5行
print(df.describe())#查看数据集的统计信息

#定义线性回归模型
class LinearRegression:
    def __init__(self,alpha=0.01,max_iter=1000,method='gd'):
        self.alpha = alpha
        self.max_iter = max_iter
        self.method = method
        self.theta = None

#定义代价函数
    def cost(self,X,y,theta):
        m = len(y)
        J = np.sum((X.dot(theta) - y) ** 2) / (2 * m)
        return J

#定义梯度下降方法
    def gradient_descent(self,X,y,theta):
        m = len(y)
        J_history = np.zeros(self.max_iter)
        for i in range(self.max_iter):
            theta = theta - self.alpha / m * (X.T.dot(X.dot(theta) - y))
            J_history[i] = self.cost(X,y,theta)
        return theta, J_history

#定义最小二乘法方法、
    def least_squares(self,X,y):
        self.theta = np.linalg.inv(X.T.dot(X)).dot(X.T).dot(y)

#训练模型
    def fit(self,X,y):
        m, n = X.shape
        X = np.hstack((np.ones((m,1)), X))#添加一列为1的特征（偏置项）
        if self.method == 'gd':
            self.theta = np.zeros((n + 1, 1))#初始化模型参数
            self.theta, J_history = self.gradient_descent(X,y,self.theta)#进行梯度下降优化
        elif self.method == 'ls':
            self.least_squares(X,y)#进行最小二乘法优化

#预测
    def predict(self,X):
        m = X.shape[0]
        X = np.hstack((np.ones((m,1)), X))#添加一列为1的特征（偏置项）
        return X.dot(self.theta)#进行预测

#定义特征和标签
X = df[['RM']].values
y = df['PRICE'].values
#区分训练集和测试集
train_size = int(0.8 * len(X))
X_train, X_test = X[:train_size], X[train_size:]
y_train, y_test = y[:train_size], y[train_size:]
#训练模型
model = LinearRegression(alpha=0.01, max_iter=1000, method='gd')
model.fit(X_train, y_train)


#绘制训练集的散点图和回归曲线
plt.scatter(X_train, y_train, color = 'purple')
plt.title('Training Set')
plt.xlabel('Rooms')
plt.ylabel('Price')
plt.show()
plt.plot(X_train, model.predict(X_train), color = 'red')
plt.title('Training Set')
plt.xlabel('Rooms')
plt.ylabel('Price')
plt.show()

#进行预测
y_pred = model.predict(X_test)
#为了避免y_test与y_pred的形状不匹配，使用reshape()函数转换成相同的形状
y_test = y_test.reshape(-1,1)
#计算均方误差
mse = np.mean((y_pred - y_test) ** 2)
print('MSE:', mse)#输出误差