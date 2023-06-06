#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int *arr, int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int *arr, int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

void bubble_sort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
        }
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int *arr, int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void generate_random_array(int *arr, int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; // Generiranje slučajnih brojeva od 0 do 99
    }
}

void print_array(int *arr, int n) {
    for (int i= 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Unesite veličinu polja: ");
    scanf("%d", &n);

    int arr[n];

    generate_random_array(arr, n);

    clock_t start = clock();
    bubble_sort(arr, n);
    clock_t end = clock();

    double time_taken_bubble = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);

    printf("Vrijeme sortiranja pomoću Bubble sort algoritma: %.2f ms\n", time_taken_bubble);

    generate_random_array(arr, n);

    start = clock();
    heap_sort(arr, n);
    end = clock();

    double time_taken_heap = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);

    printf("Vrijeme sortiranja pomoću Heap sort algoritma: %.2f ms\n", time_taken_heap);

    generate_random_array(arr, n);

    start = clock();
    merge_sort(arr, 0, n - 1);
    end = clock();

    double time_taken_merge = ((double)(end - start)) / (CLOCKS_PER_SEC / 1000);

    printf("Vrijeme sortiranja pomoću Merge sort algoritma: %.2f ms\n", time_taken_merge);

    return 0;
}

