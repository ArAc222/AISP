#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
int s1[N];
int s2[N];
int sp1 = 0;
int sp2 = 0;
int x1 = 0;
int x2 = 0;

int povrhRek(int a, int b)
{
      if (a == b || b == 0) return 1;
      else return povrhRek(a - 1, b - 1) + povrhRek(a - 1, b);
}

struct Node {
    int val;
    struct Node* next;
};

struct Node* top1 = NULL;
struct Node* top2 = NULL;
int povrh = 0;

void push_s1(int x)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->val = x;
    newNode->next = top1;
    top1 = newNode;
}

void push_s2(int x)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack overflow\n");
        return;
    }
    newNode->val = x;
    newNode->next = top2;
    top2 = newNode;
}

int pop1() {
    if (top1 == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = top1->val;
    struct Node* temp = top1;
    top1 = top1->next;
    free(temp);
    return x;
}

int pop2() {
    if (top2 == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    int x = top2->val;
    struct Node* temp = top2;
    top2 = top2->next;
    free(temp);
    return x;
}

void povrhStog(int a, int b)
{
    push_s1(a);
    push_s2(b);

    while (top1 != NULL)
    {
        a = pop1();
        b = pop2();

        if (a == b || b == 0)
        {
            povrh = povrh + 1;
        }
        else
        {
            push_s1(a - 1);
            push_s2(b - 1);
            push_s1(a - 1);
            push_s2(b);
        }
    }
    printf("%d\n\n", povrh);
}


int main()
{
      time_t t1, t2, t3, t4;
      int n, m;
      printf("upisite n: ");
      scanf("%d", &n);
      m = n/2;
      t1 = clock();
      printf("%d\n\n", povrhRek(n, m));
      t2 = clock();
      t3 = clock();
      povrhStog(n, m);
      t4 = clock();
      printf("Vrijeme trajanja rekurzije: %ldms\nVrijeme trajanja stoga: %ldms\n\n", t2 - t1, t4 - t3);
      system("pause");

      return 0;
}
