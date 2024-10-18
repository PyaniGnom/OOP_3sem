#include <vector>
#include <fmt/color.h>
#include "List.h"

void PrintList(List& list) {
    fmt::print("\nВ текущем списке следующие элементы:\n");

    fmt::print("NULL <-> ");
    for (int i = 0; i < list.GetSize(); i++) {
        fmt::print("{} <-> ", list[i]);
    }
    fmt::print("NULL\n\n");
}

int main() {
    /*list.PushFront(989);
    for (int i = 2; i < 10; i += 2) {
        list.PushFront(i);
    }

    std::vector<int> vec {list.ListToVector()};*/

    extern int x[];

    std::vector<int> vec1 {2, 9, 7};
    std::vector<int> vec2 {3, 4, 2, 5, 2, 6, 7, 2};

    List list1;
    list1.VectorToList(vec1);
    List list2;
    list2.VectorToList(vec2);

    List list3 = list1.Union(list2);
    PrintList(list3);

    list3.DeleteAllEntry(2);

    PrintList(list3);

    return 0;
}
