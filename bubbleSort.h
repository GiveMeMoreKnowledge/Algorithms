// Sorting rules
enum type { increase, lessening };

template <typename T, type e>
void bubbleSort(T arr[], int n)
{
	std::function<bool(T, T)> predicate;
	bool swapped = false; // Flag event
	int cnt = 0;
	
	// Lambda expression
	switch (e)
	{
		case increase:  predicate = [] (T x, T y) { return x > y ? true : false; };
		case lessening: predicate = [] (T x, T y) { return x < y ? true : false; };
	}
	
	for (int i = 0; i < n - 1; i++)
	{
		cnt++;
		for (int j = 0; j < n - i - 1; j++)
		{
			if (predicate(arr[j], arr[j + 1]))
			{
				T tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
				swapped = true;
				cnt++;
			}
		}
		if (!swapped) break;
	}
	
	// Output array
	for (int i : n)
	{
		std::cout << i << " ";
	}
	
	// Output count steps
	std::cout << "(" << cnt << ")" << std::endl;
}

// Example 
/*
	{
		int arr[] = { 123, 321, 213, 231, 312, 321 };
		bubbleSort<int, increase> (arr, 6);
		std::cout << std::endl;
	}
	
	{
		int arr[] = { 123, 321, 213, 231, 312, 321 };
		bubbleSort<int, lessening> (arr, 6);
		std::cout << std::endl;
	}
*/