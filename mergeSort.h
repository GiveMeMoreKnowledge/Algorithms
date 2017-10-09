// Rules sort
enum type { increase, lessening };

template <typename T, type e>
void mergeSort(T arr[], int n)
{
    std::function<bool(T, T)> predicate;

	// Lambda expression
    switch(e)
    {
        case increase:  predicate = [] (T x, T y) { return x > y ? true : false; }; break;
        case lessening: predicate = [] (T x, T y) { return x < y ? true : false; }; break;
    }
	
	// Algorithm
    if (n > 1)
    {
        int const left_size = n / 2;
        int const right_size = n - left_size;

		// Recursion
        mergeSort<T, e> (&arr[0], left_size);
        mergeSort<T, e> (&arr[left_size], right_size);

		// Variables left block, right block and tempopary
        int lidx = 0, ridx = left_size, idx = 0;
        std::unique_ptr<T[]> tmp_arr(new T[n]);

        while(lidx < left_size || ridx < n)
        {
            if (predicate(arr[lidx], arr[ridx]))
            {
                tmp_arr[idx++] = std::move(arr[lidx]);
                lidx++;
            }
            else
            {
                tmp_arr[idx++] = std::move(arr[ridx]);
                ridx++;
            }

            if (lidx == left_size)
            {
                std::copy(std::make_move_iterator(&arr[ridx]),
                          std::make_move_iterator(&arr[n]),
                          &tmp_arr[idx]); break;
            }
            if (ridx == n)
            {
                std::copy(std::make_move_iterator(&arr[lidx]),
                          std::make_move_iterator(&arr[left_size]),
                          &tmp_arr[idx]); break;
            }
        }

        std::copy(&tmp_arr[0], &tmp_arr[n], arr);
    }

	// Output array
    for (int i = 0; i < n; i++)
    {
        std::cout << *(arr + i) << " ";
    }

    std::cout << std::endl;
}

/* Example
{
    int arr[] = { 6, 4, 2, 7, 8, 3, 5, 123, 354, 65 };
    mergeSort<int, increase>(arr, 10);
    std::cout << std::endl;
}

{
    int arr[] = { 9, 4, 2, 7, 8, 3, 5, 123, 354, 65 };
    mergeSort<int, lessening>(arr, 10);
	std::cout << std::endl;
}
*/