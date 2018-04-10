#include "list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    List* l = (List*) malloc(sizeof(List));
    init(l);
    int option,val,k;

    while(1){
        printf("Print an option (menu - 1):");
        scanf("%d",&option);
        switch (option) {
        case 0:
            exit(EXIT_SUCCESS);
            break;
        case 1:
            menu();
            break;
        case 2:
            printf("Size of elemetns:%d\n",size(l));
            break;
        case 3:
            if(head(l) == 0) printf("Move cur_ to head_\n");
            else printf("List is empty...\n");
            break;
        case 4:
            if(next(l) == 0) printf("Next..\n");
            else printf("You can't do that...\n");
            break;
        case 5:
            if(prev(l) == 0) printf("Prev..\n");
            else printf("You can't do that...\n");
            break;
        case 6:
            if(get(l,&val) != -1) printf("Value is %d\n",val);
            else printf("List is empty...\n");
            break;
        case 7:
            printf("Insert value :");
            scanf("%d",&val);
            if(set(l,val) != -1) printf("Success!\n");
            else printf("List is empty...\n");
            break;
        case 8:
            printf("Insert value :");
            scanf("%d",&val);
            if(insert_after(l,val) != -1) printf("Success!\n");
            else printf("Error: no memo...\n");
            break;
        case 9:
            printf("Insert value :");
            scanf("%d",&val);
            if(insert_before(l,val) != -1) printf("Success!\n");
            else printf("Error: no memo...\n");
            break;
        case 10:
            destroy(l);
            printf("Destroid...\n");
            break;
        case 11:
            if(print(l) == -1) printf("List is empty!\n");
            break;
        default:
            printf("Incorrect option!\n");
            break;
        }

    }


}

int menu(){
    printf("\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("Lab_4. Vaigachev A., 6382\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf(" 1. Menu \n");
    printf(" 2. Size \n");
    printf(" 3. Move cur to head \n");
    printf(" 4. Next \n");
    printf(" 5. Prev \n");
    printf(" 6. Get value \n");
    printf(" 7. Set value \n");
    printf(" 8. Insert after \n");
    printf(" 9. Insert before \n");
    printf("10. Destroy \n");
    printf("11. Show \n");
    printf(" 0. Exit \n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
