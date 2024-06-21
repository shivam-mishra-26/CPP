#include <iostream>
#include <std::vector<T>>
using namespace std;
void func(int n)
{
    int i=1;
    int my_list;
    int count=0;
    while(i<=n)
    {
        if(n%i==0)
        {
            my_list.push_back(i);
            count+=1;
        }
    }
    cout<<cout<<endl;
    cout<<*my_list<<" ";
   
}
int main() 
{
	int N;
	cin>>N;
	func(N);
	return 0;
}