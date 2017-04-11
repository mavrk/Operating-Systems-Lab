#include<iostream>
#include<process.h>



using namespace std;

struct data
{
    int jno,slot,s,e;
};

struct dataslot
{
    int freemem,s,e;
};

data status[1000];
dataslot slot[1000];

int n=0,sn=0;

void inp(void)
{
    int jn,mem;
    cout<<"enter process no and memory required.\n";
    cin>>jn>>mem;
    if(mem>500) {
        cout<<"no free mem \n";
        return ;
    }
    if(sn<4){
        switch(sn){
            case 0:slot[sn].s=0+mem,slot[sn].e=499;
                    break;
            case 1:slot[sn].s=500+mem,slot[sn].e=999;
                    break;
            case 2:slot[sn].s=1000+mem,slot[sn].e=1499;
                    break;
            case 3:slot[sn].s=1500+mem,slot[sn].e=1999;
                    break;

        }
        slot[sn].freemem=500-mem;
        status[n].slot=sn;
        status[n].jno=jn;
        status[n].s=slot[sn].s-mem;
        status[n].e=slot[sn].s;
        sn++,n++;

    }
    else{
        int i;
        for(i=0;i<sn;i++)
            if(slot[i].freemem>=mem) break;
        if(i==sn) return;
        slot[i].freemem-=mem;
        status[n].slot=i;
        status[n].jno=jn;
        status[n].s=slot[i].s;
        status[n].e=slot[i].s+mem;
        slot[i].s+=mem;
        n++;
    }
}


void disp(void)
{
    int i;
    cout<<"\nStatus:\n";
    for(i=0;i<n;i++){
        cout<<"%d %d %d %d\n",status[i].jno,status[i].slot,status[i].s,status[i].e;
    }
    cout<<"\n";
}


void copydata(data &temp,data &a)
{
    temp.jno=a.jno;
    temp.slot=a.slot;
    temp.s=a.s;
    temp.e=a.e;
}


void del()
{
    int jn,i,j;
    cout<<"Enter process number which is to be removed \n";
    cin>>jn;
    for(i=0;i<n;i++) if(status[i].jno==jn) break;
    if(i==n){
        cout<<"Process not found\n";
        return;
    }
    data temp;
    copydata(temp,status[i]);
    for(j=i;j<n-1;j++)
        copydata(status[j],status[j+1]);
    n--;
    for(i=0;i<sn;i++){
        if(slot[i].s-temp.e<=1){
            slot[i].s=temp.s;
            slot[i].freemem=temp.e-temp.s + 1;
            cout<<"Free memory"<<slot[i].freemem<<endl;
            return;
        }
    }
    slot[sn].freemem=temp.e-temp.s;
    slot[sn].s=temp.s;
    slot[sn].e=temp.e;
    sn++;
}

int main()
{
    int c;
    while(1){
        cout<<"Enter choice \n1. Insert process\n2. Delete process\n3. Exit\n";
        cin>>c;
        switch(c)
        {
            case 1:inp();
                        break;
            case 2:del();
                        break;
            case 3:exit(0);
        }
        disp();
    }
    return 0;
}
