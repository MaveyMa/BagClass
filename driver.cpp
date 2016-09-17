#include "Bag.h"
#include <iostream>
#include <cstdlib>
using namespace std;
using namespace maveym_bag;

int main()
{
    Bag b1, b2, b3, b4, b5, b6, b7, b8;
    //
    //Same=============
    b1.insert("2");
    b1.insert("2");
    b1.insert("2");
    b1.insert("2");
    b1.insert("2");

    b2.insert("2");
    b2.insert("2");
    b2.insert("2");

    b3.insert("1");
    b3.insert("1");
    b3.insert("1");
    b3.insert("1");
    b3.insert("1");

    b4.insert("1");
    b4.insert("1");
    b4.insert("1");
    //
    //Different=============
    b5.insert("5");
    b5.insert("2");
    b5.insert("6");
    b5.insert("4");
    b5.insert("1");

    b6.insert("5");
    b6.insert("0");
    b6.insert("1");

    b7.insert("5");
    b7.insert("2");
    b7.insert("0");
    b7.insert("4");
    b7.insert("1");

    b8.insert("5");
    b8.insert("0");
    b8.insert("1");

    //==============================================
    /* TEST CASE #1 PASSED: biggerSame - smallerSame
    // Expected: Takes away from bigger

    */
    cout << "=====Bag 1=====" << endl;
    cout << b1;
    cout << "=====Bag 2=====" << endl;
    cout << b2;
    cout << "=====B1 - B2=====" << endl;
    b1 -= b2;
    cout << b1;
    //==============================================
    /* TEST CASE #2: smallerSame - biggerSame
    // Expected: Takes away from smaller, so left with zero

    */
    cout << "=====Bag 3=====" << endl;
    cout << b3;
    cout << "=====Bag 4=====" << endl;
    cout << b4;
    cout << "=====B4 - B3=====" << endl;
    b4 -= b3;
    cout << b4;
    //==============================================
    /* TEST CASE #3: biggerDiff - smallerDiff
    // Expected: Takes away from bigger, so left with zero
    cout << "=====Bag 5=====" << endl;
    cout << b5;
    cout << "=====Bag 6=====" << endl;
    cout << b6;
    cout << "=====B5 - B6=====" << endl;
    b6 -= b5;
    cout << b6;
    */
    //==============================================
    /* TEST CASE #4: smallerDiff - biggerDiff
    // Expected: Takes away from bigger, so left with zero
    cout << "=====Bag 7=====" << endl;
    cout << b7;
    cout << "=====Bag 8=====" << endl;
    cout << b8;
    cout << "=====B8 - B7=====" << endl;
    b8 -= b7;
    cout << b8;
    return EXIT_SUCCESS;
    */
}
