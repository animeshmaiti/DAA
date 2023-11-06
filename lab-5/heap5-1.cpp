#include <iostream>
#include<fstream>

using namespace std;

struct Student{
    int id;
    string name;
    int age;
    int height;
    int weight;
};

class MinHeap{
    private:
    Student* heapArray;
    int maxSize;
    int currentSize;

    // Heapify functions
    void heapifyUp(int index);
    void heapifyDown(int index);
    public:
    MinHeap(int size);
    ~MinHeap();

    bool insert(const Student& person);
    bool removeMin();
    void displayWeightOfYoungest();
    void insertNewPerson();
    void deleteOldestPerson();
};

MinHeap::MinHeap(int size) {
    maxSize = size;
    heapArray = new Student[size];
    currentSize = 0;
}

MinHeap::~MinHeap() {
    delete[] heapArray;
}

void MinHeap::heapifyUp(int index) {
    int parentIndex = (index - 1) / 2;
    while (index > 0 && heapArray[index].age < heapArray[parentIndex].age) {
        std::swap(heapArray[index], heapArray[parentIndex]);
        index = parentIndex;
        parentIndex = (index - 1) / 2;
    }
}

void MinHeap::heapifyDown(int index) {
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;
    int smallest = index;

    if (leftChild < currentSize && heapArray[leftChild].age < heapArray[smallest].age)
        smallest = leftChild;
    if (rightChild < currentSize && heapArray[rightChild].age < heapArray[smallest].age)
        smallest = rightChild;

    if (smallest != index) {
        std::swap(heapArray[index], heapArray[smallest]);
        heapifyDown(smallest);
    }
}

bool MinHeap::insert(const Student& person) {
    if (currentSize == maxSize)
        return false;

    heapArray[currentSize] = person;
    heapifyUp(currentSize);
    ++currentSize;
    return true;
}

bool MinHeap::removeMin() {
    if (currentSize == 0)
        return false;

    heapArray[0] = heapArray[currentSize - 1];
    --currentSize;
    heapifyDown(0);
    return true;
}

void MinHeap::displayWeightOfYoungest() {
    if (currentSize > 0)
        cout << "Weight of the youngest person: " << heapArray[0].weight << std::endl;
    else
        cout << "Heap is empty." << std::endl;
}

void MinHeap::insertNewPerson() {
    Student newPerson;
    cout << "Enter name: ";
    cin >> newPerson.name;
    cout << "Enter age: ";
    cin >> newPerson.age;
    cout << "Enter weight: ";
    cin >> newPerson.weight;

    insert(newPerson);
}

void MinHeap::deleteOldestPerson() {
    if (removeMin())
        cout << "Oldest person deleted from heap." << std::endl;
    else
        cout << "Heap is empty." << std::endl;
}

int main() {
    int n;
    cout << "Enter the number of persons: ";
    cin >> n;

    MinHeap minAgeHeap(n);
    MinHeap maxWeightHeap(n);

    std::ifstream inputFile("person_data.txt");
    if (!inputFile) {
        std::cerr << "Error opening file." << std::endl;
        return 1;
    }

    for (int i = 0; i < n; ++i) {
        Student person;
        inputFile >> person.name >> person.age >> person.weight;
        minAgeHeap.insert(person);
        maxWeightHeap.insert(person);
    }

    inputFile.close();

    int choice;
    do {
        cout << "\nMAIN MENU (HEAP)\n";
        cout << "1. Read Data\n";
        cout << "2. Create a Min-heap based on the age\n";
        cout << "3. Create a Max-heap based on the weight\n";
        cout << "4. Display weight of the youngest person\n";
        cout << "5. Insert a new person into the Min-heap\n";
        cout << "6. Delete the oldest person\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Read data from file
                break;
            }
            case 2: {
                // Create Min-heap based on age
                break;
            }
            case 3: {
                // Create Max-heap based on weight
                break;
            }
            case 4: {
                minAgeHeap.displayWeightOfYoungest();
                break;
            }
            case 5: {
                minAgeHeap.insertNewPerson();
                break;
            }
            case 6: {
                minAgeHeap.deleteOldestPerson();
                break;
            }
            case 7: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Try again.\n";
            }
        }
    } while (choice != 7);

    return 0;
}