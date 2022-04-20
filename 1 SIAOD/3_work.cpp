#include <iostream>
#include <chrono>
#include <vector>
#include <algorithm>

using namespace std;
/*
// ������� "�����������" ����� ���� - ������������ ����
void siftDown(int* numbers, int root, int bottom, long long &compares, long long &swaps)
{
    int maxChild; // ������ ������������� �������
    int done = 0; // ���� ����, ��� ���� ������������
    // ���� �� ����� �� ���������� ����
    while ((root * 2 <= bottom) && (!done))
    {
        compares++;

        if (root * 2 == bottom)    // ���� �� � ��������� ����,
            maxChild = root * 2;    // ���������� ����� �������
          // ����� ���������� ������� ������� �� ����
        else if (numbers[root * 2] > numbers[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;
        // ���� ������� ������� ������ ������������� �������
        compares+=2;
        swaps++;

        if (numbers[root] < numbers[maxChild])
        {
            int temp = numbers[root]; // ������ �� �������
            numbers[root] = numbers[maxChild];
            numbers[maxChild] = temp;
            root = maxChild;
            swaps += 2;
        }
        else { // �����
            done = 1; // �������� ������������
            swaps++;
        }
        compares++;
    }
}
// ������� ���������� �� ����
void heapSort(int* numbers, int array_size, long long &compares, long long &swaps)
{
    // ��������� ������ ��� ��������
    for (int i = (array_size / 2); i >= 0; i--){
        siftDown(numbers, i, array_size - 1, compares, swaps);
    }
    compares++;
    // ���������� ����� �������� ��������� ��������
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
	//����� ������ �������
	//�������� �-�� ���������� ��� ����� �������� �������
    MergeSort(arr, start, (start + end) / 2, compares, swaps);
	//�������� �-�� ���������� ��� ������ �������� ������� 
    MergeSort(arr, (start + end) / 2, end, compares, swaps);
	// ������������� �������
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
	cout << "������� ������ ��c����: " << endl;
	cin >> size;
	int* matrix = new int[size];
	srand(time(NULL));
	
	cout << "������� ������: " << endl;

	long long compars = 0;
	long long swaps = 0;

	for (int i = 0; i < size; i++) {
		//matrix[i] = 1 + rand() % 4000;
		//matrix[i] = i + 1;
		cin >> matrix[i];
		//cout << matrix[i] << " ";
	}
	
	cout << "��������� ������: " << endl;
	
	for (int i = 0; i < size; i++) { // ����� ������� �� ����������
		cout << matrix[i] << " ";
	}
	
	
	
	cout << endl;
	auto start = chrono::high_resolution_clock::now();
	//MergeSort(matrix, 0, size, compars, swaps);
    heapSort(matrix, size, compars, swaps);
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> time = end - start;
	
	

	
	
	cout << "��������������� ������: " << endl;
    for (int i = 0; i < size; i++) {
        cout << matrix[i] << " ";
    }
	

	cout << endl;

	cout << "������� �����: " << time.count() * 1000 << " �� " << endl;
	cout << "���-�� ������������: " << swaps << endl;
	cout << "���-�� ���������: " << compars << endl;
	cout << "����� ���-�� ��������: " << compars + swaps << endl;
	

	return 0;
}
*/