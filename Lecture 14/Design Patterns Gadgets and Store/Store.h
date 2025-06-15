#pragma once
#include"Gadget.h"

class Store
{
	Gadget** gadgets;
	size_t size;
	size_t capacity;

	Store();
	Store(const Store& other)=delete;
	Store& operator=(const Store& other)=delete;

	void resize();
	void free();
public:
	static Store& getInstance();
	~Store();

	void sellProduct(const Gadget& obj);
	void buyProduct(const Gadget&obj);
	void printAll()const;

	class Iterator {
		Gadget** ptr;
	public:
		Iterator(Gadget**ptr):ptr(ptr){}
		Gadget* operator*()const { return *ptr; }
		Iterator& operator++() {
			++ptr;
			return *this;
		}
		bool operator!=(const Iterator& other)const {
			return ptr != other.ptr;
		}

	};

	Iterator begin() {
		return Iterator(gadgets);
	}
	Iterator end() {
		return Iterator(gadgets + size);
	}
	
};

