#ifndef HEADER_FILE
#define HEADER_FILE
    struct node;
    int getIntInput();
    void getFileName(char prompt[], char *inFileName);
    void addNewElement(struct node** head, int temp);
    void createList(struct node** head);
    void printNode(struct node* head, struct node* tmp);
    struct node* findTail(struct node* head);
    void listInsert(struct node** head);
    int getMenuInput(int menuSize);
#endif