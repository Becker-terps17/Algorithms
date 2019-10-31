//C++ merge sort practice 

#include<iostream>
#include<vector>

//using namespace std;

void sortArray(std::vector<int>& arrayIn);
void mergeArrays(std::vector<int>& leftSub, std::vector<int>& rightSub, std::vector<int>& mergedArray);
void printArray(std::vector<int>& sortedArray);

int main(){

	std::vector<int> myArray{2,5,9,6,10,22,1,15};

	sortArray(myArray);
	std::cout<<"Sorted Array: ";
	printArray(myArray);
	
	return 0;
}

// Divide array into single element arrays 
// Top-down 
void sortArray(std::vector<int> &arrayIn){
	// if array has one element, it is sorted
	if (arrayIn.size() == 1){
		return;
	}

	std::vector<int> leftSub;
	std::vector<int> rightSub;
	int mid = arrayIn.size()/2;

	// Put the first half of the array into array one
	for (int i=0; i<arrayIn.size()/2; ++i){
		leftSub.push_back(arrayIn[i]);
	}
	// Put the second half of the array into array two
	for (int i=mid; i<arrayIn.size(); ++i){
		rightSub.push_back(arrayIn[i]);
	}

	// Use recursion to continue to split arrays until the baseline condition is met
	sortArray(leftSub);
	sortArray(rightSub);
	mergeArrays(leftSub, rightSub, arrayIn);

}


// Merge array elements into smaller sorted arrats
// Bottom-up portion
//void mergeArrays(std::vector<int>& leftSub, std::vector<int>& rightSub){
void mergeArrays(std::vector<int> &leftSub, std::vector<int> &rightSub, std::vector<int> &mergedArray){
	
	mergedArray.clear();
	
	while ( (!leftSub.empty()) && (!rightSub.empty()) ){
		if (leftSub[0] <= rightSub[0]){
			mergedArray.push_back(leftSub[0]);
			leftSub.erase(leftSub.begin());
		}
		else {
			mergedArray.push_back(rightSub[0]);
			rightSub.erase(rightSub.begin());
		}
	}
	
	// Either arrayA or arrayB are empty
	// Add remaining sorted values from A or B into merged array
	while (!leftSub.empty()){
		mergedArray.push_back(leftSub[0]);
		leftSub.erase(leftSub.begin());
	}

	while (!rightSub.empty()){
		mergedArray.push_back(rightSub[0]);
		rightSub.erase(rightSub.begin());
	}
	
}


void printArray(std::vector<int> &sortedArray){
	std::cout<<"{ ";
	for (int i=0; i<sortedArray.size(); ++i){
		std::cout<<sortedArray[i]<<" ";
	}
	std::cout<<"}"<<"\n";
}