#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.
 
objPosArrayList::objPosArrayList()
{                                                       //Default Constructor
    listSize = 0;                                      // Setting the lisSize within the array.
    arrayCapacity = ARRAY_MAX_CAP;                     //Setting the Max array capacity. 
    aList = new objPos[ARRAY_MAX_CAP];                    // Setting memory on heap with the size of the max array capacity.

    for(int i = 0; i < ARRAY_MAX_CAP - 1; i++){               
        aList[i] = objPos();                                  //Initialling every index of the array on the heap.
    }

}

// COPY CONSTRUCTOR
objPosArrayList::objPosArrayList(const objPosArrayList &copy){             
    listSize = copy.listSize;
    arrayCapacity = copy.arrayCapacity;
    aList = new objPos[ARRAY_MAX_CAP];
    
    for(int i = 0; i < listSize - 1; i++){
        aList[i] = copy.aList[i];
    }
}

//COPY ASSIGNMENT OPERATOR
objPosArrayList& objPosArrayList::operator=(const objPosArrayList &copy){
    if(this != &copy){
        this->listSize = copy.listSize;
        this->arrayCapacity = copy.arrayCapacity;
        for(int i = 0; i < this->listSize - 1; i++){
            this->aList[i] = copy.aList[i];
        }
    }
    return *this;
}



objPosArrayList::~objPosArrayList()
{
    delete[] aList;
}

int objPosArrayList::getSize() const
{
    return listSize;   //Returns the current listSize.
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if(listSize < arrayCapacity){                     //Checking to see that we're not going to be out of bounds of the array.        
        for(int i = listSize; i > 0; i--){
            aList[i] = aList[i - 1];     //Shifting every element to the right to make space on head index of the list.
        }
        aList[0] = thisPos;           //Setting the head of the list as whatever you're trying to insert at head.
        listSize++;                   //Increasing the listSize since theres an extra element in the list now.
    }    
    
}

void objPosArrayList::insertTail(objPos thisPos)    
{
    if(listSize < arrayCapacity){                //Checking to see that we're not going to be out of bounds of the array.
        aList[listSize] = thisPos;               // Inserting an element at the end of the list.
        listSize++;                              // Increasing the listSize.
    }

}

void objPosArrayList::removeHead()
{
    if(listSize >= 0 && listSize <= arrayCapacity){        //Checking for bounds
        for(int i = 0; i < listSize - 1; i++){
            aList[i] = aList[i+1];            //Shifting every element to the left and overwriting the element on the first index.
        }
        listSize--;                        //Decreasing the listSize since we got rid of an element.
    }
}

void objPosArrayList::removeTail()
{
    if(listSize > 0){        //Checking for bounds
        listSize--;         // Decreasing the listsize, therefore removing the last element (Lazy Delete).
    }
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];  // Returning the element at the first index. 
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize - 1];         //Reuturn the last element of the list.
}

objPos objPosArrayList::getElement(int index) const
{
    if(index >= 0 && index < listSize ){             //Checking bounds.
        return aList[index];                          //Returns the element at a given index.
    }  
    else{
        return objPos();           //Returns the defualt constructor of the class objPos.    
    }
}
