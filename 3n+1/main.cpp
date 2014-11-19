#include <iostream>

using namespace std;

int GenerareSecventa(int n, int &max, int flag)
{
    int contor = 0;

    max = n;
    while (n != 1)
    {
        if (n % 2 ==0)
            n = n / 2;
        else
            n = 3 * n + 1;
        if (flag == 1)
            cout << n << " ";
        if (n > max)
            max = n;
        contor++;
    }
    return contor;
}

int main()
{

    int n, max;
    cout << "introduceti un nr.:";
    cin >> n;


    int lungimeSecventa = GenerareSecventa(n, max, 1);
    cout << endl << "lungimea secventei este: " << lungimeSecventa << endl;
    cout << "maximul din secventa este: " << max << endl;

    int a, b, i;
    cout << "introduceti capetele intervalului: ";
    cin >> a >> b;

    int lungimeMaxima = 0;
    for (i = a; i <= b; i++)
    {
        cout << i << ": ";
        lungimeSecventa = GenerareSecventa(i, max, 1);
        cout << endl << "lungimea secventei este: " << lungimeSecventa << endl;
        if (lungimeMaxima < lungimeSecventa)
            lungimeMaxima = lungimeSecventa;
        cout << endl;
    }
    cout << "lungimea maxima este: " << lungimeMaxima << endl;

    cout << "secventa de lungime maxima se obtine pt. : ";
    for (i = a; i <= b; i++)
    {
        lungimeSecventa = GenerareSecventa(i, max, 0);

        if (lungimeMaxima == lungimeSecventa)
            cout << i << endl;

    }
    cout << endl;
    return 0;
}
