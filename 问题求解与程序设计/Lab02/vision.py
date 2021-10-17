import numpy as np
import matplotlib.pyplot as plt

result1 = open("result3.txt")
head = result1.readline()
headlist = head.split(' ')
nums = result1.readlines()
numList = []


for i in range(len(nums)):
    numList.append(int(nums[i]))
mean = np.mean(numList)
stdv = np.std(numList)


plt.figure()
plt.bar(range(len(numList)), numList, fc='b')
plt.plot(range(len(numList)), [mean]*len(numList), color='r', lineStyle='-')
plt.plot(range(len(numList)), [mean - stdv]*len(numList), color='r', lineStyle='-')
plt.plot(range(len(numList)), [mean + stdv]*len(numList), color='r', lineStyle='-')
plt.xlabel("key")
plt.ylabel("frequence")
plt.title("M=" + headlist[0])
plt.show()
# plt.

# print(num1)
# # head2list = head2.split('\n')
# # print(head2list)
# print(headlist)
print(head)
print(stdv)


