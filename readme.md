# CRUD com Listas Encadeadas Dinâmicas
## Objetivo

Desenvolver um sistema de cadastro na linguagem C.
<br>
<br>

## Especificações

1- O sistema deverá possuir um menu para escolha das funções por parte do usuário, conforme o exemplo:

    1) Inserir
    2) Alterar
    3) Consultar
    4) Listar
    5) Excluir
    6) Gravar em arquivo
    7) Carregar em arquivo
    -1) Sair

2 – Na inclusão de um novo produto, o sistema deve permitir a inclusão de um registro por vez.
    A lógica a ser utilizada poderá ser com o uso de memória estática ou memória dinâmica.

3 – A função “Consultar” deverá retornar o registro de acordo com algum critério de busca (Ex.: Id). Em seguida, imprimir os dados do registro localizado, ou simplesmente informar que o registro não foi localizado.

5 – A função “Alterar” deve usar a função “Consultar” como busca para identificar o registro que deseja alterar as informações.

<br>

## Métodos implementados

Criação de uma nova lista 
```
List* create()
```

Inserir um novo registros na lista
```
void insert(List* list, Client client) 
```

Exibe todos os registros da lista
```
void getAll(List* list) 
```

Busca um registro na lista pelo id
```
ListNode* get(List* list, int id)

```

Busca e atuzaliza um registro na lista pelo id
```
ListNode* getAndUpdate(List* list, int id, Client client)
```

Atualiza um registro na lista pelo id
```
ListNode* update(List* list, int id, Client client)
```

Remove um registro da lista pelo id
```
void toRemove(List* list, int id)
```

Salva os dados da lista para um arquivo
```
void saveToFile(List* list)
```

Carrega os dados de um arquivo para a lista
```
void loadFromFile(List* database)
```
## Requisitos 

- [gcc](https://gcc.gnu.org/onlinedocs/)


## Como Rodar
Na raiz do arquivo execute o comando 

<code> bash exec.sh</code>