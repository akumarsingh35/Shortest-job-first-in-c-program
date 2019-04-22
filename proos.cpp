#include<stdio.h>
int main()
{
	int n; int q=0,c=0,Ct=0;
    printf("Enter number of process:");
    scanf("%d",&n);
    int bt[n],at[n],p[n],wt[n],tat[n],ct[n],rt[n],i,j,total=0,pos,temp;
     int a=0,b=0,b1;
 
    printf("\nEnter Burst Time and arrival time respectively\n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d %d",&bt[i],&at[i]);
       // scanf("%d",&at[i]);
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
				for(int o1 = o + 1; o1 < n; ++o1)
			if (bt[o]>bt[o1])
			 {
				int t;
				t=bt[o];
				bt[o]=bt[o1];
				bt[o1]=t;
				int t2;
				t2=at[o];
				at[o]=at[o1];
				at[o1]=t2;
				int t3;
				t3=p[o];
				p[o]=p[o1];
				p[o1]=t3;
			 }
		    }
		    for(int j=i;j<n;j++){
			
		    Ct=Ct+bt[j];
			ct[j]=Ct;}
}
     //for(i=0;i<n;i++)
     //{
     //	tat[i]=ct[i]-at[i];
	 //}
	 printf("\nProcessNo\tA.T\tB.Time\tC.T\tT.A.T\tW.T");
	 for(int l=0;l<n;l++)
	 {
	 	printf("\n%d\t\t%d\t%d\t%d\t%d\t%d",p[l],at[l],bt[l],ct[l],tat[i],wt[i]);
	 }
	 
    
}
