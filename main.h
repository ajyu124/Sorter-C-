#pragma once

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

int main();

    vector<string> inputArray;
    int currentComparisonNum = 1;
    //Scanner consoleScanner = new Scanner(System.in);
    
     vector<string> getSortedArray();
 
     //MergeSort(vector<string> inputArray);
    
     void sortGivenArray();
    
     void divide(int startIndex,int endIndex);
    
     void merger(int startIndex,int midIndex,int endIndex);

     bool isLessThan( string element1,  string element2);