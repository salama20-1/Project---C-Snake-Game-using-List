#include "objPos.h"

// default constructor
objPos::objPos()
{
    pos = new Pos;
    pos->x = 0;
    pos->y = 0;
    symbol = 0; //NULL
}

// parameterized constructor
objPos::objPos(int xPos, int yPos, char sym)
{
    pos = new Pos;
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// destructor
objPos::~objPos (){
    delete pos;
}

// copy constructor
objPos::objPos(const objPos &pos1){
    pos = new Pos;
    pos->x = pos1.pos->x;
    pos->y = pos1.pos->y;
    symbol = pos1.symbol;
}

// copy assignment operator
objPos& objPos::operator =(const objPos &pos1){
    if (this != &pos1){
        delete pos; // Delete old pos
        pos = new Pos; // Create new pos
        pos->x = pos1.pos->x;
        pos->y = pos1.pos->y;
        symbol = pos1.symbol;
    }
    return *this;
}

// sets the position and symbol using another objPos object
void objPos::setObjPos(objPos o)
{
    pos->x = o.pos->x;
    pos->y = o.pos->y;
    symbol = o.symbol;
}

// sets the position and symbol using given x, y, and symbol
void objPos::setObjPos(int xPos, int yPos, char sym)
{
    pos->x = xPos;
    pos->y = yPos;
    symbol = sym;
}

// returns a copy of the current objPos
objPos objPos::getObjPos() const
{
    objPos returnPos;
    returnPos.pos->x = pos->x;
    returnPos.pos->y = pos->y;
    returnPos.symbol = symbol;
    
    return returnPos;
}

// returns the symbol of the object
char objPos::getSymbol() const
{
    return symbol;
}

// checks if the position of the current object is equal to the reference object's position
bool objPos::isPosEqual(const objPos* refPos) const
{
    return (refPos->pos->x == pos->x && refPos->pos->y == pos->y);
}

// returns the symbol if the positions are equal, otherwise returns NULL
char objPos::getSymbolIfPosEqual(const objPos* refPos) const
{
    if(isPosEqual(refPos))
        return symbol;
    else
        return 0;
}
