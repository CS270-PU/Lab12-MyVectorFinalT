#include "MyVector.h"
#include <gtest/gtest.h>

TEST (MyVectorTest, DefaultConstructorSetsCapacityAndSize) {
  MyVector v;

  EXPECT_EQ (MyVector::DEFAULT_CAPACITY, v.capacity ());
  EXPECT_EQ (0, v.size ());
}

TEST (MyVectorTest, ConstructorWithCapacitySetsCapacityAndSize) {
  MyVector v (20);

  EXPECT_EQ (20, v.capacity ());
  EXPECT_EQ (0, v.size ());
}

TEST (MyVectorTest, PushBackAddsOneValue) {
  MyVector v;

  v.push_back (42);

  EXPECT_EQ (1, v.size ());
  EXPECT_EQ (42, v.at (0));
}

TEST (MyVectorTest, PushBackAddsSeveralValuesInOrder) {
  MyVector v;

  v.push_back (10);
  v.push_back (20);
  v.push_back (30);

  EXPECT_EQ (3, v.size ());
  EXPECT_EQ (10, v.at (0));
  EXPECT_EQ (20, v.at (1));
  EXPECT_EQ (30, v.at (2));
}

TEST (MyVectorTest, PushBackExpandsWhenFull) {
  MyVector v (2);

  v.push_back (5);
  v.push_back (6);
  v.push_back (7);

  EXPECT_EQ (3, v.size ());
  EXPECT_EQ (2 + MyVector::EXPAND_AMOUNT, v.capacity ());
  EXPECT_EQ (5, v.at (0));
  EXPECT_EQ (6, v.at (1));
  EXPECT_EQ (7, v.at (2));
}

TEST (MyVectorTest, AtReturnsReferenceSoValueCanBeChanged) {
  MyVector v;

  v.push_back (100);
  v.at (0) = 200;

  EXPECT_EQ (200, v.at (0));
}

TEST (MyVectorTest, ClearSetsSizeToZero) {
  MyVector v;

  v.push_back (1);
  v.push_back (2);
  v.push_back (3);
  v.clear ();

  EXPECT_EQ (0, v.size ());
  EXPECT_EQ (MyVector::DEFAULT_CAPACITY, v.capacity ());
}

TEST (MyVectorTest, CopyConstructorMakesDeepCopy) {
  MyVector original;

  original.push_back (11);
  original.push_back (22);
  original.push_back (33);

  MyVector copy (original);

  EXPECT_EQ (original.size (), copy.size ());
  EXPECT_EQ (original.capacity (), copy.capacity ());
  EXPECT_EQ (11, copy.at (0));
  EXPECT_EQ (22, copy.at (1));
  EXPECT_EQ (33, copy.at (2));

  original.at (0) = 999;

  EXPECT_EQ (11, copy.at (0));
}

TEST (MyVectorTest, AssignmentOperatorCopiesValues) {
  MyVector a;
  a.push_back (7);
  a.push_back (8);

  MyVector b;
  b.push_back (100);

  b = a;

  EXPECT_EQ (a.size (), b.size ());
  EXPECT_EQ (a.capacity (), b.capacity ());
  EXPECT_EQ (7, b.at (0));
  EXPECT_EQ (8, b.at (1));
}

TEST (MyVectorTest, AssignmentOperatorMakesDeepCopy) {
  MyVector a;
  a.push_back (1);
  a.push_back (2);

  MyVector b;
  b = a;

  a.at (0) = 99;

  EXPECT_EQ (1, b.at (0));
  EXPECT_EQ (2, b.at (1));
}

TEST (MyVectorTest, SelfAssignmentDoesNotBreakObject) {
  MyVector v;

  v.push_back (3);
  v.push_back (4);

  v = v;

  EXPECT_EQ (2, v.size ());
  EXPECT_EQ (3, v.at (0));
  EXPECT_EQ (4, v.at (1));
}