#include <bits/stdc++.h>
#define max_processes 1000
#define max_customers 1000
using namespace std;
void scheduling_algorithms();
void FCFS();
void RR();
void SJF();
void LJF();
void rr_2(struct OS *p,int n);
void SRTF();
void LRTF();
void HRRN();
void sortByArrival();
int firstFit_MFT(int *,int,int *,int,int);
void bestFit_MFT(int *,int,int  *,int);
void worstFit_MFT(int *,int,int  *,int);
void firstFit();
void bestFit();
void worstFit();
void Remove();
void mem_display();
void FIFO();
void MRU();
void LRU();
void optimalpagereplacement();
void fifo();
void lru();
void mru();
void philosophers_cycle();
void wait_d(int, int, int);
void signal_d(int);
void dining_philosophers();
void sleeping_barber();
void Page_Replacement();
void bankers_algorithm();
void paging_With_Offset();
void MVT_first_best_worst_fits();
void MFT_first_best_worst_fits();
void reader_writer();
void producer_consumer();
void synchronisation_algorithms();
void disk_scheduling();
//Declarations for reader_writer
int readcount=0;
int writecount=0;
int t=0;
int mutex=1;
int rw_mutex=1;

int details[15][10];
//details[i][0]=process ID
//details[i][1]=arrival time
//details[i][2]=burst time
//details[i][4]=waiting time
//details[i][5]=turnaround time

int temp;
int v;
struct Row
{
    int AT;
    int BT;
    bool reader;
    int serial;
    int endtime;
};
bool comp(const Row &a,const Row &b)
{
    if(a.reader==true&&b.reader==false&&a.AT==b.AT)
    {
        return 2<1;                             //one is reader and other is writer arrived at same time then writer is given priority
    }

    return a.AT<b.AT;                           //else the one with less arrival time is given priority
}
//declarations for producer_consumer
int s=1;
int emptY=6;
int full=0;
int st=0;
//defining semaphores ,emptY,full and time variables
//Structure for Process
struct Row1
{
    bool producer;
    int AT;
    int BT;
    int serial;
    bool completed;
};
//Comparision Function for Ordering Processes
bool comp1(const Row1 &a,const Row1 &b)
{
    if(a.producer==false&&b.producer==true&&a.AT==b.AT)//priority checking if one among a and b is producer ,that gets more priority
    {
        return b.AT<a.AT;

    }

    return a.AT<b.AT;//if the two are either consumers or producers then the one which arrives first is given priority
}
//Signal Function
int signal(int s)
{
    s++;
    return s;
}
//Wait Function
int wait(int s)
{
    while(s<=0);

    s--;
    return s;
}

//Declarations for code Choice5
struct process{
    int size;
    int id;
};
struct process *proc;

struct node{
    int size;
    int flag;
    struct process p;
    struct node *prev;
    struct node *next;
};
struct node *head;
int t_size, id, free_space;
//End Declarations for Choice5

 typedef struct atrbts{
    int p_id,at,bt,ct,tat,wt,bat,btt;
}schedule;
/*defining a structure of the timetable*/
 struct process_2_ {
	char name;
	int at, bt, ct, wt, tt;
	int completed;
} p_2[10];
int hnn;
bool cmp(schedule a,schedule b){
    return a.at<b.at;
}
/*comaprison function in sort based on arrival time*/
bool cmp2(schedule a,schedule b){
    return a.bt<b.bt;
}
/*sorting based on burst times*/
bool cmp3(schedule a,schedule b){
    if(a.bt!=b.bt)
     return a.bt>b.bt;
   return a.at<b.bt;
}
struct OS
{
    int p_no,at,bt,ct,tat,wt,flag; //process id,arrival time,burst time,completion time,term around time and wait time

}*p;

//Declarations for Dining philosopher
struct semaphore1{
    int value;
};
struct philosopher{
    int Pno, AT, BT, start_time;
};
struct semaphore1 *s1;
struct philosopher *p1, *q1, *running, *w_0, *w_1;
struct philosopher dead_lock_0, dead_lock_1;
int i, j, r_end, q_end, w_0_end, w_1_end, t1, dead_cond, flag, n, run_flag, fork_picked, count1, dead_count, first;
//End of declarations for dining philosopher

//Declarations for Choice 8
int next(int , int, int *);
int max_tracks;
//End of declarations for choice 8

int main(){
    cout<<"SIMULATOR BY GROUP 221-230\n\n";
    int choice;
    while(choice!=9){
        cout<<"Please choose"<<endl<<"1==>scheduling algos\n2==>synchronisation algos\n3==>bankers algorithm\n4==>MFT first,best and worst fits\n5==>MVT first,best and worst fits\n6==>Page replacement algos\n7==>paging with offset\n8==>Disk scheduling\n9==>Quit \n";
        cin>>choice;
        if(choice==1) //BY Karthik Chandra 191CS222 ,Aashish Prateek 191CS225
        {
            scheduling_algorithms();
        }
        if(choice==2){
           synchronisation_algorithms();
        }
        if(choice==3)   // code contributed by 191CS223 SRAVANI
        {
            bankers_algorithm();
        }
        if(choice==4)  //code contributed by 191CS230 MOHIYADDEEN RAZA
        {
            MFT_first_best_worst_fits();
        }
        if(choice==5)  //code contributed by 191CS224 KRUTHIKA
        {
            MVT_first_best_worst_fits();
        }
        if(choice == 6) // code contributed by Dharmick
        {
            Page_Replacement();
        }
        if (choice==7) // contributed by LALIT 191CS227
        {
            paging_With_Offset();
        }
        if(choice==8)   //contributed by Mihir and Sandeep
        {
            disk_scheduling();
        }
    }

    return 0;
}

//CODE MODULES FOR CHOICE 8
void disk_scheduling()
{
    int i = 0, j = 0, t = 0, pos, size, temp, val,menu=-1,init, direction, flag1, flag2;

    cout<<"\nEnter initial position :";
    cin>>pos;
    init=pos;

    cout<<"\nEnter total number of tracks :";
    cin>>max_tracks;

    cout<<"\nEnter number of tracks requests :";
    cin>>size;

    int unsq[size],req[size],q[size];
    cout<<"\nEnter the track requests :";

    while (i < size){

        cin>>unsq[i];
        i++;
    }

    //copying the sequence of track requests to req[] and q[]
    for(i=0;i<size;i++){
        req[i]=unsq[i];
        q[i]=unsq[i];
    }

    //sorting track requests in array req[]
    sort(req, req + size);
    while(req[t]<pos){
        t++;
    }
    //storing the first track request to the right of initial position;
    j=t;

    i=0;

    cout<<"Guide:\n1 for FCFS\n2 for SSTF\n3 for SCAN\n4 for CSCAN\n5 for LOOK\n6 for CLOOK\n7 to exit";

    while(menu){
        cout <<"\nChoose menu :";
        cin>>menu;

        switch(menu){
            case 1:
                cout<<"Track sequence is (FCFS):";
                j=0;
                //printing the sequence of track sequence
                while(j<size){
                    cout<<"\n"<<unsq[j];
                    j++;
                }

                //adding first track request seek time to val
                val=abs(pos-unsq[0]);
                j=0;
                while(j<size-1){
                    temp=abs(unsq[j]-unsq[j+1]);// calculating seek time for each track request
                    val=val+temp;               //adding all seek times
                    j++;
                }
                cout<<"\nThe total time taken is :"<<val;
                break;

            case 2:
                cout<<"Track sequence is (SSTF):";
                t=0;
                for (j = 0; j < size; j++)
                {
                    cout<<"\n"<<q[next (init, size, q)];
                    t = t + abs (init - q[next (init, size, q)]);

                    //storing the current position of head to temp
                    temp = q[next (init, size, q)];
                    q[next (init, size, q)] = 1000; //eliminating the occurrence of already visited track requests
                    init = temp;
                }
                cout<<"\nTotal movements are :"<<t;
                break;

            case 3:
                flag1=0;
                flag2=0;
                t=0;
                for(i=0;i<size;i++){
                    req[i]=unsq[i];
                }
                sort(req, req + size);

                while(req[t]<pos)
                {
                    t++;
                }
                j=t;
                cout<<"(Enter 1 for moving towards least track and enter 2 for moving towards highest track)"<<endl;
                cout<<"Enter the direction of traversal of head:";
                cin>>direction;
                cout<<"\nThe track sequence is (SCAN) :\n";
                if(direction==2){
                    while(j<size){
                        cout<<req[j]<<"\n";
                        j++;
                        flag1=1;
                    }
                    j=t;
                    while(j>0){
                        cout<<req[--j]<<"\n";
                        flag2=1;
                    }
                    if(flag2){
                        val=2*(max_tracks-1)-req[0]-pos;
                    }else if(!flag2){
                        val=(max_tracks-1)-pos-req[size-1];
                    }
                }
                if(direction==1){
                    if(req[t]!=pos){
                        j=--t;
                    }
                    while(j>=0){
                        cout<<req[j--]<<"\n";
                        flag1=1;
                    }
                    j=t;
                    while(j<size-1){
                        cout<<req[++j]<<"\n";
                        flag2=1;
                    }
                    if(flag2){
                        val=req[size-1]+pos;
                    }else if(flag1){
                        val=pos-req[0];
                    }
                }
                cout<<"\nThe total time taken is :"<<val;
                break;

            case 4:
                flag1=0;
                flag2=0;
                t=0;
                for(i=0;i<size;i++){
                    req[i]=unsq[i];
                }
                sort(req, req + size);

                while(req[t]<pos)
                {
                    t++;
                }
                j=t;
                cout<<"(Enter 1 for moving towards least track and enter 2 for moving towards highest track)"<<endl;
                cout<<"Enter the direction of traversal of head:";
                cin>>direction;
                cout<<"\nThe track sequence is (CSCAN) :\n";
                if(direction==2){
                    while(j<size){
                        cout<<req[j]<<"\n";
                        j++;
                        flag1=1;
                    }
                    j=0;

                    while(j<t){
                        cout<<req[j]<<"\n";
                        j++;
                        flag2=1;
                    }
                    if(flag2){
                        val=2*(max_tracks-1)-pos+req[t-1];
                    }else if(flag1){
                        val=req[size-1]-pos;
                    }
                }
                if(direction==1){
                    if(req[t]!=pos){
                        j=--t;
                    }
                    while(j>=0){
                        cout<<req[j]<<"\n";
                        j--;
                        flag1=1;
                    }
                    j=size-1;

                    while(j>t){
                        cout<<req[j]<<"\n";
                        j--;
                        flag2=1;
                    }
                    if(flag2){
                        val=pos+2*(max_tracks-1)-req[t+1];
                    }else if(flag1){
                        val=pos-req[0];
                    }
                }
                cout<<"\nThe total time taken is :"<<val;
                break;

            case 5:
                flag1=0;
                flag2=0;
                t=0;
                for(i=0;i<size;i++){
                    req[i]=unsq[i];
                }
                sort(req, req + size);

                while(req[t]<pos)
                {
                    t++;
                }
                j=t;
                cout<<"(Enter 1 for moving towards least track and enter 2 for moving towards highest track)"<<endl;
                cout<<"Enter the direction of traversal of head:";
                cin>>direction;
                cout<<"\nThe track sequence is (LOOK) :\n";
                if(direction==2){
                    while(j<size){
                        cout<<req[j]<<"\n";
                        j++;
                        flag1=1;
                    }
                    j=t;
                    while(j>0){
                        cout<<req[--j]<<"\n";
                        flag2=1;
                    }
                    if(flag2){
                        val=(2*req[size-1])-req[0]-pos;
                    }else if(flag1){
                        val=req[size-1]-pos;
                    }
                }
                if(direction==1){
                    if(req[t]!=pos){
                        j=--t;
                    }
                    while(j>=0){
                        cout<<req[j]<<"\n";
                        j--;
                        flag1=1;
                    }
                    j=t+1;

                    while(j<size){
                        cout<<req[j]<<"\n";
                        j++;
                        flag2=1;
                    }
                    if(flag2){
                        val=pos-req[0]+req[size-1];
                    }else if(flag1){
                        val=pos-req[0];
                    }
                }


                cout<<"\nThe total time taken is :"<<val;
                break;

            case 6:
                flag1=0;
                flag2=0;
                t=0;
                for(i=0;i<size;i++){
                    req[i]=unsq[i];
                }
                sort(req, req + size);

                while(req[t]<pos)
                {
                    t++;
                }
                j=t;
                cout<<"(Enter 1 for moving towards least track and enter 2 for moving towards highest track)"<<endl;
                cout<<"Enter the direction of traversal of head:";
                cin>>direction;
                cout<<"\nThe track sequence is (CLOOK):\n";
                if(direction==2){
                    while(j<size){
                        cout<<req[j]<<"\n";
                        j++;
                        flag1=1;
                    }
                    j=0;
                    while(j<t){
                        cout<<req[j]<<"\n";
                        j++;
                        flag2=1;
                    }
                    if(flag2){
                        val=(req[size-1]-pos)+(req[size-1]-req[0])+(req[t-1]-req[0]);
                    }else if(flag1){
                        val=req[size-1]-pos;
                    }
                }
                if(direction==1){
                    if(req[t]!=pos){
                        j=--t;
                    }
                    while(j>=0){
                        cout<<req[j]<<"\n";
                        j--;
                        flag1=1;
                    }
                    j=size-1;

                    while(j>t){
                        cout<<req[j]<<"\n";
                        j--;
                        flag2=1;
                    }
                    if(flag2){
                        val=(pos-req[0])+(req[size-1]-req[0])+(req[size-1]-req[t+1]);
                    }else if(flag1){
                        val=pos-req[0];
                    }
                }
                cout<<"\nThe total time taken is :"<<val;
                break;
            case 7:
                menu=0;
                break;
            default:
                cout<<"\nEnter valid input";
        }
    }
}

