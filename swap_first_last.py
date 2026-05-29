arr = [10, 20, 30, 40]

first_index = 0
last_index = len(arr) - 1

temp = arr[first_index]
arr[first_index] = arr[last_index]
arr[last_index] = temp

print(arr)
