# Count of how many times a number appears in an array lets goo

arr = [2, 5, 2, 8, 2]
target = 2

count = 0

for i in range(len(arr)):
    if arr[i] == target:
        count = count + 1

print("Target:", target)
print("Count:", count)