int next (int num, int var, int arr[])
{
    int sval = abs (num - arr[0]), position, i;
    position = 0;
    for (i = 0; i < var; i++)
    {
        if(arr[i]<max_tracks){
            if (sval > abs (num - arr[i]))
            {
                sval = abs (num - arr[i]);
                position = i;
            }
        }
    }
  return position;
}
//END OF MODULES FOR CHOICE 8


void scheduling_algorithms(){
    int k;
    cout<<"1==>FCFS\n2==>SJF\n3==>LJF\n4==>SRTF\n5==>LRTF\n6==>RR\n7==>HRRN"<<endl;
    cin>>k;
    if(k==1)
    {
        FCFS();
    }
    if(k==2)
    {
       SJF();
    }
    if(k==3)
    {
       LJF();
    }
    if(k==4)
    {
        SRTF();
    }
    if(k==5)
    {
        LRTF();
    }
    if(k==6)
    {
        RR();
    }
    if(k==7)
    {
        HRRN();
    }
}
void sortByArrival()
{
	struct process_2_ temp;
	int i, j;
	for (i = 0; i < hnn - 1; i++) {
		for (j = i + 1; j < hnn; j++) {
			if (p_2[i].at > p_2[j].at) {
				temp = p_2[i];
				p_2[i] = p_2[j];
				p_2[j] = temp;
			}
		}
	}
}
void HRRN(){
	int i, j, t, sum_bt = 0;
	char c;
	float avgwt = 0, avgtt = 0;
	cout<<"Enter the number of processes\n";
    cin>>hnn;
	int arriv[hnn];
	int burst[hnn];
	for(i=0;i<hnn;i++){
        cout<<"Enter arrival and burst time of process"<<i<<endl;
        cin>>arriv[i]>>burst[i];
    }
	for (i = 0, c = 'A'; i < hnn; i++, c++) {
		p_2[i].name = c;
		p_2[i].at = arriv[i];
		p_2[i].bt = burst[i];
		p_2[i].completed = 0;
		sum_bt += p_2[i].bt;
	}
	sortByArrival();
	cout << "Name " << " Arrival Time " << " Burst Time " << " Waiting Time "
	<< " TurnAround Time ";
	for (t = p_2[0].at; t < sum_bt;) {
		float hrrn = -9999;
		float temp;
		int loc;
		for (i = 0; i < hnn; i++) {
			// Checking if process has arrived and is Incomplete
			if (p_2[i].at <= t && p_2[i].completed != 1) {
	            // Calculating Response Ratio
				temp = (p_2[i].bt + (t - p_2[i].at)) / p_2[i].bt;
				// Checking for Highest Response Ratio
				if (hrrn < temp) {
	    			hrrn = temp;
					loc = i;
				}
			}
		}
		t += p_2[loc].bt;
		p_2[loc].wt = t - p_2[loc].at - p_2[loc].bt;
		p_2[loc].tt = t - p_2[loc].at;
		avgtt += p_2[loc].tt;
		p_2[loc].completed = 1;
		avgwt += p_2[loc].wt;
		cout<< "\n" << p_2[loc].name <<"\t" << p_2[loc].at;
		cout << "\t\t" << p_2[loc].bt <<"\t\t"<< p_2[loc].wt;
		cout <<"\t\t"<< p_2[loc].tt <<endl;
	}
	cout << "\nAverage waiting time: " << avgwt /hnn << endl;
	cout <<"Average Turn Around time:"<< avgtt / hnn<<endl;
}


void FCFS(){
    int n,i,change;
    float sumw=0,sumt=0;
    schedule x[20];
    cout<<"enter the number of processes:";
    cin>>n;
    for(i=0;i<n;i++){
        x[i].p_id=i;
        cout<<"enter arrival time of process "<<i<<" :";
        cin>>x[i].at;
        cout<<"enter burst time of the same process: ";
        cin>>x[i].bt;
        x[i].bat=x[i].bt;
    }
    sort(x,x+n,cmp);
    x[0].ct=x[0].bt;
    x[0].tat=x[0].ct-x[0].at;
    sumt=x[0].tat;
    x[0].wt=x[0].tat-x[0].bt;
    sumw=x[0].wt;
    for(i=1;i<n;i++){
        x[i].ct=x[i-1].ct+x[i].bt;
        x[i].tat=x[i].ct-x[i].at;
        x[i].wt=x[i].tat-x[i].bt;
        sumt+=x[i].tat;
        sumw+=x[i].wt;
    }
    /*printnig the time table*/
    cout<<"p_id\tAT\tBT\tCT\tTaT\tWT"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<x[i].p_id<<"\t"<<x[i].at<<"\t"<<x[i].bt<<"\t"<<x[i].ct<<"\t"<<x[i].tat<<"\t"<<x[i].wt<<endl;
    }
    cout<<"the avg waitng time is "<<sumw/n<<endl;
    cout<<"the avg turnaround time is "<<sumt/n<<endl;
}

void sort(int n)
{
    for(int j=0; j<n; j++)
    {
     for(int i=0; i<n-j-1; i++)
     {
       if(details[i][1] >= details[i+1][1])
        {
        for(int k=0; k<5; k++)
        {
            temp=details[i][k];
            details[i][k]=details[i+1][k];
            details[i+1][k]=temp;
        }
    }
}
}
}

void c_time_SJF(int n)
{
    for(int j=0; j<n; j++)
    {
     for(int i=0; i<n-j-1; i++)
     {
       if(details[i][2] >= details[i+1][2] && details[i][1]==details[i+1][1])
        {
        for(int k=0; k<5; k++)
        {
            temp=details[i][k];
            details[i][k]=details[i+1][k];
            details[i+1][k]=temp;
        }
        }
     }
    }
    details[0][3]=details[0][1]+details[0][2];
    details[0][5]=details[0][3]-details[0][1]; //turnaround time = waiting time + burst time
    details[0][4]=details[0][5]-details[0][2]; //waiting time = turaround time - burst time

    for(int i=1; i<n; i++)
    {
        temp = details[i-1][3];
        int l = details[i][2];
        for(int j=i; j<n; j++)
        {
            if(l >= details[j][2] && temp >= details[j][1])
            {

                l = details[j][2];
                v=j;

            }
        }
        details[v][3] = temp + details[v][2];
        details[v][5] = details[v][3] - details[v][1];
        details[v][4] = details[v][5] - details[v][2];
        for(int k=0; k<6; k++)
        {
            temp = details[v][k];
            details[v][k] = details[i][k];
            details[i][k] = temp;
        }
    }
}


void SJF()
{
    int n, temp;

    cout<<"Enter number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        details[i][0] = i;
    }

    for(int i=0; i<n; i++)
    {

        cout<<"Enter Process details for process " <<i+1<<" :"; cout<<"\n";
        cout<<"Enter the Arrival Time: ";
        cin>>details[i][1];
        cout<<"Enter the Burst Time: ";
        cin>>details[i][2];
    }
    sort(n);
    c_time_SJF(n);
    cout<<"details: \n";
    cout<<"p_id\t       AT\t         BT\t    Turnaround Time\t WT\n";
    for(int i=0; i<n; i++) {
        cout<<details[i][0]<<"\t\t"<<details[i][1]<<"\t\t"<<details[i][2]<<"\t\t"<<details[i][5]<<"\t\t"<<details[i][4]<<"\n";
    }

    int avg_TT,avg_WT,total_TT=0,total_WT=0;
    for(int i=0;i<n;i++)
    {
        total_TT=total_TT + details[i][5];
        total_WT=total_WT + details[i][4];
    }
    cout<<"\n";
    cout<<"average waiting time is: "<<(float) total_WT/n<<"\n";
    cout<<"average turnaround time is: "<<(float) total_TT/n<<endl;

}

void c_time_LJF(int n)
{
    for(int j=0; j<n; j++)
    {
     for(int i=0; i<n-j-1; i++)
     {
       if(details[i][2] <= details[i+1][2] && details[i][1]==details[i+1][1])
        {
        for(int k=0; k<5; k++)
        {
            temp=details[i][k];
            details[i][k]=details[i+1][k];
            details[i+1][k]=temp;
        }
        }
     }
    }
    details[0][3]=details[0][1]+details[0][2]; 
    details[0][5]=details[0][3]-details[0][1]; //turnaround time = waiting time + burst time
    details[0][4]=details[0][5]-details[0][2]; //waiting time = turaround time - burst time
    for(int i=1; i<n; i++)
    {
        temp = details[i-1][3];
        int l = details[i][2];
        for(int j=i; j<n; j++)
        {
            if(l <= details[j][2] && temp >= details[j][1])
            {

                l = details[j][2];
                v=j;

            }
        }
        details[v][3] = temp + details[v][2];
        details[v][5] = details[v][3] - details[v][1];
        details[v][4] = details[v][5] - details[v][2];
        for(int k=0; k<6; k++)
        {
            temp = details[v][k];
            details[v][k] = details[i][k];
            details[i][k] = temp;
        }
    }
}


void LJF()
{
    int n, temp;

    cout<<"Enter number of Process: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        details[i][0] = i;
    }

    for(int i=0; i<n; i++)
    {

        cout<<"Enter Process details for process " <<i+1<<" :"; cout<<"\n";
        cout<<"Enter the Arrival Time: ";
        cin>>details[i][1];
        cout<<"Enter the Burst Time: ";
        cin>>details[i][2];
    }
    sort(n);
    c_time_LJF(n);
    cout<<"details: \n";
    cout<<"p_id\t       AT\t         BT\t    Turnaround Time\t WT\n";
    for(int i=0; i<n; i++) {
        cout<<details[i][0]<<"\t\t"<<details[i][1]<<"\t\t"<<details[i][2]<<"\t\t"<<details[i][5]<<"\t\t"<<details[i][4]<<"\n";
    }

    int avg_TT,avg_WT,total_TT=0,total_WT=0;


     for(int i=0;i<n;i++)
    {
        total_WT=total_WT + details[i][4];

    }
     for(int i=0;i<n;i++)
    {
        total_TT=total_TT + details[i][5];

    }


    cout<<"\n";
    cout<<"average waiting time is: "<<(float) total_WT/n<<"\n";
    cout<<"average turnaround time is: "<<(float) total_TT/n;




}


