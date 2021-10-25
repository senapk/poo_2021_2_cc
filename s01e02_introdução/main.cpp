#include <stdio.h>

bool existe(int vet[], int size, int value) {
    for (int i = 0; i < size; i++)
        if (vet[i] == value)
            return true;
    return false;
}

#define size 5

int main() 
{
    int vet[size] = {1, 2, 3, 4, 5};
    printf("%d\n", existe(vet, size, 3));
    printf("%d\n", existe(vet, size, 6));
}