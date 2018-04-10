#include "list.h"
#define start_with 5

int empty(const List* list){
    if(list->head_ == 0) return 1;
    if(list->cur_ == 0) return 1;
    return 0;
}

int size(const List* list){
    int size = 0;
    if(empty(list)) return size;
    head(list);
    do{
            ++size;
    }while(next(list) != -1);
    head(list);
    return size;
}

int head(List* list){
    if(empty(list)) return -1;
    list->cur_ = list->head_;
    return 0;
}

int next(List* list){
    if(empty(list)) return -1;
    if(list->cur_->next_ == 0) return -1;
    list->cur_ = list->cur_->next_;
    return 0;
}

int prev(List* list){
    if(empty(list)) return -1;
    if(list->cur_->prev_ == 0) return -1;
    list->cur_ = list->cur_->prev_;
    return 0;
}

int get(List* list, T* val){
    if(empty(list)) return -1;
    *val = list->cur_->val_;
    return 0;
}

int set(List* list, T val){
    if(empty(list))
    {
        createNew(list);
        set(list,val);
        return 0;
    };
    list->cur_->val_ = val;
    return 0;
}

int insert_before(List* list, T val){
    if(empty(list))
    {
        createNew(list);
        set(list,val);
        return 0;
    };
    Node *ptr = (Node*) malloc(sizeof(Node));
    if(ptr == 0) return -1;
    ptr->next_ = list->cur_;
    if(prev(list) == -1)
    {
        ptr->prev_ = 0;
        list->cur_->prev_ = ptr;
        prev(list);
        set(list,val);
    }
    else
    {
        ptr->prev_ = list->cur_;
        list->cur_->next_ = ptr;
        next(list);
        next(list);
        list->cur_->prev_ = ptr;
        prev(list);
        set(list,val);
    }
    next(list);
    return 0;
}

int insert_after(List* list, T val){
    if(empty(list))
    {
        createNew(list);
        set(list,val);
        return 0;
    };
    Node *ptr = (Node*) malloc(sizeof(Node));
    if(ptr == 0) return -1;
    ptr->prev_ = list->cur_;
    if(next(list) == -1)
    {
        ptr->next_ = 0;
        list->cur_->next_ = ptr;
        next(list);
        set(list,val);
    }
    else
    {
        ptr->next_ = list->cur_;
        list->cur_->prev_ = ptr;
        prev(list);
        prev(list);
        list->cur_->next_ = ptr;
        next(list);
        set(list,val);
    }
    prev(list);
    return 0;
}

void destroy(List* list){
    if(empty(list) == -1) return -1;
    head(list);
    next(list);
    int siz = size(list);
    for(int i = 0; i < siz;i++){
        free(list->head_);
        list->head_ = list->cur_;
        next(list);
    }
    list->head_ = 0;
}

int init(List* list){
    list->head_ = 0;
    createNew(list);
    set(list,0);

    for(int i = 1; i < start_with; i++){
        insert_after(list,i*i);
        next(list);
    }
}

int print(List* list){
    if(empty(list)) return -1;
    head(list);
    T val = 0;
    printf("   List:\n");
    int siz = size(list);
    for(int i = 0; i < siz;i++){
        get(list,&val);
        printf("%d) %d\n",i,val);
        next(list);
    }
}
int createNew(List *list){
    if(empty(list))
    {
        list->head_ = (Node*) malloc(sizeof(Node));
        list->head_->prev_ = 0;
        list->head_->next_ = 0;
        head(list);
    }
    else
    {
        destroy(list);
        createNew(list);
    }
}
