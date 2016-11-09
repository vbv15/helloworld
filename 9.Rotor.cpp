#include<iostream>
#include<cstring>
class Rt
{
	private:
		struct rotor
		{
			int right[26];
			int left[26];
		}rot;
		char strtext[100],strcode[100];
		int i,j,k,len;
	public:
		void gettext();
		void input_rotor();
		void encrypt();
		void printcode();
		void getcode();
		void decrypt();
		void printtext();
		void rotate_rotor();
	
	
};
void Rt::gettext()
{
	std::cout<<"enter text"<<std::endl;
	std::cin>>strtext;
	len=strlen(strtext);
	std::cout<<"length= "<<len<<std::endl;
}
void Rt::input_rotor()
{
	std::cout<<"enter rotor details"<<std::endl;
	for(i=0;i<=25;++i)
	{
	  rot.left[i]=i;
	  /*std::cout<<"enter right col mapping for left col "<<i;
	  std::cin>>rot.right[i];*/
	  rot.right[i]=(i+1)%25;	
	}
}
void Rt::rotate_rotor()
{
	for(i=0;i<=25;++i)
	{
		rot.right[i]=(rot.right[i]-1+25)%25;
		rot.left[i]=(rot.left[i]-1+25)%25;
	}
	std::cout<<"after rotation"<<rot.left[1]<<"is mapped to "<<rot.right[1]<<std::endl;
}
void Rt::printcode()
{
	std::cout<<"code=  "<<strcode<<std::endl;
}
void Rt::encrypt()
{
	input_rotor();
	gettext();
	for(k=0;k<=len-1;++k)
	{
		std::cout<<"next character "<<strtext[k]<<"value= "<<strtext[k]-97<<std::endl;
		for(j=0;j<=25;++j)
		{
			if(strtext[k]-97==rot.left[j])
			{
				strcode[k]=rot.right[j]+97;
			}
		}
		std::cout<<strtext[k]<<" mapped to "<<strcode[k];
		rotate_rotor();
	}
	printcode();
}
void Rt::getcode()
{
	std::cout<<"code entered";
}
void Rt::printtext()
{
	std::cout<<"text found= "<<strtext<<std::endl;
}
void Rt::decrypt()
{
	input_rotor();
	for(k=0;k<=len-1;++k)
	{
		std::cout<<"next code "<<strcode[k]<<"value= "<<strcode[k]-97<<std::endl;
		for(j=0;j<=25;++j)
		{
			if(strcode[k]-97==rot.right[j])
			{
				strtext[k]=rot.left[j]+97;
			}
		}
		std::cout<<strcode[k]<<" mapped to "<<strtext[k];
		rotate_rotor();
	}
	printtext();
}
int main()
{
	Rt r;
	r.encrypt();
	r.decrypt();
	
	return 0;
}
