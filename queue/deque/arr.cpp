#include <iostream>

using namespace std;

int main()
{
    int C = 100;
    int n = 10;
    int arr[10][10] = {0};
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            int temp = arr[i][j] + C;
            arr[i][j] = arr[j][i];
            arr[j][i] = temp - C;
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}