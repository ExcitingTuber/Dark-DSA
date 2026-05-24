class Solution {
public:
    void merge(vector<int>& a, int s, int m, int e){
        int n1=m+1-s, n2=e-m;
        vector<int>L(n1,0);
        vector<int>R(n2,0);
        for(int i=0;i<n1;i++){
            L[i]=a[s+i];
        }
        for(int i=0;i<n2;i++){
            R[i]=a[m+1+i];
        }
        int i=0,j=0,k=s;
        while(i<n1 && j<n2){
            if(L[i]<R[j]){
                a[k++]=L[i++];
            }
            else{
                a[k++]=R[j++];
            }
        }
        while(i<n1){
            a[k++]=L[i++];
        }
        while(j<n2){
            a[k++]=R[j++];
        }
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
        Msort(a,0,a.size()-1);
        return a;
    }
};