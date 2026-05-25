# 1. Print all array elements

arr = [10, 20, 30, 40]

for i in range(len(arr)):
    print(arr[i]) # 2. Find sum of array

arr = [2, 4, 6]

total = 0

for i in range(len(arr)):
    total = total + arr[i]

print("Total:", total)# 3. Find maximum number

arr = [7, 4, 10, 2]

max_num = arr[0]

for i in range(len(arr)):
    if arr[i] > max_num:
        max_num = arr[i]

print("Maximum:", max_num)# 4. Find minimum number

arr = [7, 4, 10, 2]

min_num = arr[0]

for i in range(len(arr)):
    if arr[i] < min_num:
        min_num = arr[i]

print("Minimum:", min_num)
