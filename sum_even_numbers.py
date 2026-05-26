# Sum of even numbers in an array

arr = [3, 6, 8, 11, 14]

total = 0

for i in range(len(arr)):
    if arr[i] % 2 == 0:
        total = total + arr[i]

print("Even Sum:", total)
