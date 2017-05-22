#include <stdlib.h>
#include <stdio.h>


typedef struct Element Element;
typedef struct List List;

struct Element
{
	int number;
	Element *next;
};

struct List
{
	Element *first;
};

List *init()
{
	List *list = malloc(sizeof(*list));
	Element *element = malloc(sizeof(*element));

	if (list == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	element->number = 0;
	element->next = NULL;
	list->first = element;

	return list;
}


List *initWithValue(int firstValue)
{
	List *list = malloc(sizeof(*list));
	Element *element = malloc(sizeof(*element));

	if (list == NULL || element == NULL)
	{
		exit(EXIT_FAILURE);
	}
	
	element->number = firstValue;
	element->next = NULL;
	list->first = element;

	return list;
}

void ft_insert_element(List *list, int newNumber)
{
	/*creation d'un nouvel element */
	Element *newElement = malloc(sizeof(*newElement));
	if (list == NULL || newElement ==  NULL)
	{	
		exit(EXIT_FAILURE);
	}
	newElement->number = newNumber; 

	/*ft_insert_elementien de l'element au début de la list*/
	newElement->next = list->first;
	list->first = newElement;

}

void ft_delete_last_element(List *list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	if (list->first != NULL)
	{
		Element *toDelete = list->first;
		list->first = list->first->next;
		free(toDelete);
	}
}

void ft_show_list(List *list)
{
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element *actuel = list->first;

	while (actuel != NULL)
	{
		printf("%d -> ", actuel->number);
		actuel = actuel->next;
	}
	printf("NULL\n");
}

int ft_show_element(List *list, int elementNumber)
{
	int i = 1;
	if (list == NULL)
	{
		exit(EXIT_FAILURE);
	}

	Element *actuel = list->first;

	while (i < elementNumber)
	{	
		actuel = actuel->next;
		i++;
	}

	printf("%d ", actuel->number);
	
	return actuel->number;
}

void ft_insert_at_place(List *list, int place, int newNumber)
{
	int i = 1;

	Element *newElement = malloc(sizeof(*newElement));
	if (list == NULL || newElement == NULL)
	{
		exit(EXIT_FAILURE);
	}
	newElement->number = newNumber;
	
	Element *actuel = list->first;
	if (place == 0)
	{
		ft_insert_element(list, newNumber);
	}
	else
	{		
	while(i != place)
	{
		actuel = actuel->next;
		i++;
	}		
	newElement->next = actuel->next;
	actuel->next = newElement; 
	}
}

int ft_size_list(List *list)
{
	int size = 0;
	
	Element *actuel = list->first;	

	while(actuel != NULL)
{
		size++;
		actuel = actuel->next;	
	}
	
	printf("%d", size);

	return size;
}


