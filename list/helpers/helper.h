#include <stdio.h>

void printWithLine(char text[500])
{
    printf("\n\n %s \n\n", text);
}

void notFound(char text[10])
{
    printf("\n\n %s Not Found \n\n", text);

    return;
}

void emptyDatabaseMessage(char text[10])
{
    printf("\n\nImpossivel %s. O banco de dados não possui registros armazenados\n\n", text);

    return;
}