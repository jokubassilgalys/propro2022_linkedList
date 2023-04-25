#include <stdio.h>
#include <stdlib.h>
#include "menuFunctions.h"

struct node 
{
    int data;
    struct node *next;
};

void printMenu(int menuSize, char *menuOptions[])
{
    if (menuSize > 0){
        printf("\nMENIU\n");
        for (int i = 0; i < menuSize; ++i){
            printf("%s\n", menuOptions[i]);
        }
    }
    else return;
}

int main()
{
    char* menuOptions[] = {"Iveskite 0 kad sukurtumete sarasa",
    "Iveskite 1 kad isspausdintumete sarasa",
    "Iveskite 2 kad iterptumete i sarasa nauja elementa",
    "Iveskite 3 kad isjuntumete programa"};

    int option, menuSize = sizeof(menuOptions)/sizeof(menuOptions[0]);
    struct node *head = NULL;

    do {
        printMenu(menuSize, menuOptions);
        for (;;){
            option = getIntInput();
            if (option >= 0 && option < menuSize){
                break;
            }
            printf("Neteisinga ivestis, bandykite is naujo: ");
        }
        
        switch (option)
        {
            case 0:
            createList(&head);
            break;

            case 1:
            printNode(head, head);
            printf("\n");
            break;

            case 2:
            listInsert(&head);
            break;

            case 3:
            printf("Programa sekmingai isjungta");
            break;

            default:
            printf("Meniu pasirinkimo klaida");
            return 0;
        }
    } while (option != 3);

    return 0;
}