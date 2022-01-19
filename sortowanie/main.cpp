#include<iostream>
#include<math.h>
#include<time.h>
#include<windows.h>

using namespace std;

class heapSort_class { //Heap Sorting
public:
    int* harr;
    int capacity;
    int heap_size;
    ~heapSort_class() {
        delete[]harr;
    }
    heapSort_class(int cap) {
        heap_size = cap;
        capacity = cap;
        harr = new int[cap];
    }
    void printArray() {
        for (int i = 0; i < heap_size; i++)
            cout << harr[i] << " ";
        cout << endl;
    }
    int parent(int i) {
        return (i - 1) / 2;
    }
    int left(int i) {
        return (2 * i + 1);
    }
    int right(int i) {
        return (2 * i + 2);
    }
    int getMin() {
        return harr[0];
    }
    void MinHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if (l < heap_size && harr[l] < harr[i])
            smallest = l;
        if (r < heap_size && harr[r] < harr[smallest])
            smallest = r;
        if (smallest != i) {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }
    int extractMin() {
        if (heap_size <= 0)
            return 0;
        if (heap_size == 1) {
            heap_size--;
            return harr[0];
        }
        int root = harr[0];
        harr[0] = harr[heap_size - 1];
        heap_size--;
        MinHeapify(0);
        return root;
    }

    void getUnsortedArray() {
        cout << "Enter " << capacity << "no elements to sort using heapsort" << endl;
        for (int i = 0; i < capacity; i++)
            cin >> harr[i];
    }

    void heapSort() {
        int* temp = new int[capacity];
        for (int j = 0; j < capacity; j++) {
            temp[j] = extractMin();
            cout << temp[j] << " ";
        }
        delete[] temp;
    }

};

void insertionSort(int arr[]){ //Insertion Sorting
    int j = 0;
    int key;
    for (int i = 1; i < 5; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int m, int right){ //Merge Sorting-1
    int i = left;
    int j = m + 1;
    int k = left;
    int temp[5];
    while (i <= m && j <= right){
        if (arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
            k++;
        }
        else{
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= m){
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int s = left; s <= right; s++){
        arr[s] = temp[s];
    }
}
void mergeSort1(int arr[], int left, int right){ //Merge Sorting-2
    if (left < right){
        int m = (left + right) / 2;
        mergeSort1(arr, left, m);
        mergeSort1(arr, m+1, right);
        merge(arr, left, m, right);
    }
}

void quickSort(int* tablica, int left, int right){//Quick Sorting
	int v = tablica[(left + right) / 2];
	int i, j, x;
	i = left;
	j = right;
	do {
		while (tablica[i] < v) i++;
		while (tablica[j] > v) j--;
		if (i <= j) {
			x = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = x;
			i++; j--;
			}
	} while (i <= j);

	if (j > left) quickSort(tablica, left, j);
	if (i < right) quickSort(tablica, i, right);
}

void bubbleSort(int* tab, int n){//Bubble Sorting
	for (int i = 1; i < n; i++){
		for (int j = n - 1; j >= 1; j--){
			if (tab[j] < tab[j - 1]){
				int bufor;
				bufor = tab[j - 1];
				tab[j - 1] = tab[j];
				tab[j] = bufor;
			}
		}
	}
}

int main() {//Chose sorting if
    int x; //Sorting type
    cout << "1 - Heap Sorting" << endl << "2 - Insertion Sorting" << endl << "3 - Merge Sorting" << endl << "4 - Quick Sorting" << endl << "5 - Bubble Sorting" << endl;
    cout << "Enter type of sorting:" <<endl;
    cin >> x;
    if (x == 1)//Heap Sorting
        {
        int a;
        cout << "Enter Size of Min Heap" << endl;
        cin >> a;
        heapSort_class obj(a);
        obj.getUnsortedArray();
        cout << "Unsorted Array:" << endl;
        obj.printArray();
        for (int i = a / 2 - 1; i >= 0; i--) {
            obj.MinHeapify(i);
        }
        cout << "Heap Sorted Array :" << endl;
        obj.heapSort();
    }
    else if (x == 2)//Insertion Sorting
        {
        int myarray[5];
        cout << "Enter 5 numbers: " << endl;
        for (int i = 0; i < 5; i++){
            cin >> myarray[i];
        }
        cout << "Unsorted Array: " << endl;
        for (int i = 0; i < 5; i++){
            cout<<myarray[i]<<" ";
        }
        insertionSort(myarray);
        cout << endl << "Insertion Sort Array: " << endl;
        for (int i = 0; i < 5; i++){
            cout << myarray[i] << " ";
        }
    }
    else if (x == 3)//Merge Sorting
        {
        cout << "Enter 5 numbers: ";
        int myarr[5];
        for (int i = 0; i < 5; i++){
            cin >> myarr[i];
        }
        cout << "Unsorted Array: " << endl;
        for (int i = 0; i < 5; i++){
            cout << myarr[i] << " ";
        }
        mergeSort1(myarr, 0, 4);
        cout << endl << "Merge Sort Array: " << endl;
        for (int i = 0; i < 5; i++){
            cout << myarr[i] << " ";
        }
    }
    else if (x == 4)//Quick Sorting
        {
        int amount;
        clock_t start, stop;
        double time1;
        cout << "How many random numbers in Array? ";
        cin >> amount;
        int* array1;
        array1 = new int[amount];
        srand(time(NULL));
        for (int i = 0; i < amount; i++){
            array1[i] = rand() % 1000000 + 1;
        }
        cout << "Unsorted Array: " << endl;
        for (int i = 0; i < amount; i++){
            cout << array1[i] << " ";
        }
        cout << endl << "Quick Sorting. Wait a moment..." << endl;
        start = clock();
        quickSort(array1, 0, amount-1);
        stop = clock();
        time1 = (double)(stop - start) / CLOCKS_PER_SEC;
        cout << "Quick Sort Array: " << endl;
        for (int i = 0; i < amount; i++){
            cout << array1[i] << " ";
        }
        cout << endl << "Quick Sort time: " << time1 << " s" << endl;
        delete[] array1;
    }
    else if (x == 5)//Bubble Sorting
        {
        int amount;
        clock_t start, stop;
        double time1;
        cout << "How many random numbers in Array? ";
        cin >> amount;
        int* array1;
        array1 = new int[amount];
        srand(time(NULL));
        for (int i = 0; i < amount; i++){
            array1[i] = rand() % 100000 + 1;
        }
        cout << "Unsorted Array: " << endl;
        for (int i = 0; i < amount; i++){
            cout << array1[i] << " ";
        }
        cout << endl << "Bubble Sorting. Wait a moment..." << endl;
        start = clock();
        bubbleSort(array1, amount);
        stop = clock();
        time1 = (double)(stop - start) / CLOCKS_PER_SEC;
        cout << "Bubble Sort Array: " << endl;
        for (int i = 0; i < amount; i++){
            cout << array1[i] << " ";
        }
        cout << endl << "Bubble Sort time: " << time1 << " s" << endl;
        delete[] array1;
        }
    else
        {
        cout << "Wrong number" << endl;
    }
return 0;
}