void SRTF(){
    schedule x[20];
    int n,i,j,pcom;
    float sumw,sumt;
    cout<<"enter number of programs:";
    cin>>n;
    for(i=0;i<n;i++){
        x[i].p_id=i;
        cout<<"enter arrival time of process "<<i<<" :";
        cin>>x[i].at;
        cout<<"enter burst time of the same process:";
        cin>>x[i].bt;
        x[i].btt=x[i].bt;
    }
    sort(x,x+n,cmp);
    i=0;
    /*iterator for  completion time*/
    pcom=0;
    while(pcom<n){
          for(j=0;j<n;j++){
              if(x[j].at>i)
              break;
          }
          sort(x,x+j,cmp2);
          if(j>0){
              for(j=0;j<n;j++)
              {
                  if(x[j].bt!=0)
                  break;
              }
              if(x[j].at>i){
                  i=x[j].at;
              }
              x[j].ct=i+1;
              x[j].bt--;
          }
          i++;
          pcom=0;
          for(j=0;j<n;j++){
              if(x[j].bt==0)
              pcom++;
          }
    }
    /*printing the time table*/
    cout<<"p_id\tAT\tBT\tCT\tTAT\tWT"<<endl;
    sumt=0;
    sumw=0;
    for(i=0;i<n;i++){
        x[i].tat=x[i].ct-x[i].at;
        sumt+=x[i].tat;
        x[i].wt=x[i].tat-x[i].btt;
        sumw+=x[i].wt;
        cout<<x[i].p_id<<"\t"<<x[i].at<<"\t"<<x[i].btt<<"\t"<<x[i].ct<<"\t"<<x[i].tat<<"\t"<<x[i].wt<<endl;
    }
    cout<<"avg waiting time is:"<<sumw/n<<endl;
    cout<<"avg turnaround time is"<<sumt/n<<endl;
}
void RR(){
    int n,i;
    cout<<"  Enter number of processes:"<<endl;
    cin>>n;
    struct OS arr[n];
    cout<<"  Enter details(arrival time and burst time ) of respective procesess:"<<endl;
    for(i=0;i<n;i++)
    {
        arr[i].p_no = i;
          cout<<"Enter arrival time of process :"<<i<<" :";
        cin>>arr[i].at;
        cout<<"  Enter burst time: ";
        cin>>arr[i].bt;
    }
    p=arr; //assigning base address of structure array to a pointer for easy handling of data

    rr_2(p,n);

    float avg_tat,avg_wt;
    cout<<"\n  P.ID\tAT\tBT\tCT\tTAT\tWT"<<endl;
    for(i=0;i<n;i++)
    {
        cout<<(p+i)->p_no<<"\t"<<(p+i)->at<<"\t"<<(p+i)->bt<<"\t"<<(p+i)->ct<<"\t"<<(p+i)->tat<<"\t"<<(p+i)->wt<<endl;
        avg_tat+=(p+i)->tat; avg_wt+=(p+i)->wt;
    }
    avg_tat/=n; avg_wt/=n;
    cout<<"average turn around time is "<<avg_tat<<endl;
    cout<<"average waiting time is "<<avg_wt<<endl;
}
void rr_2(struct OS *p,int n)
{
    int time=0,slice,i=0;
    cout<<"Enter time quantum\n";
    cin>>slice;
    int temp_bt[n];
    for(i=0;i<n;i++)
    {
        temp_bt[i] = (p+i)->bt;
        (p+i)->flag = 0;
    }
    char over;//var to check if all programs are completed
    while(1)
    {
        for(i=0;i<n;i++)
        {
            over = 'y';//let it yes
            for(int k=0;k<n;k++)
            {
                if((p+k)->flag ==0)
                    over = 'n';//there are still elements left
            }
            for(int j=1;j<=slice;j++)
            {
                if((p+i)->at <= time )
                {
                    if((p+i)->flag == 0)
                    {
                        time++;
                        temp_bt[i]--;
                        if(temp_bt[i] == 0)
                        {
                            (p+i)->ct = time;
                            (p+i)->flag = 1;
                            break;
                        }
                    }
                }
                else //in case no process has arrived yet
                {
                    time++;
                    j=0;//to avoid odd slicing of time

                }
            }
        }
        if(over == 'y')
            break;
    }
    for(i=0;i<n;i++)
    {
        (p+i)->tat = (p+i)->ct - (p+i)->at ;
        (p+i)->wt = (p+i)->tat - (p+i)->bt ;
    }
}
void LRTF(){
    schedule x[20];
    int n,i,j,pcom;
    float sumw,sumt;
    cout<<"enter number of programs:";
    cin>>n;
    for(i=0;i<n;i++){
        cout<<"enter arrival time of process "<<i<<" :";
        x[i].p_id=i;
        cin>>x[i].at;
        cout<<"enter burst time of the same process:";
        cin>>x[i].bt;
        x[i].btt=x[i].bt;
    }
    sort(x,x+n,cmp);
    i=0;
    /*iterator for  completion time*/
    pcom=0;
    while(pcom<n){
          for(j=0;j<n;j++){
              if(x[j].at>i)
              break;
          }
          sort(x,x+j,cmp3);
          if(j>0){
              if(x[0].bt!=0)
             {
              if(x[0].at>i){
                  i=x[0].at;
              }
              x[0].ct=i+1;
              x[0].bt--;
             }
          }
          i++;
          pcom=0;
          for(j=0;j<n;j++){
              if(x[j].bt==0)
              pcom++;
          }
    }
    /*printing the time table*/
    cout<<"p_id\tAT\tBT\tCT\tTAT\tWT"<<endl;
    sumt=0;
    sumw=0;
    for(i=0;i<n;i++){
        x[i].tat=x[i].ct-x[i].at;
        sumt+=x[i].tat;
        x[i].wt=x[i].tat-x[i].btt;
        sumw+=x[i].wt;
        cout<<x[i].p_id<<"\t"<<x[i].at<<"\t"<<x[i].btt<<"\t"<<x[i].ct<<"\t"<<x[i].tat<<"\t"<<x[i].wt<<endl;
    }
    cout<<"avg waiting time is:"<<sumw/n<<endl;
    cout<<"avg turnaround time is"<<sumt/n<<endl;
}

void synchronisation_algorithms(){
    int c;
    cout<<"Enter 1.Reader_writer 2.Producer_consumer 3.Dining_Philosophers 4.Sleeping Barber\n";
    cin>>c;
    if(c==1){
        reader_writer();
    }
    else if(c==2){
        producer_consumer();
    }else if(c==3){
        dining_philosophers();
    }else if(c==4){
        sleeping_barber();
    }
}

//CODE MODULES FOR CHOICE 4 : MOHIYADDEEN RAZA
void MFT_first_best_worst_fits()
{
    int totalmem,ch,r=0;
	cout<<"Please enter the total block memory\n";
	cin>>totalmem;
    int m;
    cout<<"Can you please enter the number of partitions:\n";
    cin>>m;
    int partitionSize[m];
    int n;
    cout<<"Can you please enter the number of processes:\n";
    cin>>n;
    int processSize[n];
	int temp=0;
    for(int i=0;i<m;i++){
        cout<<"Partition size"<<i+1<<":";
        cin>>partitionSize[i];
		if(temp+partitionSize[i]>totalmem){
			cout<<"Insufficient memory to partition["<<i+1<<"] memory left is "<<totalmem-temp<<" and partition size is "<<partitionSize[i]<<endl;
			partitionSize[i]=0;

		}
		else{
			temp+=partitionSize[i];
		}

    }
    for(int i=0;i<n;i++)
    {
        cout<<"Process size"<<i+1<<":";
        cin>>processSize[i];
    }
    int count=totalmem-temp;
    do
    {
        cout<<"1.First fit\n2.Best fit\n3.Worst fit"<<endl;
        cout<<"Enter your choice :\t";
        cin>>ch;
        switch(ch)
        {
            case 1:
            r=firstFit_MFT(partitionSize,m,processSize,n,count);
            break;
            case 2:
                bestFit_MFT(partitionSize,m,processSize,n);
            break;
            case 3:
                worstFit_MFT(partitionSize,m,processSize,n);
            break;
        }
    }while(ch<=3);
    cout<<"amount of memory is left after partitioning: "<<count<<endl;
    cout<<" Internal fragmentation : "<<r-count<<endl;
}


/*MFT first fit*/
int firstFit_MFT(int partitionSize[], int m, int processSize[], int n,int count)
{
	// Stores block id of the
	// block allocated to a process
	int allocation[n];
	// Initially no block is assigned to any process
	memset(allocation, -1, sizeof(allocation));
    int free[m];
  	for(int j=0;j<m;j++)
    {
      free[j]=-1;
    }

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (partitionSize[j] >= processSize[i] && free[j]==-1)
			{
				// allocate block j to p[i] process
              	free[j]=i;
				allocation[i] = j;

				// Reduce available memory in this block.
				break;
			}
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t"
			<< processSize[i] << "\t\t";
		if (allocation[i] != -1)
		{
			cout << allocation[i] + 1;
        }
		else
			cout << "Not Allocated";
		cout << endl;
	}
  for(int j=0;j<m;j++)
  {
  	if(free[j]!=-1)
  	{
      count+=partitionSize[j]-processSize[free[j]];
	  cout<<"space left in partition "<<j+1<<" is "<<partitionSize[j]-processSize[free[j]]<<endl;
	  }
  	else
  	{
      count+=partitionSize[j];
	  if(partitionSize[j]!=0)
	  {
	  cout<<"space left in partition "<<j+1<<" is "<<partitionSize[j]<<endl;
	  }
	}
  }
  cout<<"space left in partitions after allocating processes is :"<<count<<endl;
  return count;
}

