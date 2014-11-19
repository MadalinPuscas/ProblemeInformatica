#include <iostream>
#define MAX 100
using namespace std;

///////////////////////
// permutari
//////////////////////
void init(int v[], int k)
{
    v[k] = 0;
}

int succesor(int v[], int k, int n)
{
    int as = 0;
    if (v[k] < n)
    {
         v[k]++;
         as = 1;
    }

    return as;
}
int valid(int v[], int k, int n)
{
    int i;
    int ev = 1;
    for (i = 0; i < k && ev == 1; i++)
        if (v[i] == v[k])
            ev = 0;
    return ev;
}

int solutie(int v[], int k, int n)
{
    return k == n - 1;
}

void tipar(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}

void Permutari(int n)
{
    int v[MAX] = {0};
    int k, as, ev;

    k = 0;
    init(v, k);
    while (k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as)
                ev = valid(v, k, n);
        }while (as && !ev);
        if (as)
        {
            if (solutie(v, k, n))
                tipar(v, n);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k = k - 1;
    }
}


/////////////////////
// Produs Cartezian
////////////////////

int validPC(int v[], int k, int n)
{
   return 1;
}

void ProdusCartezian(int n)
{
    int v[MAX] = {0};
    int k, as, ev;

    k = 0;
    init(v, k);
    while (k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as)
                ev = validPC(v, k, n);
        }while (as && !ev);
        if (as)
        {
            if (solutie(v, k, n))
                tipar(v, n);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k = k - 1;
    }
}

////////////////////////
// Aranjamente
////////////////////////


void Aranjamente(int n, int r)
{
    int v[MAX] = {0};
    int k, as, ev;

    k = 0;
    init(v, k);
    while (k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as)
                ev = valid(v, k, n);
        }while (as && !ev);
        if (as)
        {
            if (solutie(v, k, r))
                tipar(v, r);
            else
            {
                k++;
                init(v, k);
            }
        }
        else
            k = k - 1;
    }
}


/////////////////////////
// Combinari
/////////////////////////

void initCMB(int v[], int k)
{
    if (k == 0)
        v[k] = 0;
    else
        v[k] = v[k - 1];
}

void Combinari(int n, int r)
{
    int v[MAX] = {0};
    int k, as, ev;

    k = 0;
    initCMB(v, k);
    while (k >= 0)
    {
        do
        {
            as = succesor(v, k, n);
            if (as)
                ev = valid(v, k, n);
        }while (as && !ev);
        if (as)
        {
            if (solutie(v, k, r))
                tipar(v, r);
            else
            {
                k++;
                initCMB(v, k);
            }
        }
        else
            k = k - 1;
    }
}


int main()
{
    int n;
    cout << "n= ";
    cin >> n;

    cout << "Permutari:\n";
    Permutari(n);

    cout << "ProdusCartezian:\n";
    ProdusCartezian(n);

    int k;
    cout << "k=";
    cin >> k;

    cout << "Aranjamente:\n";
    Aranjamente(n, k);

    cout << "Combinari:\n";
    Combinari(n, k);
    return 0;
}
