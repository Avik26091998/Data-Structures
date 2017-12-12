#        INSERTON SORT

# Worst Case - Big-O(n^2)
# Best Case - Big-Ohm(n)
# Average Case - Big-Theta(n^2)


n = raw_input("Enter The Number of Input - ")
arr = list()
print("Enter The Array - ")
for i in range(int(n)):
	num = raw_input("num:")
	arr.append(int(num))
for i in range(1, int(n)):
	hole = i
	val = arr[hole]
	while hole > 0 and arr[hole - 1] > val:
		print(hole)
		arr[hole] = arr[hole - 1]
		hole -= 1
	arr[hole] = val

print("The Sorted Array Is - " + str(arr))