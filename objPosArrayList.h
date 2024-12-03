#ifndef OBJPOS_ARRAYLIST_H
#define OBJPOS_ARRAYLIST_H

#define ARRAY_MAX_CAP 200

#include "objPos.h"

class objPosArrayList
{
    private:
        objPos* aList;
        int listSize;
        int arrayCapacity;

    public:
        objPosArrayList();
        ~objPosArrayList();
        objPosArrayList(const objPosArrayList &a);
        objPosArrayList& operator = (const objPosArrayList &a);

        int getSize();
        void insertHead(const objPos thisPos);
        void insertTail(objPos thisPos);
        void removeHead();
        void removeTail();
        
        objPos getHeadElement();
        objPos getTailElement();
        objPos getElement(int index);
};

#endif






 