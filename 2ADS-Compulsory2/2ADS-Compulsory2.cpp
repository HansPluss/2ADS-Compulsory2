#include <cstdio>
#include <list>
#include <vector>
#include<iostream>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <algorithm>
#include <random>
using namespace std;

vector<int> myvector;
list<int> mylist;
bool isSorted(vector<int> list);
bool sortDone = false;
int maxIteration;
void PrintList(vector<int> list) {

    for (int i = 0; i < list.size(); i++) {
        cout << list[i] << "\n";
    }
    //cout << maxIteration << " Maxiterations" << "\n";
}
void Shuffle(vector<int> list) {

    if (isSorted(list) == true) {
        
        PrintList(list);
        return;
    }
    
    for (int i = 0; i < list.size(); i++) {
        srand(time(NULL));
        swap(list[i], list[rand() % (list.size())]);
        //PrintList(list);
        //cout << list[rand() % (list.size() - 1)] << "\n";
        if (isSorted(list) == true) {
            PrintList(list);

            return;
        }
        
    }
    
}
bool CheckifSorted(vector<int>& vect) {
    for (int i = 1; i < vect.size(); i++) {
        if (vect[i] < vect[i - 1]) {
            //cout << "Not Sorted\n";
            return false;

        }
    }
    cout << "Sorted\n";
    PrintList(vect);
    return true;
}
void Bogosort(std::vector<int>& list) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (!CheckifSorted(list)) {
        std::random_shuffle(list.begin(), list.end());
    }
}
void ShellSort(vector<int> l) {

    if (isSorted(l) || l.size() <= 1) {

        return;
    }
    else {
        for (int gap = (l.size() - 1 / 2); gap > 0; gap /= 2) {


            for (int i = gap; i < l.size() - 1; i += 1) {

                int temp = l[i];


                int j;
                for (j = i; j >= gap && l[j - gap] > temp; j -= gap)
                    l[j] = l[j - gap];


                l[j] = temp;

            }

        }
        if (!isSorted(l)) {
            ShellSort(l);
        }
        else {
            PrintList(l);
            return;
        }

    }
}
void CockTailSort(vector<int> l) {

    if (isSorted(l) || l.size() <= 1) {
        return;
    }
    else {
        for (int i = 0; i < l.size() - 1; i++) {
            if (l[i] > l[i + 1]) {
                swap(l[i], l[i + 1]);

            }
        }
        for (int i = 0; i < l.size() - 1; i++) {
            if (l[i] > l[i + 1]) {
                swap(l[i], l[i + 1]);

            }
        }
        if (!isSorted(l)) {
            CockTailSort(l);
        }
        else {
            PrintList(l);
            return;
        }

    }


}

bool isSorted(vector<int> list) {
    int front;

    if (list.empty() || list.size() <= 1)
    {
        cout << "Sorted\n";
        return true;

    }

    else
    {
        front = list.front();
        list.erase(list.begin());
        if (front > list.front())
        {
            cout << "not Sorted\n";
            return false;
        }
        isSorted(list);
    }
}

int main()
{

    // TODO
    // ADD XML Doc(comments
    // Add switch to choose between sorting functions
    // Add user input
    // Description for each function
    //NOTE WORKS ONLY FOR VS 2022 or later version

    int listSize = 10;
    printf("hello from %s!\n", "Cocktailsort");
    srand(time(NULL));
    for (int i = 0; i < listSize; i++) {
        
        myvector.push_back(rand() % 10 + 1);
    }
    cout << "Original array" << "\n";
    PrintList(myvector);
    Bogosort(myvector);
    
    return 0;
}
