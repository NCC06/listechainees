#include "listeChainees.h"

List *init();
List *initWithValue(int firstValue);
void ft_insert_element(List *list, int newNumber);
int ft_show_element(List *list, int elementNumber);
void ft_show_list(List *list);
void ft_delete_last_element(List *list);
int ft_size_list(List *list);
void ft_insert_at_place(List *list, int place, int newNumber);

int main()
{
	List *maListe = initWithValue(1);
	ft_insert_element(maListe, 2);
	ft_insert_element(maListe, 3);
	ft_insert_element(maListe, 4);
	ft_insert_at_place(maListe, 3, 7);
	ft_show_element(maListe, 2);
	ft_show_list(maListe);
	ft_size_list(maListe);

	return EXIT_SUCCESS;
}
