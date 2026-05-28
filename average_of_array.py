# Find average of numbers in an array

arr = [10, 20, 30]

total = 0

for i in range(len(arr)):
    total = total + arr[i]

average = total / len(arr)

print("Average:", average)
