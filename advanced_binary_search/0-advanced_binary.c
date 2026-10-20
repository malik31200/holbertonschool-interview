
static int advanced_binary_recursive(int *array, size_t size,
				     int value, size_t offset)
{
	size_t mid;
	int result;

	if (size == 0)
		return (-1);

	print_array(array, size);
	mid = (size - 1) / 2;

	if (size == 1)
		return (array[0] == value ? (int)offset : -1);

	if (array[mid] == value)
	{
		result = advanced_binary_recursive(array, mid, value, offset);
		if (result != -1)
			return (result);
		return ((int)(offset + mid));
	}

	if (array[mid] < value)
		return (advanced_binary_recursive(array + mid + 1,
						  size - mid - 1,
						  value, offset + mid + 1));

	return (advanced_binary_recursive(array, mid + 1, value, offset));
}
