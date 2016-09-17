#ifndef BAG_H
#define BAG_H

// *****************************
// Class Name: Bag
//
// Description: Container for items
// *****************************

#include <cstdlib> // size_t, typedef
#include <iostream>
#include <string>
using namespace std;
namespace maveym_bag
{
    class Bag
    {
        public:
            //"value_type" synonymous to "string"
            typedef string value_type;
            //"size_type" synonymous to "size_t"
            typedef size_t size_type;
            //Array size will hold 50 items
            static const size_type CAPACITY = 50;
            //=======================
            Bag() {used = 0;}
            // Summary: Default constructor
            // Preconditions: Declare Bag object
            // Postconditions: Bag is empty; garbage values
            //=======================
            //
            //=======================
            void eraseEntireBag();
            // Summary: Erases everyting in the bag
            // Preconditions: Call erase on this->Bag
            // Postconditions: Erases the entire bag; garbage values
            //=======================
            //
            //=======================
            bool eraseOneItem(const value_type& target);
            // Summary: Erases one specific item
            // Preconditions: Takes in the specified target to erase
            // Postconditions: If target found, replaces it with the last item in array, decrementing used, and returns true. If not found, does nothing, returns false.
            //=======================
            //
            //=======================
            size_type eraseCopies(const value_type& target);
            // Summary: Erases the target and all its duplicates
            // Preconditions: Takes in the specified target to erase
            // Postconditions: Copies are erased in manner of erasing one item (replace the erased with the last item in the array), and the number of copies found is returned
            //=======================
            //
            //=======================
            void insert(const value_type& value);
            // Summary: Adds an item into the bag
            // Preconditions: Takes in value to add
            // Postconditions: Adds item to the end of the array if there's still room (used < CAPACITY). Otherwise does nothing, and returns.
            //=======================
            //
            //=======================
            size_type size() const {return used;}
            // Summary: Tells you how much is in the bag so far
            // Preconditions: Call size() on this->Bag
            // Postconditions: Returns used variable
            //=======================
            //
            //=======================
            size_type count(const value_type& target) const;
            // Summary: getCount(); How many times an item shows up in bag
            // Preconditions: Pass in an item you want to count
            // Postconditions: Returns number of times that value is in our bag. Const at the end because we're just returning a number, and not making any changes
            //=======================
            //
            //=======================
            void operator += (const Bag& newBag);
            // Summary: Combines another bag with the this->bag
            // Preconditions: Takes in the a new bag
            // Postconditions: Adds the new bag's contents into existing bag
            //=======================
            //
            //=======================
            void operator -= (const Bag& newBag);
            // Summary: Removes all of newBag's contents from this->bag's contents
            // Preconditions: Takes in the a new bag
            // Postconditions: Removes the new bag's contents from existing bag
            //=======================
            //
            //=======================
            friend ostream& operator << (ostream& out, const Bag& b);
            

        private:
            value_type data[CAPACITY];
            size_type used;
    };

    //NON-MEMBER FUNCTIONS
    //cannot access the private members directly, since not a friend
    //=======================
    Bag operator + (const Bag& lBag, const Bag& rBag);
    // Summary: Adds two bags and returns a new bag
    // Preconditions: Takes in left bag and right bag
    // Postconditions: Adds together contents in 1Bag, RBag to return a new bag
    //=======================
    //
    //=======================
    Bag operator - (const Bag& xBag,  const Bag& yBag);
    // Summary: For two bags x and y, the returned bag x-y contains all the items of x, with any items from y removed.
    // Preconditions: Takes in two bags
    // Postconditions: Returns a new bag with updated result
    //=======================
}
#endif //BAG_H
