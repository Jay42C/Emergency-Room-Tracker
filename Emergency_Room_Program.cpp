// Jesse Chairez
//C++ program to track patients entering and leaving a hospital emergency room.

#include <iostream>
#include <vector>
#include <string>

class PatientHeap {
private:
    std::vector<std::string> heap;

    void heapUp(int index) {
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapDown(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }

        if (rightChild < heap.size() && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }

        if (largest != index) {
            std::swap(heap[index], heap[largest]);
            heapDown(largest);
        }
    }

public:
    bool add(const std::string& newPatient) {
        heap.push_back(newPatient);
        heapUp(heap.size() - 1);
        return true;
    }

    std::string peekTop() {
        if (!heap.empty()) {
            return heap[0];
        } else { 
            return ""; 
        }
    }

    bool remove() {
        if (!heap.empty()) {
            std::swap(heap[0], heap[heap.size() - 1]);
            heap.pop_back();
            heapDown(0);
            return true;
        } else {
            return false; 
        }
    }
};

int main() {
    PatientHeap ER;
    
  
ER.add("17 Shohei");
ER.add("16 Will");
std::cout << ER.peekTop() << " will now see the doctor.\n";
ER.remove();
ER.add("5 Freddie");
ER.add("8 Enrique");
ER.add("4 Tesco");
ER.add("44 Andy");
ER.add("11 Miguel");
ER.add("9 Gavin");
ER.add("8 Miguel");
ER.add("3 Chris");

std::cout << ER.peekTop() << " will now see the doctor.\n";
ER.remove();
std::cout << ER.peekTop() << " will now see the doctor.\n";
ER.remove();
std::cout << ER.peekTop() << " will now see the doctor.\n";
ER.remove();

    std::cout << "Next patient to be served: " << ER.peekTop() << std::endl;
    ER.remove();
    std::cout << "Next patient to be served after removal: " << ER.peekTop() << std::endl;

    return 0;
}




/*
17 Shohei will now see the doctor.
9 Gavin will now see the doctor.
8 Miguel will now see the doctor.
8 Enrique will now see the doctor.
Next patient to be served: 5 Freddie
Next patient to be served after removal: 44 Andy

*/