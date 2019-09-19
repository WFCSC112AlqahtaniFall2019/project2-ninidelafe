/* Alexa (Nini) de la Fe
Section B
Project 2
This program will create a vector that has a length imported by the user then randomly generates numbers to populate the
 vector. The vector will then be sorted in ascending order using recursion and other functions.
 */

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

// declares Functions
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    //gets input for seed
    int seed;
    cout << "Please enter a seed: "<<endl;
    cin >> seed;
    srand(seed);

    //gets input for length
    int length;
    cout<<"Please enter a length for your vector: "<<endl;
    cin>> length;

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    //states that a unit test is occurring, with the numbers being tested, and the expected output
    cout<< "Performing a unit Test with the vector {12, 23, 3, 61}. I am expecting the output to be: 3 12 23 61."<<endl;
    vector<int> unitTest = {12, 23, 3, 61}; //unit test vector to be sorted
    vector<int> unitTestTemp(4); //unit test temporary workspace

    mergeSortedLists(unitTest, unitTestTemp, 0, 1, 3);
    //testing the unitTest array
    for(int i = 1; i < unitTest.size() - 1; i++) {
        assert(unitTest.at(i-1) <= unitTest.at(i));
    }
    //prints the output of the unit test after it has gone through mergeSortedLists
    cout << "The unit test of mergeSortedList prints: " << endl;
    for(int i = 0; i < unitTest.size(); i++) {
        cout << unitTest.at(i) << '\t';
    }
    cout<<endl<<endl;

    // initializes and prints input values that are randomly selected
    cout << "Unsorted Values:" << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // Sorts vector v by sending the parameters to functions
    mergeSort(v, t, 0, (v.size() - 1));

    // Prints output of vector v in ascending order
    cout << "Values Sorted in Ascending Order: " << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // checks output to make sure it is sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

// this function takes the vector and sorts it into smaller pieces so that it can be sorted easier
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right) {
    // Base Case
    if (left == right) {
        return;
    }
    // recursion begins to take effect here when it starts breaking the vector into left and right before organizing it
    // in the mergeSortedLists function
    else {
        mergeSort(a, tmp, left, ((right + left) / 2));
        mergeSort(a, tmp, (((left + right) / 2) + 1), right);
        mergeSortedLists(a, tmp, left, ((right + left) / 2), right);
    }
}

// this function takes the pieces and organizes them into ascending order while storing the lowest number in the tmp vector
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right) {
    int i = left;
    int j = (middle + 1);
    int k = left;
    int l;
    int mid = (middle +1);

    while (i < mid && j < (right + 1)) {
        if (a.at(i) < a.at(j)) {
            tmp.at(k) = a.at(i);
            i++;
            k++;
        }
        else {
            tmp.at(k) = a.at(j);
            j++;
            k++;
        }
    }
    if (i >= mid) {
        while (j <= right) {
            tmp.at(k) = a.at(j);
            j++;
            k++;
        }
    }
    else if (j >= right) {
        while (i < mid) {
            tmp.at(k) = a.at(i);
            i++;
            k++;
        }
    }

    //takes the values from the tmp vector and puts them into vector a sorted 
    for (l = left; l <= right; l++) {
        a.at(l) = tmp.at(l);
    }

}
