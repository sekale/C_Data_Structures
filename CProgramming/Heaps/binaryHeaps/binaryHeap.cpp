#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

class binaryHeap
{
	private:
		int *heap;
		int capacity;
		int heapSize;

	public:
		binaryHeap(int capacity);
		void insert(int insElement);
		void printHeap();
		int extractMin();
		void minHeapify(int index);
};

binaryHeap::binaryHeap(int _capacity)
{
	capacity = _capacity;
	heap = new int[capacity];
	heapSize = 0;
}

void binaryHeap::insert(int insElement)
{
	if(heapSize == capacity)
	{
		cout <<"\nOverflow";
		return;
	}

	heapSize++;
	int i = heapSize - 1;
	heap[i] = insElement;
	int parent = (i - 1) / 2;

	for(;i != 0 && heap[parent] > heap[i];)
	{
		parent = (i - 1) / 2;
		int swapTemp = heap[parent];
		heap[parent] = heap[i];
		heap[i] = swapTemp;
		i = parent;	
	}
}

int binaryHeap::extractMin()
{
	if(heapSize <= 0)
	{
		return INT_MAX;
	}

	if(heapSize == 1)
	{
		heapSize--;
		return heapSize;
	}

	int value = heap[0];
	heap[0] = heap[heapSize - 1];
	heapSize--;
	minHeapify(0);
	return value;
}

void binaryHeap::minHeapify(int index)
{
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int smallest = index;
	if(left < heapSize && heap[left] < heap[index])
	{
		smallest = left;
	}

	if(right < heapSize && heap[right] < heap[smallest])
	{
		smallest = right;
	}

	if(smallest != index)
	{
		int swapTemp = heap[smallest];
		heap[smallest] = heap[index];
		heap[index] = swapTemp;
		minHeapify(smallest);
	}
}

void binaryHeap::printHeap()
{
	int m = 0;
	for(int i = 0; i < heapSize; ++i)
	{
		cout << "\t" << heap[i];
		// m = pow(2, i);
		// for(;i < m; ++i)
		// {
		// 	if(i > heapSize)
		// 		break;
		// 	cout << "\t" << heap[i];
		// }
	}
}

int main()
{
	//driver program
	binaryHeap heapObj(10);
	heapObj.insert(3);
	heapObj.insert(2);
	heapObj.insert(1);
	heapObj.insert(15);
	heapObj.insert(5);
	heapObj.insert(4);
	heapObj.insert(45);
	heapObj.printHeap();
	cout << endl << "min" << heapObj.extractMin();
	heapObj.printHeap();
	cout << endl << "min" << heapObj.extractMin();
	heapObj.printHeap();
	cout << endl;
	return 0;
}