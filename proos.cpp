#include<stdio.h>
int main()
{
	int n; int q=0,c=0,Ct=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],at[n],p[n],wt[n],tat[n],ct[n],rt[n],i,j,total=0,pos,temp,as1,avg_tat=0,avg_wt=0;
    int a=0,b=0,b1;
 
    printf("\nEnter Burst Time and arrival time respectively\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:\n",i+1);
        printf("Enter arrival time:");
        scanf("%d",&at[i]);
		printf("Enter burst time:");
		scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
	for (i=0; i<n; ++i) 
        {
            for(j = i + 1; j < n; ++j)
            {
 
                if(at[i] > at[j]) 
                {
 
                    a =  at[i];
                    at[i] = at[j];
                    at[j] = a;
                    
                    b = bt[i];
                    bt[i]=bt[j];
                    bt[j]=b;
                    
                    b1= p[i];
                    p[i]=p[j];
                    p[j]=b1;
 
                }
            }
        }
        for(i=0;i<n;i++)
	{
		if(as1 == i) i++;
		
		if(at[0]!=0&&c==0)
		{
			Ct=Ct+at[0];
			c++;
		}
		
		if(at[i]==at[i+1])
		{
			if(bt[i]<=bt[i+1])
			{
			as:
				Ct=bt[i]+Ct;
				ct[i]=Ct;
			} else {
				Ct =  Ct + bt[i+1];
				ct[i+1]=Ct;
				as1 = i + 1;
				goto as;
				
			}
		}
		else if(at[n-1]<=Ct)
		{
			q=i;
			goto sortbt;
		}
		/*else if(at[i]>bt[i-1])
		{
			Ct= Ct+at[i];
		}*/
		else
		{
			Ct=Ct+bt[i];
			ct[i]=Ct;
		}
    } 
    sortbt:
    	{
	
			for(int o=q;o<n-1;o++)
			{
				for(int o1 = q; o1 < n-o-1; o1++)
			if (bt[o]>bt[o1])
			 {
				int t;
				t=bt[o1];
				bt[o1]=bt[o1+1];
				bt[o1+1]=t;
				int t2;
				t2=at[o1];
				at[o1]=at[o1+1];
				at[o1+1]=t2;
				int t3;
				t3=p[o1];
				p[o1]=p[o1+1];
				p[o1]=t3;
			 }
		    }
		    for(int j=i;j<n;j++){
			
		    Ct=Ct+bt[j];
			ct[j]=Ct;}
}
     for(i=0;i<n;i++)
     {
     	tat[i]=ct[i]-at[i];
     	avg_tat=avg_tat+tat[i];
     	wt[i]=tat[i]-bt[i];
     	avg_wt=avg_wt+wt[i];
	 }
	 printf("\nProcessNo\tA.T\tB.Time\tC.T\tT.A.T\tW.T");
	 for(int l=0;l<n;l++)
	 {
	 	printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",p[l],at[l],bt[l],ct[l],tat[l],wt[l]);
	 }
	 printf("\nAverage turn around time:%d",avg_tat/n);
	 printf("\nAverage wating time:%d",avg_wt/n);
	 
    
}
