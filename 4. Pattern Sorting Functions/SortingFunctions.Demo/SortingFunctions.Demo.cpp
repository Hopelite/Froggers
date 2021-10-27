#include <iostream>
#include <vector>
#include <iterator>
#include "..\SortingFunctions\SortingFunctions.h"

using namespace std;

int main()
{
    int arr[5]{ 3, 5, 2, 1, 4 };
    vector<int> vect;
    vect.push_back(3);
    vect.push_back(5);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(4);

    SortingFunctions::bubbleSort(vect.begin(), vect.end());
    SortingFunctions::bubbleSort(begin(arr), end(arr));
    for (size_t i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << vect[i] << endl;
    }
}
