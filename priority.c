#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],pri[20],i,j,k,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("enter number of processes ");
    scanf("%d",&n);
    printf("enter burst time: \n");
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1; ///contains process number

    }
printf("enter priority of thr process ");
for(i=0;i<n;i++)
{
    p[i]=i;
    //print priority of process
    printf("p%d",i+1);
    scanf("%d",&pri[i]);

}
for(i=0;i<n;i++)
for(k=i+1;k<n;k++)
if(pri[i]>pri[k])
{
temp=p[i];
    p[i]=p[k];
    p[k]=temp;

    temp=bt[i];
    bt[i]=bt[k];
    bt[k]=temp;;
    temp= pri[i];
    pri[i]=pri[k];
    pri[k]=temp;
}
    wt[0]=0; ///waiting time for first response will be zero
    //calcuate waiting time
    for (i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
        wt[i]+=bt[j];

    total+=wt[i];

    }
avg_wt=(float)total/n;  //avg waiting time
    total=0;
    printf("\nprocess\t bursttime\t priority\t waiting time\t \t turnaround time");
    for (i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];  //calculate tuurn around time
        total+=tat[i];
        printf("\np%d\t\t%d\t\t %d\t\t\t%d",p[i],bt[i],pri[i],wt[i],tat[i]);

    }
avg_tat=(float)total/n; //avg turn around time
printf("\n\n avg waiting time= %f",avg_wt);
printf("\naverage turnaround time=%f\n",avg_tat);

}