#include <algorithm>
#include <iostream>

using namespace std;
int arr1[500]; int arr2[500]; int arr3[500]; int n3; int n; int temp = 0;
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}
void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i = n - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int deleteElement(int arr[], int n, int x)
{
	int i;
	for (i = 0; i < n; i++)
		if (arr[i] == x)
			break;
	if (i < n)
	{
		n = n - 1;
		for (int j = i; j < n; j++)
			arr[j] = arr[j + 1];
	}
	return n;
}

bool issorted(int arr[], int n3)
{
	int a = 0;
	for (int i = 0; i < n3 - 1; i++)
	{
		if (arr[i + 1] > arr[i])
			a = 0;
		else
		{
			a = 1; break;
		}
	}
	if (a == 0)
		return true;
	else
		return false;
}

void ttsort(int* arr, int n)
{
	int i, j, n1 = 0, k = 0, n2 = 0, n3 = n, n4 = 0, r = 0;
	for (i = 0; i < n3; i++)
	{
		for (j = 0; j < 7 && j < n3; j++)
		{
			arr1[n1++] = arr[j];
		}
		if (n1 > n)
			n1 = n;
		heapSort(arr1, n1);
		n1 = 0;
		n = deleteElement(arr, n, arr1[0]);
		if (arr2[n2 - 1] < arr1[0] || i == 0)
			arr2[n2++] = arr1[0];
		else
			arr3[n4++] = arr1[0];
	}
	heapSort(arr3, n4);
	int cou = 0, l = 0;
	if (n4 > n2)
	{
		for (i = 0; i < n2 + n4; i++)
		{
			if (i < (2 * n2))
			{
				if (cou == 0)
				{
					arr[i] = arr3[l++]; cou = 1;
				}
				else
				{
					arr[i] = arr2[k++]; cou = 0;
				}
			}
			else
			{
				arr[i] = arr3[l++];
			}
		}
	}
	else
	{
		for (i = 0; i < n2 + n4; i++)
		{
			if (i < (2 * n4))
			{
				if (cou == 0)
				{
					arr[i] = arr3[l++]; cou = 1;
				}
				else
				{
					arr[i] = arr2[k++]; cou = 0;
				}
			}
			else
			{
				arr[i] = arr2[k++];
			}
		}
	}
	k = 0; l = 0;
	if (issorted(arr, n3) == false)
		ttsort(arr, n3);
	else
	{
		cout << "The numbers in sorted order are:" << endl;
		printArray(arr, n3);
	}
}

int main()
{
	cout << "Enter number of elements" << endl;
	cin >> n;
	int * arr = new int[n];
	cout << "Enter elements" << endl;
	for (int m = 0; m < n; m++)
		cin >> arr[m];
	ttsort(arr, n);
}