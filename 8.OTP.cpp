#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
class OTP
{
	private:
		char strtext[100],strcode[100];
		int key[100],len,i,d;
		
	public:
		
		void gettext();
		void generate_random();
		void encrypt();
		void printcode();
		void getcode();
		void decrypt();
		void printtext();	
	
	
};
void OTP::gettext()
{
	std::cout<<"enter text";
	std::cin>>strtext;
	len=strlen(strtext);
	
}
void OTP::generate_random()
{
	d=rand()%15;
}
void OTP::encrypt()
{
	for(i=0;i<=len-1;++i)
	{
		generate_random();
		key[i]=d;
		strcode[i]=strtext[i]^key[i];
	}
}
void OTP::printcode()
{
	std::cout<<"code=   "<<strcode;
}
void OTP::getcode()
{
	std::cout<<"code entered";
}
void OTP::decrypt()
{
	for(i=0;i<=len-1;++i)
	{
		strtext[i]=strcode[i]^key[i];
	}
}
void OTP::printtext()
{
	std::cout<<"text=   "<<strtext;
}
int main()
{
	OTP t;
	t.gettext();
	t.encrypt();
	t.printcode();
	t.getcode();
	t.decrypt();
	t.printtext();
}
