#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
class ST
{
	private:
		char strtext[100],strcode[100],key[100];
		int len,i,k,d,shift_register[100];
		
	public:
		
		void gettext();
		void generate_random();
		void encrypt();
		void printcode();
		void getcode();
		void decrypt();
		void printtext();	
	
	
};
void ST::gettext()
{
	std::cout<<"enter text";
	std::cin>>strtext;
	len=strlen(strtext);
	
}
void ST::generate_random()
{
	shift_register[5]=shift_register[0]^shift_register[2]^shift_register[3];
	d=shift_register[5];
	for(i=0;i<5;++i)
	{
		shift_register[(i+1)%4]=shift_register[i];
	}
	for(i=0;i<5;++i)
	{
		std::cout<<" shift reg "<<i<<" = "<<shift_register[i];
	}
}
void ST::encrypt()
{
	shift_register[0]=1;
    shift_register[1]=0;
    shift_register[2]=0;
    shift_register[3]=1;
    
	for(k=0;k<=len-1;++k)
	{
		generate_random();
		key[k]=d;
		strcode[k]=strtext[k]^key[k];
	}
}
void ST::printcode()
{
	std::cout<<"code=   "<<strcode;
}
void ST::getcode()
{
	std::cout<<"code entered";
}
void ST::decrypt()
{
	for(i=0;i<=len-1;++i)
	{
		strtext[i]=strcode[i]^key[i];
	}
}
void ST::printtext()
{
	std::cout<<"text=   "<<strtext;
}
int main()
{
	ST t;
	t.gettext();
	t.encrypt();
	t.printcode();
	t.getcode();
	t.decrypt();
	t.printtext();
}
