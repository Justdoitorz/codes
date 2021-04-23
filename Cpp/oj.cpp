#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;
char a[10],b[10];int n,j;
int main(){
    scanf("%d",&n);
for (int i=1;i<=n;i++){
scanf("%s%s",a,b);
j=strcmp(a,b);
if ((a=="Paper")&&(b=="Scissor")) cout<<"Player2";
else if ((b=="Paper")&&(a=="Scissor")) cout<<"Player1";
else if (j==1) cout<<"Player2";
else if (j==-1) cout<<"Player1";
else if (j==0) cout<<"Tie";
cout<<endl;
a[0]='\0';b[0]='\0';
}
return 0;}
