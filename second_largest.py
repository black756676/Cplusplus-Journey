# Find the second largest number in an array

arr = [10, 40, 20, 50, 30]

largest = arr[0]
second_largest = None

for i in range(1, len(arr)):
    if arr[i] > largest:
        second_largest = largest
        largest = arr[i]
    elif arr[i] != largest:
        if second_largest is None or arr[i] > second_largest:
            second_largest = arr[i]

print("Largest Number:", largest)
print("Second Largest Number:", second_largest)
