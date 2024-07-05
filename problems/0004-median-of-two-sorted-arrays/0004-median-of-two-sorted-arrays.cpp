class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if(n1 > n2 ){
            findMedianSortedArrays(nums2,nums1);
        }
        int n = n1+n2;
        int left = (n1+n2+1)/2 ;    // left-half >=  right half

        int low = 0, high =n1 ;
        
        while(low <= high){
            int mid1 = (low+high)/2;   // mid1 --> number of element from nums1 in left half
            int mid2 = left - mid1;    // mid2 --> number of element from nums2 in left half
            int l1 = INT_MIN, l2 = INT_MIN;  // l1 --> max element of nums1 in left half
            int r1 = INT_MAX, r2 = INT_MAX;

            if( mid1-1 >=0  ) l1 = nums1[mid1-1];
            if( mid2-1 >=0  ) l2 = nums2[mid2-1];
            if( mid1 < n1 ) r1 = nums1[mid1];
            if( mid2 < n2 ) r2 = nums2[mid2];

            if( l1 <= r2 && l2 <= r1 ){
                if(n%2 == 1 ) return max(l1,l2);   // if n is odd , left half's last element is median
                else return ((double)(max(l1,l2) + min(r1,r2))/2.0);  //left half's (last element + right's first elem)/2 is median
            }

            else if ( l1 > r2 ){   // more than required elements are taken from nums1
                high = mid1-1;
            }
            else{
                low = mid1+1;   // (l2 > r1 ) -->more than required elements are taken from nums2
            }
        }
        return 0;
    }
};