/*MFT BEST FIT*/
void bestFit_MFT(int partitionSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int free[m];
    int partitionSize_temp[m];
    memset(allocation, -1, sizeof(allocation));
    memset(free, -1, sizeof(free));
    for (int i=0; i<n; i++)
    {
        int bestIdx = -1;
        for (int j=0; j<m; j++)
        {
            partitionSize_temp[j]=partitionSize[j];
            if (partitionSize_temp[j] >= processSize[i] && free[j]==-1)
            {
                if (bestIdx == -1)
                    bestIdx = j;
                else if (partitionSize_temp[bestIdx] > partitionSize_temp[j])
                    bestIdx = j;
            }
        }
        if (bestIdx != -1)
        {
            // allocate block j to p[i] process
            free[bestIdx]=1;
            allocation[i] = bestIdx;

            // Reduce available memory in this block.
            partitionSize_temp[bestIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

/*MFT worst fit*/
void worstFit_MFT(int partitionSize[], int m, int processSize[], int n)
{
// Stores block id of the block allocated to a
    // process
    int allocation[n];
    int partitionSize_temp[m];
    int free1[m];
    
    // Initially no block is assigned to any process
    memset(allocation, -1, sizeof(allocation));
    memset(free1,-1,sizeof(free1));
    for(int i=0;i<m;i++)
    {
    partitionSize_temp[i]=partitionSize[i];
    }
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i=0; i<n; i++)
    {
        int wstIdx = -1;
        for (int j=0; j<m; j++)
        {
            if (partitionSize_temp[j] >= processSize[i] && free1[j]==-1)
            {
                if (wstIdx == -1)
                    wstIdx = j;
                else if (partitionSize_temp[wstIdx] < partitionSize[j])
                    wstIdx = j;
            }
        }

        // If we could find a block for current process
        if (wstIdx != -1)
        {
            // allocate block j to p[i] process
            allocation[i] = wstIdx;
            free1[wstIdx]=1;
            // Reduce available memory in this block.
           partitionSize_temp[wstIdx] -= processSize[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "   " << i+1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

//END OF MODULES FOR MFT FIRST,BEST,WORST FIT. 191CS230 MOHIYADDEEN RAZA


//CODE MODULES FOR CHOICE 5: KRUTHIKA K SUDHAMA

void MVT_first_best_worst_fits(){
    int n1;
    int c=1, n2;
    proc=(struct process*)malloc(100*sizeof(struct process));
    cout<<"\nEnter the total memory block size: ";
    cin>>t_size;
    free_space=t_size;
    head=(struct node*)malloc(sizeof(struct node));
    head->size=t_size;
    head->flag=0;
    head->prev=head->next=NULL;
    //asking the user to select insert operation to be performed this remains constant throughout the program
    cout<<"1. First Fit";
    cout<<"\t2. Best Fit";
    cout<<"\t3. Worst Fit"<<endl;
    cout<<"\nEnter the insert operation to be performed:";
    cin>>n2;
    while(c){
        cout<<"\nThe operations available are:";
        cout<<"\t1. Insert";
        cout<<"\t2. Remove";
        cout<<"\t3. Exit";
        cout<<"\nEnter the appropriate operation: ";
        cin>>n1;
        switch(n1){
        case 1:
            {
                switch(n2){
                case 1:{
                        firstFit();
                        break;}
                case 2:{
                        bestFit();
                        break;}
                case 3:{
                        worstFit();
                        break;}
                }
                break;
            }
            case 2:{
                    Remove();
                    break;}
            case 3:{
                    c=0;
                    break;}
            default:
                cout<<"\nEnter the valid input!!";
        }
    }
}

//This function displays the partitions and
//processes in those partitions, if any
void mem_display()
{
    int i=0, count=0;
    struct node *temp, *n;
    n= (struct node*)malloc(sizeof(struct node));
    temp=(struct node*)malloc(sizeof(struct node));
    temp=head;
    do{
        cout<<"----------------------- ";
        count++;
    }while((temp=temp->next) && count<=7);
    cout<<endl;
    i=0;
    count=0;
    temp=head;
    do{
        cout<<"|Partition "<<i<<" ("<<temp->size<<"KB)\t";
        i++;
        count++;
    }while((temp=temp->next) && count<=7);
    cout<<"|"<<endl;
    count=0;
    temp=head;
    do{
        cout<<"----------------------- ";
        count++;
    }while((temp=temp->next) && count<=7);
    cout<<endl;
    count=0;
    temp=head;
    do{
        if(temp->flag==1){
            cout<<"|Process "<<temp->p.id<<" ("<<temp->p.size<<"KB)\t";
        }else{
            cout<<"|No process allocated\t";
        }
        count++;
    }while((temp=temp->next) && count<=7);
    cout<<"|"<<endl;
    count=0;
    temp=head;
    do{
        cout<<"----------------------- ";
        count++;
    }while((temp=temp->next) && count<=7);
    cout<<endl;
    while(temp){
        count=0;
        n=temp;
        do{
            cout<<"----------------------- ";
            count++;
        }while((temp=temp->next) && count<=7);
        cout<<endl;
        i=0;
        count=0;
        temp=n;
        do{
            cout<<"|Partition "<<i<<" ("<<temp->size<<"KB)\t";
            i++;
            count++;
        }while((temp=temp->next) && count<=7);
        cout<<"|"<<endl;
        count=0;
        temp=n;
        do{
            cout<<"----------------------- ";
            count++;
        }while((temp=temp->next) && count<=7);
        cout<<endl;
        count=0;
        temp=n;
        do{
            if(temp->flag==1){
                cout<<"|Process "<<temp->p.id<<" ("<<temp->p.size<<"KB)\t";
            }else{
                cout<<"|No process allocated\t";
            }
            count++;
        }while((temp=temp->next) && count<=7);
        cout<<"|"<<endl;
        count=0;
        temp=n;
        do{
            cout<<"----------------------- ";
            count++;
        }while((temp=temp->next) && count<=7);
        cout<<endl;
    }
}

/* FIRST FIT */
void firstFit()
{
    int flag=0;
    struct node *newnode, *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    (proc+id)->id = id;
    cout<<"\nEnter the Process size: ";
    cin>>(proc+id)->size;
    temp=head;
    do{
        //flag marks whether or not a partition is accommodated
        //& the condition also checks if partition size is greater
        //than size of process so it can be accommodated
        if(temp->flag==0 && temp->size>(proc+id)->size){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->size=(proc+id)->size;  //we need a new node to accomodate the process
            newnode->flag=1;
            newnode->p=*(proc+id);
            temp->size=temp->size-(proc+id)->size;
            if(temp->prev){ //if the process is not being accommodated to first or head partition
                temp->prev->next=newnode;
                newnode->prev=temp->prev;
                newnode->next=temp;
                temp->prev=newnode;
            }else{          //if process is accommodated to head partition
                newnode->prev=NULL;
                head=newnode;
                head->next=temp;
                temp->prev=head;
            }
            flag=1;
            break;
        }
        //if some partition has same size as the process size,
        //then no new linked list node is required, add the process to existing linked list
        else if(temp->flag==0 && temp->size==(proc+id)->size){
            temp->flag=1;
            temp->p=*(proc+id);
            flag=1;
            break;
        }
    }while((temp=temp->next));
    if(flag==1){
        free_space=free_space-(proc+id)->size;
        cout<<"\nThe process is allocated"<<endl;
    }else{
        if(free_space>=(proc+id)->size){
            cout<<"\nThe process couldn't be allocated even though "<<free_space<<"KB space is remaining, due to external fragmentation."<<endl;
        }else{
            cout<<"\nThe process couldn't be allocated because only "<<free_space<<"KB is remaining."<<endl;
        }
    }
    mem_display();
    id++;
}

/* BEST FIT */
void bestFit()
{
    int flag=0, min, flag1=0;
    struct node *newnode, *temp, *minNode;
    minNode=(struct node*)malloc(sizeof(struct node));
    temp=(struct node*)malloc(sizeof(struct node));
    (proc+id)->id = id;
    cout<<"\nEnter the Process size: ";
    cin>>(proc+id)->size;
    temp=head;
    min=t_size+1;
    do{ //check if some partition has same size as process entered
        //as it be the best fit
        if(temp->flag==0 && temp->size==(proc+id)->size){
            temp->flag=1;
            temp->p=*(proc+id);
            flag=1;
            flag1=0;
            break;
        }
        //if no same sized partition exists then look for min sized partition
        //that can accommodate the process
        else if(temp->flag==0 && temp->size>(proc+id)->size){
            flag1=1;
            if((temp->size-(proc+id)->size)<min){
                min=temp->size-(proc+id)->size;
                minNode=temp;
            }
        }
    }while((temp=temp->next));
    //if there is a min Node, add the process to a newnode partition by diving
    //minNode according to process size
    if(flag1==1){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->flag=1;
        newnode->size=(proc+id)->size;
        newnode->p=*(proc+id);
        minNode->size=minNode->size-(proc+id)->size;
        if(minNode->prev){  //if minNode is not head node
            minNode->prev->next=newnode;
            newnode->prev=minNode->prev;
            newnode->next=minNode;
            minNode->prev=newnode;
        }
        else{   //if minNode is a head node
            newnode->prev=NULL;
            newnode->next=minNode;
            minNode->prev=newnode;
            head=newnode;
        }
        flag=1;
    }
    if(flag==1){
        free_space=free_space-(proc+id)->size;
        cout<<"\nThe process is allocated"<<endl;
    }else{
        if(free_space>=(proc+id)->size){
            cout<<"\nThe process couldn't be allocated even though "<<free_space<<"KB space is remaining, due to external fragmentation."<<endl;
        }else{
            cout<<"\nThe process couldn't be allocated because only "<<free_space<<"KB is remaining."<<endl;
        }
    }
    mem_display();
    id++;
}

/*WORST FIT */
void worstFit()
{
    int flag=0, max, flag1=0;
    struct node *newnode, *temp, *maxNode;
    maxNode=(struct node*)malloc(sizeof(struct node));
    temp=(struct node*)malloc(sizeof(struct node));
    (proc+id)->id = id;
    cout<<"\nEnter the Process size: ";
    cin>>(proc+id)->size;
    temp=head;
    max=0;
    do{ //find the max sized node that can accommodate the process
        if(temp->flag==0 && temp->size>=(proc+id)->size){
            flag1=1;
            if((temp->size-(proc+id)->size)>max){
                max=temp->size-(proc+id)->size;
                maxNode=temp;
            }
        }
    }while((temp=temp->next));
    //if a max node exists then add the process to a new node
    //formed by didving the maxNode
    if(flag1==1){
        if(maxNode->size>(proc+id)->size){
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->flag=1;
            newnode->size=(proc+id)->size;
            newnode->p=*(proc+id);
            maxNode->size=maxNode->size-(proc+id)->size;
            if(maxNode->prev){  //if maxNode is head node
                maxNode->prev->next=newnode;
                newnode->prev=maxNode->prev;
                newnode->next=maxNode;
                maxNode->prev=newnode;
            }
            else{               //if maxNode is not head node
                newnode->prev=NULL;
                newnode->next=maxNode;
                maxNode->prev=newnode;
                head=newnode;
            }
        }//if max node has same size as process
        //no new node partition required, add the process to existing partition
        else if(maxNode->size==(proc+id)->size){
            maxNode->flag=1;
            maxNode->p=*(proc+id);
        }
        flag=1;
    }
    if(flag==1){
        free_space=free_space-(proc+id)->size;
        cout<<"\nThe process is allocated"<<endl;
    }else{
        if(free_space>=(proc+id)->size){
            cout<<"\nThe process couldn't be allocated even though "<<free_space<<"KB space is remaining, due to external fragmentation."<<endl;
        }else{
            cout<<"\nThe process couldn't be allocated because only "<<free_space<<"KB is remaining."<<endl;
        }
    }
    mem_display();
    id++;
}

//This function removes an existing process from the partition
void Remove()
{
    int v, flag=0, p_size;
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    cout<<"\nEnter the Process ID of the process to be removed: ";
    cin>>v;
    temp=head;
    do{
        //conditions to check if the partition is accommodated by given process id
        if(temp->flag==1 && temp->p.id==v){
            p_size=temp->p.size;
            temp->flag=0;
            flag=1;
            //condition to check if the partition containing process to be removed
            //is surrounded by other partitions on both sides
            if((temp->prev) && (temp->next)){
                if(temp->prev->flag==0 && temp->next->flag==0){
                    temp->size=temp->size+temp->prev->size+temp->next->size;
                    temp->prev=temp->prev->prev;
                    temp->next=temp->next->next;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    break;
                }//if the partition on left side is not accommodated,
                //then add that partition to this emptied partition
                else if(temp->prev->flag==0){
                    temp->size=temp->size+temp->prev->size;
                    temp->prev=temp->prev->prev;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    break;
                }//if the partition on right side is not accommodated,
                //then add that partition to this emptied partition
                else if(temp->next->flag==0){
                    temp->size=temp->size+temp->next->size;
                    temp->next=temp->next->next;
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    break;
                }
            }else if((temp->prev)){
                //condition to check if the partition containing process to be removed
                //has a partition on the left side
                if(temp->prev->flag==0){    //if neighbour partition is emptY, merge them
                    temp->size=temp->size+temp->prev->size;
                    temp->prev=temp->prev->prev;
                    if(temp->prev){
                        temp->prev->next=temp;
                    }else{
                        head=temp;
                    }
                    break;
                }
            }else if((temp->next)){
                //condition to check if the partition containing process to be removed
                //has a partition on the right side
                if(temp->next->flag==0){    //if neighbour partition is emptY, merge them
                    temp->size=temp->size+temp->next->size;
                    temp->next=temp->next->next;
                    if(temp->next){
                        temp->next->prev=temp;
                    }
                    head=temp;
                    break;
                }
            }
        }
    }while((temp=temp->next));
    if(flag==1){
        free_space=free_space+p_size;
        cout<<"\nThe process is removed. The remaining free space is "<<free_space<<"KB"<<endl;
    }else{
        cout<<"\nThe process couldn't be removed as it is presently not in the memory."<<endl;
    }
    mem_display();
}
//END OF MODULES OF Choice 5

void Page_Replacement()
{
    int flag;
    cout<<"Page Replacement Menu:\nEnter 1 => FIFO , 2 => LRU , 3 => MRU  4=>Optimal : ";
    do
    {
        cin>>flag;
        if(flag<=0 || flag>=5)
        {
            cout<<"Please Enter  1 => FIFO , 2 => LRU , 3 => MRU  4=>Optimal";
        }
    } while (flag<=0 || flag>=5);

    switch(flag)
    {
        case 1:
            FIFO();
            break;
        case 2:
            LRU();
            break;
        case 3:
            MRU();
            break;
        case 4:
            optimalpagereplacement();
            break;
    }

}

void FIFO()
{
    int n , pg_fault , total_input , time ;

    //input frames
    cout<<"Enter number of Frames: ";
    cin>>n;

    int i, a[max_processes] , incomming_time[max_processes]  , p_id;

    //intialisation
    for(i=0;i<n;i++)
    {
        a[i] = -1;
        incomming_time[i] = -1;
    }
    pg_fault = 0;
    total_input = 0;
    time = 0;

    while(true)
    {
        time++; //increment time
        cout<<"Menu\n Enter 1 to add pages into frame , Enter 2 to stop: ";

        int flag;
        cin>>flag;

        while(flag<1||flag>2)
        {
            cout<<"Wrong Input\n Enter 1 to add pages into frame , Enter 2 to stop: ";
            cin>>flag;
        }

        if(flag==1) // add frame
        {
            total_input++;
            cout<<"Enter Page Number: ";
            cin>>p_id;

            //check if page present in main mem
            for(i=0;i<n;i++)
            {
                if(a[i] == p_id)
                {
                    cout<<"Page P"<<p_id<<" is already present in frame "<<i<<endl;
                    break;
                }
            }
            if(i==n) //page not present
            {
                pg_fault++;
                int index ,min_time;
                index = -1;
                min_time = INT_MAX;

                //find frame which contains page having min incomming time
                for(i=0;i<n;i++)
                {
                    if(min_time> incomming_time[i])
                    {
                        index = i;
                        min_time = incomming_time[i];
                    }
                }

                if(incomming_time[index]>0) // check if frame has a page
                {
                    //replace page
                    cout<<"Page P"<<p_id<<" replaceses  Page P"<<a[index]<<" in frame "<<index<<endl;
                    a[index] = p_id;
                    incomming_time[index] = time;
                }
                else
                {
                    cout<<"Page P"<<p_id<<" is accomidated in frame "<<index<<endl;
                    a[index] = p_id;
                    incomming_time[index] = time;
                }

            }
        }
        else
        {
            //output page faults
            cout<<"Number of Page Faults = "<<pg_fault<<endl;
            cout<<"ratio of page fault = "<<( (float (pg_fault))/total_input)  <<endl<<endl;

            break;
        }
        cout<<"Main Memory:"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Frame F"<<i<<" | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1)
            cout<<"Page P"<<a[i]<<"  | ";
            else
            cout<<"Empty    | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
    }

}

void LRU()
{
    int n , pg_fault , total_input , time ;

    //input frames
    cout<<"Enter number of Frames: ";
    cin>>n;

    int i, a[max_processes] , recently_used_time[max_processes]  , p_id;

    //initialisation
    for(i=0;i<n;i++)
    {
        a[i] = -1;
        recently_used_time[i] = -1;
    }
    pg_fault = 0;
    total_input = 0;
    time = 0;

    while(true)
    {
        time++;  //increment time
        cout<<"Menu\n Enter 1 to add pages into frame , Enter 2 to stop: ";

        int flag;
        cin>>flag;
        while(flag<1||flag>2)
        {
            cout<<"Wrong Input\n Enter 1 to add pages into frame , Enter 2 to stop: ";
            cin>>flag;
        }

        if(flag==1) // add frame
        {
            total_input++;
            cout<<"Enter Page Number: ";
            cin>>p_id;

            //check if page present in main mem
            for(i=0;i<n;i++)
            {
                if(a[i] == p_id)
                {
                    cout<<"Page P"<<p_id<<" is already present in frame "<<i<<endl;
                    recently_used_time[i] = time; //update usage time
                    break;
                }
            }
            if(i==n) //page not present
            {
                pg_fault++;
                int index ,min_time;
                index = -1;
                min_time = INT_MAX;

                //find frame which contains page having min recently used time
                for(i=0;i<n;i++)
                {
                    if(min_time> recently_used_time[i])
                    {
                        index = i;
                        min_time = recently_used_time[i];
                    }
                }
                if(recently_used_time[index]>0) // check if frame has a page
                {
                    //replace page
                    cout<<"Page P"<<p_id<<" replaceses  Page P"<<a[index]<<" in frame "<<index<<endl;
                    a[index] = p_id;
                    recently_used_time[index] = time;
                }
                else
                {
                    cout<<"Page P"<<p_id<<" is accomidated in frame "<<index<<endl;
                    a[index] = p_id;
                    recently_used_time[index] = time;
                }

            }
        }
        else
        {
            //output page faults
            cout<<"Number of Page Faults = "<<pg_fault<<endl;
            cout<<"ratio of page fault = "<<( (float (pg_fault))/total_input)  <<endl<<endl;

            break;
        }
        cout<<"Main Memory:"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Frame F"<<i<<" | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1)
            cout<<"Page P"<<a[i]<<"  | ";
            else
            cout<<"Empty    | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
    }

}

void MRU()
{
    int n , pg_fault , total_input , time ;

     //input frames
    cout<<"Enter number of Frames: ";
    cin>>n;

    int i, a[max_processes] , recently_used_time[max_processes]  , p_id;

    //initialisation
    for(i=0;i<n;i++)
    {
        a[i] = -1;
        recently_used_time[i] = -1;
    }
    pg_fault = 0;
    total_input = 0;
    time = 0;

    while(true)
    {
        time++; //increment time
        cout<<"Menu\n Enter 1 to add pages into frame , Enter 2 to stop: ";

        int flag;
        cin>>flag;

        while(flag<1||flag>2)
        {
            cout<<"Wrong Input\n Enter 1 to add pages into frame , Enter 2 to stop: ";
            cin>>flag;
        }

        if(flag==1) // add frame
        {
            total_input++;
            cout<<"Enter Page Number: ";
            cin>>p_id;

            //check if page present in main mem
            for(i=0;i<n;i++)
            {
                if(a[i] == p_id)
                {
                    cout<<"Page P"<<p_id<<" is already present in frame "<<i<<endl;
                    recently_used_time[i] = time;  //update usage time
                    break;
                }
            }
            if(i==n) //page not present
            {
                pg_fault++;
                int index ,max_time;
                index = -1;
                max_time = -2;

                 //find frame which contains page having max recently used time
                for(i=0;i<n;i++)
                {
                    if(recently_used_time[i] == -1 ) // frame is free
                    {
                        index = i;
                        break;
                    }
                    if(max_time< recently_used_time[i])
                    {
                        index = i;
                        max_time = recently_used_time[i];
                    }
                }
                if(recently_used_time[index]>0) // check if frame has a page
                {
                    //replace page
                    cout<<"Page P"<<p_id<<" replaceses  Page P"<<a[index]<<" in frame "<<index<<endl;
                    a[index] = p_id;
                    recently_used_time[index] = time;
                }
                else
                {
                    cout<<"Page P"<<p_id<<" is accomidated in frame "<<index<<endl;
                    a[index] = p_id;
                    recently_used_time[index] = time;
                }

            }
        }
        else
        {
            //output page faults
            cout<<"Number of Page Faults = "<<pg_fault<<endl;
            cout<<"ratio of page fault = "<<( (float (pg_fault))/total_input)  <<endl<<endl;
            break;
        }
        cout<<"Main Memory:"<<endl;
        int i;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"Frame F"<<i<<" | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=-1)
            cout<<"Page P"<<a[i]<<"  | ";
            else
            cout<<"Empty    | ";
        }
        cout<<endl;
        for(i=0;i<n;i++)
        {
            cout<<"---------|-";
        }
        cout<<endl;
    }

}
void bankers_algorithm(){
    int p;//processes
    int r;//resources
    cout<<"Enter the number of processes\n";
    cin>>p;
    cout<<"Enter the number of resources\n";
    cin>>r;
    //we need the information about the  about the alloted resources to the processes initially we also need the max resources each process need
    // we maintain the available resources also ie. total resources - alloted resources
    int allotted[p][r];
    int maxrequired[p][r];
    int totalresources[r];
    int available[r];
    cout<<"enter the allotted resources for each process"<<endl;
    for(int i=0;i<p;i++){
        cout<<"alloted resources for process"<<i<<endl;
        for(int j=0;j<r;j++){
            cin>>allotted[i][j];
        }
    }
    for(int i=0;i<p;i++){
        cout<<"maximum resources required for process"<<i<<endl;
        for(int j=0;j<r;j++){
            cin>>maxrequired[i][j];
        }
    }
    cout<<"enter the total instances for each resource"<<endl;
    for(int i=0;i<r;i++){
        cin>>totalresources[i];
    }

    // we calculate the amount of resources available now
    for(int i=0;i<r;i++){
        available[i]=totalresources[i];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<p;j++){
            available[i]-=allotted[j][i];
        }
    }
    //printing the available resources
    cout<<"the available resources are"<<endl;
    for(int i=0;i<r;i++){
        cout<<available[i]<<"\t";
    }
    cout<<endl;
    cout<<"The allotted resource table is \n";
    cout<<"PID \t   RESOURCES \n";
    for(int i=0;i<p;i++){
        cout<<"P["<<i<<"]   | \t";
        for(int j=0;j<r;j++){
            printf("\t %d   |",allotted[i][j]);
        }
        cout<<endl;
    }
    cout<<"The maximum resources table is \n";
    cout<<"PID \t   RESOURCES \n";
    for(int i=0;i<p;i++){
        cout<<"P["<<i<<"]   | \t";
        for(int j=0;j<r;j++){
            printf("\t %d   |",maxrequired[i][j]);
        }
        cout<<endl;
    }
    //now we are good to go.... what do we do iterate through all process if any process can be processed do that and update the available resources else continue
    // so how many iterations we need to do .. so basically in every iteration atleast one process will be done .. otherwise that will be deadlock
    int needed[p][r];
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++){
        needed[i][j]=maxrequired[i][j]-allotted[i][j];
        }
    }
    cout<<"The resources needed \n";
    cout<<"PID \t   RESOURCES \n";
    for(int i=0;i<p;i++){
        cout<<"P["<<i<<"]   | \t";
        for(int j=0;j<r;j++){
            printf("\t %d   |",needed[i][j]);
        }
        cout<<endl;
    }
    int sequence[p];
    // how do we know if a process is done .. so we maintain flag kinda array for this
    int check[p];
    // initially all processes are not done so set check[process]=0 for each process
    for(int i=0;i<p;i++){
        check[i]=0;
    }
    int index=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            if (check[j]==0){
                // check if need is satisfied by available resources
                int flag=0; // this is maintained to address the case when the need is fulfilled
                for(int k=0;k<r;k++){
                    if(needed[j][k]>available[k]){
                        flag=1;
                        break; //as the need is not satisfied no need to check for further resources
                    }
                }
                if(flag==0){
                    sequence[index++]=j;
                        // we also need to update available resources as the process when done releases its alloted resources
                    for(int s=0;s<r;s++){
                        available[s]+=allotted[j][s];
                    }
                    check[j]=1;
                }
        }

    }
    }
    if(count(check,check+p,1)<p){
        cout<<"\n deadlock occured";
    }
    else{
        cout<<"\n the safe sequence is"<<endl;
        for(int i=0;i<p;i++){
            cout<<"P"<<sequence[i]<<"\t";
        }
        cout<<endl;
    }
}

