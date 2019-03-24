/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main()
{
  ariel::Tree emptytree;
  ariel::Tree threetree;
  ariel::Tree fbtree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree mytree;

  badkan::TestCase tc("Binary tree");
  tc
      .CHECK_EQUAL(emptytree.size(), 0)
      .CHECK_OK(emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_EQUAL(emptytree.contains(5), true)
      .CHECK_OK(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.contains(5), false)
      .CHECK_THROWS(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size(), 0)

      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.root(), 5)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_THROWS(threetree.left(6))
      .CHECK_OK(threetree.print())

      .CHECK_THROWS(fbtree.remove(5))
      .CHECK_THROWS(fbtree.left(5))
      .CHECK_THROWS(fbtree.right(5))
      .CHECK_THROWS(fbtree.parent(5))
      .CHECK_EQUAL(fbtree.size(), 0)
      .CHECK_OK(fbtree.insert(666))
      .CHECK_OK(fbtree.insert(555))
      .CHECK_OK(fbtree.insert(444))
      .CHECK_EQUAL(fbtree.size(), 3)
      .CHECK_THROWS(fbtree.insert(666))
      .CHECK_OK(fbtree.insert(110))
      .CHECK_EQUAL(fbtree.parent(555), 666)
      .CHECK_EQUAL(fbtree.parent(444), 555)
      .CHECK_THROWS(fbtree.right(666))
      .CHECK_EQUAL(fbtree.parent(110), 444)
      .CHECK_THROWS(fbtree.right(444))
      .CHECK_EQUAL(fbtree.left(444), 110)
      .CHECK_OK(fbtree.print())
      .CHECK_OK(emptytree.remove(110))
      .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}