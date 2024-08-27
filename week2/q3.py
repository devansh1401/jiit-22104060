def duplicate(numbers):
    # Create a dictionary to store the count of each number
    count_dict = {}
    
    # Count occurrences of each number
    for num in numbers:
        if num in count_dict:
            count_dict[num] += 1
        else:
            count_dict[num] = 1
    
    # Find numbers with count greater than 1
    duplicates = [num for num, count in count_dict.items() if count > 1]
    
    return duplicates

# Test the function
test_list = [1, 2, 3, 4, 2, 5, 6, 3, 7, 8]
result = duplicate(test_list)
print("Duplicates:", result)