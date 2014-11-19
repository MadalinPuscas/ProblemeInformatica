#include <iostream>
#include <fstream>
using namespace std;

int cool(int a[], int n, int stg, int dr, int &max, int &distincte)
{
    int min = 1001;
    int i;
    int C[1001] = {0};

    for (i = stg; i <= dr; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
        C[a[i]]++;
    }
    for (i = min; i <= max; i++)
        if (C[i] == 1)
            distincte++;

    if ((max - min + 1 == dr - stg + 1) && (distincte == dr - stg + 1))
        return 1;
    else
        return 0;


}

int main()
{
    ifstream f("7-cool.in");
    ofstream g("cool.out");
    int a[5001] = {0};
    int p, n, k, j;
    int i, max = 0, distincte = 0, contor = 0;

    f >> p;
    f >> n >> k;
    for (i = 1; i <= n; i++)
        f >> a[i];
    f.close();

    if (p == 1)
    {
        if(cool(a, n, 1, k, max, distincte))
        {
            g << max;
        }
        else{
            g << distincte;
        }
    }
    else if (p ==2)
    {
        // rezolvarea cerintei 2
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= i; j++)
            {
                max = distincte = 0;
                if(cool(a, n, j, j + n - i, max, distincte))
                {
                    contor++;
                }
            }
            if (contor > 0)
            {
                g << n - i + 1 << endl;
                g << contor;
                break;
            }
        }
    }
    else
        cout << "fisier gresit";
    return 0;
}
