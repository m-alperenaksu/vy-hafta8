// Stack (Yığın / Yığıt)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define STACK_SIZE 4
// alttan üste doğru

struct stack{
    int data[STACK_SIZE];
    int top; // top en üstteki elemanın indisini tutuyor.
};

struct stack stk;

void push(struct stack * stk, int data){
    if(stk->top == (STACK_SIZE - 1) ){
        printf("Stack dolu.\n");
        return;
    }
    else{
        stk->top++;
        stk->data[stk->top] = data;
    }
}

int pop(struct stack * stk){
    if(stk->top == -1){
        printf("Stack boş\n");
        return;
    }
    printf("%d elemanı stackten çıkartılmıştır.", stk->data[stk->top]);
    int data = stk->data[stk->top];
    stk->top--;
    return data;
}

void print_stack(struct stack * stk){
    if(stk->top == -1){
        printf("Stack boş\n");
        return;
    }
    int temp = stk->top; // Top'u kaybetmemek için temp'e atıyoruz.
    while(temp > -1){
        printf("%d ", stk->data[temp]);
        temp--;
    }
}

void reset(struct stack * stk){
    stk->top = -1;
}

int main(){
    setlocale(LC_ALL,"Turkish");
    int secim, data;
    struct stack stk;
    stk.top = -1;
    while(1){
        printf("\nStack with Array\n");
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