// paging algorithm with offset
void paging_With_Offset(){

    int ch;
    printf("Choices available for paging algorithm\n1.FIFO\t\t2.LRU\t\t3.MRU\nEnter your choice :");
    scanf("%d",&ch);

    // switch case
    switch (ch)
    {
    case 1:
        fifo();
        break;
    case 2:
        lru();
        break;
    case 3:
        mru();
        break;

    default:
        printf("Not a Valid Input!!");
        break;
    }
}


// FIFO algorithm
void fifo(){
    printf("Implimenting FIFO algorithm\n");
    // input size of physical memory
    int pM;
    printf("Enter size of physical memory in KB:");
    scanf("%d",&pM);

    // input size of virtual memory
    int vM;
    printf("Enter size of virtual memory in KB:");
    scanf("%d",&vM);

    // input size of page
    int size;
    printf("Enter size of pages in KB:");
    scanf("%d",&size);

    //  number of frames in physical memory and number of pages in virtual memory

    int frames=pM/size;
    int pages=vM/size;

    // array of frames and their indexing
    int arrayF[frames][2];
    int total=0;

    // initializing array
    for(int i=0; i<frames; i++){
        arrayF[i][0]=-1;
        arrayF[i][1]=0;
    }

    int arrayP[pages];
    // initializing page table
    for (int i = 0; i < pages; i++)
    {
        arrayP[i]=-1;
    }


    // variable for choice of operation and counting the number of faults
    int choice=1 , count=0;

    // loop label
    loop:
    while (choice)
    {
        // choice of operation
        printf("1.Enter Virtual Address generated by CPU as pageNO offset zero based indexing\t\t\t2.exit\nEnter your choice : ");
        scanf("%d",&choice);

        // asign page into frame if it is not there
        if(choice==1){

            // page address
            int pN, offset=0;
            printf("Enter virtual address:");
            scanf("%d%d",&pN,&offset);

            // condition check
            if (pN>=pages || pN<0)
            {
                printf("Page number should be in between 0 to %d\n",pages-1);
                goto loop;
            }
            else if (offset>=20*1024 || offset<0)
            {
                printf("Offset value should be in between 0 to %dBytes\n",size*1024-1);
                goto loop;
            }



            // total count total number of pages used
            total++;

            // if page already present
            if (arrayP[pN]!=-1)
            {
                printf("The physical address for the above virtual address is: %d | %d\n",arrayP[pN],offset);
                goto loop;
            }


            // if page not present already
            printf("Page%d is not present in the physical memory\n",pN);
            int i;
            bool flag=0;
            for (i = 0; i < frames; i++)
            {
                if (arrayF[i][0]==-1)
                {
                    flag=1;
                    break;
                }
            }

            // if any frame is emptY
            if (flag)
            {
                printf("Page%d is accomodated in Frame%d\n",pN,i);
                arrayF[i][0]=pN;
                arrayF[i][1]=++count;
                arrayP[pN]=i;
            }
            // if no frame is emptY
            else{
                int min=__INT_MAX__;
                int index=-1;
                for (int i = 0; i < frames; i++)
                {
                    if (min>arrayF[i][1])
                    {
                        min=arrayF[i][1];
                        index=i;
                    }
                }

                printf("page%d is Removed from Frame%d using fifo replacement policy\n",arrayF[index][0],index);
                arrayP[arrayF[index][0]]=-1;
                arrayF[index][0]=pN;
                arrayF[index][1]=++count;
                arrayP[pN]=index;
                printf("Page%d is accomodated in Frame%d\n",pN,index);
            }


        }
        // final output
        else if (choice==2)
        {
            // output number of faults and fault ratio
            printf("Number of page faults = %d\n",count);
            printf("Page Fault Ratio = %f\n",(float)count/total);

            // final page table
            printf("\nfinal page table\n");
            printf("-----------------\n");
            for (int i = 0; i < pages; i++)
            {
                printf("P%d | %d\n",i,arrayP[i]);
            }

            // final physical memory
            printf("\nfinal physical memory\n");
            printf("---------------------\n");
            for (int i = 0; i < frames; i++)
            {
                printf("F%d | P%d\n",i,arrayF[i][0]);
            }

            break;
        }
        else{
            printf("Invalid Input!! Try again\n");
            goto loop;
        }

    }

}

