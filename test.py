# total = 0
# while True:
#     s = input("请输入一个浮点数或整数(quit结束程序)：")
#     if s.lower() == 'quit':
#         break
#     total += float(s)
# print('累加和为：', total)

s = input("请输入字符串：")
sLower = s.lower()
sUnique = ""

for c in s:
    cLower = c.lower()
    if c.isalpha():
        if sLower.count(cLower) == 1:
            sUnique += c

if len(sUnique) < 5:
    print("找不到5个不重复字母！")
else:
    print(sUnique[:5])

# stuScores = "李白 82 78;王伟 72 71"
# stuList = stuScores.split(";")

# print("姓名\t总分\t平均分")
# for stu in stuList:
#     stuInfo = stu.split(" ")
#     total = int(stuInfo[1]) + int(stuInfo[2])
#     print(stuInfo[0] + '\t' + str(total) + '\t' + str(total / 2))


