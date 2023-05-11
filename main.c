#include <stdio.h>
#include "helpers.h"

#define DATABASE './database.txt'

typedef struct list List;
typedef struct client Client;
typedef struct listNode ListNode;

struct client
{
    int id;
    int age;
    char name; //com array ta dando xabu na atualização
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
    ListNode* node = (ListNode*) malloc(sizeof(ListNode));
    
    client.active = 1;
    client.id = list->totalElements;

    node->client = client;
    node->next = list->first; //Seta o fim da lista, atribuindo null a última posição do ponteiro na primeira atribuição
   
    list->first = node;
    list->totalElements ++;
    
    return;
}

void getAll(List* list)
{
    if (list->totalElements == 0) {
        printWithLine("O banco de dados não possui registro");
    }

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        printf("Id: %d ", ln->client.id);
        printf("Nome: %c ", ln->client.name);
        printf("Idade: %d ", ln->client.age);
        printf("\n");
    }

    return;
}

void get(List* list, int id)
{
    if (id > list->totalElements || id < 0)
    {
        notFound("Id");

        return;
    }

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        if (ln->client.id == id) {
            printf("\n\n");
            printf("Id: %d ", ln->client.id);
            printf("Nome: %c ", ln->client.name);
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
            ln->client.name = client.name;
            ln->client.age = client.age;
        }  
    }
}

void save(List* list)
{

    FILE *fptr;

    fptr = fopen(DATABASE, "w");

    for (ListNode* ln = list->first; ln != NULL; ln = ln->next)
    {
        printf("Id: %d ", ln->client.id);
        printf("Nome: %c ", ln->client.name);
        printf("Age: %d ", ln->client.age);
        printf("Active: %d ", ln->client.active);
        printf("\n");

        if (ln->client.active == 1) {
            // fprintf(fptr, "%d %s %d %d \n", lança falha de segmentação
            fprintf(fptr, "%d %c %d %d \n", 
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

void loadFile(List *database)
{
    FILE *fptr;

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



void menu()
{
    int resp = 0;
    int id;
    Client client; 
    List* database = create();

    printf("Bem vindo ao Cadastro!");

    while(resp != -1)
    {
        printf("\nDigite 1 para Inserir,2 para Alterar, 3 para consultar, \n4 para listar, 5 para excluir, 6 para gravar no banco de dados, 7 para carregar do banco de dados -1 para sair: \n");
        scanf("%d", &resp);

        switch (resp)
        {
            case 1:
                printf("Insira o nome: ");
                scanf("%s", &client.name);

                printf("Insira o idade: ");
                scanf("%d", &client.age);
                
                insert(database, client);
                break;

            case 2:
                if (database->first == NULL) {

                    emptyDatabaseMessage("atualizar");                    
                    break;
                }

                printf("Insira o Id do usuário a ser atualizado: ");
                scanf("%d", &id);

                if (id < 0 || id > database->totalElements) {
                    notFound("Id");

                    break;;
                }
                
                printf("Insira o novo nome do usuário: ");
                scanf("%s", &client.name);

                printf("Insira a nova idade do usuário: ");
                scanf("%d", &client.age);

                update(database, id, client);
                break;

            case 3:
                if (database->first == NULL) {
                    emptyDatabaseMessage("consultar");
                    break;
                }

                printf("Insira o Id do usuário a ser consultado: ");
                scanf("%d", &id);     

                get(database, id);
                break;

            case 4:
                if (database->first == NULL) {
                    emptyDatabaseMessage("consultar");
                    
                    break;
                }
        
                getAll(database);
                break;

            case 5:
                // delete();
                break;  

            case 6:
                if (database->first == NULL) {
                    printWithLine("Não há registros para serem gravados no banco de dados");
                    
                    break;;
                }

                save(database);
                break;

            case 7:
                printWithLine("Carregando registros do banco de dados...");
                loadFile(database);
                sleep(5);
                printWithLine("Registros carregados em memória com sucesso!");
                break; 
            default:
                break;
        }
    
    }
}

int main()
{
    menu();
}