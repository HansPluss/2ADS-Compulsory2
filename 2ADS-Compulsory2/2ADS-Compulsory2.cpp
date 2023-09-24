#include <cstdio>
#include <list>
#include <vector>
#include<iostream>
#include <stdlib.h>
#include <time.h> 
#include <stdio.h>
#include <algorithm>
#include <random>
#include <chrono>
using namespace std;

vector<int> myvector;
bool isSorted(vector<int> list);
bool sortDone = false;
int maxIteration;
void PrintVector(vector<int> vect) {

    for (int i = 0; i < vect.size(); i++) {
        cout << vect[i] << "\n";
    }

    //cout << maxIteration << " Maxiterations" << "\n";
}
void Shuffle(vector<int> vect) {

    if (isSorted(vect) == true) {
        
        PrintVector(vect);
        return;
    }
    
    for (int i = 0; i < vect.size(); i++) {
        srand(time(NULL));
        swap(vect[i], vect[rand() % (vect.size())]);
        //PrintList(list);
        //cout << list[rand() % (list.size() - 1)] << "\n";
        if (isSorted(vect) == true) {
            PrintVector(vect);

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
    PrintVector(vect);
    return true;
}
void Bogosort(std::vector<int>& vect) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    while (!CheckifSorted(vect)) {
        std::random_shuffle(vect.begin(), vect.end());
    }
}
void ShellSort(vector<int> vect) {

    if (CheckifSorted(vect) || vect.size() <= 1) {

        return;
    }
    else {
        for (int gap = (vect.size()/ 2); gap > 0; gap /= 2) {


            for (int i = gap; i < vect.size(); i += 1) {

                int temp = vect[i];


                int j;
                for (j = i; j >= gap && vect[j - gap] > temp; j -= gap)
                    vect[j] = vect[j - gap];


                vect[j] = temp;

            }

        }
        if (!CheckifSorted(vect)) {
            ShellSort(vect);
        }
        

    }
}
void CockTailSort(vector<int> l) {

    if (CheckifSorted(l) || l.size() <= 1) {
        
        return;
    }
    bool swapped = false;
    for (int i = 0; i < l.size() - 1; i++) {
        if (l[i] > l[i + 1]) {
            swap(l[i], l[i + 1]);
            swapped = true;
        }
    }
    if (!swapped) {
        return;
    }
    for (int i = 0; i < l.size() - 1; i++) {
        if (l[i] > l[i + 1]) {
            swap(l[i], l[i + 1]);
            swapped = true;
        }
    }
    if (swapped) {
        CockTailSort(l);
    }
    /*if (!CheckifSorted(l)) {
       
    }
    else {

        return;
    }*/
        

    


}


bool isSorted(vector<int> vect) {
    int front;

    if (vect.empty() || vect.size() <= 1)
    {
        cout << "Sorted\n";
        PrintVector(vect);
        return true;

    }

    else
    {
        front = vect.front();
        vect.erase(vect.begin());
        if (front > vect.front())
        {
            cout << "not Sorted\n";
            return false;
        }
        isSorted(vect);
    }
}

int main()
{

    int input;
    bool isRunning = true;
    while (isRunning) {
        // TODO
   // ADD XML Doc(comments
   // Add switch to choose between sorting functions
   // Add user input
   // Description for each function
   //NOTE WORKS ONLY FOR VS 2022 or later version

        int listSize;
        int userInupt;
        // printf("hello from %s!\n", "Cocktailsort");
        printf("Choose list size \n");
        cin >> listSize;
        printf("Choose sorting method: \n");
        printf("1: Cocktailsort \n");
        printf("2: Shellsort \n");
        printf("3: Bogosort \n");
        cin >> userInupt;

        srand(time(NULL));
        for (int i = 0; i < listSize; i++) {

            myvector.push_back(rand() % 20 + 1);
        }
        cout << "Original array" << "\n";
        PrintVector(myvector);
        auto start_time = std::chrono::high_resolution_clock::now();
        switch (userInupt) {
        case 1:
            CockTailSort(myvector);
            break;
        case 2:
            ShellSort(myvector);
            break;
        case 3:
            Bogosort(myvector);
            break;
        }
        //Start timer

        auto end_time = std::chrono::high_resolution_clock::now();

        // Calculate the duration in milliseconds
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        // Convert the duration to milliseconds and print it
        long long milliseconds = duration.count();
        std::cout << "Time elapsed: " << milliseconds << " milliseconds" << std::endl;
        cout << "Type 1 to continue any other number to stop" << "\n";
        cin >> input;
        if (input == 1) {
            isRunning = true;
            listSize = 0;
            myvector.clear();
        }
        else {
            isRunning = false;
        }

    }
   
    
}
