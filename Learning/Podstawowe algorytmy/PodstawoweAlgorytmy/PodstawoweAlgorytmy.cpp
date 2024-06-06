#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

int BinarySearch(const vector<int>& tab, int target, int right, int left = 0) //rekurencyjna wersja(podawanie indeksów)
{
    int mid = left + (right - left) / 2;

    if (left >= right)
    {
        return -1;
    }

    if (tab[mid] == target)
    {
        return mid;
    }
    else if (mid < target)
    {
       return BinarySearch(tab, target, right, mid + 1);
    }
    else
    {
        return BinarySearch(tab, target, mid-1, left);
    }
}

int main()
{
    vector<int> TAB = { 1,2,3,4,5,5,7,9,12,16,21,27,90 };

    cout << BinarySearch(TAB,100, TAB.size());
}
