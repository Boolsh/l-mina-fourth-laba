#pragma once

#include <iostream>
#include <fstream>
#include <fstream>
#include <functional>
#include <string>

#include "Pet.h"

using TInfo = Pet*;

class NODE
{
public:
	TInfo info;
	NODE* next;
	NODE(TInfo info, NODE* ptr = nullptr) : info(info), next(ptr) {}
	~NODE() { next = nullptr; }

	TInfo get_info() { return info; };
	NODE* get_next() { return next; }
	void set_info(TInfo inf) { info = inf; };
	void set_next(NODE* nxt) { next = nxt; };
};

using ptrNODE = NODE*;

class FLIST
{
private:
	ptrNODE head, tail;
	size_t size;

	void adding_by_pointer(ptrNODE& ptr, TInfo elem)
	{
		ptr = new NODE(elem, ptr);
		++size;
	}
	void deleting_by_pointer(ptrNODE& ptr)
	{
		ptrNODE p = ptr;
		ptr = p->next;
		delete p;
		--size;
	}
public:
	FLIST() { head = nullptr; tail = nullptr; size = 0; };

	FLIST(std::ifstream& file);
	~FLIST();
	ptrNODE get_head() { return head; };
	ptrNODE get_tail() { return tail; };
	void set_tail(ptrNODE ptr) { tail = ptr; };
	void set_head(ptrNODE ptr) { head = ptr; };

	TInfo get_ELEM(ptrNODE ptr) { return ptr->get_info(); };
	size_t get_size() { return size; };
	bool empty() { return !head; };

	void print(std::ostream& out = std::cout);
	void sorting();


	//////////////////////////////////////////////////////////////

	void add_after_position(TInfo elem, unsigned int position);
	void del_at_position(unsigned int position);
	TInfo find_at_position(unsigned int position);
	void read_from_file(std::ifstream& file);


	void add_to_head(TInfo elem);
	void add_to_tail(TInfo elem);


	void del_from_head();
	void del_from_tail();

	void clear();

	////////////////////////////////////////////////////////////////
};