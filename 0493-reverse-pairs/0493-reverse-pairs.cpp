class Solution {
public:
    void mergepls(vector<int>&arr,int start,int end,int &count,vector<int>&tmp)
    {
        int mid=start+(end-start)/2;
        int left=start,right=mid+1,k=start;
        while(left<=mid  && right<=end)
        {
            if(arr[left]>(long long)2*arr[right])
            {
                count+=(mid-left+1);
                right++;
            }
            else
                left++;
        }
        left=start,right=mid+1;
        while(left<=mid && right<=end)
        {
            if(arr[left]<=arr[right])
            {
                tmp[k]=arr[left];
                left++;
                k++;
            }
            else
            {
                tmp[k]=arr[right];
                right++;
                k++;
            }
        }        
        while(left<=mid )
        {
            tmp[k]=arr[left];
                left++;
                k++;
        }
        while(right<=end)
        {
            tmp[k]=arr[right];
                right++;
                k++;
        }
        while(start <= end){
            arr[start] = tmp[start];
            start++;
        }
    }
    void ms(vector<int>&arr,int start,int end,int &count,vector<int>&tmp)
    {
        if(start>=end)
            return ;
        int mid=start+(end-start)/2;
        ms(arr,start,mid,count,tmp);
        ms(arr,mid+1,end,count,tmp);
        mergepls(arr,start,end,count,tmp);
    }
    int reversePairs(vector<int>& arr) 
    {
        int start=0;
        int n=arr.size();
        int count=0;
        vector<int>tmp(n);
        ms(arr,0,n-1,count,tmp);
        return count;
    }
};