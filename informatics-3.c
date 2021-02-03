#include<stdio.h>

void printArray(int array[], int arrayLength) {
    for (int i = 0; i < arrayLength; i++)
        printf("%d ", array[i]);
    printf("\n");
}

//--------------------------------------------------------43
//for (s = 0, i = 0; i < n; i++) {
//    if (i % 2 == 0)	s = s + A[i]; // (i % 2 == 0) — опечатка? (A[i] % 2 == 0)?
//    else s = s - A[i];
//}
//Нахождение разности суммы элементов с чётным индексом и суммы элементов с нечётным индексом в массиве
int task43(int array[], int arrayLength) {
    int sum;
    int i;

    for (sum = 0, i = 0; i < arrayLength; i++) {
        if (i % 2 == 0)	sum = sum + array[i];   // Если элемент с чётным индексом, то элемент прибавляем
        else sum = sum - array[i];              // Если же элемент с нечётным индексом, то вычитаем.
    }

    return sum;
}

////--------------------------------------------------------44
//for (j = 0; n != 0; j++) {
//    for (k = 0, i = 1; i < n; i++)
//        if (A[i] < A[k]) k = i;
//    B[j] = A[k];
//    for (; k < n - 1; k++) A[k] = A[k + 1];
//    n--;
//}
//Сортировка выборкой по возрастанию, которая записывается в массив B
void task44(int arrayA[], int arrayB[], int arrayLength) {
    int j, i, k;
    int n = arrayLength;

    for (j = 0; n != 0; j++) {
        for (k = 0, i = 1; i < n; i++)        // Цикл действует пока n не равен нулю, а также i < n
            if (arrayA[i] < arrayA[k]) k = i; // Если элемент i-того массива меньше элемента k-того массива, то k = i;

        arrayB[j] = arrayA[k];                // В массив B записывается элемент с массива A k-того.

        for (; k < n - 1; k++)
            arrayA[k] = arrayA[k + 1]; // Цикл действует пока индекс k меньше предпоследнего максимального. Сдвигается массив.

        n--;
    }

    printArray(arrayB, arrayLength);
}

////--------------------------------------------------------45
//for (j = 0, max = A[0]; j < n; j++)
//    if (A[j] > max) max = A[j];
//for (j = 0; j < n; j++) {
//    for (k = 0, i = 1; i < n; i++)
//        if (A[i] < A[k]) k = i;
//    B[j] = A[k];
//    A[k] = max + 1;
//}
//Заполняет массив В элементами из массива А по возрастанию
void task45(int arrayA[], int arrayB[], int arrayLength) {
    int j, max, k, i;

    for (j = 0, max = arrayA[0]; j < arrayLength; j++) //нахождение максимального элемента в массиве А
        if (arrayA[j] > max) max = arrayA[j];

    for (j = 0; j < arrayLength; j++) {
        for (k = 0, i = 1; i < arrayLength; i++)  //Сортировка массива А в порядке возрастания
            if (arrayA[i] < arrayA[k]) k = i;     // Для каждого j-того места в массиве B ищем оставшееся минимальное из массива А
        arrayB[j] = arrayA[k];
        arrayA[k] = max + 1; // Присваиваем минимальному элементу макс. значение+1, чтобы он не мешался при след. итерации
    }

    printArray(arrayB, arrayLength);
}

////--------------------------------------------------------46
/*
int n = 10, k, i, c, A[10] = { 1, 15, 29, 10, 0, -1, -12, 3, 5, 6 };
while (n != 0)
{
    for (k = 0, i = 1; i < n; i++)
        if (A[i] < A[k]) k = i;           
    c = A[k]; A[k] = A[n - 1]; A[n - 1] = c;    
    n--;
}
for (i = 0; i < 10; i++)
    printf("A[%d] = %d\n", i, A[i]); */
void task46(int A[], int arrayLenght)
{
    int n = arrayLenght;
    int k, i, c;
    while (n != 0)
    {
        for (k = 0, i = 1; i < n; i++)
            if (A[i] < A[k]) k = i;           //запоминает номер минимального элемента      
        c = A[k]; A[k] = A[n - 1]; A[n - 1] = c;     //сортирует массив в порядке убывания
        n--;
    }
    printArray(A, arrayLenght); //выводит отсортированный массив
}

////--------------------------------------------------------47
//for (j = 0, a = 10; a < v; a++) {
//    for (s = 0, n = a, s = 0; n != 0; n = n / 10) {
//        k = n % 10;
//        if (k != 0 && a % k != 0) { s = 1; break; }
//    }
//    if (s == 0) A[j++] = a;
//}
//  Заполняет массив числами, в которых каждая цифра делит само число без остатка.
void task47(int maxInt, int A[], int n) {
    int j, a, s, n, k;

    for (j = 0, a = 10; a < maxInt && j < n; a++) {
        for (s = 0, n = a, s = 0; n != 0; n = n / 10) {    // Цикл выполняется пока n не равен 0, при этом после каждого действия
            k = n % 10;                                    // запоминается последняя цифра числа и откидываеся у изначального (div и mod)
            if (k != 0 && a % k != 0) { s = 1; break; }    // Если последняя цифра числа k и остаток от деления числа а на k не равны нулю, то s = 1. Цикл прекращает работу.
        }
        if (s == 0) A[j++] = a;                            // Если выполнилось условие и s = 0, то в массив сохраняется число a
    }

    printf("maxInt: %d\n", maxInt);
    printArray(A, j);
    printf("\n");
}

