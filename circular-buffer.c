#include <stdio.h>
#include <stdlib.h>


struct list
{
    float *buffer;
    int size;
    int head;
    int tail;
};

void init_list(struct list *ptr, int size){
    ptr->size = size;
    ptr->buffer = (float*) malloc(size*sizeof(float));
    ptr->head = 0;
    ptr->tail = 0;
}

void visit_list(struct list *ptr){
    int position = ptr->head;
    for(position = ptr->head; position != ptr->tail; position = (position + 1) % ptr->size)
        printf("val = %f \n", ptr->buffer[position]);
}

void pre_insert(struct list *ptr, float value){

    if(((ptr->tail+1) % ptr->size) != ptr->head){
        ptr->head = (ptr->head + ptr->size - 1) % ptr->size;
        ptr->buffer[ptr->head] = value;
    
    }
}

void suf_insert(struct list *ptr, float value){
    if(((ptr->tail +1) % ptr->size) != ptr->head){
        ptr->buffer[ptr->tail] = value;
        ptr->tail = (ptr->tail + 1) % ptr->size;
    }
}

int main(void){

    /*declare list*/
    struct list l;
    struct list *ptr;
    int size;
    int selection;
    float pre_insert_val;
    float suf_insert_val;

    ptr = &l;
    size = 0;


    printf("Choose list size \n");
    scanf("%d", &size);
    printf("You choose size = %d \n", size);
    
    init_list(ptr,size);

    
    while(1){
        printf("Choose action\n 1-Pre-insert \n 2-Visit list \n 3-Suf-insert \n 4-Exit\n");
        scanf("%d", &selection);


        switch(selection){
            case 1:
                printf("Choose pre-insert value\n");
                scanf("%f",&pre_insert_val);
                pre_insert(ptr, pre_insert_val);
                break;
            case 2:
                printf("Print list: \n");
                visit_list(ptr);
                break;
            case 3:
                printf("Choose suf-insert value \n");
                scanf("%f", &suf_insert_val);
                suf_insert(ptr, suf_insert_val);
                break;
            case 4:
                exit(1);
            default:
                printf("Invalid selection number\n");
                exit(1);
                break;
        }
        
            


    }
    



    return 0;
}