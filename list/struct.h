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