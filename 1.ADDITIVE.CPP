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
    strcode[i]=(((strtext[i]-97)+key)%26)+97;
    }
 cout<<"code=   "<<strcode<<endl;

 }
void decrypt()
{
 char strcode[100],strtext[100];
 int len,key1,key2,i;
 strcpy(strtext,"    ");
 cout<<"Enter code   "<<endl;
 cin>>strcode;
 cout<<"you entered  "<<strcode<<endl;
 cout<<"enter key  "<<endl;
 cin>>key1;

 len=strlen(strcode);
 cout<<"length=   "<<len;

 key2=26-key1;
 for(i=0;i<=len-1;++i)
 {
    strtext[i]=(((strcode[i]-97)+key2)%26)+97;
    }
 cout<<"text=   "<<strtext<<endl;

 }
 void main()
 {
  encrypt();
  decrypt();
  getch();
 }