////--------------------------------------------------------48
/*
int A[10] = { -1,2,2,0,0,0,7,-8,9,7 };
int n = 10; 
int i, j;
for (i = 0; i < n - 1; i++)
    if (A[i] == A[i + 1]) {
        for (j = i; j < n - 2; j++) A[j] = A[j + 2];
        n = n - 2;
        i--;
    }

for (i = 0; i < n; i++) {
    printf("%d ", A[i]);
} */
void task48(int A[], int arrayLenght)
// Удаляет по два равных элемента, которые идут подряд
// На места удалённых элементов сдвигаются последующие элементы массива
{
    int n = arrayLenght;
    int i, j;
    for (i = 0; i < n - 1; i++)
        // Если текущий и след. элемент равны
        if (A[i] == A[i + 1]) {
            // То сдвигаем массив влево, так что вместо текущего и след. элемента
            // окажутся числа которые шли после
            for (j = i; j < n - 2; j++) A[j] = A[j + 2];
            n = n - 2;
            i--;
        }
    printArray(A, n);
}

////--------------------------------------------------------49
/*
int i, s, k, A[10] = { 0, 2, -2, -1, 5, 6, 9, 11, 15, 20};
for (i = 0, k = -1; i < 10; i++) {
    if (A[i] < 0) continue;             
    if (k == -1) k = i;
    else if (A[i] < A[k]) k = i;        
}
printf("Min=%d", A[k]); */
int task49(int A[], int arrayLenght)
{
    int i, k, n = arrayLenght;               //ищет минимальный неотрицательный элемент массива
    for (i = 0, k = -1; i < n; i++) {
        if (A[i] < 0) continue;             //пропускает отрицательные элементы
        if (k == -1) k = i;
        else if (A[i] < A[k]) k = i;        //запоминает номер минимального элемента
    }
    return A[k];
}

////--------------------------------------------------------50
/*
int s, i, k, A[10] = { -1, 2, 3, -1, 4, -6, -1, 5, 11, -9 };
for (i = 0, s = 0, k = 0; i < 10; i++)
    if (A[i] < 0) k = 1;
    else {                      
        if (k == 1) s++;       
        k = 0;
    }
printf("%d", s); */
int task50(int A[], int arrayLenght)
{
    int s, i, k, n=arrayLenght;
    for (i = 0, s = 0, k = 0; i < n; i++)
        if (A[i] < 0) k = 1;
        else {                      //ищет количестов пар элементов(отрицательный элемент, положительный элемент, которые идут друг за другом) 
            if (k == 1) s++;        //s - переменная счетчик    
            k = 0;
        }
    return s;
}

////--------------------------------------------------------51
/*
int i, s, A[10] = { 1, 2, 3, 4, 5, 6, -7, -8, 9, 10 };
for (i = 0, s = 0; i < 10; i++)
    if (A[i] > s) s = A[i];    
printf("%d", s); */
int task51(int A[], int arrayLenght)
{
    int i, s;
    for (i = 0, s = 0; i < arrayLenght; i++)
        if (A[i] > s) s = A[i];    //поиск максимума в массиве, путем присваивания максимального элемента переменной
    return s;
}

////--------------------------------------------------------52
// for (i=1,k=0; i<10; i++)
//     if (A[i]>A[k]) k=i;
// Возвращает индекс макс. элемента.
int task52(int array[], int arrayLength) {
    int i, k;

    for (i = 1, k = 0; i < arrayLength; i++)
        if (array[i] > array[k]) k = i;//поиск максимума в массиве, путем запоминания индекса максимального элемента

    return k;
}

