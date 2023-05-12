#include "list/list.h"

#define DATABASE "./database.txt"

void menu()
{
    int id;
    int resp = 0;

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

                if (id < 0 || id > database->totalElements -1 ) {
                    notFound("Id");

                    break;
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
                if (database->first == NULL)
                {
                    emptyDatabaseMessage("deletar");
                    break;
                }
                
                printf("Insira o id do usuário a ser deletado: ");
                scanf("%d", &id);

                if (id > database->totalElements - 1) {
                    notFound("User");
                    break;
                }

                toRemove(database, id);
                break;  

            case 6:
                if (database->first == NULL) {
                    printWithLine("Não há registros para serem gravados no banco de dados");
                    
                    break;
                }

                saveToFile(database);
                break;

            case 7:
                printWithLine("Carregando registros do banco de dados...");

                loadFromFile(database);
                
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