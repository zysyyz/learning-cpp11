#include <gtest/gtest.h>
#include <iostream>
#include "red-black-bst.cpp"

TEST(RedBlackBST, getMissingKey) {
  RedBlackBST bts = RedBlackBST();
  try {
    bts.get(10);
  } catch (const char *msg) {
    EXPECT_EQ("No such key", msg);
  }
}

TEST(RedBlackBST, getSingleValue) {
  RedBlackBST bts;
  bts.put(1, 'z');
  EXPECT_EQ('z', bts.get(1));
}

TEST(RedBlackBST, put) {
  RedBlackBST bts;
  bts.put(1, 'z');
  bts.put(2, 'b');
  EXPECT_EQ('z', bts.get(1));
  EXPECT_EQ('b', bts.get(2));
}

TEST(RedBlackBST, sizeEmpty) {
  RedBlackBST bts;
  EXPECT_EQ(0, bts.size());
}

TEST(RedBlackBST, size) {
  RedBlackBST bts;
  bts.put(1, 'z');
  bts.put(2, 'a');
  EXPECT_EQ(2, bts.size());
}

TEST(RedBlackBST, min) {
  RedBlackBST bts;
  bts.put(1, 'a');
  bts.put(2, 'z');
  EXPECT_EQ('a', bts.min());
}

TEST(RedBlackBST, max) {
  RedBlackBST bts;
  bts.put(1, 'a');
  bts.put(2, 'b');
  bts.put(3, 'c');
  bts.put(4, 'd');
  EXPECT_EQ('d', bts.max());
}

TEST(RedBlackBST, rank) {
  RedBlackBST bts;
  bts.put(1, 'a');
  bts.put(2, 'b');
  bts.put(3, 'c');
  bts.put(4, 'd');
  EXPECT_EQ(3, bts.rank(4));
  EXPECT_EQ(2, bts.rank(3));
  EXPECT_EQ(1, bts.rank(2));
  EXPECT_EQ(0, bts.rank(1));
}
