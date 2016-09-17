// *****************************
// Bag.cpp
//
// Summary: Includes implementation for Bag class (Bag.h)
//
// Author: Mavey Ma
// Created: September 7, 2016
// Summary of Modifications:
//      16 Sept 2016 - Overloaded -= and - operators
// *****************************
#include "Bag.h"
#include <algorithm> // copy function available to us here
#include <cassert> //assert()

namespace maveym_bag
{
    const Bag::size_type Bag::CAPACITY;

    void Bag::eraseEntireBag() //Big O(1)
    {
        used = 0;
        return;
    }//ERASE ALL OF BAG'S CONTENTS

    bool Bag::eraseOneItem(const value_type& target) //Big O(n)
    {
        size_type index = 0;
        //traverse through data array while there's still content to seach
        // and while the data does not match the target
        while (index < used && data[index] != target)
            index++; // in other words, break out of while loop when data found
            // or, when you run out of items to search

        if (index == used)
            return false; //did not remove anything
            //empty bag, or came to the end of the bag and didn't find it

        used--; //one less item in our array
        data[index] = data[used];
        return true; //removed one item
    }//ERASE JUST ONE ITEM

    Bag::size_type Bag::eraseCopies(const value_type& target) //Big O(n)
    {   //Textbook's equivalent of erase() (p. 118-120)
        size_type numCopies = 0;
        size_type i = 0;
        while (i < used)
        {
            if (data[i] == target)
            {
                used--;
                data[i] = data[used];
                numCopies++;
            }
            else
                i++;
        }
        return numCopies;
    }//END ERASE TARGET AND ALL ITS DUPLICATES

    void Bag::insert(const value_type& value) //Big O(1)
    {
        if (used < CAPACITY)
        {
            data[used] = value;
            used++;
        }
        return;
    }//END INSERT

    Bag::size_type Bag::count (const value_type& target) const //Big O(n)
    {
        size_type total = 0;
        for (size_type i = 0; i < used; i++)
        {
            if (data[i] == target)
                total++;
        }
        return total;
    }//END COUNT

    void Bag::operator += (const Bag& newBag)
    {
        assert(used + newBag.used <= CAPACITY);
        if ((used + newBag.used) <= CAPACITY) //if true, it fits
        {
            //copy(startAddress, endAddress, destinationAddress);
            //copy(the beginning of array, end of array, and where i want it to be)
            copy(newBag.data, newBag.data + newBag.used, data + used);

            used += newBag.used; //updated used count
        }
        return;
    }//END += OVERLOADED OPERATOR

    void Bag::operator -= (const Bag& newBag)
    {
        assert(used + newBag.used <= CAPACITY);

        for (int i = 0; i < used; i++) //this->bag
        {
            cout << "this is " << i << endl;
            for (int j = 0; j < newBag.used; j++) //grab targets from newBag
            {

                if ((data[i] == newBag.data[j]))
                {
                    copy(data+i, data+used, data+i-1);
                    used--;
                    cout << "this is if state" << endl; 
                    break;
                }
                cout << "this is " << j << endl;
            }
        }
        return;
    }//END -= OPERATOR

    Bag operator + (const Bag& lBag, const Bag& rBag)
    {
        assert(lBag.size() + rBag.size() <= Bag::CAPACITY);
        Bag newBag;
        newBag += lBag;
        newBag += rBag;
        return newBag;
    }//END + OVERLOADED OPERATOR

    Bag operator - (const Bag& xBag,  const Bag& yBag)
    {

        return xBag;
    }//END - OVERLOADED OPERATOR

    ostream& operator << (ostream& out, const Bag& b)
    {
        for (int i = 0; i < b.size(); i++)
        {
            out << "[" << i << "] " << b.data[i] << endl;
        }
        return out;
    }//END COUT << OPERATOR

}
