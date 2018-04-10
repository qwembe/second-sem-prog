#include <stdio.h>
#include <stdlib.h>
#include "list.h"


void menu();


int main()
{
    Node* head = NULL;
    init(&head);
    //insert(&head,5,777);
    int choice;
    int ch;
    int val;

    while(1){
        menu();
        scanf("%d",&choice);
        switch (choice) {
        case 1:
            if(show(head) == -1) printf("Empty..\n");
        break;
        case 2:
            val = size(head);
            if(val != -1) printf("Size of list - %d",val);
            else printf("No list loaded...\n");
        break;
        case 3:
            printf("Enter number: \n");
            scanf("%d", &ch);
            if(at(head, ch, &val) == 0){
                printf("Element = %d\n", val);
            }
            else{
                printf("There is no element\n");
            }
        break;
        case 4:
            printf("Enter number of element: ");
            scanf("%d", &ch);
            printf("Enter element: ");
            scanf("%d", &val);
            if(insert(&head, ch, val) != 0) printf("You can't do that...\n");
        break;
        case 5:
            printf("Enter number of element: ");
            scanf("%d", &ch);
            if(erase(&head, ch) == -1) printf("You can't do that...\n");
        break;
        case 6:
            eraseAll(&head);
            printf("Deleted...\n");
        break;
        case 0:
            exit(EXIT_SUCCESS);
        break;
        default:
            printf("Incorrect option!");
            break;
        }

    }




    return 0;
}

void menu(){
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Lab_3. Vaigachev A., 6382\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("1. Print list                  \n");
    printf("2. Size of list                \n");
    printf("3. Print element               \n");
    printf("4. Add element                 \n");
    printf("5. Delete element of list      \n");
    printf("6. Delete list                 \n");
    printf("0. Exit                        \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

}


