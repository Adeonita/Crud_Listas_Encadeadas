#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../helpers.h"

#define DATABASE "./database.txt"

typedef struct list List;
typedef struct client Client;
typedef struct listNode ListNode;

struct client
{
    int id;
    int age;
    char name[10];
    int active;
};

struct list
{
    ListNode* first;
    ListNode* last;
    int totalElements;
};

struct listNode
{
    Client client;
    ListNode* next;
};

List* create()
{
    List* list = (List*) malloc(sizeof(List));
    list->first = NULL;
    list->totalElements = 0;

    return list;
}

void insert(List* list, Client client)
{
    ListNode* ant = NULL;
    ListNode* first = list->first;
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    

    while (first != NULL)
    {
        ant = first;
        first = first->next;
    }
    
    client.active = 1;
    client.id = list->totalElements;

    node->client = client;

    if (ant == NULL) {
        node->next = list->first; //Seta o fim da lista, atribuindo null a última posição do ponteiro na primeira atribuição
        list->first = node;
    } else {
        node->next = ant->next;
        ant->next = node;
    }
    
    list->totalElements ++;
    
    return;
}

void getAll(List* list)
{
    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        printf("Id: %d ", ln->client.id);
        printf("Nome: %s ", ln->client.name);
        printf("Idade: %d ", ln->client.age);
        printf("\n");
    }

    return;
}

void get(List* list, int id)
{
    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        if (ln->client.id == id) {
            printf("\n\n");
            printf("Id: %d ", ln->client.id);
            printf("Nome: %s ", ln->client.name);
            printf("Idade: %d", ln->client.age);
            printf("\n\n");
        }  
    }

    return;
}

void update(List* list, int id, Client client)
{
    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        if (ln->client.id == id) {
            ln->client.id = id;
            strcpy(ln->client.name, client.name);
            ln->client.age = client.age;
        }  
    }
}

void toRemove(List* list, int id)
{
    ListNode* ant = NULL;
    ListNode* actualElement = list->first;
    
    while (actualElement != NULL && actualElement->client.id != id)
    {
        ant = actualElement;
        actualElement = actualElement->next;
    }

    if (ant == NULL) { 
        list->first = actualElement->next;
    } else {
        ant->next = actualElement->next;
    }

    free(actualElement);
}

void saveToFile(List* list)
{
    FILE* fptr;

    fptr = fopen(DATABASE, "w");

    if (fptr == NULL) {
        if (fptr == NULL) {
            notFound("File");
            exit(1);
        }
        exit(1);
    }

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        printf("Id: %d ", ln->client.id);
        printf("Nome: %s ", ln->client.name);
        printf("Age: %d ", ln->client.age);
        printf("Active: %d ", ln->client.active);
        printf("\n");

        if (ln->client.active == 1) {
            fprintf(fptr, "%d %s %d %d \n",
                ln->client.id, 
                ln->client.name,
                ln->client.age,
                ln->client.active
            );
        }
    }

    fclose(fptr);

    printWithLine("O registro foi armazenado no banco de dados!");
}

void loadFromFile(List* database)
{
    FILE* fptr;

    fptr = fopen(DATABASE, "r");

    if (fptr == NULL) {
        notFound("File");
        exit(1);
    }

    Client client;
        
    while ((fscanf(
                fptr,
                "%d %s %d %d\n",
                &client.id, 
                &client.name, 
                &client.age, 
                &client.active
            )) != EOF)
    {        
        if (client.active == 1) {
            insert(database, client);
        }
    }

    fclose(fptr);
}