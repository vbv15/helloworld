#include<iostream>
#include<cstring>
class vinr
{
  private:
      char strcode[100],strtext[100];
     int len,i,j,k,keylength,pos1[10],pos2[10],diffn[10],temp,max;
     char key[50];

public:
     void read_key();
     void read_text();
     void encrypt();
     void print_code();
     void read_code();
     int gcd(int a,int b);
     void analyse();



};
void vinr::read_key()
{

  len=0;

  std::cout<<"enter the key";
     std::cin>>key;
     keylength=strlen(key);
     std::cout<<"keylength=  "<<keylength<<std::endl;

  std::cout<<"key is "<<key<<std::endl;
  
}
void vinr::read_text()
{
  std::cout<<"Enter text   "<<std::endl;
 std::cin>>strtext;
 len=strlen(strtext);

}
void vinr::encrypt()
{
  j=0;
  for(i=0;i<=len-1;++i)
  {
    std::cout<<key[j];
    strcode[i]=(((strtext[i]-97)+(key[j]-97))%26)+97;
    j=(j+1)%keylength;
  }

}
void vinr::print_code()
{
  std::cout<<"code=  "<<strcode;
}
void vinr::read_code()
{
  std::cout<<"enter code=   ";
  //std::cin>>strcode;
}
int vinr::gcd(int a,int b)
{
	int r1,r2,r,q;
	r1=a;
	r2=b;
	while(r2>0)
	{
		q=r1/r2;
		r=r1-q*r2;
		r1=r2;
		r2=r;
	}
	std::cout<<"gcd=   "<<r1<<std::endl;
    return r1;
}
void vinr::analyse()
{
	len=strlen(strcode);
	max=999;
	for(i=0;i<=len-1;++i)
	{
       k=i+1;
       while(k<=len-1)
       {
         if(strcode[i]==strcode[k] && strcode[i+1]==strcode[k+1] && strcode[i+2]==strcode[k+2])
         {
         	pos1[j]=i;
         	pos2[j]=k;
         	diffn[j]=k-i;
         	std::cout<<"pos1=   "<<i<<"pos2=   "<<k<<"diff= "<<diffn[j]<<"j==  "<<j<<"temp=  "<<temp<<"max= "<<max<<std::endl;
         	if(j<=0)
             temp=999;
             else if(j==1)
              temp=gcd(diffn[0],diffn[1]);
            else
           	temp=gcd(temp,diffn[j]);
           	
         	if(max>temp)
         	max=temp;
         	++j;
		 }
		 k++;
	   }
	 }
		
    	
	std::cout<<"keylength according to kasiski test=  "<<max;
}


 int main()
 {
  vinr r;
  r.read_key();
  r.read_text();
  r.encrypt();
  r.print_code();
  r.read_code();
  r.analyse();
    return 0;
 }
