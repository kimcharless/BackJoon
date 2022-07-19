#include <bits/stdc++.h>
using namespace std;

bool arr[10][10];
bool temp[10][10];
int answer = 9999999;
bool str[10];
int x[4] = {-1,0,1,0};
int y[4] = {0,1,0,-1};
int dum;

void click(int a,int b){
    temp[a][b] = !temp[a][b];
    //printf("[%d,%d] : %d -> %d\n",a,b,temp[a][b],!temp[a][b]);
    for(int i=0;i<4;i++){
        int ta = a + x[i],tb = b + y[i];
        if(ta > -1 && ta < 10 && tb > -1 && tb < 10){
            //printf("[%d,%d] : %d -> %d\n",ta,tb,temp[ta][tb],!temp[ta][tb]);
            temp[ta][tb] = !temp[ta][tb];
            
        }
    }
}

void show(){
    cout<<endl;
    Sleep(1000);
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<temp[i][j];
        }cout<<endl;
    }
}

bool check(){
    int num = 0;
    
    //show();
    for(int i=0;i<9;i++){
        for(int j=0;j<10;j++){
            if(temp[i][j] == true){
                //cout<<"click!"<<endl<<endl;
                click(i+1,j);
                //show();
                num = num + 1;
            }
        }
    }
    for(int j=0;j<10;j++){
        if(temp[9][j]) return false;
    }
    num = num + dum;
    if(num < answer) answer = num;
    return true;
}
bool check2(){
    int num = 0;
    
    show();
    for(int i=0;i<9;i++){
        for(int j=0;j<10;j++){
            if(temp[i][j] == true){
                cout<<"click!"<<endl<<endl;
                click(i+1,j);
                show();
                num = num + 1;
            }
        }
    }
    for(int j=0;j<10;j++){
        if(temp[9][j]) return false;
    }
    num = num + dum;
    if(num < answer) answer = num;
    return true;
}


void dfs(int K){
    if(K == 10){
        dum = 0;
        copy(&arr[0][0] , &arr[0][0] + 100,&temp[0][0]);
        //show();
        //cout<<"go"<<endl;
        for(int i=0;i<10;i++){if(str[i]){click(0,i);dum++;}}
        //show();
        //cout<<"this"<<endl;
        if(check()){
            dum = 0;
            copy(&arr[0][0] , &arr[0][0] + 100,&temp[0][0]);
            for(int i=0;i<10;i++){if(str[i]){click(0,i);dum++;}}
            cout<<dum<<endl;
            //check2();
        }
        //show();
        //cout<<check();
        //Sleep(6000);
        return;
    }
    dfs(K+1);
    str[K] = str[K] == 0 ? 1 : 0;
    dfs(K+1);
    str[K] = str[K] == 0 ? 1 : 0;
}


int main(){
    char K;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
           cin>>K;
           arr[i][j] = (K=='#') ? false : true; 
        }
    }


    dfs(0);
    if(answer == 9999999) cout<<"-1";
    else cout<<answer;
    
    return 0;
}