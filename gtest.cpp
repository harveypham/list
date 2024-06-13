#include "list.hpp"
#include <gtest/gtest.h>

TEST(List, default_ctor__creates_empty_list) {
    List<int> l{};
    ASSERT_EQ(l.empty(), true);
}

TEST(List, init_list_ctor__creates_list_with_items_in_order) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    ASSERT_EQ(l.size(), 10);
    ASSERT_EQ(l.front(), 1);
    ASSERT_EQ(l.back(), 10);
}

TEST(List, push_front__adds_item_to_front_and_increases_size_by_one) {
    List <int> l{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        auto size_before_push = l.size();
        l.push_front(i);
        ASSERT_EQ(l.front(), i);
        ASSERT_EQ(l.size(), size_before_push+1);
    }
}

TEST(List, pop_front__removes_front_item_and_decreases_size_by_one) {
    List <int> l{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        auto size_before_pop = l.size();
        l.pop_front();
        ASSERT_EQ(l.front(), i);
        ASSERT_EQ(l.size(), size_before_pop-1);
    }
    l.pop_front();
    ASSERT_EQ(l.size(), 0);
}

TEST(List, push_back__adds_item_to_back_and_increase_size_by_one) {
    List <int> l{};
    for (auto i : {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) {
        auto size_before_push = l.size();
        l.push_back(i);
        ASSERT_EQ(l.back(), i);
        ASSERT_EQ(l.size(), size_before_push+1);
    }
}

TEST(List, pop_back__removes_back_item_and_decreases_size_by_one) {
    List <int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (auto i : {9, 8, 7, 6, 5, 4, 3, 2, 1}) {
        auto size_before_pop = l.size();
        l.pop_back();
        ASSERT_EQ(l.back(), i);
        ASSERT_EQ(l.size(), size_before_pop-1);
    }
    l.pop_back();
    ASSERT_EQ(l.size(), 0);
}

TEST(List, begin__returns_iterator_pointed_to_front) {
    List<int> l{1, 2};
    ASSERT_EQ(*l.begin(), 1);
}

TEST(List, end__returns_iterator_pointed_to_end_of_the_list) {
    List<int> l{1, 2};
    auto it = l.begin();
    ++it; ++it;
    ASSERT_EQ(l.end(), it);
}

TEST(List, rbegin_returns_reverse_iterator_pointed_to_back) {
    List<int> l{1, 2};
    ASSERT_EQ(*l.rbegin(), 2);
}

TEST(List, rend__returns_reverse_iterator_pointed_to_before_front_item) {
    List<int> l{1, 2};
    auto it = l.rbegin();
    ++it; ++it;
    ASSERT_EQ(l.rend(), it);
}

TEST(List, iterator__can_traverse_both_directions) {
    List <int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = l.begin();
    for (; *it != l.back(); ++it);

    for (; *it != l.front(); --it);

    for (; it != l.end(); ++it);
}

TEST(List, reverse_iterator__can_traverse_both_directions) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = l.rbegin();
    for (; *it != l.front(); ++it);

    for (; *it != l.back(); --it);

    for (; it != l.rend(); ++it);
}

TEST(List, insert__at_begin_adds_item_to_front) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto size_before_insert = l.size();
    l.insert(100, l.begin());
    ASSERT_EQ(l.front(), 100);
    ASSERT_EQ(l.size(), size_before_insert+1);
}

TEST(List, insert__at_end_adds_item_to_back) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto size_before_insert = l.size();
    l.insert(100, l.end());
    ASSERT_EQ(l.back(), 100);
    ASSERT_EQ(l.size(), size_before_insert+1);
}

TEST(List, insert__at_rbegin_add_item_to_back) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto size_before_insert = l.size();
    l.insert(100, l.rbegin());
    ASSERT_EQ(l.back(), 100);
    ASSERT_EQ(l.size(), size_before_insert+1);
}

TEST(List, insert__at_rend_add_item_to_front) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto size_before_insert = l.size();
    l.insert(100, l.rend());
    ASSERT_EQ(l.front(), 100);
    ASSERT_EQ(l.size(), size_before_insert+1);
}

TEST(List, insert__at_iterator_moves_items_toward_end) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = l.begin();
    ++it;
    ++it;
    l.insert(100, it);
    it = l.begin();
    ++it;
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(*it, 100);
    ++it;
    ASSERT_EQ(*it, 3);
}

TEST(List, insert__at_reverse_iterator_moves_items_toward_begin) {
    List<int> l{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto it = l.rbegin();
    ++it;
    ++it;
    l.insert(100, it);
    it = l.rbegin();
    ++it;
    ASSERT_EQ(*it, 9);
    ++it;
    ASSERT_EQ(*it, 100);
    ++it;
    ASSERT_EQ(*it, 8);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
