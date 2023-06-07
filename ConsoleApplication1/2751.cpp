#include "pch.h"

void merge(int * A, int begin, int middle, int end, int* sortedarray)
{
	int sortedInd = begin;
	int i = begin;
	int j = middle + 1;

	while (i <= middle && j <= end)
	{
		if (A[i] < A[j])
		{
			sortedarray[sortedInd] = A[i++];
		}
		else
		{
			sortedarray[sortedInd] = A[j++];
		}
		++sortedInd;
	}

	if (i > middle)
	{
		while (j <= end)
		{
			sortedarray[sortedInd] = A[j++];
			sortedInd++;
		}
	}

	if (j > end)
	{
		while (i <= middle)
		{
			sortedarray[sortedInd] = A[i++];
			sortedInd++;
		}
	}

	for (int k = begin; k <= end; ++k) A[k] = sortedarray[k];
}

void mergeSort(int* A, int begin, int end, int* array)
{
	if (begin < end)
	{
		int middle = (begin + end) / 2;
		mergeSort(A, begin, middle, array);
		mergeSort(A, middle + 1, end, array);

		merge(A, begin, middle, end, array);
	}
}


int main()
{
	int n = 0;

	cin >> n;

	int* A = new int[n];
	int* sortedarray = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> A[i];
	}

	mergeSort(A, 0, n - 1, sortedarray);

	for (int i = 0; i < n; ++i)
	{
		cout << A[i] << endl;
	}
	return 0;
}