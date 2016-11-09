#include<iostream.h>
#include<conio.h>
#include<string.h>
class affi_ci
{
  private:
      char strcode[100],strtext[100];
     int len,keya,keyb,i,keya2,keyb2;
     int r1,r2,r,t1,t2,t,q;

public:
     affi_ci();
     void encrypt();
     void decrypt();



};
void affi_ci::affi_ci()
{
  strcpy(strtext,"   ");
  strcpy(strcode,"    ");
  len=0;
  keya=keyb=keya2=keyb2=0;

}
void affi_ci::encrypt()
{
 cout<<"Enter text   "<<endl;
 cin>>strtext;
 len=strlen(strtext);
 cout<<"enter key1  "<<endl;
 cin>>keya;
 cout<<"enter key2  "<<endl;
 cin>>keyb;
 for(i=0;i<=len-1;++i)
 {
    strcode[i]=((((strtext[i]-97)*keyb)+keya)%26)+97;
    }
 cout<<"code=   "<<strcode<<endl;

 }
void affi_ci::decrypt()
{

 strcpy(strtext,"    ");
 cout<<"Enter code   "<<endl;
 cin>>strcode;
 cout<<"you entered  "<<strcode<<endl;
 cout<<"enter key1  "<<endl;
 cin>>keya;
 cout<<"enter key2  "<<endl;
 cin>>keyb;
 r1=26;
 r2=keyb;
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
   if(r1==1) keyb2=t1;
   if(keyb2<0){ keyb2=keyb2+26; }
   cout<<"inverse key2=   "<<keyb2;
   keya2=26-keya;
 len=strlen(strcode);
 cout<<"length=   "<<len;


 for(i=0;i<=len-1;++i)
 {
    strtext[i]=((((strcode[i]-97)+keya2)*keyb2)%26)+97;
    }
 cout<<"text=   "<<strtext<<endl;

 }
 void main()
 {
  affi_ci ac;
  ac.encrypt();
  ac.decrypt();
  getch();
 }