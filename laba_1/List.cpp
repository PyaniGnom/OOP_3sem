#include "List.h"

List::List() {
    size = 0;
    head = nullptr;
    tail = nullptr;
}

List::~List() {
    Clear();
    fmt::print("\nВызван деструктор!!!\n");
}

size_t List::GetSize() {
    return size;
}

void List::Init(size_t count) {
    for (size_t i = 0; i < count; ++i) {
        PushBack(GenerateRandomInt(0, 100));
    }
}

List::Node *List::getAt(int index) {
    int counter = 0;
    Node* current = head;

    while (counter != index) {
        if (current == nullptr) {
            return current;
        }

        current = current->pNext;
        counter++;
    }

    return current;
}

int& List::operator[](const int index) {
    return getAt(index)->data;
}

void List::PushFront(int data) {
    Node* current = new Node(data);

    current->pNext = head;

    if (head != nullptr) {
        head->pPrev = current;
    }
    if (tail == nullptr) {
        tail = current;
    }
    head = current;

    ++size;
}

void List::PushBack(int data) {
    Node* current = new Node(data);

    current->pPrev = tail;

    if (tail != nullptr) {
        tail->pNext = current;
    }
    if (head == nullptr) {
        head = current;
    }
    tail = current;

    ++size;
}

void List::PopFront() {
    Node* newHead = head->pNext;

    if (newHead != nullptr) {
        newHead->pPrev = nullptr;
    }
    else {
        tail = nullptr;
    }

    delete head;
    head = newHead;

    --size;
}

void List::PopBack() {
    if (tail == nullptr)
        return;

    Node* newTail = tail->pPrev;
    if (newTail != nullptr)
        newTail->pNext = nullptr;
    else
        head = nullptr;

    delete tail;
    tail = newTail;

    --size;
}

void List::Clear() {
    while (size) {
        PopFront();
    }
}

std::vector<int> List::ListToVector() {
    std::vector<int> vector {};

    Node* current = head;
    while (current != tail) {
        vector.push_back(current->data);
        current = current->pNext;
    }
    vector.push_back(current->data);

    return vector;
}

void List::VectorToList(std::vector<int>& vector) {
    Clear();

    for (auto x : vector) {
        PushBack(x);
    }
}

void List::DeleteAllEntry(int value) {
    std::vector<int> vector = ListToVector();
    std::erase(vector, value);
    VectorToList(vector);
}

List List::Union(List &secondList) {
    std::vector<int> v1, v2, dest;
    v1 = this->ListToVector();
    v2 = secondList.ListToVector();
    std::set_union(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(dest));

    List newList; // = new List();
    newList.VectorToList(dest);

    return newList;
}

int List::GenerateRandomInt(int min, int max) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);
}
