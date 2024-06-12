#include <iostream>
#include <cassert>
#include "list.hpp"

void TestDefaultConstructorCreatesEmptyList() {
    auto l = List<int>{};
    assert(l.empty());
}

void TestPushFrontAddsItemToFrontAndIncreasesSizeByOne() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_front(i);
        assert(l.front() == i && l.size() == i);
    }
}

void TestPopFrontRemovesFrontItemAndDecreasesSizeByOne() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_front(i);
    }

    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        l.pop_front();
        assert(l.front() == i && l.size() == i);
    }
    l.pop_front();
    assert(l.size() == 0);
}

void TestPushBackAddsItemToBackAndIncreasesSizeByOne() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
        assert(l.back() == i && l.size() == i);
    }
}

void TestPopPackRemovesBackItemAndDecreasesSizeByOne() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }

    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        l.pop_back();
        assert(l.back() == i && l.size() == i);
    }
    l.pop_back();
    assert(l.size() == 0);
}

void TestBeginReturnsAnIteratorPointedAtFrontThatCanBeAdvancedToEnd() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }

    int start = 1;
    for (auto it = l.begin(); it != l.end(); ++it) {
        assert(*it == start++);
    }
}

void TestRBeginReturnsAnIteratorPointedAtBackThatCanBeAdvancedToBeforeBegin() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }

    int start = 10;
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        assert(*it == start--);
    }
}

void TestIteratorCanBeTraverseBackwardToFront() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }

    auto it = l.begin();
    for (auto i: {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        assert(*it == i);
        it++;
        assert(*it == i+1);
    }
    for (auto i : {10, 9, 8, 7, 6, 5, 4, 3, 2}) {
        assert(*it == i);
        it--;
        assert(*it == i-1);
    }
}

void TestReverseIteratorCanBeTraverseBackwardToBack() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }

    auto it = l.rbegin();
    for (auto i : {10, 9, 8, 7, 6, 5, 4, 3, 2}) {
        assert(*it == i);
        it++;
        assert(*it == i-1);
    }
    for (auto i: {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        assert(*it == i);
        it--;
        assert(*it == i+1);
    }
}

void TestInsertAtBeginAddsItemToFront() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    l.insert(100, l.begin());
    assert(l.front() == 100 && l.size() == 11);
}

void TestInsertAtEndAddsItemToBack() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    l.insert(100, l.end());
    assert(l.back() == 100 && l.size() == 11);
}

void TestInsertAtIteratorMoveItemsToTail() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    auto it = l.begin();
    ++it;
    ++it;
    l.insert(100, it);
    it = l.begin();
    ++it;
    assert(*it == 2);;
    ++it;
    assert(*it == 100);
    ++it;
    assert(*it == 3);
}

void TestInsertAtREndAddsItemToFront() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    l.insert(100, l.rend());
    assert(l.front() == 100 && l.size() == 11);
}

void TestInsertAtRBeginAddsItemToBack() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    l.insert(100, l.rbegin());
    assert(l.back() == 100 && l.size() == 11);
}

void TestInsertAtIteratorMoveItemsToHead() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
    }
    auto it = l.rbegin();
    ++it;
    ++it;
    l.insert(100, it);
    it = l.rbegin();
    ++it;
    assert(*it == 9);;
    ++it;
    assert(*it == 100);
    ++it;
    assert(*it == 8);
}

int main() {
    using namespace std;

    TestDefaultConstructorCreatesEmptyList();

    TestPushFrontAddsItemToFrontAndIncreasesSizeByOne();
    TestPopFrontRemovesFrontItemAndDecreasesSizeByOne();
    TestPushBackAddsItemToBackAndIncreasesSizeByOne();
    TestPopPackRemovesBackItemAndDecreasesSizeByOne();

    TestBeginReturnsAnIteratorPointedAtFrontThatCanBeAdvancedToEnd();
    TestRBeginReturnsAnIteratorPointedAtBackThatCanBeAdvancedToBeforeBegin();
    TestIteratorCanBeTraverseBackwardToFront();
    TestReverseIteratorCanBeTraverseBackwardToBack();

    TestInsertAtBeginAddsItemToFront();
    TestInsertAtEndAddsItemToBack();
    TestInsertAtIteratorMoveItemsToTail();

    TestInsertAtREndAddsItemToFront();
    TestInsertAtRBeginAddsItemToBack();
    TestInsertAtIteratorMoveItemsToHead();

    cout << "All tests passed!!!" << endl;
    return 0;
}