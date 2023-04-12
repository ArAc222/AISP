#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100000 // broj elemenata u nizu

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    int v[N]; // niz V
    Node* head = NULL; // glava povezanog popisa
    clock_t start, end; // varijable za mjerenje vremena

    // generiranje niza V
    start = clock();
    for (int i = 0; i < N; i++) {
        v[i] = rand();
    }
    end = clock();
    double time_v = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // stvaranje povezanog popisa
    start = clock();
    for (int i = N - 1; i >= 0; i--) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = v[i];
        new_node->next = head;
        head = new_node;
    }
    end = clock();
    double time_list = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // sekvencijalno pretraživanje niza
    start = clock();
    int search_element = v[N-1]; // tražimo zadnji element u nizu
    for (int i = 0; i < N; i++) {
        if (v[i] == search_element) {
            break;
        }
    }
    end = clock();
    double time_v_search = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // sekvencijalno pretraživanje povezanog popisa
    start = clock();
    Node* current = head;
    while (current != NULL) {
        if (current->data == search_element) {
            break;
        }
        current = current->next;
    }
    end = clock();
    double time_list_search = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;

    // ispis rezultata mjerenja vremena
    printf("Vrijeme potrebno za generiranje niza: %f sekundi\n", time_v);
    printf("Vrijeme potrebno za stvaranje povezanog popisa: %f sekundi\n", time_list);
    printf("Vrijeme potrebno za sekvencijalno pretraživanje niza: %f sekundi\n", time_v_search);
    printf("Vrijeme potrebno za sekvencijalno pretraživanje povezanog popisa: %f sekundi\n", time_list_search);

    // oslobađanje memorije zauzete za povezani popis
    current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
