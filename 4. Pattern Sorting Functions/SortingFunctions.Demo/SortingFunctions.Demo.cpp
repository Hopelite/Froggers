#include <iostream>
#include <vector>
#include <iterator>
#include "..\SortingFunctions\SortingFunctions.h"
#include "TestClass.h"

using namespace std;

int main()
{
    int arr[5]{ 3, 5, 2, 1, 4 };
    TestClass testArr[5]{ TestClass(3), TestClass(5), TestClass(2), TestClass(1), TestClass(4) };
    vector<int> vect;
    vect.push_back(3);
    vect.push_back(5);
    vect.push_back(2);
    vect.push_back(1);
    vect.push_back(4);

    //SortingFunctions::bubbleSort(vect.begin(), vect.end());
    //SortingFunctions::bubbleSort(arr, end(arr));
    //SortingFunctions::bubbleSort(testArr, end(testArr));
    SortingFunctions::patienceSort(vect.begin(), vect.end());
    SortingFunctions::patienceSort(arr, end(arr));
    SortingFunctions::patienceSort(testArr, end(testArr));
    for (size_t i = 0; i < vect.size(); i++)
    {
        cout << vect[i] << endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << arr[i] << endl;
    }

    for (size_t i = 0; i < 5; i++)
    {
        cout << testArr[i].getField() << endl;
    }
}
