#include <iostream>
#include <fstream>
#define MAX 100
using namespace std;
int BinSum(int currentBin, int w[], int n, int bin[])
{

}

void PrintBins (int w[], int n, int bin[])
{
    int max = 0, i, j;
    for (i = 0; i < n; i++)
        if (max < bin[i])
            max = bin[i];
    for (i = 1; i <= max; i++)
    {
        cout << i << ": ";
        for (j = 0; j < n; j++)
            if (bin[j] == i)
                cout << w[j] << " ";
        cout << endl;
    }
}


void NextFit(int C, int n, int w[], int bin[])
{
    int currentBin = 1, suma = 0, i;
    for (i = 0; i < n; i++)
    {
        if (suma + w[i] <= C)
        {
            bin[i] = currentBin;
            suma = suma + w[i];
        }
        else
        {
            currentBin++;
            bin[i] = currentBin;
            suma = w[i];
        }
    }
}

int main()
{
    int C, n, w[MAX] = {0}, bin[MAX] = {0}, i;

    ifstream f("Date.in");

    f >> C;
    f >> n;
    for (i = 0; i < n; i++)
        f >> w[i];
    f.close();

    NextFit(C, n, w, bin);
    PrintBins(w, n, bin);

    return 0;
}
