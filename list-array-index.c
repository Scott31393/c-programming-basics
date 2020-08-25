#include <stdlib.h>
#include <stdio.h>


struct record{
    float value;
    int next;
};


struct list{
    struct record *buffer;
    int size;
    int first;
    int free;
};


void init_list(struct list *ptr, int size){
    int count;

    ptr->buffer = (struct record*) malloc(size*sizeof(struct record));
    ptr->size = size;
    ptr->free = 0;
    ptr->first = size;

    for(count = 0; count < ptr->size; count++)
        ptr->buffer[count].next = count + 1;
}


void pre_insert(struct list *ptr, float value){
    int moved;
    
    if( ptr->free != ptr->size){
        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->first;
        ptr->first = moved;
    }

    printf("miao\n");

    for(int i = 0; i < ptr->size; i++){
        printf("list[%d] = %f\n", i, ptr->buffer[i].value);
    }
}


void visit_list(struct list *ptr){
    int position;

    position = ptr->first;
    while(position != ptr->size){
        printf("List val = %f\n", ptr->buffer[position].value);
        position = ptr->buffer[position].next;
    }
}


void suf_insert(struct list *ptr, float value){
    int moved;
    int *position_ptr;

    if(ptr->free != ptr->size){

        moved = ptr->free;
        ptr->free = ptr->buffer[ptr->free].next;
        *position_ptr = ptr->first;
        while(*position_ptr != ptr->size)
            position_ptr = &(ptr->buffer[*position_ptr].next);
        
        *position_ptr = moved;
        ptr->buffer[moved].value = value;
        ptr->buffer[moved].next = ptr->size;
    }
}

void search(struct list *ptr, float value){
    int position;
    int found;

    found = 1;
    position = ptr->first;

    while(position != ptr->size && found == 1){
        if(ptr->buffer[position].value == value ){
            found = 0;
        }else
        {
            position = ptr->buffer[position].next;
            found = 1;
        }
        
    }
    if(found == 0)
        printf("Founded value = %f\n", value);
    if(found == 1)
        printf("Can't found vaule = %f\n",value);
}



int main (void){
    struct list l;
    struct list *ptr;
    int size;
    int selection;
    float val;
    


    ptr = &l;


    printf("Choose list size \n");
    scanf("%d", &size);
    printf("You choose size = %d \n", size);

    init_list(ptr,size);


    while(1){
        printf("Choose action\n 1-Pre-insert \n 2-Visit list \n 3-Suf-insert \n 4-Search\n 5-Exit\n");
        scanf("%d", &selection);


        switch(selection){
            case 1:
                printf("Choose pre-insert value \n");
                scanf("%f", &val);
                pre_insert(ptr, val);
                break;
            case 2:
                printf("Print list \n");
                visit_list(ptr);
                break;
            case 3:
                printf("Choose suf-insert value \n");
                scanf("%f", &val);
                suf_insert(ptr, val);
                break;
            case 4:
                printf("Choose value to be search \n");
                scanf("%f", &val);
                search(ptr, val);
                break;
            default:
                printf("Exit \n");
                exit(1);
                break;
        }
        
    }

    return 0;
}