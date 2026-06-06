# Find the index of an element in a list

arr = [10, 20, 30, 40]
target = 30

found_index = -1

for i in range(len(arr)):
    if arr[i] == target:
        found_index = i
        break

if found_index == -1:
    print("Element not found")
else:
    print("Element found at index:", found_index)
