    #ifndef LIST_H
#define LIST_H
typedef int T;

typedef struct node{
    T val;
    struct Node* next;
} Node;

// Возвращает 1, если список пуст, иначе - 0
int empty(const Node *head);

// Возвращает количество элементов в списке
int size(const Node* head);

// Если в списке есть элемент с номером k, то присваивает аргументу val значение k-го
// элемента и возвращает 0, иначе - возвращает -1
int at(const Node* head, int k, T* val);

// Добавляет на k-ю позицию элемент со значением val. Если это возможно возвращает
// 0, иначе - возвращает -1
int insert(Node** head, int k, T val);

// Если в списке есть элемент с номером k, то удаляет из списка k-й элемент и
// возвращает 0, иначе - возвращает -1
int erase(Node** head, int k);

// Удаляет все элементы из списка
void eraseAll(Node** head);

//Проверяет ключевые условия для соответсвия действительности
int range(const Node* head,int k);

//Инициализация - заполняет max_size елементов квадратами чисел.
void init(Node **head);

//Выводит на экран структуру.
int show(const Node* head);


#endif // LIST_H