// lRU algorithm
void lru(){
    printf("Implimenting LRU algorithm\n");
     // input size of physical memory
    int pM;
    printf("Enter size of physical memory:");
    scanf("%d",&pM);

    // input size of virtual memory
    int vM;
    printf("Enter size of virtual memory:");
    scanf("%d",&vM);

    // input size of page
    int size;
    printf("Enter size of pages:");
    scanf("%d",&size);

    //  number of frames in physical memory and number of pages in virtual memory

    int frames=pM/size;
    int pages=vM/size;

    // array of frames and their indexing
    int arrayF[frames][2];
    int total=0;

    // initializing array
    for(int i=0; i<frames; i++){
        arrayF[i][0]=-1;
        arrayF[i][1]=0;
    }

    int arrayP[pages];
    // initializing page table
    for (int i = 0; i < pages; i++)
    {
        arrayP[i]=-1;
    }


    // variable for choice of operation and counting the number of faults
    int choice=1 , count=0;
    // inc used to increase the sequence prefference
    int inc=0;

    // loop label
    loop:
    while (choice)
    {
        // choice of operation
        printf("1.Enter Virtual Address generated by CPU as [pageNO|offset]\t\t\t2.exit\nEnter your choice : ");
        scanf("%d",&choice);

        // take the virtual memory address and verify it
        if(choice==1){

            // page address
            int pN, offset=0;
            printf("Enter virtual address:");
            scanf("%d%d",&pN,&offset);

            // condition check
            if (pN>=pages || pN<0)
            {
                printf("Page number should be in between 0 to %d\n",pages-1);
                goto loop;
            }
            else if (offset>=20*1024 || offset<0)
            {
                printf("Offset value should be in between 0 to %dKB\n",size*1024-1);
                goto loop;
            }


            // total count total number of pages used
            total++;

            // if page already present
            if (arrayP[pN]!=-1)
            {
                printf("The physical address for the above virtual address is: %d | %d\n",arrayP[pN],offset);
                arrayF[arrayP[pN]][1]=++inc;
                goto loop;
            }


            // if page not present already
            printf("Page%d is not present in the physical memory\n",pN);
            int i;
            bool flag=0;
            for (i = 0; i < frames; i++)
            {
                if (arrayF[i][0]==-1)
                {
                    flag=1;
                    break;
                }
            }

            // if any frame is emptY
            if (flag)
            {
                printf("Page%d is accomodated in Frame%d\n",pN,i);
                arrayF[i][0]=pN;
                arrayF[i][1]=++inc;
                count++;
                arrayP[pN]=i;
            }

            // if no frame is emptY
            else{
                int min=__INT_MAX__;
                int index=-1;
                for (int i = 0; i < frames; i++)
                {
                    if (min>arrayF[i][1])
                    {
                        min=arrayF[i][1];
                        index=i;
                    }
                }

                printf("page%d is Removed from Frame%d using LRU replacement policy\n",arrayF[index][0],index);
                arrayP[arrayF[index][0]]=-1;
                arrayF[index][0]=pN;
                arrayF[index][1]=++inc;
                count++;
                arrayP[pN]=index;
                printf("Page%d is accomodated in Frame%d\n",pN,index);
            }


        }
        // final output
        else if (choice==2)
        {
            // output number of faults and fault ratio
            printf("Number of page faults = %d\n",count);
            printf("Page Fault Ratio = %f\n",(float)count/total);

            // final page table
            printf("\nfinal page table\n");
            printf("-----------------\n");
            for (int i = 0; i < pages; i++)
            {
                printf("P%d | %d\n",i,arrayP[i]);
            }

            // final physical memory
            printf("\nfinal physical memory\n");
            printf("---------------------\n");
            for (int i = 0; i < frames; i++)
            {
                printf("F%d | P%d\n",i,arrayF[i][0]);
            }

            break;
        }
        else{
            printf("Invalid Input!! Try again\n");
            goto loop;
        }

    }
}

