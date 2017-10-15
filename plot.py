import numpy as np
import matplotlib.pyplot as plt
x = [10,20,50,100,250,1000,500,750,1500,2000,4000,8000,10000]
t = np.zeros([13,100])
for i in range(13):
	t[i] = np.load("%d.npy"%(i+1))
y = np.mean(t, axis=1)

for i in range(13):
	plt.scatter(x[i],y[i])

x1 = np.random.uniform(0,1,10000)
x1 = x1*10000
plt.plot(np.unique(x1), np.poly1d(np.polyfit(x, y, 1))(np.unique(x1)))
#plt.plot(np.poly1d(np.polyfit(x,y,4)))
plt.show()
plt.hist(t[12],25)
plt.show()
print(np.polyfit(x,y,1))
