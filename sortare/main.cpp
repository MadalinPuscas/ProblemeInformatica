#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 200000

using namespace std;

void Print(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void Swap(int a[], int i, int j)
{
    int aux;
    aux = a[i];
    a[i] = a[j];
    a[j] = aux;
}

void Sort1(int a[], int n)
{
    int i, j, aux;
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (a[i] > a[j])
                Swap(a, i, j);
}

void Sort2(int a[], int n)
{
    int i, aux, sortat;
    do
    {
        sortat = 1;
        for (i = 0; i < n - 1; i++)
            if (a[i] > a[i + 1])
            {
                Swap(a, i, i + 1);
                sortat = 0;
            }
    }while (sortat == 0);
}

void InsertionSort(int a[], int n)
{
    int i, j, key;
    for (j = 1; j < n; j++)
    {
        key = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            i = i - 1;
        }
        a[i + 1] = key;
    }
}
void RandomInitialize(int a[], int n)
{
    /* initialize random seed: */
    srand (time(NULL));

    for (int i = 0; i < n; i++)
        a[i] = rand() % 1000;
}
int main()
{
    int v[] = {3, 4, 1, 2, 6, 5};
    int a[N] = {0};

    int n;

    n = sizeof(v) / sizeof(int);

    Print(v, n);
    InsertionSort(v, n);
    Print(v, n);


    n = N;
    cout << "Initializing...";
    RandomInitialize(a, n);
    cout << "Done!" << endl;
    //Print(a, n);

    cout << "Sorting...";
    InsertionSort(a, n);
    cout << "Done!" << endl;
    //Print(a, n);
    return 0;
}
