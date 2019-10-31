#!/usr/bin/python3

# Merge sort practice 

def main():
	sort_array(myArray)
	print("Sorted Array: %s" % myArray)
	

def sort_array(sorted_array):
	#recursive function to split array 
	#baseline
	if len(sorted_array) > 1:
	
		mid = len(sorted_array)//2
		left_array = sorted_array[:mid]
		right_array = sorted_array[mid:]

		sort_array(left_array)
		sort_array(right_array)

		merge_arrays(left_array, right_array, sorted_array)


def merge_arrays(left_array, right_array, sorted_array):
	#merge into sorted array 
	sorted_array.clear() 

	while (left_array and right_array):
		if (left_array[0] <= right_array[0]):
			sorted_array.append(left_array[0])
			left_array.pop(0)
		else:
			sorted_array.append(right_array[0])
			right_array.pop(0)

	# Add items from remaining sorted list
	while (left_array):
		sorted_array.append(left_array[0])
		left_array.pop(0)

	while (right_array):
		sorted_array.append(right_array[0])
		right_array.pop(0)


if __name__ == '__main__':
	myArray = [2,6,8,5,91,52,11,25]
	main()