// mru algorithm
void mru(){
    printf("Implimenting MRU algorithm\n");
    // input size of physical memory
    int pM;
    printf("Enter size of physical memory:");
    scanf("%d",&pM);

    // input size of virtual memory
    int vM;
    printf("Enter size of virtual memory:");
    scanf("%d",&vM);

    // input size of page
    int size;
    printf("Enter size of pages:");
    scanf("%d",&size);

    //  number of frames in physical memory and number of pages in virtual memory

    int frames=pM/size;
    int pages=vM/size;

    // array of frames and their indexing
    int arrayF[frames][2];
    int total=0;

    // initializing array
    for(int i=0; i<frames; i++){
        arrayF[i][0]=-1;
        arrayF[i][1]=0;
    }

    int arrayP[pages];
    // initializing page table
    for (int i = 0; i < pages; i++)
    {
        arrayP[i]=-1;
    }


    // variable for choice of operation and counting the number of faults
    int choice=1 , count=0;
    // inc used to increase the sequence prefference
    int inc=0;

    // loop label
    loop:
    while (choice)
    {
        // choice of operation
        printf("1.Enter Virtual Address generated by CPU as [pageNO|offset]\t\t\t2.exit\nEnter your choice : ");
        scanf("%d",&choice);

        // take the virtual memory address and verify it
        if(choice==1){

            // page address
            int pN, offset=0;
            printf("Enter virtual address:");
            scanf("%d%d",&pN,&offset);

            // condition check
            if (pN>=pages || pN<0)
            {
                printf("Page number should be in between 0 to %d\n",pages-1);
                goto loop;
            }
            else if (offset>=20*1024 || offset<0)
            {
                printf("Offset value should be in between 0 to %dKB\n",size*1024-1);
                goto loop;
            }


            // total count total number of pages used
            total++;

            // if page already present
            if (arrayP[pN]!=-1)
            {
                printf("The physical address for the above virtual address is: %d | %d\n",arrayP[pN],offset);
                arrayF[arrayP[pN]][1]=++inc;
                goto loop;
            }


            // if page not present already
            printf("Page%d is not present in the physical memory\n",pN);
            int i;
            bool flag=0;
            for (i = 0; i < frames; i++)
            {
                if (arrayF[i][0]==-1)
                {
                    flag=1;
                    break;
                }
            }

            // if any frame is emptY
            if (flag)
            {
                printf("Page%d is accomodated in Frame%d\n",pN,i);
                arrayF[i][0]=pN;
                arrayF[i][1]=++inc;
                count++;
                arrayP[pN]=i;
            }

            // if no frame is emptY
            else{
                int max=-(__INT_MAX__);
                int index=-1;
                for (int i = 0; i < frames; i++)
                {
                    if (max<arrayF[i][1])
                    {
                        max=arrayF[i][1];
                        index=i;
                    }
                }

                printf("page%d is Removed from Frame%d using MRU replacement policy\n",arrayF[index][0],index);
                arrayP[arrayF[index][0]]=-1;
                arrayF[index][0]=pN;
                arrayF[index][1]=++inc;
                count++;
                arrayP[pN]=index;
                printf("Page%d is accomodated in Frame%d\n",pN,index);
            }


        }
        // final output
        else if (choice==2)
        {
            // output number of faults and fault ratio
            printf("Number of page faults = %d\n",count);
            printf("Page Fault Ratio = %f\n",(float)count/total);

            // final page table
            printf("\nfinal page table\n");
            printf("-----------------\n");
            for (int i = 0; i < pages; i++)
            {
                printf("P%d | %d\n",i,arrayP[i]);
            }

            // final physical memory
            printf("\nfinal physical memory\n");
            printf("---------------------\n");
            for (int i = 0; i < frames; i++)
            {
                printf("F%d | P%d\n",i,arrayF[i][0]);
            }

            break;
        }
        else{
            printf("Invalid Input!! Try again\n");
            goto loop;
        }

    }
}
void reader_writer(){
    int read=0,write=0;
    cout<<"Enter Number of Readers"<<endl;
    cin>>read;
    cout<<"Enter Number of Writers"<<endl;
    cin>>write;
    vector<Row>Arr(read+write); //vector of structures to hold all the information about the processes
    for(int i=0;i<read;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Reader "<<i+1<<endl;
        Arr[i].reader=true;
        Arr[i].serial=i+1;

        cin>>Arr[i].AT>>Arr[i].BT;
        Arr[i].endtime=Arr[i].BT+Arr[i].AT;
    }

    for(int i=0;i<write;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Writer "<<i+1<<endl;
        Arr[read+i].reader=false;
        Arr[read+i].serial=i+1;
        cin>>Arr[read+i].AT>>Arr[read+i].BT;
        Arr[read+i].endtime=Arr[read+i].BT+Arr[read+i].AT;
    }
    queue<Row>readers;
    queue<Row>writers;
    sort(Arr.begin(),Arr.end(),comp);//we are sorting the vector of structs containing information about readers and writers based on priority
    int n=read+write;
    for(int i=0;i<n;i++)
    {
        if(Arr[i].reader==true)
        {
            readers.push(Arr[i]);           //enqueing the readers and writers into their respective queues
        }
        else
        {
            writers.push(Arr[i]);
        }
    }
    queue<Row>ongoing;
    while(readers.size()!=0||writers.size()!=0)
    {
        Row f;
        while(ongoing.size()!=0&&ongoing.front().endtime==t)
        {
            f=ongoing.front();
            if(f.reader==true)
            {
                cout<<"Reader "<<f.serial<<" Finished reading at t= "<<t<<endl;         //processing the processes enqueued earlier.
                readcount--;
            }
            else
            {
                cout<<"Writer "<<f.serial<<" Finished writing at t= "<<t<<endl;
                writecount--;
            }
            ongoing.pop();
        }
        Row turn;
        if(readcount==0&&writecount==0)
        {

            if(writers.size()!=0&&writers.front().AT<=t)      //enqueing writers into the ongoing queue based on their arrival tiems
            {
                turn=writers.front();
                writecount++;
                turn.endtime=t+turn.BT;
                cout<<"Writer "<<turn.serial<<" Started Writing at t= "<<t<<endl;
                ongoing.push(turn);
                writers.pop();

            }
            else if(readers.size()!=0&&readers.front().AT<=t)
            {
                turn=readers.front();
                cout<<"Reader "<<turn.serial<<" Started Reading at t= "<<t<<endl;
                turn.endtime=t+turn.BT;
                readcount++;
                ongoing.push(turn);
                readers.pop();
            }

        }
        else if(writecount==0)              //if no writers are present in the queue now
        {
            if(readers.size()!=0&&readers.front().AT<=t)
            {
                turn=readers.front();
                turn.endtime=t+turn.BT;
                cout<<"Reader "<<turn.serial<<" Started Reading at t= "<<t<<endl;
                readcount++;
                ongoing.push(turn);
                readers.pop();


            }


        }
        else
        {
            for(int i=0;i<n;i++)
            {
                if(Arr[i].AT==t)
                {
                    if(Arr[i].reader==true)
                    {
                        cout<<"Reader "<<Arr[i].serial<<" Starts waiting at t= "<<t<<endl;
                    }
                    else
                    {
                        cout<<"Writer "<<Arr[i].serial<<" Starts waiting at t= "<<t<<endl;

                    }
                }

            }
        }

        t++;
    }
    Row f;
    while(ongoing.size()!=0)
    {
        f=ongoing.front();
        if(f.reader==true)
        {
            cout<<"Reader "<<f.serial<<" Finished reading at t= "<<t<<endl;
            readcount--;
        }
        else
        {
            cout<<"Writer "<<f.serial<<" Finished writing at t= "<<t<<endl;
            writecount--;
        }
        ongoing.pop();
        t++;
}
}
void producer(int bt,int serial)//Argument:Burst Time of the Process
{
    s=wait(s);
    full=signal(full);
    emptY=wait(emptY);
    st+=bt;//time is incremented by bt
    cout<<"Producer "<<serial<<" Producing Finished at  time t="<<st<<endl;

    s=signal(s);
}
void consumer(int bt,int serial)//Argument:Burst Time of Porcess
{
    s=wait(s);
    full=wait(full);
    emptY=signal(emptY);
    st+=bt;
    cout<<"Consumer "<<serial<<" Consuming Finished at t="<<st<<endl;
    s=signal(s);
}

