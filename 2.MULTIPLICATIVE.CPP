#include<iostream.h>
#include<conio.h>
#include<string.h>
void encrypt()
{
 char strcode[100],strtext[100];
 int len,key,i;

 cout<<"Enter text   "<<endl;
 cin>>strtext;
 len=strlen(strtext);
 cout<<"enter key  "<<endl;
 cin>>key;
 for(i=0;i<=len-1;++i)
 {
    strcode[i]=(((strtext[i]-97)*key)%26)+97;
    }
 cout<<"code=   "<<strcode<<endl;

 }
void decrypt()
{
 char strcode[100],strtext[100];
 int len,key1,key2,i;
 int r1,r2,r,t1,t2,t,q;
 strcpy(strtext,"    ");
 cout<<"Enter code   "<<endl;
 cin>>strcode;
 cout<<"you entered  "<<strcode<<endl;
 cout<<"enter key  "<<endl;
 cin>>key1;
 r1=26;
 r2=key1;
 t1=0;
 t2=1;
 while(r2>0)
 {
   q=r1/r2;

   r=r1-q*r2;
   r1=r2;
   r2=r;

   t=t1-q*t2;
   t1=t2;
   t2=t;
   }
   if(r1==1) key2=t1;
   if(key2<0){ key2=key2+26; }
   cout<<"inverse key=   "<<key2;
 len=strlen(strcode);
 cout<<"length=   "<<len;


 for(i=0;i<=len-1;++i)
 {
    strtext[i]=(((strcode[i]-97)*key2)%26)+97;
    }
 cout<<"text=   "<<strtext<<endl;

 }
 void main()
 {
  encrypt();
  decrypt();
  getch();
 }