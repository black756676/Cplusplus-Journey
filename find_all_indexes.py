# Find all indexes of a target element in a list

arr = [10, 20, 30, 20, 40, 20]
target = 20

found = False

for i in range(len(arr)):
    if arr[i] == target:
        print("Element found at index:", i)
        found = True

if found == False:
    print("Element not found")
