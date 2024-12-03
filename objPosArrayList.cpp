#include "objPosArrayList.h"
#include "GameMechs.h"
#include <iostream>

using namespace std;
// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList() // default
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}
objPosArrayList::~objPosArrayList() // destructor
{
    delete[] aList;
}

objPosArrayList::objPosArrayList(const objPosArrayList &a) // copy
{

    listSize = a.listSize;
    arrayCapacity = a.arrayCapacity;

    aList = new objPos[arrayCapacity];
    for(int i=0;i<listSize;i++)
    {
        aList[i] = a.aList[i];
    }
}
objPosArrayList& objPosArrayList::operator = (const objPosArrayList &a) // copy assigment
{
    if (this != &a)
    {
        delete[] aList;
        listSize = a.listSize;
        arrayCapacity = a.arrayCapacity;

        aList = new objPos[arrayCapacity];

        for(int i=0;i<listSize;i++)
        {
            aList[i] = a.aList[i];
        }
    }

    return *this;
}

int objPosArrayList::getSize()
{
    return listSize;
}
void objPosArrayList::insertHead(objPos thisPos)
{
    
    for(int i=listSize;i>0;--i)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos;
    ++listSize;
}
void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    ++listSize;
}
void objPosArrayList::removeHead()
{
    
    for(int i=0;i<listSize-1;i++)
    {
        aList[i] = aList[i+1];
    }
    --listSize;
}
void objPosArrayList::removeTail()
{
    
    --listSize; // Lazy delete
}

//Getters

objPos objPosArrayList::getHeadElement()
{
    return aList[0];
}

objPos objPosArrayList::getTailElement()
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index)
{
    return aList[index];
}




 