# Check if an element exists in an array/list

arr = [10, 20, 30, 40]
target = 30

found = False

for i in range(len(arr)):
    if arr[i] == target:
        found = True
        break

if found == True:
    print("Element exists in the array")
else:
    print("Element does not exist in the array")
