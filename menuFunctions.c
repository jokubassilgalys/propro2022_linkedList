#include <stdio.h>
#include <stdlib.h>
#include "menuFunctions.h"

struct node 
{
    int data;
    struct node *next;
};

int getIntInput()
{
    int number;
    char ch, buffer[50], *prompt = "";

    do {
        printf("%s", prompt);
        prompt = "Ivestis neteisinga, iveskite is naujo: ";

        fgets(buffer, sizeof buffer, stdin);

    } while (sscanf(buffer, "%d %c", &number, &ch) != 1);

    return number;
}

void getFileName(char prompt[], char *inFileName)
{
    printf("%s", prompt);
       
    if (scanf("%s", inFileName) != 1){ 
        getFileName("Neteisinga ivestis, iveskite pavadinima is naujo: ", inFileName);
    }
}

void addNewElement(struct node** head, int temp)
{
    struct node *current = NULL;
    struct node *new = *head;

    current = (struct node*) malloc(sizeof(struct node));
    current->data = temp;
    current->next = *head;
           
    if (*head == NULL){
        *head = current;
        (*head)->next = *head;
    }
    else {
        while (new->next != *head){
            new = new->next;
        }
        new->next = current;
    }
}

void createList(struct node** head)
{
    char inFileName[255];
    FILE *filePtr;
    
    int temp, result;
    char ch;

    if (*head == NULL){
        getFileName("Iveskite ivesties failo pavadinima: ", inFileName);

        for (;;){
            if ((filePtr = fopen(inFileName, "r")) == NULL){
                getFileName("Nepavyko atidaryti failo, iveskite pavadinima is naujo: ", inFileName);
            }
            else break;
        }
        fflush(stdin);

        while ((result = fscanf(filePtr, "%d", &temp)) != EOF){
            if (result == 0){
                fscanf (filePtr, "%c", &ch);    
            }
            else {
                addNewElement(head, temp);
            }
        }


        printf("Sarasas sekmingai sukurtas\n");
        fclose(filePtr);
    }
    else {
        printf("Sarasas jau sukurtas\n");
    }
}

void printNode(struct node* head, struct node* tmp)
{
    if (head != NULL){
        printf("%d ", tmp->data);
        if (tmp->next != head){
            printNode(head, tmp->next);
        }
    }
    else {
        printf("Sarasas dar nesukurtas");
    }
}

struct node* findTail(struct node* head)
{  
    struct node* current = head;
    for (;;){
        if(current->next != head){
            current = current->next;
        }
        else {
            break;
        }
    }
    return current;
}

void listInsert(struct node** head)
{
    if (*head != NULL) {
        printf("Iveskite elementa pries kuri bus iterptas naujas: ");
        int element = getIntInput();

        printf("Iveskite nauja elementa: ");
        int newValue = getIntInput();

        struct node *new;
        struct node *current = *head;
        struct node *before = findTail(*head);

        new = (struct node*) malloc(sizeof(struct node));
        new->data = newValue;
        new->next = NULL;

        do {
            if (current->data == element){
                before->next = new;
                new->next = current;

                if (current == *head){
                    *head = new;
                }
                break;
            }
            before = current;
            current = current->next;

        } while (current != *head);

        if (current == *head){
            printf("Elemento %d nera sarase\n", element);
            return;
        }

        printf("Elementas %d sekmingai iterptas\n", newValue);
    }
    else {
        printf("Sarasas dar nesukurtas\n");
    }
}

int getMenuInput(int menuSize)
{   
    if (menuSize > 0){
        int number;
        char ch, buffer[50], *prompt = "";

        do {
            printf("%s", prompt);
            prompt = "Ivestis neteisinga, iveskite is naujo: ";

            fgets(buffer, sizeof buffer, stdin);

        } while (sscanf(buffer, "%d %c", &number, &ch) != 1 || number > menuSize-1);
        
        return number;
    }
    else return -1;
}

