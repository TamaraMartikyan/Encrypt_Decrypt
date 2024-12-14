#include <iostream>
#include <cmath>
using namespace std;

int main(){

	int a,b, lcm;
	cout<<"Enter 2 integers"<<endl;
	cin>>a>>b;

	a=abs(a);
	b=abs(b);

	int max=(a>b) ? a:b;

	for(int i=max; i<=a*b; i++){
	
		if (i%a==0 && i%b==0){
		    lcm=i;
			break;
		}
	
	}

	cout<<"LCM is  "<<lcm<<endl;
return 0;
}


