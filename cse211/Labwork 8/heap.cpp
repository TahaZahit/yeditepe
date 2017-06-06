#include "heap.h"
#include <iostream>

void heap::swap(int a, int b)
{
	int c = data[a];
	data[a] = data[b];
	data[b] = c;
}
int right(int i) { return i * 2 + 2; }
int left(int i) { return i * 2 + 1; }
void heap::percolate_down(int index)
{
	int left = 2 * index + 1;
	int right = left + 1;
	int min = index;
	if (left < size && data[left] < data[min]) min = left;
	if (right < size && data[right] < data[min]) min = right;
	if (min != index)
	{
		swap(index, min);
		percolate_down(min);
	}
}

void heap::inorder(int index)
{
	if (index >= size)return;
	inorder(left(index));
	std::cout << data[index] << " ";
	inorder(right(index));
}

void heap::heapify(int i)
{
	for (int i = (size - 1) / 2; i >= 0; i--)
	{
		percolate_down(i);
	}
}
int heap::min(int a, int b)
{
	if (!size) {
		std::cout << "Empty Heap!" << std::endl;
		return 0;
	}
	int m = data[a];
	for (int i = a; i < b && i < size; i++)if (m < data[i])m = data[i];
	return m;
}

heap::heap(int *d, int s)
{
	data = d;
	size = s;
	heapify(0);
}

void heap::delete_min()
{
	data[0] = data[--size];
	percolate_down(0);
}

void heap::print()
{
	for (int i = 0; i < size; i++) std::cout << data[i] << " ";
	std::cout << std::endl;
}

void heap::inorder()
{
	inorder(0);
	std::cout << std::endl;
}




