import numpy as np
import matplotlib.pyplot as plt

result = open("result4.txt")
head = result.readline()
headList = head.split(' ')
M = int(headList[1])
depthList = []
rationList = []

for line in result:
    lineList = line.split(' ')
    depthList.append(int(lineList[0]))
    rationList.append(float(lineList[1]))


meanr = np.mean(rationList)
meand = np.mean(depthList)
plt.figure()
plt.title("N=" + headList[0])
plt.xlim(0, M)
plt.ylim(0, 2 * meand)
plt.plot(range(M), [meand]*M, color='r', linestyle='-')
plt.plot(range(M), depthList, color='b', lineStyle='-')
plt.show()
print(meand)