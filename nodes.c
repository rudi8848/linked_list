#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	int value;
	struct Node *next;
} Node;

	void	push(Node **head, int data)
	{
														printf("=====function push=====\n");
														printf("push data: %i\n", data);
		
		Node *tmp = (Node*)malloc(sizeof(Node));
														//printf("tmp: %p\n", &tmp);

		tmp->value = data;
		
		tmp->next  = (*head);
														//printf("tmp->next: %p\n", &tmp->next);
		
		(*head) = tmp;
														//printf("head: %p\n", &head);
}

	int		pop(Node **head)
	{
														printf("=====function pop=====\n");
														//printf("head: %p\n", &head);
		Node *prev = NULL;
														//printf("prev: %p\n", &prev);
		int val;
		if (head == NULL)
			exit (-1);
		prev = (*head);
		val = prev->value;
		(*head) = (*head)->next;
														//printf("head: %p\n", &head);
		free (prev);
														printf("delete %i\n", val);
		return val;
	}

	Node	*getNth(Node *head, int n)
	{
														printf("=====function getNth=====\n");
														printf("get %i-th\n", n);
														//printf("head: %p\n", &head);
		int counter = 0;
		while (counter < n && head)
		{
			head = head->next;
														//printf("head->next: %p\n", &head->next);
			counter++;
		}
														//printf("head: %p\n", &head);
														printf("%i-th->value: %i\n", n, head->value);
		return head;
	}

	Node	*getLast(Node *head)
	{
														printf("=====function getLast=====\n");
														//printf("head: %p\n", &head);
		if (head == NULL)
			return (NULL);
		while (head->next)
			head = head->next;
														printf("head->next: %p, head->value: %i\n", &head->next, head->value);
														printf("head: %p, last->value: %i\n", &head, head->value);
		return head;
	}

	void pushBack(Node *head, int value)
	{
														printf("=====function pushBack=====\n");
														printf("push back value %i\n", value);
														//printf("head: %p\n", &head);
		Node *last = getLast(head);
														printf("last->value: %i, last adr. %p\n", last->value, &last);
		Node *tmp = (Node*)malloc(sizeof(Node));
		tmp->value = value;
														printf("tmp->value: %i, tmp adr. %p\n", tmp->value, &tmp);
		tmp->next = NULL;
		last->next = tmp;
														//printf("head: %p\n", &head);
	}

	Node *getLastButOne(Node *head)
	{
														printf("=====function getLastButOne=====\n");
														//printf("head: %p\n", &head);
		if (head == NULL)
			exit (-2);
		if (head->next == NULL)
			return NULL;
		while (head ->next->next)
			head = head->next;
														printf("pre-last: %p, pre-last->value: %i\n", &head, head->value);
		return head;
	}

	void	popBack(Node **head)
	{
														printf("=====function popBack=====\n");
		Node *lastbn = NULL;
		//если прилетел NULL
		if (!head)
			exit (-1);
		//если список пустой
		if (!(*head))
			exit (-1);
		lastbn = getLastButOne(*head);
		//если в списке 1 элемент
		if (lastbn == NULL)
		{
			free(*head);
			*head = NULL;
		}
		else
		{
														printf("delete the last: %i, adr.: %p\n", lastbn->next->value, &lastbn->next);
			free(lastbn->next);
			lastbn->next = NULL;
		}
	}


	void	insert(Node *head, unsigned n, int val)
	{
														printf("=====function insert=====\n");
														printf("insert %i after the %d-th place\n", val, n);
		unsigned i = 0;
		Node *tmp = NULL;
   		//Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
    	//ошибка выбрасываться не будет, произойдёт вставка в конец
		while (i < n && head->next)
		{
			head = head->next;
			i++;
		}
		tmp = (Node*)malloc(sizeof(Node));
		tmp->value = val;
	    //Если это не последний элемент, то next перекидываем на следующий узел
		if (head->next)
			tmp->next = head->next;
		//иначе на NULL
		else
			tmp->next = NULL;
		head->next = tmp;
	}

	int 	deleteNth(Node **head, int n)
	{
														printf("=====function deleteNth=====\n");
														printf("delete %i-th elenment\n", n);
		if (n == 0)
			return pop(head);
		else
		{
			Node *prev = getNth(*head, n-1);
			Node *elm = prev->next;
			int val = elm->value;

			prev->next = elm->next;
			free(elm);
														printf("delete %i\n", val);
			return val;
		}
	}

	void	deleteList(Node **head)
	{
														printf("=====function deleteList=====\n");
		while ((*head)->next)
		{
			pop(head);
			*head = (*head)->next;
		}
		free(*head);
	}



	void	fromArray(Node **head, int *arr, size_t size)
	{
														printf("=====function fromArray=====\n");
		size_t i = size - 1;
		if (arr == NULL || size == 0)
			return;
		do
		{
			push(head, arr[i]);
		} while (i-- != 0);
	}

	int 	*toArray(const Node *head)
	{
		int leng = 3;
		int *values = (int*)malloc(leng * sizeof(int));
		while (head)
		{
			values[--leng] = head->value;
			head = head->next;
		}
		return values;
	}

	//=======MY FUNCTIONS======

	void printValues(Node *head, int last)
	{
		printf("==========now the list is==========\n");
		int i = 0;
		printf("%i --> ", head->value);
		while (i < last)
		{
			head = head->next;
			printf("%i --> ", head->value);
			i++;
		}
		printf("NULL\n===================================\n");
	}

	int elementsCount(Node *head)
	{
		int i = 0;
		if (!head)
			return 0;
		while(head->next)
		{
			head = head->next;
			i++;
		}
		//printf("%i\n", i);
		return (i);
	}

	Node *search_data(Node *head, int data)
	{
		printf("=====function search_data=====\n");
		while (head->next)
		{
			if (data == head->data)
				return (head);
			head = head->next;
		}
		return (NULL);
	}




int		main(void)
{
	Node *head = NULL;
	int arr[3] = {1, 2, 3};
	printf("head: %p\n", &head);


	push(&head, 42);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	push(&head, 256);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	push(&head, 512);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	push(&head, 1024);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	pop(&head);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	getNth(head, 1);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	getLast(head);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	pushBack(head, 2048);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	getLastButOne(head);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	popBack(&head);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	insert(head, 0, 4096);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	deleteNth(&head, 1);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	deleteList(&head);
	printf("===============\nhead->value\n %i\n===============\n", head->value);
	printValues(head, elementsCount(head));

	search_data(head, 42);

	// fromArray(&head, arr, 3);
	// printf("===============\nhead->value\n %i\n===============\n", head->value);
	// printValues(head, elementsCount(head));
	

	//int *out = toArray(head);
	//printf("out arr is  %d, %d, %d \n", out[0], out[1], out[2]);
	//printValues(head, 0);

	//elementsCount(head);
	return 0;
}