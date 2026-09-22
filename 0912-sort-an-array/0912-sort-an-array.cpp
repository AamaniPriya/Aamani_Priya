class Solution {

public:

 

   int partition(vector<int>& arr, int low, int high)

   {

       // Middle element ko pivot banaya

       int mid = low + (high - low) / 2;

 

       swap(arr[low], arr[mid]);

 

       int pivot = arr[low];

 

       int start = low;

       int end = high;

 

       while (start < end)

       {

           while (start <= high && arr[start] <= pivot)

           {

               start++;

           }

 

           while (arr[end] > pivot)

           {

               end--;

           }

 

           if (start < end)

           {

               swap(arr[start], arr[end]);

           }

       }

 

       // Pivot ko correct position par rakho

       swap(arr[low], arr[end]);

 

       return end;

   }

 

   void quickSort(vector<int>& arr, int low, int high)

   {

       if (low < high)

       {

           int p = partition(arr, low, high);

 

           quickSort(arr, low, p - 1);

           quickSort(arr, p + 1, high);

       }

   }

 

   vector<int> sortArray(vector<int>& nums)

   {

       quickSort(nums, 0, nums.size() - 1);

 

       return nums;

   }

};