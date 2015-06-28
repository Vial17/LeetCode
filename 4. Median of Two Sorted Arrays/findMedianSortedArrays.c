#define min(a, b) ((a) < (b)? (a) : (b))

// Find the kth smallest element in two sorted arrays.
double findKthElement(int nums1[], int len1, int nums2[], int len2, int k);

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int total = nums1Size + nums2Size;
    if(total & 1)
        return findKthElement(nums1, nums1Size, nums2, nums2Size, total / 2 + 1);
    else
        return (findKthElement(nums1, nums1Size, nums2, nums2Size, total / 2) + 
                findKthElement(nums1, nums1Size, nums2, nums2Size, total / 2 + 1) ) / 2;
}

double findKthElement(int nums1[], int len1, int nums2[], int len2, int k)  {  
    // Assure that m is equal or smaller than n.
    if (len1 > len2)  
        return findKthElement(nums2, len2, nums1, len1, k);
    
    // Handle two base conditions.
    if (len1 == 0)   return nums2[k - 1];  
    if (k == 1)      return min(nums1[0], nums2[0]);
	
    // Divide nums1 and nums2 into two parts; sum of the lengths of their first part .  
    int mid1 = min(k / 2, len1);
    int mid2 = k - mid1;

    // Reduce problem size.
    if (nums1[mid1 - 1] < nums2[mid2 - 1])  
        return findKthElement(nums1 + mid1, len1 - mid1, nums2, len2, k - mid1);  
    else  
        return findKthElement(nums1, len1, nums2 + mid2, len2 - mid2, k - mid2);  
}
