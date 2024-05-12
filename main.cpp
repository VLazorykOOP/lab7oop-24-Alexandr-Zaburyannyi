#include <iostream>
#include <cstring>
using namespace std;


template <typename T>
T MaxE(T arr[], int size) {
    T maxElement = arr[0];

    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i];
        }
    }

    return maxElement;
}

template <>
char* MaxE(char* arr[], int size) {
    char* maxLengthStr = arr[0];
    for (int i = 1; i < size; ++i) {
        if (strlen(arr[i]) > strlen(maxLengthStr)) {
            maxLengthStr = arr[i];
        }
    }

    return maxLengthStr;
}


//
// #2
template <typename T>
void selectionSort(T arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        T temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) {
       cout << arr[i] << " ";
    }
   cout <<endl;
}

template <>
void selectionSort(char* arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(arr[j], arr[minIndex]) < 0) {
                minIndex = j;
            }
        }
        char* temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

template <>
void printArray(char* arr[], int size) {
    for (int i = 0; i < size; ++i) {
       cout << arr[i] << " ";
    }
   cout <<endl;
}
void firstTask(){
    int intArr[] = { 5, 10, 3, 8, 1 };
    double doubleArr[] = { 2.5, 4.7, 3.2, 6.1, 1.9 };
    char* strArr[] = { (char*)"apple", (char*)"banana", (char*)"orange", (char*)"grape", (char*)"pineapple" };

    cout << "Max element in intArr: " << MaxE(intArr, 5) << endl;
    cout << "Max element in doubleArr: " << MaxE(doubleArr, 5) << endl;
    cout << "Longest string in strArr: " << MaxE(strArr, 5) << endl;

    int intArr2[] = { 5, 2, 8, 1, 9 };
    double doubleArr2[] = { 3.5, 1.2, 4.8, 2.1, 5.9 };
    char* strArr2[] = { (char*)"orange", (char*)"banana", (char*)"apple", (char*)"grape", (char*)"pineapple" };

    selectionSort(intArr2, 5);
    selectionSort(doubleArr2, 5);
    selectionSort(strArr2, 5);

    cout << "Sorted intArr2: ";
    printArray(intArr2, 5);
    cout << "Sorted doubleArr2: ";
    printArray(doubleArr2, 5);
    cout << "Sorted strArr2: ";
    printArray(strArr2, 5);
}

template <class T, int capacity>
class CircularQueue {
private:
    T* arr;
    int front;
    int rear;
    int currentSize;

public:
    CircularQueue() {
        arr = new T[capacity];
        front = rear = -1;
        currentSize = 0;
    }

    ~CircularQueue() {
        delete[] arr;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    bool isFull() {
        return currentSize == capacity;
    }

    void enqueue(T element) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue more elements.\n";
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }
        arr[rear] = element;
        currentSize++;
    }


    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue.\n";
            return;
        }
        if (front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % capacity;
        }
        currentSize--;
    }

    T peek() {
        if (isEmpty()) {
            cout << "Queue is empty. No elements to peek.\n";
            exit(1);
        }
        return arr[front];
    }
};

void thirdTask(){
    CircularQueue<int, 5> queue;

    queue.enqueue(11);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    cout << "Front element: " << queue.peek() << endl;

    queue.dequeue();
    queue.enqueue(6);

    cout << "Front element after dequeue and enqueue: " << queue.peek() << endl;

}

template <typename T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* p) : ptr(p) {}

    T& operator*() const {
        return *ptr;
    }

    Iterator& operator++() {
        ++ptr;
        return *this;
    }

    Iterator operator++(int) {
        Iterator tmp = *this;
        ++ptr;
        return tmp;
    }

    bool operator!=(const Iterator& other) const {
        return ptr != other.ptr;
    }
};

template <typename T, int size>
class Array {
private:
    T arr[size];

public:
    Array() {}

    T& operator[](int index) {
        return arr[index];
    }

    Iterator<T> begin() {
        return Iterator<T>(arr);
    }

    Iterator<T> end() {
        return Iterator<T>(arr + size);
    }
};

void fourthTask(){
    Array<int, 5> arr;

    for (int i = 0; i < 5; ++i) {
        arr[i] = i * 2;
    }

    cout << "Array elements: ";
    for(Iterator<int> it = arr.begin(); it != arr.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
}
int main() {
   firstTask();
//   thirdTask();
//   fourthTask();
    return 0;
}
