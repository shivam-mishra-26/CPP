#include <iostream>
using namespace std;
int main() 
{
	int N,i=0,arr[N];
	cin>>N;
    for(int k=1; k<=N; k++)
    {
        if(N%k==0)
        {
            arr[i]=k;
            i++;
        }
    }
    cout<<i<<endl;
    for(int k=0; k<i; k++)
    {
        cout<<arr[k]<<" ";
    }
	return 0;
}
