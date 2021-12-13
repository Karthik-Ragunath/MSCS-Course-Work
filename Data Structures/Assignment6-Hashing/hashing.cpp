#include <bits/stdc++.h>
using namespace std;

string *resize_hash_table(string hash_table[], int current_size)
{
	int new_size = current_size * 2;
	string *new_hash_table = new string[new_size];
	for(int i = 0; i < current_size; i++)
	{
		new_hash_table[i] = hash_table[i];
	}
	return new_hash_table;
}

bool *resize_bit_map(bool bit_map[], int current_size)
{
	int new_size = current_size * 2;
	bool *new_bitmap = new bool[new_size];
	for(int i = 0; i < current_size; i++)
	{
		new_bitmap[i] = bit_map[i];
	}
	return new_bitmap;
}

void print_strings(string inputs[], int input_size)
{
	cout << "========= Printing Strings =========\n";
	for(int i = 0; i < input_size; i++)
	{
		cout << inputs[i] << "\n";
	}
	cout << "====================================\n";
}

void print_bitmaps(bool inputs[], int input_size)
{
	cout << "========= Printing Strings =========\n";
	for(int i = 0; i < input_size; i++)
	{
		cout << inputs[i] << "\n";
	}
	cout << "====================================\n";
}

int main()
{
	hash< string > str_hash;
	int input_count;
	int table_size;
	int collision_count = 0;
	int input_type;
	cout << "Enter input count: " << "\n";
	cin >> input_count;
	string *input_strs = new string[input_count];
	cout << "Do you want inputs from file: (Type 1 for yes and 0 for no)\n";
	cin >> input_type;
	if(input_type == 1)
	{
		ifstream file_stream;
		file_stream.open("string_inputs.txt");
		string line;
		int str_index = 0;
		while(getline(file_stream, line))
		{
			input_strs[str_index] = line;
			str_index++;
		}
		file_stream.close();
	}
	else
	{
		cout << "Enter inputs: " << "\n";
		for(int i = 0; i < input_count; i++)
		{
			string input;
			cin >> input;
			input_strs[i] = input;
	 	}
 	}
 	cout << "Enter the table size: " << "\n";
 	cin >> table_size;
 	bool *bit_map = new bool[table_size];
	string *hash_table = new string[table_size];
	for(int i = 0; i < table_size; i++)
	{
		bit_map[i] = false;		
	}
 	for(int i = 0; i < input_count; i++)
 	{
 		if(table_size/2 < (i+1))
 		{
 			cout << "----------------------------------------\n";
			cout << "Resized when inserting string index: " << (i + 1) << "\n";
			cout << "Collision count before resizing: " << collision_count << "\n";
			cout << "----------------------------------------\n";
 			hash_table = resize_hash_table(hash_table, table_size);
 			bit_map = resize_bit_map(bit_map, table_size);
			table_size = table_size * 2;
 		}
 		int hash_val = str_hash(input_strs[i]) % table_size;
 		if(!bit_map[hash_val])
 		{
 			bit_map[hash_val] = true;
 			hash_table[hash_val] = input_strs[i];
 			continue;
 		}
 		collision_count++;
 		for(int j = 1;;j++)
 		{
 			hash_val = (hash_val + 2 * j - 1) % table_size; // computing subsequent quadriatic squares efficiently
 			if(!bit_map[hash_val])
 			{
 				bit_map[hash_val] = true;
 				hash_table[hash_val] = input_strs[i];
 				break;
 			}
 			collision_count++;
 		}
 	}
 	cout << "==========================================\n";
 	cout << "The total number of collisions: " << collision_count << "\n";
 	cout << "==========================================\n";
	return 0;
}