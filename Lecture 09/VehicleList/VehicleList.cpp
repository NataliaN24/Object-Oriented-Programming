#include "VehicleList.h"

void VehicleList::copyFrom(const VehicleList& other)
{
	list = new Vehicle * [other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		list[i] = new Vehicle(*other.list[i]);
	}
	size = other.size;
	capacity = other.capacity;
}

void VehicleList::free()
{
	for (int i = 0; i < capacity; i++)
	{
		if (list[i])
		{
			delete list[i];
		}	
	}
	delete[]list;
}

void VehicleList::resize(size_t newCap)
{
	Vehicle** copy = new Vehicle * [newCap];
	for (int i = 0; i < size; i++)
	{
		copy[i] = list[i];
	}
	delete[]list;
	list = copy;
	capacity = newCap;
}

VehicleList::VehicleList(int cap)
{
	list = new Vehicle * [cap]{nullptr};
	capacity = cap;
	size = 0;

}

VehicleList::VehicleList(const VehicleList& other)
{
	copyFrom(other);
}

VehicleList& VehicleList::operator=(const VehicleList& other)
{

	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

VehicleList::~VehicleList()
{
	free();
}

void VehicleList::addVehicle(const Vehicle& vehicle)
{
	if (size >= capacity)
	{
		resize(capacity * 2);
	}
	list[size++] = new Vehicle(vehicle);
}

Vehicle& VehicleList::operator[](size_t index)
{
	if (index >= capacity)
	{
		throw std::out_of_range("Invalid index!");
	}
	return *list[index];
}

const Vehicle& VehicleList::operator[](size_t index) const
{
	if (index >= capacity)
	{
		throw std::out_of_range("Invalid index!");
	}
	return *list[index];
}

bool VehicleList::isEmpty() const
{
	return size == 0;
}

size_t VehicleList::getSize() const
{
	return size;
}

size_t VehicleList::getCapacity() const
{
	return capacity;
}

Vehicle* VehicleList::getByRegNumber(const Registration& reg)
{
	for (int i = 0; i < capacity; i++)
	{
		if (list[i]&&strcmp(list[i]->getRegistration().getRegNumber(), reg.getRegNumber()) == 0)
		{
			return list[i];
		}
	}
	return nullptr;
}
