#include <stdio.h>
#include <stdlib.h>


#define TRUE 1
#define FALSE 0
typedef unsigned short int Boolean;


struct list{
    float value;
    struct list * next_ptr;
};


void init_list(struct list **ptrptr){
    *ptrptr = NULL;
}

void pre_insert(struct list **ptrptr, float value){
        struct list *tmp_ptr;

        tmp_ptr = *ptrptr;
        *ptrptr = (struct list *) malloc(sizeof(struct list));
        (*ptrptr)->value = value;
        (*ptrptr)->next_ptr = tmp_ptr;
}

void suf_insert( struct list **ptrptr, float value){

    while((*ptrptr)->next_ptr != NULL)
        ptrptr = &((*ptrptr)->next_ptr);
    
    pre_insert(ptrptr, value);   
}


void visit_list(struct list *ptr){
    while( ptr != NULL){
        printf("List val = %f \n", ptr->value);
        ptr = ptr->next_ptr;
    }

}


int search(struct list **ptrptr, float value, struct list *ptr){

    int found = FALSE;
    while(ptr != NULL && found == FALSE){
        if( ptr->value == value){
            found = TRUE;
            *ptrptr = ptr;
        }else
        {
            ptr = ptr->next_ptr;
        }
    }
    return found;
}



int main(void){
    float value;
    int selection;
    int found;
    struct list l;
    struct list *ptr;
    struct list **ptrptr;
    
    ptr = &l;
    ptrptr = &ptr;

    
    printf("Init list \n");
    init_list(ptrptr);

    while(1){

        printf("Select option: \n 1-Pre-insert \n 2-Suf-insert \n 3-Visit list \n 4-Search value \n");
        scanf("%d", &selection);
        printf("Option selected = %d \n", selection);

        
        switch (selection)
        {
        case 1:
            printf("Insert pre-insert value \n");
            scanf("%f",&value);
            pre_insert(ptrptr,value);
            break;
        case 2:
            printf("Insert suf-insert value \n");
            scanf("%f", &value);
            suf_insert(ptrptr,value);
            break;
        case 3:
            printf("Visit list \n");
            visit_list(ptr);
            break;
        case 4:
            printf("Search value \n");
            printf("Tipe the value that you want check \n");
            scanf("%f", &value);
            found = search(ptrptr, value, ptr);
            if(found == 1){
                printf("Value found --> %f\n", (*ptrptr)->value);
            }else
            {
                printf("Don't found \n");
            }
            break;
        default:
            exit(1);
            break;
        }
    }

    
    return 0;
}