#include<stdio.h>
#include<unistd.h>
int main ()
{ 
	int arr[10]={1,2,3,4,5,6,7,8,9,10}; 
	int ev=0,od=0;
	int x=fork ();
	if(x!=0)
	{
		for(int i=0;i<10;i++)
		{
			if(arr[i]%2!=0)
				od+=arr[i]; 
		} 
printf(“Process ID: %d has calculated the sum: %d\n”, getpid(),od); 
		}
		else
		{
		For(int i=0;i<10;i++)
		{
			If(arr[i]%2==0)
				ev+=arr[i]; 
		}  
printf(“Process ID: %d has calculated the sum: %d\n”, getpid(),ev);

	}
	return 0;
}
