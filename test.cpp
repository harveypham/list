#include <iostream>
#include <cassert>
#include "list.hpp"

void TestDefaultConstructorCreatesEmptyList() {
    assert(List<int>{}.empty());
}

void TestPushFrontAddsItemToFrontAndIncreasesSizeByOne() {
    auto l = List<int>{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_front(i);
        assert(l.front() == i && l.size() == i);
    }
}

void TestPopFrontRemovesFrontItemAndDecreasesSizeByOne() {
    List<int> l{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        l.pop_front();
        assert(l.front() == i && l.size() == i);
    }
    l.pop_front();
    assert(l.size() == 0);
}

void TestPushBackAddsItemToBackAndIncreasesSizeByOne() {
    List<int> l{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        l.push_back(i);
        assert(l.back() == i && l.size() == i);
    }
}

void TestPopPackRemovesBackItemAndDecreasesSizeByOne() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        l.pop_back();
        assert(l.back() == i && l.size() == i);
    }
    l.pop_back();
    assert(l.size() == 0);
}

void TestBeginReturnsAnIteratorPointedAtFrontThatCanBeAdvancedToEnd() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int start = 1;
    for (auto it = l.begin(); it != l.end(); ++it) {
        assert(*it == start++);
    }
}

void TestRBeginReturnsAnIteratorPointedAtBackThatCanBeAdvancedToBeforeBegin() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int start = 10;
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        assert(*it == start--);
    }
}

void TestIteratorCanBeTraverseBackwardToFront() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

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
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.insert(100, l.begin());
    assert(l.front() == 100 && l.size() == 11);
}

void TestInsertAtEndAddsItemToBack() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.insert(100, l.end());
    assert(l.back() == 100 && l.size() == 11);
}

void TestInsertAtIteratorMovesItemsTowardTail() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.insert(100, l.rend());
    assert(l.front() == 100 && l.size() == 11);
}

void TestInsertAtRBeginAddsItemToBack() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    l.insert(100, l.rbegin());
    assert(l.back() == 100 && l.size() == 11);
}

void TestInsertAtReverseIteratorMovesItemsTowardHead() {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
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
    TestIteratorCanBeTraverseBackwardToFront();
    TestRBeginReturnsAnIteratorPointedAtBackThatCanBeAdvancedToBeforeBegin();
    TestReverseIteratorCanBeTraverseBackwardToBack();

    TestInsertAtBeginAddsItemToFront();
    TestInsertAtEndAddsItemToBack();
    TestInsertAtIteratorMovesItemsTowardTail();

    TestInsertAtREndAddsItemToFront();
    TestInsertAtRBeginAddsItemToBack();
    TestInsertAtReverseIteratorMovesItemsTowardHead();

    cout << "All tests passed!!!" << endl;
    return 0;
}