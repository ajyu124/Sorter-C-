#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "main.h"
//#include "MergeSort.h"

using namespace std;

  //int currentComparisonNum = 1;

  int main() {
    
    /*Random rand = new Random();
    Scanner inputData = OpenFile.openToRead("InputData.txt");
    PrintWriter outputSortedRanking = OpenFile.openToWrite("OutputSortedRanking.txt");
    ArrayList<String> elements = new ArrayList<String>();*/

    ifstream inputFile ("InputData.txt");
  ofstream outputFile ("OutputSortedRanking.txt");
    //vector<string> elements;

    /*while (inputData.hasNext()) {
        elements.add(inputData.nextLine());
    }*/

    if (inputFile.is_open()) {
      string programLine = "";
      while ( getline (inputFile,programLine) ) {
        inputArray.push_back(programLine);
      }
    }

    /*System.out.println("\n------------------------\n");
    System.out.println("Welcome to the Sorter!\n");
    System.out.println("------------------------");*/

    std::cout << "\n------------------------\n" << std::endl;
    std::cout << "Welcome to the Sorter!\n" << std::endl;
    std::cout << "------------------------" << std::endl;

    /*MergeSort sorter = new MergeSort(elements);
    sorter.sortGivenArray();
    ArrayList<String> elementsRanked = sorter.getSortedArray();
    int numOfElements = elementsRanked.size();*/

    sortGivenArray();
    vector<string> elementsRanked = getSortedArray();
    int numOfElements = elementsRanked.size();

    /*outputSortedRanking.write("RESULTS: \n");
    for (int ind = 0; ind < elementsRanked.size(); ind++) {
        outputSortedRanking.write((ind+1)+": "+elementsRanked.get(ind)+"\n");
    }*/

    outputFile << "RESULTS: \n" << std::endl;
    for (int ind = 0; ind < elementsRanked.size(); ind++) {
        outputFile << (ind+1) << ": " << elementsRanked[ind] << std::endl;
    }

    /*System.out.println("\n\n-----------------------------");
    System.out.println("Your ranking is complete! Check OutputSortedRanking.txt.");
    System.out.println("It took a total of "+(sorter.currentComparisonNum-1)+" comparisons to sort "+numOfElements+" elements.\n\n");
    outputSortedRanking.close();*/

    std::cout << "\n\n-----------------------------" << std::endl;
    std::cout << "Your ranking is complete! Check OutputSortedRanking.txt." << std::endl;
    std::cout << "It took a total of " << (currentComparisonNum-1) << " comparisons to sort " << numOfElements << " elements.\n\n" << std::endl;

    inputFile.close();
    outputFile.close();
    
  }

       vector<string> getSortedArray() {
        return inputArray;
    }
    
     void sortGivenArray(){       
        divide(0, inputArray.size()-1);
    }
    
     void divide(int startIndex,int endIndex){
        
        //Divide till you breakdown your list to single element
        if(startIndex<endIndex && (endIndex-startIndex)>=1){
            int mid = (endIndex + startIndex)/2;
            divide(startIndex, mid);
            divide(mid+1, endIndex);        
            
            //merging Sorted array produce above into one sorted array
            merger(startIndex,mid,endIndex);            
        }       
    }   
    
     void merger(int startIndex,int midIndex,int endIndex){
        
        //Below is the mergedarray that will be sorted array Array[i-midIndex] , Array[(midIndex+1)-endIndex]
        vector<string> mergedSortedArray;
        
        int leftIndex = startIndex;
        int rightIndex = midIndex+1;
        
        while(leftIndex<=midIndex && rightIndex<=endIndex){
            //if(inputArray[leftIndex]<=inputArray[rightIndex]){
              if(isLessThan(inputArray[leftIndex],inputArray[rightIndex])){
                mergedSortedArray.push_back(inputArray[leftIndex]);
                leftIndex++;
            }else{
                mergedSortedArray.push_back(inputArray[rightIndex]);
                rightIndex++;
            }
        }       
        
        //Either of below while loop will execute
        while(leftIndex<=midIndex){
            mergedSortedArray.push_back(inputArray[leftIndex]);
            leftIndex++;
        }
        
        while(rightIndex<=endIndex){
            mergedSortedArray.push_back(inputArray[rightIndex]);
            rightIndex++;
        }
        
        int i = 0;
        int j = startIndex;
        //Setting sorted array to original one
        while(i<mergedSortedArray.size()){
            //inputArray.set(j, mergedSortedArray[i++]);
            inputArray[j] = mergedSortedArray[i++];
            j++;
        }
    }

     bool isLessThan( string element1,  string element2) {

      std::cout << "\n#" << currentComparisonNum << " || 1: " << element1 << " | 2: " << element2 << " || ====> ";
       string response;
       cin >> response;
      while (response != "1" && response != "2") {
            std::cout << "Invalid input. Try again." << std::endl;
            std::cout << "\n#" << currentComparisonNum << " || 1: " << element1 << " | 2: " << element2 << " || ====> ";
            cin >> response;
      }
      currentComparisonNum++;
      if (response == "1") {
          return true;
      } else {
          return false;
      }
     }