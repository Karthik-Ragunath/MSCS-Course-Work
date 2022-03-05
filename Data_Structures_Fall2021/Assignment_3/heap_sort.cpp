#include<iostream>
using namespace std;


void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void print_arr(int a[], int size)
{
	for(int i = 1; i <= size; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n";
}

void percolate_down(int arr[], int current_index, int last_index, int is_descending)
{
	if(current_index <= last_index)
	{
		if(current_index * 2 <= last_index)
		{
			if((current_index * 2 + 1) <= last_index)
			{
				if(is_descending != 1)
				{
					int bigger_child_index = arr[current_index * 2 + 1] >= arr[current_index * 2] ? (current_index * 2 + 1) : (current_index * 2);
					if(arr[bigger_child_index] >= arr[current_index])
					{
						swap(arr[bigger_child_index], arr[current_index]);
						return percolate_down(arr, bigger_child_index, last_index, is_descending);
					}
					else
					{
						return;
					}
				}
				else
				{
					int smaller_child_index = arr[current_index * 2 + 1] <= arr[current_index * 2] ? (current_index * 2 + 1) : (current_index * 2);
					if(arr[smaller_child_index] <= arr[current_index])
					{
						swap(arr[smaller_child_index], arr[current_index]);
						return percolate_down(arr, smaller_child_index, last_index, is_descending);
					}
					else
					{
						return;
					}
				}
			}
			else
			{
				if(is_descending != 1)
				{
					if(arr[(current_index * 2)] >= arr[current_index])
					{
						swap(arr[(current_index * 2)], arr[current_index]);
						return percolate_down(arr, (current_index * 2), last_index, is_descending);
					}
					else
					{
						return;
					}
				}
				else
				{
					if(arr[(current_index * 2)] <= arr[current_index])
					{
						swap(arr[(current_index * 2)], arr[current_index]);
						return percolate_down(arr, (current_index * 2), last_index, is_descending);
					}
					else
					{
						return;
					}
				}
			}
		}
	}
}

void floyds_algorithm_heapify(int arr[], int arr_size, int is_descending)
{
	int n = arr_size / 2;
	for(int i = n; i >= 1; i--)
	{
		percolate_down(arr, i, arr_size, is_descending);
	}
}

void heap_sort(int arr[], int size, int is_descending)
{
	for(int i = 1, last_index = size; i <= size; i++)
	{
		swap(arr[1], arr[last_index]);
		last_index = last_index - 1;
		percolate_down(arr, 1, last_index, is_descending);
	}
}

int main()
{
	int is_descending;
	int n;
	cout << "Enter the number of elements in unsorted array:" << "\n";
	cin >> n;

	cout << "Input the array values:" << "\n";
	int arr[n + 1];
	arr[0] = n;
	for(int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	cout << "In what order to be sorted, ascending or descending? For ascending, press 0 and for descending, press 1" << "\n";
	cin >> is_descending;
	cout << "\n";

	cout << "------------------------------------------\n";
	cout << "The given array is: (Before heapifying the array)" << "\n";
	print_arr(arr, n);
	cout << "------------------------------------------\n";
	cout << "\n";

	cout << "------------------------------------------\n";
	floyds_algorithm_heapify(arr, n, is_descending);
	cout << "Array after building a heap from it:" << "\n";
	print_arr(arr, n);
	cout << "------------------------------------------\n";
	cout << "\n";

	cout << "------------------------------------------\n";
	heap_sort(arr, n, is_descending);
	cout << "Array after performing Heap Sort" << "\n";
	print_arr(arr, n);
	cout << "------------------------------------------\n";
	cout << "\n";
	return 0;
}