void producer_consumer(){
   int prod=0,consum=0;
    cout<<"Enter Number of Producers"<<endl;
    cin>>prod;
    cout<<"Enter Number of Consumers"<<endl;
    cin>>consum;
    vector<Row1>Arr(prod+consum);\
    queue<Row1>producerqueue;
    queue<Row1>consumerqueue;
    for(int i=0;i<prod;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Producer "<<i+1<<endl;
        Arr[i].producer=true;
        Arr[i].serial=i+1;
        Arr[i].completed=false;
        cin>>Arr[i].AT>>Arr[i].BT;
    }

    for(int i=0;i<consum;i++)
    {
        cout<<"Enter Arrival Time and Burst Time of Consumer "<<i+1<<endl;
        Arr[prod+i].producer=false;
        Arr[prod+i].serial=i+1;
        Arr[prod+i].completed=false;
        cin>>Arr[prod+i].AT>>Arr[prod+i].BT;
    }
    sort(Arr.begin(),Arr.end(),comp1);
    int n=prod+consum;
    int leftover=n;
    for(int i=0;i<n;i++)
    {
        if(Arr[i].producer==true)
        {
            if(s==1&&emptY!=0)
            {
                producerqueue.push(Arr[i]);
                Row1 f=producerqueue.front();
                st=max(st,f.AT);
                cout<<"Producer "<<f.serial<<" starts production at t="<<st<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(Arr[j].AT==f.AT)
                    {
                        if(Arr[j].producer==true)
                        {
                            cout<<" Producer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }

                producer(f.BT,f.serial);
                producerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Full.Producer "<<Arr[i].serial<<" Needs to wait"<<endl;
                producerqueue.push(Arr[i]);
            }

        }
        else
        {
            if(s==1&&full!=0)
            {
                consumerqueue.push(Arr[i]);
                Row1 f=consumerqueue.front();
                st=max(st,f.AT);
                cout<<"Consumer "<<f.serial<<" starts production at t="<<st<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(Arr[j].AT==f.AT)
                    {
                        if(Arr[j].producer==true)
                        {
                            cout<<" Producer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<Arr[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }
                consumer(f.BT,f.serial);
                consumerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is emptY.Consumer "<<Arr[i].serial<<" Needs to wait"<<endl;
                consumerqueue.push(Arr[i]);
            }

        }
    }
    vector<Row1>left;
    while(producerqueue.size()!=0)
    {
        cout<<producerqueue.front().serial<<endl;
        left.push_back(producerqueue.front());
        producerqueue.pop();
    }
    while(consumerqueue.size()!=0)
    {
        left.push_back(consumerqueue.front());
        consumerqueue.pop();
    }
    sort(left.begin(),left.end(),comp1);
    n=left.size();

    for(int i=0;i<n;i++)
    {
        if(left[i].producer==true)
        {
            if(s==1&&emptY!=0)
            {
                producerqueue.push(left[i]);
                Row1 f=producerqueue.front();
                st=max(st,f.AT);
                cout<<"Producer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(left[j].AT==f.AT)
                    {
                        if(left[j].producer==true)
                        {
                            cout<<" Producer "<<left[j].serial<<" needs to wait"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<left[j].serial<<" needs to wait"<<endl;
                        }
                    }

                }
                producer(f.BT,f.serial);
                producerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is Full.Producer "<<left[i].serial<<" Needs to wait for Consumer"<<endl;
                producerqueue.push(left[i]);
            }

        }
        else
        {
            if(s==1&&full!=0)
            {
                consumerqueue.push(left[i]);
                Row1 f=consumerqueue.front();
                st=max(st,f.AT);
                cout<<"Consumer "<<f.serial<<" starts production at t="<<t<<endl;
                for(int j=i+1;j<n;j++)
                {
                    if(left[j].AT==f.AT)
                    {
                        if(left[j].producer==true)
                        {
                            cout<<" Producer "<<left[j].serial<<" is waiting"<<endl;
                        }
                        else
                        {
                            cout<<" Consumer "<<left[j].serial<<" is waiting"<<endl;
                        }
                    }

                }
                consumer(f.BT,f.serial);
                consumerqueue.pop();
                leftover--;
            }
            else
            {
                cout<<"Buffer is emptY.Consumer "<<left[i].serial<<" Needs to wait for Producer"<<endl;
                consumerqueue.push(left[i]);
            }

        }
    }
}

//Modules for Dining Philosophers
void dining_philosophers()
{
    cout<<"\n-------------------------------------------------------------------------------------------------------\n";
    cout<<"\n----------------------------------THE DINING PHILOSOPHERS PROBLEM--------------------------------------\n";
    cout<<"\n-------------------------------------------------------------------------------------------------------\n";
    cout<<"Enter the number of philosophers sitting around the dining table: ";
    cin>>n;
    //ALLOCATING MEMORIES TO ALL THE STRUCT ARRAYS USED
    p1=(struct philosopher*) malloc(n*sizeof(struct philosopher));
    w_0=(struct philosopher*) malloc(n*sizeof(struct philosopher));
    w_1=(struct philosopher*) malloc(n*sizeof(struct philosopher));
    running=(struct philosopher*) malloc(n*sizeof(struct philosopher));
    q1=(struct philosopher*) malloc(n*sizeof(struct philosopher));
    s1=(struct semaphore1*) malloc(n*sizeof(struct semaphore1));
    //INITIALLY, ASSIGNING THE semaphore1S VALUE TO 1
    for(i=0;i<n;i++){
        (s1+i)->value=1;
    }
    //TAKING INPUTS OF ARRIVAL AND BURST TIMES FROM THE USER
    cout<<"\nEnter the Arrival-time and Burst-time of each philosopher:\n";
    for(i=0;i<n;i++){
        (p1+i)->Pno=i;
        cout<<"\nArrival-time of philosopher "<<i<<":";
        cin>>(p1+i)->AT;
        cout<<"Burst-time of philosopher "<<i<<":";
        cin>>(p1+i)->BT;
    }
    //NOW THE PHILOSOPHERS CYCLE STARTS
    philosophers_cycle();
}

void philosophers_cycle(){
    first=1;
    dead_lock_0.Pno=-1;
    dead_lock_1.Pno=-1;

    //t IS THE TIME IN SECONDS
    while(1){
        cout<<"\n\nAt time = "<<t1<<" seconds\n";
        cout<<"-------------------------------------------------------------------------------------\n";

        //IF THE PHILOSOPHERS BURST TIMES ARE OVER, THEN RELEASING THE semaphore1S
        for(i=0;i<r_end;i++){
            if(t1-(running+i)->start_time==(running+i)->BT){
                cout<<"\nPhilosopher "<<(running+i)->Pno<<" put down his left and right forks.\n";
                signal_d((running+i)->Pno);
                signal_d(((running+i)->Pno+1)%n);
                for(j=i;j<r_end-1;j++){
                    *(running+j)=*(running+(j+1));
                }
                if(i<r_end){
                    r_end--, i--;
                }
            }else{
                cout<<"\nPhilosopher "<<(running+i)->Pno<<" is eating\n";
            }
        }

        //THOSE WHO COULDNOT PICK THEIR LEFT FORK IN PREVIOUS LOOP TRY PICKING IT AGAIN
        for(i=0;i<w_0_end;i++){
            fork_picked=0;
            wait_d((w_0+i)->Pno, (w_0+i)->Pno, 3);
            if(fork_picked==1){
                for(j=i;j<w_0_end-1;j++){
                    *(w_0+j)=*(w_0+(j+1));
                }
                if(i<w_0_end){
                    w_0_end--, i--;
                }
            }
        }

        //THE PHILOSOPHERS WHOSE ARRIVAL TIME IS EQUAL TO 't' ARE ENTERED INTO THE QUEUE
        for(i=0;i<n;i++){
            if((p1+i)->AT==t1){
                *(q1+q_end++)=*(p1+i);
                count1++;
            }
        }

        //IF ALL THE PHILOSOPHERS CHOOSE TO EAT AT THE SAME TIME, DEAD-LOCK CONDITION MAY OCCUR
        //SO TO AVOID DEADLOCK, WE CHANGE THE ORDER OF PICKING FORKS OF LAST PHILOSOPHER
        //SO IN DEADLOCK CONDITION, ALL PHILOSOPHERS EXCEPT LAST PHILOSOPHER PICK THEIR LEFT FORKS FIRST, THEN RIGHT FORKS
        //BUT THE LAST PHILOSOPHER PICKS RIGHT FORK FIRST, THEN LEFT FORK---ONLY IN DEADLOCK CONDITION
        if(q_end==n){
            q_end=q_end-1;
            dead_cond=1;        //A FLAG TO DEADLOCK STATE
        }

        //PHILOSOPHERS IN QUEUE 'q' PICKING UP THE LEFT FORK
        for(i=0;i<q_end;i++){
            wait_d((q1+i)->Pno, (q1+i)->Pno, 1);
        }
        q_end=0;

        //IN DEADLOCK CONDITION, THE LAST PERSON TRIES PICKING THE RIGHT FORK AGAIN IF HE COUNDN'T PICK IT IN PREVIOUS LOOP
        if(dead_lock_0.Pno!=-1){
            wait_d(dead_lock_0.Pno, (dead_lock_0.Pno+1)%n, -1);
        }
        //IN DEADLOCK CONDITION, THE LAST PERSON TRIES PICKING LEFT FORK AFTER PICKING THE RIGHT FORK
        if(dead_lock_1.Pno!=-1){
            dead_count=1;
            wait_d( dead_lock_1.Pno, dead_lock_1.Pno, 2);
        }

        //IF DEAD CONDITION EXISTS THE LAST PERSON PICKS THE RIGHT FORK FIRST
        if(dead_cond==1){
            wait_d((q1+i)->Pno, ((q1+i)->Pno+1)%n, -1);
            dead_cond=0;
        }

        //PHILOSOPHERS WHO HAVE PICKED THE LEFT FORK, TRY PICKING THE RIGHT FORK
        for(i=0;i<w_1_end;i++){
            wait_d((w_1+i)->Pno, ((w_1+i)->Pno+1)%n, 2);
            if(run_flag==1){
                for(j=i;j<w_1_end-1;j++){
                    *(w_1+j)=*(w_1+(j+1));
                }
                if(i<w_1_end){
                    w_1_end--, i--;
                }
            }
        }

        //IF ALL THE PHILOSOPHERS ARE DONE EATING, THE LOOP MAY END
        if(q_end==0&&r_end==0&&w_1_end==0&&w_0_end==0&&count1==n&&dead_count==0){
            cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
            cout<<"\n---------------------------------ALL THE PHILOSOPHERS FINISHED EATING--------------------------------------\n";
            cout<<"\n-----------------------------------------------------------------------------------------------------------\n";
            break;
        }

        t1++;
    }
}

//wait_d STATE OF PHILOSOPHERS, TO CHECK IF THE FORKS ARE AVAILABLE OR NOT
void wait_d(int pno, int stick, int flag){
    //TRYING TO PICK THE LEFT FORK
    if(flag==1){
        if((s1+stick)->value==0){
            cout<<"\nPhilosopher "<<pno<<" cannot pick his left fork as Philosopher "<<(pno+n-1)%n<<" is using it.\n";
            *(w_0+w_0_end++)=*(p1+pno);

        }else if((s1+stick)->value==1){
            cout<<"\nPhilosopher "<<pno<<" picked up his left fork.\n";
            *(w_1+w_1_end++)=*(p1+pno);
            (s1+stick)->value=0;
        }
    }
    //TRYING TO PICK THE RIGHT FORK
    else if(flag==2){
        if((s1+stick)->value==1){
            if(dead_count==1){
                dead_lock_1.Pno=-1;
                cout<<"\nPhilosopher "<<pno<<" picked up his left fork and has started eating.\n";
                dead_count=0;
            }else{
                cout<<"\nPhilosopher "<<pno<<" picked up his right fork and has started eating.\n";
            }
            (p1+pno)->start_time=t1;
            *(running+r_end++)=*(p1+pno);
            run_flag=1;
            (s1+stick)->value=0;
        }
        else{
            if(dead_count==1){
                cout<<"\nPhilosopher "<<pno<<" cannot pick his left fork as Philosopher "<<(pno+n-1)%n<<" is using it.\n";
            }else{
                cout<<"\nPhilosopher "<<pno<<" cannot pick his right fork as Philosopher "<<(pno+1)%n<<" is using it.\n";
            }
            run_flag=0;
        }
    }
    //IN DEADLOCK CONDITION, LAST PHILOSOPHER IS TRYING TO PICK THE RIGHT FORK
    else if(flag==-1){
        if((s1+stick)->value==0){
            if(first==1){
                first=0;
                cout<<"\nThe last philosopher tries to pick the right fork first to avoid deadlock, \nbut he cannot pick his right fork as Philosopher "<<(pno+1)%n<<" is using it.\n";
            }else{
                cout<<"\nPhilosopher "<<pno<<" tries to pick his right fork first, but Philosopher "<<(pno+1)%n<<" is using it.\n";
            }
            dead_lock_0=*(p1+pno);
        }else if((s1+stick)->value==1){
            cout<<"\nThe last philosopher, philosopher "<<pno<<" in deadlock state picked up the right fork first.\n";
            dead_lock_1=*(p1+pno);
            dead_lock_0.Pno=-1;
            (s1+stick)->value=0;
        }
    }
    //THE PHILOSOPHERS WHO COUDN'T PICK THEIR LEFT FORK IN PREVIOUS LOOP, TRY PICKING IT AGAIN
    else if(flag==3){
        if((s1+stick)->value==0){
            cout<<"\nPhilosopher "<<pno<<" cannot pick his left fork as Philosopher "<<(pno+n-1)%n<<" is using it.\n";
        }else if((s1+stick)->value==1){
            cout<<"\nPhilosopher "<<pno<<" picked up his left fork.\n";
            *(w_1+w_1_end++)=*(p1+pno);
            (s1+stick)->value=0;
            fork_picked=1;
        }
    }
}

//TO PUT DOWN THE FORKS AFTER EATING
void signal_d(int pno){
    (s1+pno)->value=1;
}
//End of Modules of Dining Philosophers

//Modules of Sleeping Barber
void sleeping_barber()
{
    //initialise variables
    int Total_customers , customers_in_shop ,number_of_seats , c_id;
    int arrival_time[max_customers] , burst_time[max_customers], completion_time[max_customers];
    bool barber = 0;
    set<pair<int,int> > s;
    set<pair<int,int> >::iterator it;
    customers_in_shop = 0;

    //take nuber of seats as input
    cout<<"Enter the number of seats in waiting: ";
    cin>>number_of_seats;
    while(number_of_seats<0)
    {
        cout<<"Number of seats cant be negative"<<endl;
        cout<<"Enter the number of seats in waiting: ";
        cin>>number_of_seats;
    }

    //total number of customers
    cout<<"Enter the total number of Customers: ";
    cin>>Total_customers;
    while(Total_customers<0)
    {
        cout<<"Number of Customers cant be negative"<<endl;
        cout<<"Enter the total number of Customers: ";
        cin>>Total_customers;
    }

    //arrival time input
    cout<<"Enter arrival times"<<endl;
    for(int i=0;i<Total_customers;i++)
    {
        do {
            cout<<"Ariival time of customer"<<i<<"  :";
            cin>>arrival_time[i];
            if(arrival_time[i]<0)
            {
                cout<<"Arrival time can't be negative"<<endl;
            }
        }while(arrival_time[i]<0);
        s.insert({arrival_time[i],i});
        completion_time[i] = -1;
    }

    //burst time input
    cout<<"Enter burst times"<<endl;
    for(int i=0;i<Total_customers;i++)
    {
        do {
            cout<<"time needed for haircut of customer"<<i<<"  :";
            cin>>burst_time[i];
            if(burst_time[i]<0)
            {
                cout<<"time can't be negative"<<endl;
            }
        }while(burst_time[i]<0);
    }

    int time = 0;

    while(!s.empty())
    {
        it = s.begin() ;
        c_id  = (*it).second;
        //check if arrival time > time then barber sleeps
        if(arrival_time[c_id]>=time)
        {
            if(arrival_time[c_id]>time)
            {
                cout<<"At time = "<<time<<" barber is asleep"<<endl;
                time = arrival_time[c_id];
                cout<<"At time = "<<time<<" barber is awake"<<endl;
            }
            cout<<"At time = "<<time<<" Customer C "<<c_id<<" has arrived"<<endl;
        }
        else
        number_of_seats++;
        cout<<"at time = "<<time<<" customer C "<<c_id<<" has started getting haircut "<<endl;

        // check all customers that arrive in this time
        s.erase(it);
        it = s.begin();
        while(it!=s.end())
        {
            pair<int,int> y = *it;
            it++;
            if(y.first>=time&&y.first<time+burst_time[c_id])
            {
                cout<<" At time = "<<y.first<<" Customer C "<<y.second<<" has arrived"<<endl;
                if(number_of_seats<=0) //check for number of seats
                {
                    cout<<" Customer C "<<y.second<<" has no place to sit so he leaves "<<endl;
                    s.erase(y);
                }
                else
                {
                    number_of_seats--;
                    cout<<" Customer C "<<y.second<<" waits "<<endl;
                }
            }

        }
        time+=burst_time[c_id];
        cout<<"at time = "<<time<<" customer C "<<c_id<<" is done getting haircut "<<endl;
        completion_time[c_id] = time;
    }
    //print status
    cout<<"customer | Arrival_time | Completion time"<<endl;
    for(int i=0;i<Total_customers;i++)
    {
        cout<<i<<"\t |"<<arrival_time[i]<<"\t    |";
        if(completion_time[i]!=-1)
        cout<<completion_time[i]<<endl;
        else
        cout<<"Not completed "<<endl;
    }
}

//End of Sleeping Barber


//Start of optimal page replacement algorithm

bool search(int pagenumber, vector<int>& frames)
{
	for (int i = 0; i < frames.size(); i++)
		if (frames[i] == pagenumber)
			return true;
	return false;
}
int futurefind(int page[], vector<int>& frames, int pn, int index)
{
	int res = -1, farthest = index;
	for (int i = 0; i < frames.size(); i++) {
		int j;
		for (j = index; j < pn; j++) {
			if (frames[i] == page[j]) {
				if (j > farthest) {
					farthest = j;
					res = i;
				}
				break;
			}
		}

		if (j == pn)
			return i;
	}
	return (res == -1) ? 0 : res;
}

void optimalalgo(int page[], int pageno, int framesamecount)
{
	vector<int> frames;
	int hit = 0;
	for (int i = 0; i < pageno; i++) {

		if (search(page[i], frames)) {
			hit++;
			continue;
		}
		if (frames.size() < framesamecount)
			frames.push_back(page[i]);
		else {
			int j = futurefind(page, frames, pageno, i + 1);
			frames[j] = page[i];
		}
	}
	cout << "No. of hits = " << hit << endl;
	cout << "No. of misses = " << pageno - hit << endl;
}
void optimalpagereplacement()
{
    int pn;
    cout<<"Enter the number of pagerequests\n";
    cin>>pn;
	int page[pn];
    cout<<"Enter the page requests\n";
    for(i=0;i<pn;i++){
        cin>>page[i];
    }
	int framesamecount;
    cout<<"Enter the number of framesames\n";
    cin>>framesamecount;
	optimalalgo(page, pn, framesamecount);
}
