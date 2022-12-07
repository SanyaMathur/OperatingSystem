#include<stdio.h>
#include<stdbool.h>
#include<string.h>

struct PageTable
{
    int frame_no;
    bool valid;
};

bool isPagePresent(struct PageTable PT[],int page,int n)
{
    if(PT[page].valid == 1)
       return true;
    return false;   
}
void updatePageTable(struct PageTable PT[],int page,int fr_no,int status)
{
    PT[page].valid=status;    
    PT[page].frame_no=fr_no;
}
void printContents(int frame[],int number_of_frames)
{
    for(int i=0;i<number_of_frames;i++)
      printf("%d ",frame[i]);
    printf("\n");  
}

int main()
{
    printf("Name:Sanya Mathur\n");
    int i,n,number_of_frames,page_fault=0,curr=0;
    bool flag=false;
    printf("Enter the no. of pages:\n");
    scanf("%d",&n);
    int reference_string[n]; 
    printf("Enter the reference string(different page numbers) :\n");
    for(int i=0;i<n;i++)
     scanf("%d",&reference_string[i]);
    printf("Enter the no. of frames given to the process:");
    scanf("%d",&number_of_frames);
    int frame[number_of_frames];
    memset(frame,-1,number_of_frames*sizeof(int));
    struct PageTable PT[100] ; 
    for(int i=0;i<100;i++)
      PT[i].valid=0;
    
    printf("\nThe Contents inside the Frame array are as follows:\n");
    for(int i=0;i<n;i++) 
    {
      if( ! (isPagePresent(PT,reference_string[i],n)))
      {
         page_fault++;         
         if(flag==false && curr< number_of_frames)
         {
                frame[curr]=reference_string[i];
                printContents(frame,number_of_frames);
                updatePageTable(PT,reference_string[i],curr,1);
                curr = curr + 1;
                if(curr == number_of_frames)
                {
                   curr=0;
                   flag=true;  
                }
         }
          else 
         {
                updatePageTable(PT,frame[curr], -1 ,0);   
                frame[curr]=reference_string[i];
                printContents(frame,number_of_frames);         
                updatePageTable(PT,reference_string[i],curr,1); 
                curr = ( curr + 1)% number_of_frames;
         }
      } 
    }   
   printf("\nTotal No. of Page Faults = %d\n",page_fault);
   return 0;
}
