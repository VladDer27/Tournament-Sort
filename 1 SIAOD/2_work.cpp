#include <iostream>
#include <ctime>
#include <chrono>

using namespace std;



void bubbleSort(int* num, int size)
{
	auto start = chrono::high_resolution_clock::now();
	long long perem = 0;
	long long sravn = 0;
	for (int i = 0; i < size - 1; i++)
	{
		sravn++;
		if (i % 100000 == 0)
			cout << i << endl;
		for (int j = (size - 1); j > i; j--) // ��� ���� ��������� ����� i-���
		{
			sravn++;
			if (num[j - 1] > num[j]) // ���� ������� ������� ������ �����������
			{
				int temp = num[j - 1]; // ������ �� �������
				num[j - 1] = num[j];
				num[j] = temp;
				perem = perem + 3;
			}
			sravn++;
		}
		sravn++;
	}
	sravn++;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> time = end - start;
	cout << "������� �����: " << time.count() * 1000 << " �� " << endl;
	cout << "���-�� �����������: " << perem << endl;
	cout << "���-�� ���������: " << sravn << endl;
	cout << "����� ���-�� ��������: " << perem + sravn << endl;
}



void insertionSort(int* x, int size)
{
	auto start = chrono::high_resolution_clock::now();
	long long perem = 0;
	long long sravn = 0;
	int j, key;
	for (int i = 1; i < size; i++) {
		sravn++;
		key = x[i]; perem++;
		j = i; perem++;
		while ((j > 0) && (x[j - 1] > key)) {
			sravn++;
			x[j] = x[j - 1];
			perem++;
			j = j - 1;
			perem++;
		}
		sravn++;
		x[j] = key;
		perem++;
	}
	sravn++;
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<float> time = end - start;
	cout << "������� �����: " << time.count() * 1000 << " �� " << endl;
	cout << "���-�� �����������: " << perem << endl;
	cout << "���-�� ���������: " << sravn << endl;
	cout << "����� ���-�� ��������: " << perem + sravn << endl;
}
/*
int main() {
	setlocale(LC_ALL, "russian");
	int size;
	cout << "������� ������ ��c����: " << endl;
	cin >> size;
	int* matrix = new int[size];
	srand(time(NULL));
	// ���������� ������� ���
	//cout << "������� ������: " << endl;
	for (int i = 0; i < size; i++) {
		//matrix[i] = 1 + rand() % 4000;
		matrix[i] = size - i;
		//cin >> matrix[i];
		//cout << matrix[i] << " ";
	}
	
	cout << "��������� ������: " << endl;
	for (int i = 0; i < size; i++) { // ����� ������� �� ����������
		cout << matrix[i] << " ";
	}
	

	cout << endl;
	//bubbleSort(matrix, size);
	insertionSort(matrix, size);
	
	
	cout << "��������������� ������: " << endl;
	for (int i = 0; i < size; i++) {
		cout << matrix[i] << " ";
	}
	

	return 0;
}
*/