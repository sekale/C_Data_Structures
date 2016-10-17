#include <iostream>
#include <vector>

using namespace std;

void max_heapify(vector<int> &usorted_arr, int n, int i);
void heapsort(vector<int> &usorted_arr, int n);

int main()
{
	vector<int> usorted_arr;

	usorted_arr.push_back(4);
	usorted_arr.push_back(10);
	usorted_arr.push_back(5);
	usorted_arr.push_back(3);
	usorted_arr.push_back(1);
	usorted_arr.push_back(7);
	usorted_arr.push_back(6);

	heapsort(usorted_arr, usorted_arr.size());
}

void heapsort(vector<int> &usorted_arr, int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
	{
		max_heapify(usorted_arr, n, i);
	}
	vector<int>::iterator itr = usorted_arr.begin();

	cout << "\nAfter Heapification \n";
	cout << endl;

	while(itr != usorted_arr.end())
	{
		cout << "\t" << *(itr);
		itr++;
	}

	cout << endl;
		
	for(int j = n - 1; j >= 0; j--)
	{
		swap(usorted_arr[0], usorted_arr[j]);
		max_heapify(usorted_arr, j ,0);
	}

	itr = usorted_arr.begin();

	cout << "\nAfter Sort \n";


	while(itr != usorted_arr.end())
	{
		cout << "\t" << *(itr);
		itr++;
	}
		
}

void max_heapify(vector<int> &usorted_arr, int n, int i)
{
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if(left < n && usorted_arr[largest] < usorted_arr[left])
	{
		largest = left;
	}

	if(right < n && usorted_arr[largest] < usorted_arr[right])
	{
		largest = right;
	}

	if(largest != i)
	{
		swap(usorted_arr[largest], usorted_arr[i]);
		max_heapify(usorted_arr, n, largest);
	}
}