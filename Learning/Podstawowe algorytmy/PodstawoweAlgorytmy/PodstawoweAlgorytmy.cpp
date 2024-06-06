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

void BubbleSort(vector<int>& tab)
{

    for (int j = 0; j < tab.size(); ++j) 
    {
        bool swapped = false;
        for (int i = 0; i < tab.size()-1-j; ++i)
        {
            if (tab[i] > tab[i + 1])
            {
                swap(tab[i], tab[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) return;
    }
    
}

 void SelectionSort(vector<int>& tab)
{
    for (int i = 0; i < tab.size(); ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < tab.size(); ++j)
        {
            if (tab[j] < tab[minIndex])
            {
                minIndex = j;

            }
        }
        if(i != minIndex)
            swap(tab[i], tab[minIndex]);
    }
}

int main()
{
    //vector<int> TAB = { 1,2,3,4,5,5,7,9,12,16,21,27,90 };
    //cout << BinarySearch(TAB,100, TAB.size());

    vector<int> TAB;
    const int size = 10;
    TAB.reserve(size);
    TAB.resize(size);
    srand(time(NULL));

    for (int i = 0; i < size; ++i)
    {
        TAB[i] = rand() % 100;
    }

    SelectionSort(TAB);

    for (int i = 0; i < size; ++i)
    {
        cout << TAB[i] << ", ";
    }
}
