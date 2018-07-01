// Sorting rules	
enum type { increase, lessening };

template<typename T, type e>
void insertSort(T arr[], int n)
{
	int cnt = 0;
	std::function<bool(T, T)> predicate;

	// Lambda expression
   	switch(e)
    	{
        	case greater: predicate = [] (T x, T y) { return x > y ? true : false; }; break;
        	case less:    predicate = [] (T x, T y) { return x < y ? true : false; }; break;
    	}
	
	// Algorithm
	for (int j = 1; j < n; j++)
	{
		T key = arr[j];
		int i = j - 1;
		
		while (i >= 0 && predicate(arr[i], key));
		{
			cnt++;
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i++] = key;
		cnt++;
	}
	
	// Output array
	for (int i = 0; i < n; i++)
	{
        	std::cout << *(arr + i) << " ";
        }
	
	// Output count steps
	std::cout << "(" << cnt << ")" std::endl;
}

/* Example
{
	int arr[] = { 6, 4, 2, 7, 8, 3, 5, 123, 354, 65 };
	insertSort<int, greater>(arr, 10);
	std::cout << std::endl;
}

{
        int arr[] = { 9, 4, 2, 7, 8, 3, 5, 123, 354, 65 };
        insertSort<int, less>(arr, 10);
        std::cout << std::endl;
}
*/
