/////////////////////////////////////////
// problema elicop OJI 2012 cls. IX
// Autor: Puscas Madalin (C)
// Data: 19.11.2014
///////////////////////////////////////

/////////////////////////////////////
// Date de test
//    7 9
//    1 1 1 1 1 1 1 1 1
//    0 0 0 0 1 1 1 1 0
//    0 0 1 0 1 1 1 0 0
//    1 1 1 0 1 1 0 1 1
//    0 0 1 1 1 1 0 1 1
//    1 1 1 1 1 1 0 1 1
//    1 1 1 1 1 1 0 0 1
//    4
//    1 1 3 3 -1
//    1 9 5 5 1
//    5 1 6 2 1
//    5 9 6 8 1
/////////////////////////////////////////

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int m, n, k, N1 = 0, N2 = 0, a[101][101], aux;
    int L1,C1, L2, C2, p, e[41] = {0};
    int n0, n1;
    int i , j , r;
    ifstream f("elicop.in");

    f >> m >> n;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            f >> a[i][j];

    f >> k;

    for (r = 1; r <= k; r++)
    {
        f >> L1 >> C1 >> L2 >> C2 >> p;
        if ( L1 > L2)
        {
            aux = L1; L1 = L2; L2 = aux;
            aux = C1; C1 = C2; C2 = aux;
        }
        n0 = n1 = 0;
        if (C1 < C2 && p == -1)
        {
            for (i = L1; i <= L2; i++)
                for (j = C1; j <= C1 + (i - L1); j++)
                    if (a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if (C1 < C2 && p == 1)
        {
            for (i = L1; i <= L2; i++)
                for (j = C1 + (i - L1); j <= C2; j++)
                    if (a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if (C1 > C2 && p == -1)
        {
            for (i = L1; i <= L2; i++)
                for (j = C1 - (i - L1); j <= C1; j++)
                    if (a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if (C1 > C2 && p == 1)
        {
            for (i = L1; i <= L2; i++)
                for (j = C2; j <= C1 - (i - L1); j++)
                    if (a[i][j] == 1)
                        n1++;
                    else
                        n0++;
        }
        if (n0 == 0)
            N1++;
        else if (n0 > n1)
        {
            N2++;
            e[N2] = r;
        }

    }
    f.close();


    ofstream g("elicop.out");
    g << N1 << endl;
    g << N2 << " ";
    for (i = 1; i <= N2; i++)
        g << e[i] << " ";
    g.close ();
    return 0;
}
