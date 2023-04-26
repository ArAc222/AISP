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

void push_s1(int x)
{
      if (sp1 == N)
      {
            printf("Stack overflow..");
      }
      else
      {
            sp1 = sp1 + 1;
            s1[sp1] = x;
      }
}

void push_s2(int x)
{
      if (sp2 == N)
      {
            printf("Stack overflow..");
      }
      else
      {
            sp2 = sp2 + 1;
            s2[sp2] = x;
      }
}

int pop1() {
      if (sp1 == 0) {
            printf("Stack Underflow\n");
      }
      else
      {
            x1 = s1[sp1];
            sp1 = sp1 - 1;
            return x1;
      }
}

int pop2() {
      if (sp2 == 0) {
            printf("Stack Underflow\n");
      }
      else
      {
            x2 = s2[sp2];
            sp2 = sp2 - 1;
            return x2;
      }
}

void povrhStog(int a, int b)
{
      push_s1(a);
      push_s2(b);
      int povrh = 0;

      while (sp1 != 0)
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
