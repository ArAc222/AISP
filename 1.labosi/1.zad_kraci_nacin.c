#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gen_arr(float V[], int n, float dg, float gg );
int sekv_pret( float V[], int n, float x );
void swap(float *xp, float *yp);
void selectionSort(float V[], int n);
int bin_pret(float V[], int n, float x);

int main()
{
    time_t t1, t2, t3, t4, t5, t6;
    int n;
    float *A;
    
    printf("Unesite n velicinu polja:\n");
    scanf("%d", &n);
    
    A = (float * ) malloc(n * sizeof(float));
    
    gen_arr(A, n, 5, 300);
    
    for(int i = 0; i < n; i++){
        printf("%f, ", A[i]);
    }
    
    float trazeni_br = 7;
    
    t1 = clock();
    
    sekv_pret(A, n, trazeni_br);
    
    t2 = clock();
    
    printf("\nVrijeme izmedu sekvecijalnog pr je: %ld ms", (t2 - t1));
    
    
    t3 = clock();
    
    selectionSort(A, n);
    
    t4 = clock();
    
    printf("\nVrijeme izmedu sortiranja je: %ld ms\n", (t4 - t3));
    
    
    for(int i = 0; i < n; i++){
        printf("%f, ", A[i]);
    }
    
    t5 = clock();
    
    bin_pret(A, n, trazeni_br);
    
    t6 = clock();
    
    printf("\nVrijeme izmedu binarnog pr je: %ld ms", (t6 - t5));
    
    return 0;
    
    free(A);
}

void gen_arr(float V[], int n, float dg, float gg ) {
    srand(time(NULL));
    for(int i = 0; i < n; i ++) {
        V[i] = dg + ((float) rand() / RAND_MAX) * (gg - dg);
    }
}


int sekv_pret( float V[], int n, float x ){
        for(int i = 0; i < n; i++){
        if(V[i] == x){
            return i;
        }
    }
    return -1;
}

void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
void selectionSort(float V[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (V[j] < V[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the first element
           if(min_idx != i)
            swap(&V[min_idx], &V[i]);
    }
}

int bin_pret(float V[], int n, float x)
{
    int left = 0;
    int right = n - 1;     // 2 3 5 6 9 6 7 8 6
    while (left <= right) {
        int middle = (left + right) / 2;
        if (V[middle] == x) {
            return middle;
        }
        else if (V[middle] < x) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return -1;
}
