#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//task1
template <typename T>
void fill_arr(T arr[], const int length, int left, int right)
{
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left + 1) + left;
}
//task2
template <typename T>
void print_arr(T arr[], const int length)
{
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b }\n";
}
//task3
template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0)
{
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
		{
			return i;
		}
	return -1;
}
//Task4
template <typename T>
int search_last_index(T arr[], const int length, T key)
{
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
		{
			return i;
		}
	return -1;
}

//Task5
int arr_min(int arr[], int length)
{
	int min = arr[0];
		for (int i = 0; i < length; i++)
		{
			if (min > arr[i])
				min = arr[i];
		}
	return min;
}
//Task6
int arr_max(int arr[], int length)
{
	int max = arr[0];
	for (int i = 0; i < length; i++)
	{
		if (max < arr[i])
			max = arr[i];
	}
	return max;
}
//Task7
int mean_value(int arr[], int length)
{
	int sum = 0;
	for (int i = 0; i < length; i++)
	{
		sum += arr[i];
	}
	return sum / length;
}
//Task8
void range(int arr[], int length, int num1, int num2)
{
	for (int i = 0; i < length; i++)
	{
		if (arr[i] >= num1 && arr[i] <= num2)
			std::cout << arr[i] << ", ";
	}
	std::cout << "\n";
}
//Task9
int count(int arr[], int length, int key)
{
	int counter = 0;
	for (int i = 0; i < length; i++)
	{
		if (key == arr[i])
			counter++;
	}
	return counter;
}
//Task10
void sort_arr(int arr[], int length)
{
	int a = 0;
	for (int j = 0; j < length; j++)
	{
		for (int i = 0; i < length - 1; i++) //LENGTH - 1 при сортировке запоминай, иначе выйдет за пределы массива
		{
			if (arr[i] > arr[i + 1])
			{
				a = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = a;
			}
		}
	}
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
	{
		std::cout << arr[i] << ", ";
	}
	std::cout << "\b\b } \n";
}

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;

	const int size = 20;
	int arr[size]{};
	fill_arr(arr, size, -50, 50);
	print_arr(arr, size);
	//
	std::cout << "Введите число для поиска спереди -> ";
	std::cin >> n;
	
	int index1 = search_index(arr, size, n);
	if (index1 != -1)
		std::cout << "Позиция числа в массиве - " << index1 << std::endl;
	else
		std::cout << "Такого числа нет\n";
	//
	std::cout << "Введите число для поиска c конца-> ";
	std::cin >> m;
	//
	int index2 = search_last_index(arr, size, m);
	if (index2 != -1)
		std::cout << "Позиция числа в массиве - " << index2 << std::endl;
	else
		std::cout << "Такого числа нет\n";
	//
	int min = arr_min(arr, size);
	std::cout << "Минимальная число -> " << min << std::endl;
	//
	int max = arr_max(arr, size);
	std::cout << "Максимальное число -> " << max << std::endl;
	//
	int value = mean_value(arr, size);
	std::cout << "Среднее арифмитическое всех элементов = " << value << std::endl;
	//
	int num1, num2;
	std::cout << "Введите начало и конец диапазона -> ";
	std::cin >> num1 >> num2;
	range(arr, size, num1, num2);
	//
	int key;
	std::cout << "Введите число для поиска совпадений -> ";
	std::cin >> key;
	int counter = count(arr, size, key);
	std::cout << "количество вхождений этого числа в массив -> " << counter << std::endl;
	//
	sort_arr(arr, size);

	return 0;
}