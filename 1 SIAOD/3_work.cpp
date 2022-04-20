#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
/*
// Функция "просеивания" через кучу - формирование кучи
void siftDown(int* numbers, int root, int bottom, long long &compares, long long &swaps)
{
    int maxChild; // индекс максимального потомка
    int done = 0; // флаг того, что куча сформирована
    // Пока не дошли до последнего ряда
    while ((root * 2 <= bottom) && (!done))
    {
        compares++;

        if (root * 2 == bottom)    // если мы в последнем ряду,
            maxChild = root * 2;    // запоминаем левый потомок
          // иначе запоминаем больший потомок из двух
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // если элемент вершины меньше максимального потомка
        compares+=2;
        swaps++;

        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // меняем их местами
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
            swaps += 2;
        }
        else { // иначе
            done = 1; // пирамида сформирована
            swaps++;
        }
        compares++;
    }
}
// Функция сортировки на куче
void heapSort(int* numbers, int array_size, long long &compares, long long &swaps)
{
    // Формируем нижний ряд пирамиды
    for (int i = (array_size / 2); i >= 0; i--){
        siftDown(numbers, i, array_size - 1, compares, swaps);
    }
    compares++;
    // Просеиваем через пирамиду остальные элементы
    for (int i = array_size - 1; i >= 1; i--)
    {
        int temp = numbers[0];
        numbers[0] = numbers[i];
        numbers[i] = temp;
        siftDown(numbers, 0, i - 1, compares, swaps);
        swaps++;
    }
    compares++;
}
*/




void MergeSort(int* arr, int start, int end, long long& compares, long long& swaps) {
    if (end - start < 2) {
        return;
    }
    compares++;
    if (end - start == 2 && arr[start] > arr[end - 1]) {
        swap(arr[start], arr[end - 1]);
        swaps++;
        return;
    }
    compares += 2;
	//Делим массив пополам
	//Вызываем ф-ию сортировки для левой половины массива
    MergeSort(arr, start, (start + end) / 2, compares, swaps);
	//Вызываем ф-ию сортировки для правой половины массива 
    MergeSort(arr, (start + end) / 2, end, compares, swaps);
	// Осуществление слияния
    vector<int> add_arr;
    int start_1 = start, end_1 = (start + end) / 2;
    int start_2 = end_1, end_2 = end;
    while (add_arr.size() < end - start) {
        compares++;
        if ((start_1 >= end_1) || (start_2 < end_2 && arr[start_2] < arr[start_1])) {
            add_arr.push_back(arr[start_2]);
            swaps++;
            start_2++;
        }
        else {
            add_arr.push_back(arr[start_1]);
            swaps++;
            start_1++;
        }
        compares += 3;
    }
    compares++;
    for (int i = start; i < end; i++) {
        arr[i] = add_arr[i - start];
        swaps++;
    }
    compares++;
}
/*
int main() {
	setlocale(LC_ALL, "russian");
	int size;
	cout << "Введите размер маcсива: " << endl;
	cin >> size;
	int* matrix = new int[size];
	srand(time(NULL));
	
	cout << "Введите массив: " << endl;

	long long compars = 0;
	long long swaps = 0;

	for (int i = 0; i < size; i++) {
		//matrix[i] = 1 + rand() % 4000;
		//matrix[i] = i + 1;
		cin >> matrix[i];
		//cout << matrix[i] << " ";
	}
	
	cout << "Введенный массив: " << endl;
	
	for (int i = 0; i < size; i++) { // вывод массива до сортировки
		cout << matrix[i] << " ";
	}
	
	
	
	cout << endl;
	auto start = chrono::high_resolution_clock::now();
	//MergeSort(matrix, 0, size, compars, swaps);
    heapSort(matrix, size, compars, swaps);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> time = end - start;
	
	

	
	
	cout << "Отсортированный массив: " << endl;
    for (int i = 0; i < size; i++) {
        cout << matrix[i] << " ";
    }
	

	cout << endl;

	cout << "Искомое время: " << time.count() * 1000 << " мс " << endl;
	cout << "Кол-во присваиваний: " << swaps << endl;
	cout << "Кол-во сравнений: " << compars << endl;
	cout << "Общее кол-во операций: " << compars + swaps << endl;
	

	return 0;
}
*/