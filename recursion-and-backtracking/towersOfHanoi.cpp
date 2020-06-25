#include <iostream>
#include <math.h>
using namespace std;

void towerOfHanoi(int n, char fromRod, char toRod, char auxillaryRod)
{
    if (n == 1)
    {
        cout << "Move disk 1 from " << fromRod << " to rod " << toRod << endl;
        return;
    }

    towerOfHanoi(n - 1, fromRod, auxillaryRod, toRod);
    cout << "Move disk" << n << " from rod" << fromRod << " to rod " << toRod << endl;

    towerOfHanoi(n - 1, auxillaryRod, toRod, fromRod);
}

int main()
{
    int n = 5;
    towerOfHanoi(5, 'A', 'C', 'B');
    cout << "Total number of moves required " << pow(2, 5) - 1 << endl;
    return 0;
}