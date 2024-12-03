#include "objPosArrayList.h"
#include "GameMechs.h"
#include <iostream>

using namespace std;
// Check lecture contents on general purpose array list construction,

// Initialize array
objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[arrayCapacity];
}

objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &a)
{
    listSize = a.listSize;
    arrayCapacity = a.arrayCapacity;
    aList = new objPos[arrayCapacity];

    for (int i = 0; i < listSize; ++i)
    {
        aList[i] = a.aList[i];
    }
}


objPosArrayList& objPosArrayList::operator=(const objPosArrayList &a)
{
    if (this != &a) // Prevent self-assignment
    {
        delete[] aList;
        listSize = a.listSize;
        arrayCapacity = a.arrayCapacity;
        aList = new objPos[arrayCapacity];

        for (int i = 0; i < listSize; ++i)
        {
            aList[i] = a.aList[i];
        }
    }
    return *this;
}

// size of array list
int objPosArrayList::getSize()
{
    return listSize;
}


void objPosArrayList::insertHead(objPos thisPos)
{
    // Shift all elements to the right by one
    for (int i = listSize; i > 0; --i)
    {
        aList[i] = aList[i - 1];
    }
    aList[0] = thisPos;  // Insert the new element at the head
    ++listSize;
}

// Insert an element at the tail (end) of the list.
void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;  // Insert the new element at the tail
    ++listSize;
}


void objPosArrayList::removeHead()
{
    // Shift all elements to the left by one
    for (int i = 0; i < listSize - 1; ++i)
    {
        aList[i] = aList[i + 1];
    }
    --listSize;  // Get rid of first element
}

// Remove the tail (last) element from the list.
void objPosArrayList::removeTail()
{
    --listSize;  // Get rid of last element
}

// Getter for the head element.
objPos objPosArrayList::getHeadElement()
{
    return aList[0];
}

// Getter for the tail element.
objPos objPosArrayList::getTailElement()
{
    return aList[listSize - 1];
}

// Getter for an element at a specific index.
objPos objPosArrayList::getElement(int index)
{
    return aList[index];
}





 