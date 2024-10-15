#ifndef LABA_1_LIST_H
#define LABA_1_LIST_H

#include <random>
#include <vector>
#include <algorithm>
#include <fmt/color.h>


class List {
public:
    List();
    ~List();

    ///\n Получение размера списка
    size_t GetSize();
    void Init(size_t count);
    ///\n Добавление элемента в начало списка
    void PushFront(int data);
    ///\n Добавление элемента в конец списка
    void PushBack(int data);
    ///\n Удаление элемента из начала списка
    void PopFront();
    ///\n Удаление элемента с конца списка
    void PopBack();
    ///\n Очистка списка
    void Clear();
    std::vector<int> ListToVector();
    void VectorToList(std::vector<int>& vector);
    void DeleteAllEntry(int value);
    List Union(List& secondList);

    int& operator[](int index);

private:
    struct Node {
    public:
        Node* pNext;
        Node* pPrev;
        int data;

        Node(int data = {}, Node* pPrev = nullptr, Node* pNext = nullptr) {
            this->data = data;
            this->pNext = pNext;
            this->pPrev = pPrev;
        }
    };

    Node* getAt(int index);
    int RandomGenerator();

    Node* head;
    Node* tail;
    size_t size;
};


#endif //LABA_1_LIST_H
