#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
class mno_alph
{
  private:
      char strcode[100],strtext[100];
     int len,i,j;
     char lettertext[30],key[30];

public:
     void encrypt();
     void decrypt();



};
void mno_alph::encrypt()
{
   strcpy(strtext,"   ");
  strcpy(strcode,"    ");
  len=0;
  cout<<"enter key "<<endl;
  for(i=0;i<=25;++i)
  {
   lettertext[i]=toascii(i+97);
   cout<<"enter key for "<<lettertext[i];
   cin>>key[i];

  }
 cout<<"Enter text   "<<endl;
 cin>>strtext;
 len=strlen(strtext);

 for(i=0;i<=len-1;++i)
 {
    for(j=0;j<=25;++j)
    {
     if(strtext[i]==lettertext[j])
     {
       strcode[i]=key[j];
     }
    }
 }
 cout<<"code=   "<<strcode<<endl;

 }
void mno_alph::decrypt()
{
 cout<<"Enter code   "<<endl;
 cin>>strcode;
 len=strlen(strcode);

 for(i=0;i<=len-1;++i)
 {
    for(j=0;j<=25;++j)
    {
     if(strcode[i]==key[j])
     {
       strtext[i]=lettertext[j];
     }
    }
 }
 cout<<"code=   "<<strtext<<endl;

 }
 void main()
 {
  mno_alph m;
  m.encrypt();
  m.decrypt();
  getch();
 }