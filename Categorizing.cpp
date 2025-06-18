#include<iostream>
#include<vector>
using namespace std;

void inputArray(vector<int>& arr)
{
    int n, value;
    cout<<"Enter number of elements: ";
    cin>>n;
    cout<<"Enter elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin>>value;
        arr.push_back(value);
    }
}

void SelectionSort(vector<int> &arr, int n)
{
    int min, temp;

    for(int i = 0; i < n - 1; i++)
    {
        min = i;

        for(int j = i + 1; j < n; j++)
        {
            if(arr[min] > arr[j])
                {
                    min = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
    }
}

void merge(vector<int>& arr, int start, int mid, int end)
{
    vector<int> temp;
    int i = start, j = mid + 1;

    while(i <= mid && j <= end)
    {
        if(arr[i] <= arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }

    while(i <= mid)
    {
        temp.push_back(arr[i++]);
    }

    while(j <= end)
    {
        temp.push_back(arr[j++]);
    }

    for(int k = 0; k < temp.size(); k++)
    {
        arr[start + k] = temp[k];
    }
}

void merge_sort(vector<int>& arr, int start, int end)
{
    if(start >= end) return;

    int mid = start + (end - start) / 2;

    // left
    merge_sort(arr,start,mid);

    // right
    merge_sort(arr,mid + 1,end);

    // merge
    merge(arr,start,mid,end);
}

int LinearSearch(vector<int> &arr, int target)
{
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(vector<int> &arr, int target)
{
    int start = 0;
    int end = arr.size() - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}

void Display(vector<int> &arr)
{
    cout<<"Array: ";
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr;
    int choice,key,element,result;

    do{
        cout<<endl<<"--------Sorting and Searching menu---------"<<endl;
        cout<<"1. Enter Array"<<endl;
        cout<<"2. Selection Sort"<<endl;
        cout<<"3. Merge Sort"<<endl;
        cout<<"4. Linear Search"<<endl;
        cout<<"5. Binary Search"<<endl;
        cout<<"6. Display Array"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"Enter your choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
                inputArray(arr);
            break;

            case 2:
                SelectionSort(arr, arr.size());
                cout<<"Array sorted using Selection sort."<<endl;
            break;

            case 3:
                merge_sort(arr, 0, arr.size() - 1);
                cout<<"Array sorted using Merge Sort."<<endl;
            break;

            case 4:
                cout<<"Enter element to search: ";
                cin>>element;
                result = LinearSearch(arr,element);
                if(result != -1)
                {
                    cout<<"Found at index: "<<result;
                }
                else
                {
                    cout<<"Element not found!";
                }
            break;

            case 5:
                cout<<"Enter element to search: ";
                cin>>element;
                result = binarySearch(arr, element);
                if(result != -1)
                {
                    cout<<"Found at index: "<<result;
                }
                else
                {
                    cout<<"Element not found!";
                }
            break;

            case 6:
                Display(arr);
            break;

            case 0:
                cout<<"Exiting...";
            break;

            default:
                cout<<"Wrong Choice!!!";
        }
    } while(choice != 0);

    return 0;
}