int main() {    
    {
        printf("//-------------------------------------------43\n");
        int a1[5] = { 2, 3, 4, 3, 6 };
        printf("f43-1: sum: %d\n", task43(a1, 5));
        

        int a2[4] = { 13, 23, 24, 12};
        printf("f43-2: sum: %d\n", task43(a2, 4));

        int a3[3] = { 100, 99, 3};
        printf("f43-3: sum: %d\n", task43(a3, 3));
    }

    {
        printf("//-------------------------------------------44\n");
        int A1[10] = { 1, 15, 9, 3, 7, 2, 16, 21, 1, 10 };
        int B1[10];
        printf("F44-1\n");
        task44(A1, B1, 10);

        int A2[20] = { 1, 15, 9, 3, 7, 2, 16, 21, 1, 10,17, 15, 9, 13, 71, 22, 16, 21, 19, 10 };
        int B2[20];
        printf("F44-2\n");
        task44(A2, B2, 20);

        int A3[5] = { 5,4,3,2,1};
        int B3[5];
        printf("F44-3\n");
        task44(A3, B3, 5);
    }

    {
        printf("//-------------------------------------------45\n");
        int A1[10] = { 1, 15, 9, 3, 7, 2, 16, 21, 1, 10 };
        int B1[10];
        printf("F45-1\n");
        task45(A1, B1, 10);

        int A2[20] = { 1, 15, 9, 3, 7, 2, 16, 21, 1, 10,17, 15, 9, 13, 71, 22, 16, 21, 19, 10 };
        int B2[20];
        printf("F45-2\n");
        task45(A2, B2, 20);

        int A3[5] = { 5,4,3,2,1 };
        int B3[5];
        printf("F45-3\n");
        task45(A3, B3, 5);
    }

    {
        printf("//-------------------------------------------46\n");
        int A1[10] = { 1, 15, 9, 3, 7, 2, 16, 21, 1, 10 };
        printf("F46-1\n");
        task46(A1, 10);

        printf("//-------------------------------------------46\n");
        int A2[10] = { 1, 15, 9, 21, 5, -4, 1, 200, 100, 99 };
        printf("F46-2\n");
        task46(A2, 10);

        printf("//-------------------------------------------46\n");
        int A3[10] = { 1, -3, 9, 3, 0, 1, 3, 77, 1, 9 };
        printf("F46-3\n");
        task46(A3, 10);
    }

    {
        printf("//-------------------------------------------47\n");
        int A1[100] = { 0 };
        printf("F47-1\n");
        task47(260, A1, 100);
        int A2[40] = {0};
        printf("F47-2\n");
        task47(36, A2, 40);
        int A3[70] = { 0 };
        printf("F47-3\n");
        task47(120, A3, 70);
    }

    {
        printf("//-------------------------------------------48\n");
        int A1[10] = { 1, 15, 9, 2, 2, 2, 16, 21, 1, 1 };
        printf("F48-1\n");
        task48(A1, 10);

        printf("//-------------------------------------------48\n");
        int A2[10] = { 1, 15, 15, 15, 5, 1, 1, 200, 100, 100 };
        printf("F48-2\n");
        task48(A2, 10);

        printf("//-------------------------------------------48\n");
        int A3[10] = { 1, -3, 9, 0, 4, 0, 0, 77, 1, 1 };
        printf("F48-3\n");
        task48(A3, 10);
    }

    {
        printf("//-------------------------------------------49\n");
        int A1[10] = { 1, 15, 9, 2, 2, 2, 16, 21, 1, 1 };
        printf("F49-1\n");
        printf("%d\n", task49(A1, 10));

        printf("//-------------------------------------------49\n");
        int A2[10] = { 9, 15, 15, 15, 5, 8, 7, 200, 100, 100 };
        printf("F49-2\n");
        printf("%d\n", task49(A2, 10));

        printf("//-------------------------------------------49\n");
        int A3[10] = { 1, -3, 9, 0, 4, 0, 0, 77, 1 };
        printf("F49-3\n");
        printf("%d\n", task49(A3, 9));
    }

    {
        printf("//-------------------------------------------50\n");
        int A1[10] = { 1, 15, 9, 2, 2, 2, 16, 21, 1, 1 };
        printf("F50-1\n");
        printf("%d\n", task50(A1, 10));

        printf("//-------------------------------------------50\n");
        int A2[8] = { 9, 15, 15, -1, 5, 0, -7, 1 };
        printf("F50-2\n");
        printf("%d\n", task50(A2, 8));

        printf("//-------------------------------------------50\n");
        int A3[10] = { 1, -3, 9, 0, 4, 0, 0, 77, 1 };
        printf("F50-3\n");
        printf("%d\n", task50(A3, 9));
    }

    {
        printf("//-------------------------------------------51\n");
        int A1[10] = { 1, 15, 9, 2, 2, 2, 16, 21, 1, 1 };
        printf("F51-1\n");
        printf("%d\n", task51(A1, 10));

        printf("//-------------------------------------------51\n");
        int A2[8] = { 9, 15, 15, -1, 5, 0, -7, 1 };
        printf("F51-2\n");
        printf("%d\n", task51(A2, 8));

        printf("//-------------------------------------------51\n");
        int A3[10] = { 1, -3, 9, 0, 4, 0, 0, 77, 1 };
        printf("F51-3\n");
        printf("%d\n", task51(A3, 9));
    }

    {
        printf("//-------------------------------------------52\n");
        int A1[12] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
        printf("F52-1: %d - index of max. element.\n", task52(A1, 12));
        
        int A2[10] = { 15,12,-3,4,5,6,76,88,9,10 };
        printf("F52-2: %d - index of max. element.\n", task52(A2, 10));
        
        int A3[6] = {12, 31, 67, 2, 18, 9};
        printf("F52-3: %d - index of max. element.\n", task52(A3, 6));
    }
}
