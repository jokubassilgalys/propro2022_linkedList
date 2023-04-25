#include <stdio.h>
#include <assert.h>
#include "menuFunctions.h"

struct node 
{
    int data;
    struct node *next;
};

int main()
{
    struct node* test = NULL;
    struct node* current = NULL;
    
    addNewElement(&test, 0);
    assert(test->data == 0);

    addNewElement(&test, 1);
    assert(test->next->data == 1);

    addNewElement(&test, 2);
    assert(test->next->next->data == 2);
    assert(test->next->next->next->data == 0);

    current = findTail(test);
    assert(current->data == 2);

    current = findTail(current);
    assert(current->data == 1);

    assert(getMenuInput(-5) == -1);
    assert(getMenuInput(0) == -1);

    return 0;
}