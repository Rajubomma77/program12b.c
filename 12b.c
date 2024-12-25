#include <stdio.h>
#include <stdlib.h>

int *ht, m;
int count = 0;

void Insert(int key) {
    int index = key % m;
    int originalIndex = index;

    while (ht[index] != -1) {
        index = (index + 1) % m;
        if (index == originalIndex) {
            printf("Hash table is full. Cannot insert the key: %d\n", key);
            return;
        }
    }

    ht[index] = key;
    count++;
}

void display() {
    if (count == 0) {
        printf("Hash Table is empty.\n");
        return;
    }

    printf("Hash Table contents are:\n");
    for (int i = 0; i < m; i++) {
        if (ht[i] != -1)
            printf("T[%d] --> %d\n", i, ht[i]);
        else
            printf("T[%d] --> NULL\n", i);
    }
}

int main() {
    int n;
    printf("Enter the number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    ht = (int *)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        ht[i] = -1;
    }

    int key;
    for (int i = 0; i < n; i++) {
        printf("Enter the key value (K) for employee %d: ", i + 1);
        scanf("%d", &key);
        Insert(key);
    }

    printf("\nDisplaying Keys inserted into the hash table:\n");
    display();

    free(ht);
    return 0;
}

