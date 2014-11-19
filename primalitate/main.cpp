#include <iostream>
#include <ctime>
using namespace std;

int P1(int n)
{
    int d = 0;
    int i;

    for (i = 1; i <= n; i++)
        if(n % i == 0)
            d++;

    if (d == 2)
        return 1;
    else
        return 0;

}


int P2(int n)
{
    int d = 0;
    int i;

    for (i = 2; i < n; i++)
        if(n % i == 0)
            d++;

    if (d == 0)
        return 1;
    else
        return 0;

}

int P3(int n)
{
    int d = 0;
    int i;

    for (i = 2; i <= n / 2; i++)
        if(n % i == 0)
            d++;

    if (d == 0)
        return 1;
    else
        return 0;

}
int P4(int n)
{
    int d = 0;
    int i;

    for (i = 2; i * i <= n; i++)
        if(n % i == 0)
            d++;

    if (d == 0)
        return 1;
    else
        return 0;

}
int main()
{
    cout << "Hello world!" << endl;

    int n;


    cout << "Introduceti un nr natural: ";
    cin >> n;


    clock_t begin = clock();

    if (P1(n) == 1)
        cout << "Nr. e prim" << endl;
    else
        cout << "Nr e compus" << endl;

    clock_t end = clock();
    double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Elapsed secs: " << elapsed_secs << endl;


    begin = clock();
    if (P2(n) == 1)
        cout << "Nr. e prim" << endl;
    else
        cout << "Nr e compus" << endl;
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Elapsed secs: " << elapsed_secs << endl;

    begin = clock();
    if (P3(n) == 1)
        cout << "Nr. e prim" << endl;
    else
        cout << "Nr e compus" << endl;

    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Elapsed secs: " << elapsed_secs << endl;

    begin = clock();
    if (P4(n) == 1)
        cout << "Nr. e prim" << endl;
    else
        cout << "Nr e compus" << endl;
    end = clock();
    elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
    cout << "Elapsed secs: " << elapsed_secs << endl;
    return 0;
}
