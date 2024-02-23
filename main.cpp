#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <limits>
#include <time.h>

using namespace std;


// https://big-o.io/examples/merge-sort/c++/
// merges two subarrays of array[].
void merge(std::vector<int> &arr, int start, int middle, int end) {

    std::vector<int> leftArray(middle - start + 1);
    std::vector<int> rightArray(end - middle);

    // fill in left array
    for (int i = 0; i < leftArray.size(); ++i)
        leftArray[i] = arr[start + i];

    // fill in right array
    for (int i = 0; i < rightArray.size(); ++i)
        rightArray[i] = arr[middle + 1 + i];

    /* Merge the temp arrays */

    // initial indexes of first and second subarrays
    int leftIndex = 0, rightIndex = 0;

    // the index we will start at when adding the subarrays back into the main array
    int currentIndex = start;

    // compare each index of the subarrays adding the lowest value to the currentIndex
    while (leftIndex < leftArray.size() && rightIndex < rightArray.size()) {
        if (leftArray[leftIndex] <= rightArray[rightIndex]) {
            arr[currentIndex] = leftArray[leftIndex];
            leftIndex++;
        } else {
            arr[currentIndex] = rightArray[rightIndex];
            rightIndex++;
        }
        currentIndex++;
    }

    // copy remaining elements of leftArray[] if any
    while (leftIndex < leftArray.size()) arr[currentIndex++] = leftArray[leftIndex++];

    // copy remaining elements of rightArray[] if any
    while (rightIndex < rightArray.size()) arr[currentIndex++] = rightArray[rightIndex++];
}

// main function that sorts array[start..end] using merge()
void mergeSort(std::vector<int> &arr, int start, int end) {
    // base case
    if (start < end) {
        // find the middle point
        int middle = (start + end) / 2;

        mergeSort(arr, start, middle); // sort first half
        mergeSort(arr, middle + 1, end);  // sort second half

        // merge the sorted halves
        merge(arr, start, middle, end);
    }
}

// https://runestone.academy/ns/books/published/cppds/Sort/TheInsertionSort.html
vector<int> insertionSort(vector<int> avector) {
    for (unsigned int index=1; index<avector.size(); index++) {

        int currentvalue = avector[index];
        int position = index;

        while (position>0 && avector[position-1]>currentvalue) {
            avector[position] = avector[position-1];
            position--;
        }

        avector[position] = currentvalue;
    }

    return avector;
}
int main()
{
    // Top is for merge sort, bottom is for insertion    
    vector<int> inputs = {1,10,100,200,300,400,500,600,700,800,900,1000,5000,10000, 50000, 100000, 500000, 1000000,2000000,3000000,4000000,5000000,6000000,7000000,8000000,9000000,10000000,20000000,30000000,40000000,50000000,60000000,70000000,80000000,90000000,100000000};
    //vector<int> inputs = {1,10,100,200,300,400,500,600,700,800,900,1000,5000,10000,20000,30000,40000,50000,60000,70000,80000,90000,100000,150000,200000,250000,300000,350000,400000,450000,500000};

    // Set up the random device
    std::random_device rd;
    std::mt19937 gen(rd());

    // Have the range of the rnadom number be from the lowest value of an int to the highest
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    for (int index = 0; index < inputs.size(); ++index)
    {
      int n = inputs[index];
      
      std::vector<int> vec = {};
      
      // Get the first random number and push onto vector
      for (int i = 0; i < n; ++i)
      {
        int randomInt = dist(gen);
        vec.push_back(randomInt);
      }

      // Create the timer start and stop
      clock_t start = clock();

      //mergeSort(vec, 0, vec.size());
      insertionSort(vec);

      clock_t stop = clock() - start;

      // For demonstration, print out the random int value
      std::cout << "Total time for " << n << " values: " << ((double) stop) / (double) CLOCKS_PER_SEC << std::endl;
    }


    return 0;

}