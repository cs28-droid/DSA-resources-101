#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void selectionSort(int arr[], int n){
    int minIndex;
    for(int i = 0; i < n; ++i){
        minIndex = i;
        for(int j = i+1; j < n; ++j){
            if(arr[minIndex] > arr[j])
                minIndex = j;
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > arr[key]){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n-i-1; ++j){
            if(arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
        }
    }
}

void printArray(int arr[], int n){
    for(int i = 0; i < n; ++i)
        printf("%d ", arr[i]);
    printf("\n");
}

void sort(){
    int choice, n;
    int arr[50];
    printf("Enter the number of numbers you wish to enter: ");
    scanf("%d", &n);
    printf("Enter the numbers: \n");
    for(int i = 0; i < n; ++i)
        scanf("%d", &arr[i]);
    printf("Select your sorting method:\n");
    printf("1. Bubble sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Bubble sort\n");
    scanf("%d", &choice);
    switch(choice){
        case 1: bubbleSort(arr, n);
                printArray(arr, n);
                break;
        case 2: insertionSort(arr, n);
                printArray(arr, n);
                break;
        case 3: selectionSort(arr, n);
                printArray(arr, n);
                break;
        default: printf("Invalid input!\n");
                break;
    }
}

int main(){
    int choice;
    while(1){
        printf("1. Sort numbers:\n");
        printf("2. Exit\n");
        scanf("%d", &choice);
        if(choice == 1)
            sort();
        else if(choice == 2)
            exit(0);
        else
            printf("Invalid input!\n");
    }


    return 0;
}
