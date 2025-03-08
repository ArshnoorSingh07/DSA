#include<iostream>
using namespace std;
int main(){
    int triplet[50][3],columnmajor[50][3];
    int row,col,nzero,temp=1;
    cout<<"Enter non zero elements:";
    cin>>nzero;
    cout<<"Enter the matrix"<<endl;
    for(int i=0;i<nzero+1;i++){
        for(int j=0;j<3;j++){
            cin>>triplet[i][j];
        }
    }
    row=triplet[0][0];
    col=triplet[0][1];
    columnmajor[0][0]=col;
    columnmajor[0][1]=row;
    columnmajor[0][2]=nzero;

     for(int j=0;j<col;j++){
        for(int i=1;i<nzero+1;i++){
            if(triplet[i][1]==j){
                columnmajor[temp][0]=j;
                columnmajor[temp][1]=triplet[i][0];
                columnmajor[temp][2]=triplet[i][2];
                temp++;
            }
            cout<<endl;
        }
    }
    cout<<"sparse matrix is:"<<endl;
    for(int i=0;i<nzero+1;i++){
        for(int j=0;j<3;j++){
            cout<<triplet[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
     for(int i=0;i<nzero+1;i++){
        for(int j=0;j<3;j++){
            cout<<columnmajor[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}