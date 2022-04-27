// Pirminiu dvyniu paieskos algoritmas

#include "bits/stdc++.h"

using namespace std;


void printTwinPairs(int n)
{
    int P[1000];
    P[0] = 2;
    P[1] = 3;
    int m, flag = 0, it=2;

    cout << "(3, 5)" << endl;
    for (int k = 1; k < n; k++)
    {
        m = (6 * k - 1)/2;
        for (int i = 2; i <= m; i++)
        {
            if ((6 * k - 1) % i == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            P[it] = 6 * k - 1;
            it++;
            m = (6 * k + 1)/2;
            for (int j = 2; j <= m; j++)
            {
                if ((6 * k + 1) % j == 0)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 0)
            {
                P[it] = 6 * k + 1;
                it++;
                cout << "(" << 6 * k - 1 << ", " << 6 * k + 1 << ")" << endl;
            }
        }
        flag = 0;
    }
    
}

int main()
{
    const int n = 1000; // iki kokio k norite ieskoti pirminiu skaiciu poru?

    printTwinPairs(n);

    return 0;
}