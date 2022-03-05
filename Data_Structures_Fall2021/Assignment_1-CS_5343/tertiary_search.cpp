#include <iostream>
using namespace std;

int tertiary_search(int input_arr[], int low, int high, int search_term)
{
	int mid_1 = low + ((high - low) / 3);
	int mid_2 = low + (((high - low) * 2) / 3);
	// cout << mid_1 << " " << mid_2 << "\n";
	if(low > high)
	{
		return -1;
	}
	if(search_term == input_arr[mid_1])
	{
		return mid_1;
	}
	if(search_term == input_arr[mid_2])
	{
		return mid_2;
	}
	if(search_term < input_arr[mid_1])
	{
		return tertiary_search(input_arr, low, mid_1 - 1, search_term);
	}
	if(search_term > input_arr[mid_1] and search_term < input_arr[mid_2])
	{
		low = mid_1 + 1;
		high = mid_2 - 1;
		return tertiary_search(input_arr, low, high, search_term);
	}
	return tertiary_search(input_arr, mid_2 + 1, high, search_term);

}

void print_array(int test_arr[], int len)
{
	for(int i = 0; i <= len; i ++)
	{
		cout << test_arr[i] << " ";
	}
	cout << "\n";
}

void print_test_cases(int input_arr[], int array_size, int search_term, int test_index)
{
	cout << "------------------------------\n";
	cout << "Test " << test_index << "\n";
	cout << "Input array is\n";
	print_array(input_arr, array_size);
	cout << "Search term is " << search_term << "\n";
	int search_index = tertiary_search(input_arr, 0, array_size, search_term);
	if(search_index != -1)
	{
		cout << "search term is found at position (assuming 1 Index): " << (search_index + 1) << "\n";
	}
	else
	{
		cout << "The given search term is not found in the array" << "\n";
	}
	cout << "=============================\n";
}

void sample_test_cases()
{
	int search_term = 8;
	int test_index = 1;
	int input_arr_1[] = {1,2,3,4,5,6,7,8,9};
	int array_size = (sizeof(input_arr_1)/sizeof(input_arr_1[0])) - 1;
	print_test_cases(input_arr_1, array_size, search_term, test_index);

	int input_arr_2[] = {2,4,6,8,10,12,14,16,18};
	search_term = 19;
	test_index = 2;
	array_size = (sizeof(input_arr_2)/sizeof(input_arr_2[0])) - 1;
	print_test_cases(input_arr_2, array_size, search_term, test_index);
}

void sort_arr(int arr[], int arr_size)
{
	for(int i = 0; i < arr_size; i++)
	{
		for(int j = i + 1; j < arr_size; j++)
		{
			if(arr[i] > arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int working_mode;
	cout << "Type 0 for sample test cases and 1 for testing in interactive mode:\n";
	cin >> working_mode;

	if(working_mode == 1)
	{
		cout << "Input the size of the array: \n";
		int arr_size;
		cin >> arr_size;

		cout << "Enter array elements: \n";
		int arr[arr_size];
		for(int i = 0; i < arr_size; i++)
		{
			cin >> arr[i];
		}

		cout << "Array in sorted order: \n";
		sort_arr(arr, arr_size);

		print_array(arr, (arr_size - 1));

		cout << "Enter search term: \n";
		int search_term;
		cin >> search_term;

		int search_index = tertiary_search(arr, 0, (arr_size - 1), search_term);
		if(search_index != -1)
		{
			cout << "search term is found at position (assuming 1 Index): " << (search_index + 1) << "\n";
		}
		else
		{
			cout << "The given search term is not found in the array" << "\n";
		}
		cout << "=============================\n";
	}
	else
	{
		sample_test_cases();
	}
	return 0;
}