//
// Created by José Acuña on 15/03/2019.
//

#include <gtest/gtest.h>
#include "list/List.h"

struct ListTest : testing::Test {
    List<int> *list;

    ListTest() {
        list = new List<int>();

        // Fills the list : [3, 4, 5, 6]
        list->pushTail(4);
        list->pushTail(5);
        list->pushHead(3);
        list->pushTail(6);
    };

    ~ListTest() override { delete list; }
};

TEST_F(ListTest, PushHead_PushTail_Test) {
    list->clean();

    EXPECT_EQ(0, list->getSize()); // Empty list

    // Fills the list
    list->pushTail(4);
    list->pushTail(5);
    list->pushHead(3);
    list->pushTail(6);
    list->pushHead(2);
    list->pushTail(7);  // Tail
    list->pushHead(1);  // Head

    EXPECT_EQ(list->getSize(), 7);
    EXPECT_EQ(list->getHead()->getValue(), 1);
    EXPECT_EQ(list->getTail()->getValue(), 7);
}

TEST_F(ListTest, GetValue_Test) { // [3, 4, 5, 6]

    EXPECT_EQ(list->value(0), 3);
    EXPECT_EQ(list->value(3), 6);

    EXPECT_ANY_THROW(list->value(-1));
    EXPECT_ANY_THROW(list->value(6));
}

TEST_F(ListTest, DeleteValue_Test) {  // [3, 4, 5, 6]

    list->deleteValue(2);
    EXPECT_TRUE(list->value(2) != 5);
    EXPECT_EQ(list->getSize(), 3);

    list->deleteValue(0); // Deletes the head from the list
    EXPECT_EQ(list->getHead()->getValue(), 4);
    EXPECT_EQ(list->getSize(), 2);

    EXPECT_ANY_THROW(list->value(2));

    list->deleteValue(1);
    EXPECT_EQ(list->getTail(), list->getHead()); // Deletes the tail and left the list in one element
    EXPECT_EQ(list->getSize(), 1);
}