#include<stdio.h>
#include<string.h>
int main()
{
    int Service_Time[20],Arival_Time[10],temp,Priority[10],st[10],ft[10],Waiting_Time[10],Turn_Around_Time[10],n,i,j;
    int Total_Waiting_Time=0,Total_Turn_Around_Time=0;
    float Average_Waiting_Time,Average_Turnaround_Time;
    char Process_Name[10][10],t[10];


    printf("Enter the number of Process:");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        printf("Please Enter Process Name[%d]:",i+1);
        scanf("%s",Process_Name[i]);

        printf("Please enter Arival Time:\n");
        scanf("%d",&Arival_Time[i]);

        printf("Please Enter Service/Execution Time:\n");
        scanf("%d",&Service_Time[i]);

        printf("Please Enter Priority:\n");
        scanf("%d",&Priority[i]);

    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(Priority[i]<Priority[j])
            {
                temp=Priority[i];
                Priority[i]=Priority[j];
                Priority[j]=temp;
                temp=Arival_Time[i];
                Arival_Time[i]=Arival_Time[j];
                Arival_Time[j]=temp;
                temp=Service_Time[i];
                Service_Time[i]=Service_Time[j];
                Service_Time[j]=temp;
                strcpy(t,Process_Name[i]);
                strcpy(Process_Name[i],Process_Name[j]);
                strcpy(Process_Name[j],t);
            }
        }
    for(i=0; i<n; i++)

    {

        if(i==0)
        {
            st[i]=Arival_Time[i];
            Waiting_Time[i]=st[i]-Arival_Time[i];
            ft[i]=st[i]+Service_Time[i];
            Turn_Around_Time[i]=ft[i]-Arival_Time[i];
        }
        else
        {
            st[i]=ft[i-1];
            Waiting_Time[i]=st[i]-Arival_Time[i];
            ft[i]=st[i]+Service_Time[i];
            Turn_Around_Time[i]=ft[i]-Arival_Time[i];
        }
        Total_Waiting_Time+=Waiting_Time[i];
        Total_Turn_Around_Time+=Turn_Around_Time[i];
    }
    Average_Waiting_Time=(float)Total_Waiting_Time/n;
    Average_Turnaround_Time=(float)Total_Turn_Around_Time/n;
    printf("\n\n\t*********************************************************************\n");
    printf("\t\t\t   ShortCuts Used In Table\n");
    printf("\t*********************************************************************\n");
    printf("\t\tProcess_name  --------------------------> PName\t\t\t\t\t\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tArrival_Time  --------------------------> Atime\t\t\t\t\t\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tExecution_Time  ------------------------> ETime\t\t\t\t\t\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tPriority  ----------------------------->  Priority\t\t\t\t\t\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tWaiting_Time  --------------------------> WTime\t\t\t\t\t\n");
    printf("\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("\t\tTotal_Turn_Around_Time  --------------->  TTTime\t\t\t\t\t\n");
    printf("\n\t*******************************************************************\n\n\n");
    printf("\n********************************************************************************");
    printf("\nPName\t  ATime\t\t  ETime\t\tPriority\t  WTime\t\t TTTime");
    for(i=0; i<n; i++){
      printf("\n%s\t%5d\t\t%5d\t\t%5d\t\t%5d\t\t%5d",Process_Name[i],Arival_Time[i],Service_Time[i],Priority[i],Waiting_Time[i],Turn_Around_Time[i]);
    }
    printf("\n********************************************************************************\n\n");

    printf("\n\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\nAverage waiting time is:%f\n\n",Average_Waiting_Time);
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("\nAverage turnaroundtime is:%f\n",Average_Turnaround_Time);
    printf("\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");


}
