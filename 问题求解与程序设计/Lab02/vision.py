import numpy as np
import matplotlib.pyplot as plt

result1 = open("result.txt")
head = result1.readline()
headlist = head.split(' ')
nums = result1.readlines()

numList = []
for i in range(len(nums)):
    numList.append(int(nums[i]))

plt.bar(range(len(numList)), numList, fc='b')
plt.xlabel("key")
plt.ylabel("frequence")
plt.show()
# plt.

# print(num1)
# # head2list = head2.split('\n')
# # print(head2list)
# print(headlist)
print(head)


