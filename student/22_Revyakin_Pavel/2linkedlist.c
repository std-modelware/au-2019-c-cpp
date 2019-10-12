#include <stdio.h>

/*
общий принцип:
 head (указатель)(глобальный) указывает сначала на  NULL потом на структуру темп
 temp (указатель)(локальный) указывает на только что созданную ячейку памяти, записывает туда значение переменной и нулевой указатель.
 создается указатель на структуру
 в него записывается адресс выделенной структуры памяти в которую он может обращаться и изменять элементы.
 если наша структура первая то head начинает указывать на неё(в этой структуре поле некст указывает на  NULL в этот момент), если же нет
 то наша структуру помещается в начало и её внутренний указатель(поле) указывает на 1-ю структуру(адресс которой хранил head) а head теперь хранит адресс на эту
 "втиснувшуюся в начало" структуру.

 */
typedef struct node{
    int value;
    struct node* next;
    struct node* prev;
}node;
node* head;
node* newelement(int x){
    node* tmp = (node*)malloc(sizeof(node));
    tmp->value = x;
    tmp->next = NULL;
    tmp->prev=NULL;
    return tmp;
}
void interinthestartofthedll(int x) {
    node *tmp = newelement(x);
    if (head == NULL) {
        head = tmp;
        return;
    }
    head->prev = tmp;
    tmp->next = head;
    head = tmp;
}

void print(node *head){
    node *runner=head;
    while(runner!=NULL){
        printf("%d   ",runner->value);
        runner=runner->next;
    }
    printf("\n");

}
void reversprint(node* head){
    node *reverserunner=head;
    if(reverserunner==NULL){
        return;
    }
    while(reverserunner->next!=NULL){
        reverserunner=reverserunner->next;
    }

    while (reverserunner!=NULL)
    {
        printf("%d   ",reverserunner->value);
        reverserunner=reverserunner->prev;
    }


}
void main(){
    int size,x;
    head = NULL;
    printf("how many elements you would enter?");
    scanf("%d",&size);
    for(int i =0;i<size;i++){
        scanf("%d",&x);
      interinthestartofthedllt(x);
    }

    print(head);
    reversprint(head);

}
