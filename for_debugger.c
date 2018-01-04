#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

    void    push(Node **head, int data)
    {
      
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->value = data;
        tmp->next  = (*head);
        (*head) = tmp;

}
int        pop(Node **head)
    {
        Node *prev = NULL;
       int val;
        if (head == NULL)
            exit (-1);
        prev = (*head);
        val = prev->value;
        (*head) = (*head)->next;
        free (prev);
        return val;
    }
    
  Node    *getNth(Node *head, int n)
    {
       int counter = 0;
        while (counter < n && head)
        {
            head = head->next;
            counter++;
        }
        return head;
    }
    
    Node    *getLast(Node *head)
    {
        if (head == NULL)
            return (NULL);
        while (head->next)
            head = head->next;
        return head;
    }
    
    void pushBack(Node *head, int value)
    {
        Node *last = getLast(head);
        Node *tmp = (Node*)malloc(sizeof(Node));
        tmp->value = value;
        tmp->next = NULL;
        last->next = tmp;
    }
    Node *getLastButOne(Node *head)
    {
        if (head == NULL)
            exit (-2);
        if (head->next == NULL)
            return NULL;
        while (head ->next->next)
            head = head->next;
        return head;
    }
    
    void    popBack(Node **head)
    {
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
            free(lastbn->next);
            lastbn->next = NULL;
        }
    }
    
    void    insert(Node *head, unsigned n, int val)
    {
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
    
    int     deleteNth(Node **head, int n)
    {
        if (n == 0)
            return pop(head);
        else
        {
            Node *prev = getNth(*head, n-1);
            Node *elm = prev->next;
            int val = elm->value;
            prev->next = elm->next;
            free(elm);
            return val;
        }
    }
    
        void    deleteList(Node **head)
    {
        while ((*head)->next)
        {
            pop(head);
            *head = (*head)->next;
        }
        free(*head);
    }


int main() {
Node *head = NULL;
push(&head, 42);
push(&head, 256);
push(&head, 512);
push(&head, 1024);
pop(&head);
//getNth(head, 2);
//getLast(head);
pushBack(head, 2048);
popBack(&head);
insert(head, 0, 4096);
deleteNth(&head, 1);
deleteList(&head);
  return 0;
}