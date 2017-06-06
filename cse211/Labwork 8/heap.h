

class heap {
private:
	int * data;
	int size;
	void percolate_down(int);
	void swap(int, int);
	void inorder(int);
	void heapify(int);
	int min(int, int);
public:
	heap(int *, int);
	void delete_min();
	void print();
	void inorder();
};
