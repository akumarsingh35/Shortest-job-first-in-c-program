#include<iostream>
#include<stdio.h>
int main()
{
	int n; int q=0,c=0,Ct=0;
   // float avg_wt,avg_tat;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],at[n],p[n],wt[n],tat[n],ct[n],i,j,total=0,pos,temp;
 
    printf("\nEnter Burst Time:\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        scanf("%d",&at[i]);
        p[i]=i+1;           //contains process number
    }
	/*int q=0;
	
	printf("enter the number of processes");
	int n;
	int i;
	scanf("%d",n);
	int at[n], bt[n], p[n],ct[n];int c=0;
	int Ct=0;
	printf("Enter burst time and arrival time respectively");
	for(int m=0;m<n;m++)
	{
	scanf("%d",bt[m]);
	scanf("%d",at[m]);
	p[m]=m+1;
    } */
    for(i=0;i<n;i++)
	{
		if(at[0]!=0&&c==0)
		{
			Ct=Ct+at[0];
			c++;
		}
		
		if(at[i]==at[i+1])
		{
			if(bt[i]<=bt[i+1])
			{
				Ct=bt[i]+Ct;
				ct[i]=Ct;
			}
		}
		else if(at[n]<=ct[i])
		{
			q=i;
			goto sortbt;
		}
		else if(at[i]>bt[i-1])
		{
			Ct= Ct+at[i];
		}
		else
		{
			Ct=Ct+bt[i];
			ct[i]=Ct;
		}
    } 
    sortbt:
    	{
	
			for(int o=q;o<n;o++)
			{
			if (bt[o]>bt[o+1])
			 {
				int t;
				t=bt[o];
				bt[o]=bt[o+1];
				bt[o+1]=t;
				int t2;
				t2=at[o];
				at[o]=at[o+1];
				at[o+1]=t2;
				int t3;
				t3=p[o];
				p[o]=p[o+1];
				p[o+1]=t3;
			 }
		    }
		    for(int j=i;j<n;j++){
			
		    Ct=Ct+bt[j];
			ct[j]=Ct;}
}
	 printf("\nProcessNo\tArrival Time\tBurst Time\tC.T\tT.A.T\tW.T");
	 for(int l=0;l<n;l++)
	 {
	 	printf("\n%d\t\t%d\t\t%d\t%d",p[l],at[l],bt[l],ct[l]);
	 }
	 
    
}
