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
  // Testing objects
  ariel::Tree fbtree1;
  ariel::Tree fbtree2;

  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  ariel::Tree mytree;

  badkan::TestCase tc("Binary tree");
  tc
      // emptytree testing
      .CHECK_EQUAL(emptytree.size(), 0)
      .CHECK_OK(emptytree.insert(5))
      .CHECK_EQUAL(emptytree.size(), 1)
      .CHECK_EQUAL(emptytree.contains(5), true)
      .CHECK_OK(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.contains(5), false)
      .CHECK_THROWS(emptytree.remove(5))
      .CHECK_EQUAL(emptytree.size(), 0)
      // threetree testing
      .CHECK_EQUAL(threetree.size(), 3)
      .CHECK_EQUAL(threetree.root(), 5)
      .CHECK_EQUAL(threetree.parent(3), 5)
      .CHECK_EQUAL(threetree.parent(7), 5)
      .CHECK_EQUAL(threetree.left(5), 3)
      .CHECK_EQUAL(threetree.right(5), 7)
      .CHECK_THROWS(threetree.insert(3))
      .CHECK_THROWS(threetree.left(6))
      .CHECK_OK(threetree.print())

      // fbtree1 testing
      // Check for exceptions
      .CHECK_THROWS(fbtree1.remove(5))
      .CHECK_THROWS(fbtree1.left(5))
      .CHECK_THROWS(fbtree1.right(5))
      .CHECK_THROWS(fbtree1.parent(5))
      // Empty tree
      .CHECK_EQUAL(fbtree1.size(), 0)
      // Check insertion
      .CHECK_OK(fbtree1.insert(666))
      .CHECK_OK(fbtree1.insert(555))
      .CHECK_OK(fbtree1.insert(444))
      .CHECK_OK(fbtree1.insert(110))
      // Tree of size 3
      .CHECK_EQUAL(fbtree1.size(), 4)
      // 666 is already in the tree, expect a throw
      .CHECK_THROWS(fbtree1.insert(666))
      // Check parent function
      .CHECK_EQUAL(fbtree1.parent(555), 666)
      .CHECK_EQUAL(fbtree1.parent(444), 555)
      .CHECK_EQUAL(fbtree1.parent(110), 444)
      // Check right function
      .CHECK_THROWS(fbtree1.right(666))
      .CHECK_THROWS(fbtree1.right(444))
      // Check left function
      .CHECK_EQUAL(fbtree1.left(444), 110)
      .CHECK_OK(fbtree1.print())
      // Check contains function
      .CHECK_EQUAL(fbtree1.contains(5), false)
      .CHECK_EQUAL(fbtree1.contains(666), true)
      .CHECK_EQUAL(fbtree1.contains(444), true)
      .CHECK_EQUAL(fbtree1.contains(110), true)
      .CHECK_EQUAL(fbtree1.contains(555), true)
      // Check remove function
      .CHECK_OK(fbtree1.remove(666))
      .CHECK_OK(fbtree1.print())
      .CHECK_OK(fbtree1.insert(666))
      .CHECK_OK(fbtree1.print())
      .CHECK_OK(fbtree1.remove(444))
      .CHECK_OK(fbtree1.print())
      .CHECK_OK(fbtree1.remove(110))
      .CHECK_OK(fbtree1.print())

      // fbtree2 testing
      // 0 child
      .CHECK_OK(fbtree2.insert(777))
      .CHECK_OK(fbtree2.print())
      .CHECK_OK(fbtree2.remove(777))
      .CHECK_OK(fbtree2.print())
      // 2 child
      .CHECK_OK(fbtree2.insert(500))
      .CHECK_OK(fbtree2.insert(600))
      .CHECK_OK(fbtree2.insert(400))
      .CHECK_EQUAL(fbtree2.parent(400), 500)
      .CHECK_EQUAL(fbtree2.parent(600), 500)
      .CHECK_EQUAL(fbtree2.right(500), 600)
      .CHECK_EQUAL(fbtree2.left(500), 400)

      .CHECK_OK(fbtree2.print())
      .CHECK_OK(fbtree2.remove(500))
      .CHECK_OK(fbtree2.print())
      .CHECK_THROWS(fbtree2.right(600))
      .CHECK_EQUAL(fbtree2.parent(400), 600)
      .CHECK_OK(fbtree2.insert(700))
      .CHECK_OK(fbtree2.insert(650))
      .CHECK_OK(fbtree2.insert(800))
      .CHECK_OK(fbtree2.print())
      .CHECK_OK(fbtree2.remove(600))
      .CHECK_OK(fbtree2.print())
      .CHECK_THROWS(fbtree2.parent(650))
      .CHECK_EQUAL(fbtree2.parent(700), 650)

      // Print result
      .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}