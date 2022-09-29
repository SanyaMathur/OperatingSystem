#include<stdio.h>
#include <stdlib.h>
struct Process{
	int pid;
	int at;
	int bt;
	int ct;
	int tat;
	int wt;
	int rt;
};
int compare (const void *p1, const void *p2)
{

    int a=((struct Process *)p1)->at;
    int b=((struct Process *)p2)->at;

  	if (a<b)
      	return -1;
   	else
      	return 1;
  	
}
int main()
{
	int n;
	int swt=0,stat=0,awt=0,atat=0;
	printf("Enter the number of processes: ");
	scanf("%d",&n);
	struct Process p[n];
	
	for(int i=0;i<n;i++)
	{
		
		printf("For Process %d ",i+1);
        p[i].pid=i+1;
		
		
		printf("Enter the value of AT and BT: ");
		scanf("%d %d",&p[i].at,&p[i].bt);
	}
	qsort ((void *)p, n, sizeof(struct Process), compare); 
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		else if(p[i-1].ct<=p[i].at)
		{
			p[i].ct=p[i].at+p[i].bt;
		}
		else
		{
			p[i].ct=p[i-1].ct+p[i].bt;
		} 
		
		p[i].tat= p[i].ct-p[i].at;
		p[i].wt= p[i].tat-p[i].bt;
		
		swt+=p[i].wt;
		stat+=p[i].tat; 
		p[i].rt=p[i].ct-p[i].bt;
	}
	awt=swt/n;
	atat=stat/n;
    
	printf("\nPID\tAT\tBT\tCT\tTAT\tWT\tRT\n");
	for(int i=0;i<n;i++)
	{
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);
	} 

    printf("\nSum of Turn Around Time: %d\nAverage of Turn Around Time: %d\n",stat,atat); 
	printf("Sum of Waiting Time: %d\nAverage of Waiting Time: %d\n\n",swt,awt);
	return 0;
}
