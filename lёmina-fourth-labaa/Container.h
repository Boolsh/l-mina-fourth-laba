#include "FLIST.h"

#pragma once

class Container
{
private:
	FLIST* list;
public:
	Container() { list = new FLIST(); };
	Container(std::ifstream& file) { list = new FLIST(file); };
	~Container() { delete list; list = nullptr; };
	Container(const Container& other)
	{
		list = new FLIST();
		ptrNODE tmp = other.list->get_head();
		while (tmp != nullptr)
		{
			list->add_to_tail(tmp->get_info());
			tmp = tmp->get_next();
		}
	}
	void clear() { list->clear(); }
	void add_to_head(TInfo pet) { list->add_to_head(pet); };
	void add_to_tail(TInfo pet) { list->add_to_tail(pet); };
	void del_from_head() { list->del_from_head(); }
	void del_from_tail() { list->del_from_tail(); }

	void print(std::ostream& out = std::cout) { list->print(out); };
	void add_after_position(TInfo elem, unsigned int position) { list->add_after_position(elem, position); }
	void del_at_position(unsigned int position) { list->del_at_position(position); }
	TInfo find_at_position(unsigned int position) { return list->find_at_position(position); }
	void read_from_file(std::ifstream& file) { return list->read_from_file(file); };

	Container get_special_list_y(int year);
	Container get_special_list_a(int age, std::string name_vac);
	void sorting();

	size_t get_size() { return list->get_size(); };
	bool is_empty() { return list->empty(); };




};
//• Получить список всех пациентов, посетивших клинику в заданном году,
//имеющих менее трех прививок.
//• Получить список всех пациентов, возраст которых не превышает
//заданный, имеющих прививку заданного наименования.При этом
//удалить выбранные элементы из Контейнера.
//• Упорядочить пациентов по ФИО хозяина, кличке и полу.
