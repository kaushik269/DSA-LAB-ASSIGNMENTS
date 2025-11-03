//QUES 1 ->

//PART (a) -> BUBBLE SORT

/*#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    //bubble sort -> stable sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){ //swap
                swap(arr[j],arr[j+1]);
            }
        }
    }
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/


//PART (b) -> INSERTION SORT

/*#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    // insertion sort -> T.C.- O(n) and S.C.- O(1) -> stable sort
    for(int i=1;i<n;i++){
        int j = i;
        while(j>=1 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        }
    return 0;
}*/


//PART (c) -> SELECTION SORT

/*#include<iostream>
#include<climits>
using namespace std;
int main(){
    int n;
    cout<<"enter n : ";
    cin>>n;
    int arr[n];
    cout<<"enter "<<n<<" elements : ";
    for(int i=0;i<=n-1;i++){
        cin>>arr[i];
    }
    // selection sort -> T.C. - O(n*n) and S.C. - O(1) -> unstable sort
    for(int i=0;i<n-1;i++){
        int min = INT_MAX;
        int mindx = -1;
        // min elt calculation
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                mindx = j;
            }
        }
        swap(arr[i],arr[mindx]);
    }
    cout<<"sorted array is : ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}*/


//PART (d) -> MERGE SORT

/*#include <iostream>
using namespace std;

void mergeArr(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int a[n1], b[n2];
    for(int i = 0; i < n1; i++) a[i] = arr[left + i];
    for(int i = 0; i < n2; i++) b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2) {
        if(a[i] <= b[j]) arr[k++] = a[i++];
        else arr[k++] = b[j++];
    }
    while(i < n1) arr[k++] = a[i++];
    while(j < n2) arr[k++] = b[j++];
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left + right)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        mergeArr(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, n-1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}*/


//PART (e) -> QUICK SORT

/*#include <iostream>
using namespace std;

int partitionArray(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int p = partitionArray(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
}*/


//QUES 2 -> SELECTION SORT QUESTION

/*#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter n : ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements : ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int left = 0, right = n - 1;

    while(left < right) {

        int minIndex = left;
        int maxIndex = right;

        // Find minimum and maximum in current range
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex])
                minIndex = i;
            if(arr[i] > arr[maxIndex])
                maxIndex = i;
        }

        // Swap minimum element to left side
        int temp = arr[left];
        arr[left] = arr[minIndex];
        arr[minIndex] = temp;

        // If max element was at the left position, update its index
        if(maxIndex == left)
            maxIndex = minIndex;

        // Swap maximum element to right side
        temp = arr[right];
        arr[right] = arr[maxIndex];
        arr[maxIndex] = temp;

        left++;
        right--;
    }

    cout << "Sorted array is : ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}*/



