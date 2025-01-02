#include<bits/stdc++.h>
using namespace std;

class Heap {
private:
    vector<int> heap;
    bool isMinHeap;

    // Compare function based on heap type
    bool compare(int a, int b) {
        return isMinHeap ? (a < b) : (a > b);
    }

    // Heapify up (used during insertion)
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (compare(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    // Heapify down (used during deletion)
    void heapifyDown(int index) {
        int size = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int smallestOrLargest = index;

            if (left < size && compare(heap[left], heap[smallestOrLargest])) {
                smallestOrLargest = left;
            }
            if (right < size && compare(heap[right], heap[smallestOrLargest])) {
                smallestOrLargest = right;
            }

            if (smallestOrLargest != index) {
                swap(heap[index], heap[smallestOrLargest]);
                index = smallestOrLargest;
            } else {
                break;
            }
        }
    }

public:
    // Constructor
    Heap(bool isMinHeap = true) : isMinHeap(isMinHeap) {}

    // Insert element into the heap
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    // Peek at the root element (min or max)
    int peek() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        return heap[0];
    }

    // Extract the root element (min or max)
    int extract() {
        if (heap.empty()) {
            throw runtime_error("Heap is empty");
        }
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Decrease or increase a key at a specific index
    void changeKey(int index, int newValue) {
        if (index < 0 || index >= heap.size()) {
            throw out_of_range("Index out of range");
        }
        int oldValue = heap[index];
        heap[index] = newValue;
        if (compare(newValue, oldValue)) {
            heapifyUp(index);
        } else {
            heapifyDown(index);
        }
    }

    // Delete an arbitrary element by index
    void deleteAt(int index) {
        changeKey(index, isMinHeap ? INT_MIN : INT_MAX);
        extract();
    }

    // Build a heap from an array
    void buildHeap(vector<int>& arr) {
        heap = arr;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i) {
            heapifyDown(i);
        }
    }

    // Heap sort (modifies the heap)
    vector<int> heapSort() {
        vector<int> sorted;
        while (!heap.empty()) {
            sorted.push_back(extract());
        }
        return sorted;
    }

    // Print the heap (for debugging)
    void printHeap() {
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    // Example usage
    Heap minHeap(true); // Min-heap
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(20);
    minHeap.insert(2);

    cout << "Heap elements: ";
    minHeap.printHeap();

    cout << "Peek: " << minHeap.peek() << endl;
    cout << "Extract: " << minHeap.extract() << endl;

    cout << "Heap after extraction: ";
    minHeap.printHeap();

    minHeap.changeKey(1, 1);
    cout << "Heap after changeKey: ";
    minHeap.printHeap();

    minHeap.deleteAt(0);
    cout << "Heap after deleteAt: ";
    minHeap.printHeap();

    vector<int> arr = {3, 9, 2, 1, 4, 8};
    Heap maxHeap(false); // Max-heap
    maxHeap.buildHeap(arr);
    cout << "Max-heap built from array: ";
    maxHeap.printHeap();

    vector<int> sorted = maxHeap.heapSort();
    cout << "Heap sorted array: ";
    for (int val : sorted) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
