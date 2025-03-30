#include "Town.h"

Town::Town(unsigned int id)
{
    setId(id);
}

void Town::setId(unsigned int ID)
{
    this->id = ID;
}

unsigned int Town::getID() const
{
    return id;
}
