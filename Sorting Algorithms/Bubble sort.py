#        BUBBLE SORT

# Worst Case - Big-O(n^2)
# Best Case - Big-Ohm(n)
# Average Case - Big-Theta(n^2)


n = raw_input("Enter The Number of Input - ")
arr = list()
print("Enter The Array - ")
for i in range(int(n)):
	num = raw_input("num:")
	arr.append(int(num))
	flag = 1
for i in range(int(n)):
	for j in range(0, int(n) - i - 1):
		if arr[j] > arr[j + 1]:
			arr[j], arr[j + 1] = arr[j + 1], arr[j]

print("The Sorted Array Is - " + str(arr))