// Stack (Yığın / Yığıt) linked list
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct node{
    int data;
    struct node * next;
};

struct stack{
    struct node * top;
    int cnt; //stackteki eleman sayısı;
};

void push(struct stack * stk, int data){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp->data = data;
    temp->next = stk->top;
    stk->top = temp;
    stk->cnt++;
}

int pop(struct stack * stk){
    if(stk->cnt==0){ // stk->top == NULL
        printf("Stack boş iken pop işlemi yapamazsınız.\n");
        return 0;
    }
    struct node * temp = stk -> top;
    stk-> top = stk->top->next;
    int x = temp->data;
    free(temp);
    stk->cnt --;
    return x;
}

void print_stack(struct stack * stk){
    if(stk->cnt == 0){
        printf("Boş stack.\n");
    }
    struct node * temp = stk->top;
    for(int i = stk->cnt; i > 0; i++){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void reset(struct stack * stk){
    if(stk->cnt == 0){
        printf("Stack zaten boş.\n");
        return;
    }
    struct node * temp;
    while(stk->top != NULL){
        temp = stk->top;
        stk->top = stk->top->next;
        free(temp);
    }
    stk->cnt = 0;
}

/* 
void reset(struct stack * stk){
while(stk->cnt>0){
int x = pop(stk);
}
}
*/

int main(){
    setlocale(LC_ALL,"Turkish");
    int secim, data;
    struct stack stk;
    stk.top = NULL;
    stk.cnt = 0;

while(1){
        printf("\nStack with Linked List\n");
        printf("Aşağıdaki işlemlerden birini seçiniz.\n");
        printf("1- Yığına eleman ekleme(Push)\n");
        printf("2-Yığından eleman çıkarma(Pop)\n");
        printf("3-Yığını boşaltma(Reset)\n");
        printf("4-Elemanları listele.\n");
        printf("5-Çıkış\n");
        scanf("%d",&secim);

        switch(secim){
            case 1:
                printf("Lütfen eklemek istediğiniz değeri giriniz:\n");
                scanf("%d",&data);
                push(&stk, data);
                break;
            case 2:
                data = pop(&stk);
                break;
            case 3:
                reset(&stk);
            case 4:
                print_stack(&stk);
            case 5:
                exit(0);
            default:
                printf("Yanlış seçim\n");
        }
    }
}
