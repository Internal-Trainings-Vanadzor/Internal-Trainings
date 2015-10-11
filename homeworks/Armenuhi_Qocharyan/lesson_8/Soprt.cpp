
template <class T> void sort(T a[],int n){
    T temp;
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++){
           if(a[j]>a[j+1]){
               temp=a[j]; 
               a[j]=a[j+1];  
               a[j+1]=temp;              
            }   
        }    
    }
}

int main () {
   return 0;
}
