#include<iostream>
using namespace std;

/*
Unit 1

1. Space-Time complexity:
Time complexity refers to the number of opertations occuring in a specific algorithm as a function on number of inputs i.e. n
while
Space complexity referes to the space or memoery taken by the variables assigned in the stack memory
Denoted by O(n)  

2. Arrays:
NOTE: Only one type of data is allowed in an array
a) It is the first kind of data structure we have and it is inbuilt in nature.
b) It requires the count of number of elements we want to add from the beginning and thus there is a limit here.
c) The array is stored continuesly in the stack memory with blocks assigned to different positions.
d) The array is called using the address of the first element and the size of array with type of data provided in it, thus array is indirectly a pointer only.
e) In an array you have indexing thus making it very easy to traverse in an array from one place to another.
f) Here for deleting an element or addition of an element from an array you need to shift the whole array rightwards to leftwards. 
g) Thus arrays arent self adjusting.

3. Insertion in an array: 
For inserting in an array at pth location or (p-1)th index, we have to shift the elements from p-1 to n-1 index to p to n index, for this we run the loop from n-1 to p-1 where the main action is:
arr[i+1]=arr[i] and then arr[p-1]=element

Code is as follows:
*/ 
void insert(int arr[], int pos, int element, int size){
    for (int i = size-1; i>=pos; i--)
    {
        arr[i+1]=arr[i];
    }
    arr[pos-1]=element;
}
/*
4. Deletion in an array: 
For deletion in an array at pth loaction or (p-1)th index, we have to shift the elements from p to n-1 index to p-1 to n-2 index, for this we run the loop from 0 to n-2 index numbers where the action will ne:
arr[i]=arr[i+1] and then arr[n-1]='\0'

Code is as follows:
*/
void remove(int arr[], int pos,int size){
    for (int i = 0; i < size-1; i++)
    {
        arr[i]=arr[i+1];
    }
    arr[size-1]='\0';
}

/*
5. Bubble sort:
Bubble sort works with comparing the 2 elements in the bubble, the bubble is made with pairing 2 consecutive elements together and moving forward in this manner.
By this method in every step the largest element reaches the end of the array thus we step down one element everytime for comaprisons.

Time complexity is: O(n^2) for worst case and O(n) for best case

Code is as follows: 
*/
void bubble_sort(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-i; j++)
        {
            if (arr[j+1]<arr[j])
            {
                swap(arr[j],arr[j+1]);    
            }
        }
    }
}

/*
6. Selection sort:
Here in selection sort we again do comparisons but this time from the end so that we end up getting the smallest element in the left array everytime this moving from arr to arr+1 everytime in the loop.

Time complexity: O(n^2) for worst case and O(n) for best case

Code is as follows:
*/
void selection_sort(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = size-1; j>i; j--)
        {
            if (arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
            }
        } 
    }   
}

/*
7. Insertion sort:


Code is as flw:
*/
void insertion_sort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        for (int j = i-1; j>=0; j--)
        {
            if (arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
                i--;   
                //to stay on the same element after swapping
            }
        }
    }
}

/*
8. Linear search:
Here we search for the required element linearly in thw full array using a for loop

Time complexity: O(n) for worst case and O(1) for best case

Code is as follows:
*/
int linear_search(int arr[], int element, int size){
    int i;
    for ( i = 0; i < size; i++)
    {
        if (arr[i]==element)
        {
            return i;
        }
    }
    cout<<"Element not found"<<endl;
    return -1;
}

/*
9. Binary search:
We can apply this only if the array is sorted or reverse sorted

Step 1:
First find mid element and compare with it breaking the array into 2 parts, larger than mid element and smaller than mid element.
Step 2:
Choose yr side and repeat prev step.

*/

int binary_search_helper(int arr[],int start,int end,int element){
    int size=sizeof(arr)/sizeof(arr[0]);
    if (arr[(start+end)/2] == element)
    {
        return (start+end)/2;
    }
    else if((start+end)/2 > element){
        binary_search_helper(arr,0,((start+end)/2)-1,element);
    }
    else{
        binary_search_helper(arr,((start+end)/2)+1,size-1,element);
    } 
}

void insertion_sort(int arr[], int size){
    for (int i = 1; i < size; i++)
    {
        for (int j = i-1; j>=0; j--)
        {
            if (arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
                i--;   
            }
        }
    }
}

int binary_search(int arr[], int size, int element){
    insertion_sort(arr,size);
    return binary_search_helper(arr,0,size-1,element);
}

/*
Arrays questions can be done at coding ninja's code studio there are 100 problems on arrays available there, go for them.
*/

