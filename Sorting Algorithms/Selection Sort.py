#        SELECTION SORT

# Worst Case - Big-O(n^2)
# Best Case - Big-Ohm(n^2)
# Average Case - Big-Theta(n^2)


n = raw_input("Enter The Number of Input - ")
arr = list()
print("Enter The Array - ")
for i in range(int(n)):
	num = raw_input("num:")
	arr.append(int(num))
for i in range(int(n)):
	index = i
	for j in range(i+1, int(n)):
		if(arr[j] < arr[index]):
			index = j
	arr[i], arr[index] = arr[index], arr[i]

print("The Sorted Array is - " + str(arr))
