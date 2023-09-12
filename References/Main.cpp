#include <iostream>

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

int& rmax(int arr[], const int length) {
	int max_index = 0;
	for (int i = 1; i < length; i++)
		max_index = arr[i] > arr[max_index] ? i : max_index;
	
	return arr[max_index];
}

template <typename T>
void ref_dbl(T& var1, T& var2);

int* greater_arr(int arr1[], const int length1, int arr2[], const int length2, bool& first) {
	//if (length1 > length2)
		//return arr1;
	return (first = length1 > length2) ? arr1 : arr2;
}

int main() {
	setlocale(LC_ALL, "RU");
	int n, m;

	// Cсылки на переменные 
	n = 7;
	int& refn = n;
	std::cout << "n = " << n << std::endl;
	std::cout << "refn = " << refn << std::endl;
	n = 15;
	std::cout << "refn = " << n << std::endl;
	refn = 42;
	std::cout << "n = " << n << std::endl;



	const int size = 5;
	int arr[size]{ 6, 7, 2, 7, 5 };
	print_arr(arr, size);
	std::cout << "Максимум = " << rmax(arr, size) << std::endl;
	rmax(arr, size) = -1;
	print_arr(arr, size);
	rmax(arr, size) = -1;
	print_arr(arr, size);

	// Задача 1. Квадрат или обнуление
	std::cout << "Задача 1.\nВведите 2 числа -> ";
	std::cin >> n >> m;
	ref_dbl(n, m);
	std::cout << "n = " << n << std::endl;
	std::cout << "m = " << m << "\n\n";


	// Задача 2. Указатель на массив
	std::cout << "Задача 2. \nМассив А: ";
	const int sizeA = 5, sizeB = 6;
	int A[sizeA]{ 1, 2, 3, 4, 5 };
	int B[sizeB]{ 10, 20, 30, 40, 50, 60 };
	print_arr(A, sizeA);
	std::cout<< "Массив B: ";
	print_arr(B, sizeB);
	std::cout << "Длиннейший: ";
	bool f;
	int* pointer = greater_arr(A, sizeA, B, sizeB, f);
	print_arr(pointer, f ? sizeA : sizeB);



	return 0;
}

template <typename T>
void ref_dbl(T& var1, T& var2) {
	if (var1 > var2) {
		var1 *= var1;//var1 = pow(var1, 2);
		var2 *= var2;//var2 = pow(var2, 2);
		return;
	}
	var1 = 0;
	var2 = 0;
}
