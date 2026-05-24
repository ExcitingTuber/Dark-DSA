class Solution {
public:
    void merge(vector<int>& a, int s, int m, int e){
        int n1=m+1-s, n2=e-m;
        vector<int>L(n1,0),R(n2,0);

        for(int i=0;i<n1;i++) L[i]=a[s+i];
        for(int i=0;i<n2;i++) R[i]=a[m+1+i];

        int i=0,j=0,k=s;
        while(i<n1 && j<n2){
            if(L[i]<R[j])a[k++]=L[i++];
            else a[k++]=R[j++];
        }
        while(i<n1)a[k++]=L[i++];
        while(i<n2)a[k++]=R[j++];
    }
    void Msort(vector<int>& a, int s, int e){
        if(s<e){
            int m=s+(e-s)/2;
            Msort(a,s,m);
            Msort(a,m+1,e);
            merge(a,s,m,e);
        }
    }
    vector<int> sortArray(vector<int>& a) {
        // for(int i=1;i<a.size();i++){
        //     int k=a[i], j=i-1;
        //     while(j>=0 && a[j]>k){
        //         a[j+1]=a[j];
        //         j--;
        //     }
        //     a[j+1]=k;
        // }
        Msort(a,0,a.size()-1);
        return a;
    }
};