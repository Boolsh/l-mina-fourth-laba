#include "Container.h"

Container Container::get_special_list_y(int year)
{
	Container result;
	ptrNODE ptr = list->get_head();

	while (ptr)
	{


		if (ptr->get_info()->get_prixod() == year && ptr->get_info()->get_vaccinations().size() < 3)
		{
			result.add_to_tail(ptr->info);
		}
		ptr = ptr->next;

	}
	return result;
	
}

Container Container::get_special_list_a(int age, std::string name_vac)
{

    Container result;
    ptrNODE tmp = list->get_head();
    unsigned int position = 0;
    while (tmp)
    {
        std::cout << "pop\n";
        if (tmp->get_info()->age() <= age && tmp->get_info()->check_vac(name_vac))
        {
            result.add_to_tail(tmp->info);
            list->del_at_position(position);
            tmp = list->get_head();
            for (unsigned int i = 0; i < position && tmp; i++)
                tmp = tmp->next;

        }
        else
        {
            tmp = tmp->next;
            position++;
        }

    }
    return result;
}

void Container::sorting()
{
    list->sorting();
}

//• Получить список всех пациентов, посетивших клинику в заданном году,
//имеющих менее трех прививок.
//• Получить список всех пациентов, возраст которых не превышает
//заданный, имеющих прививку заданного наименования.При этом
//удалить выбранные элементы из Контейнера.
//• Упорядочить пациентов по ФИО хозяина, кличке и полу.