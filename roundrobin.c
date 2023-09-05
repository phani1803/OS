#include<stdio.h> 
 void main() 
{ 
 int st[10],bt[10],wt[10],tat[10],n,tq; 
        int i,count=0,swt=0,stat=0,temp,sq=0; 
        float awt,atat; 
        printf("enter the number of processes: \n "); 
        scanf("%d",&n); 
        printf("enter the burst time of each process:   \n"); 
        for(i=0;i<n;i++) 
        { 
printf("p%d",i+1);                 
scanf("%d",&bt[i]); 
  st[i]=bt[i]; 
        } 
        printf("enter the time quantum: "); 
        scanf("%d",&tq);
   while(1) 
        { 
                for(i=0,count=0;i<n;i++) 
                { 
                        temp=tq; 
                        if(st[i]==0) 
                        { 
                                count++; 
                                continue; 
                        } 
                        if(st[i]>tq) 
                        st[i]=st[i]-tq; 
else 
                        if(st[i]>=0) 
                        { 
                                temp=st[i]; 
                                st[i]=0; 
                        } 
                        sq=sq+temp; 
                        tat[i]=sq; 
                } 
                if(n==count) 
                break; 
        } 
        for(i=0;i<n;i++) 
        { 
                wt[i]=tat[i]-bt[i];   
                 swt=swt+wt[i]; 
                stat=stat+tat[i]; 
        } 
        awt=(float)swt/n; 
        atat=(float)stat/n; 
        printf("process no\t burst time\t waiting time\t turnaround time\n"); 
        for(i=0;i<n;i++) 
        printf("%d\t\t %d\t\t %d\t\t %d\n",i+1,bt[i],wt[i],tat[i]); 
        printf("avg wt time=%f,avg turn around time=%f",awt,atat); 
}          
 