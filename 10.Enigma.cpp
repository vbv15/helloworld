#include<iostream>
#include<cstring>
#include<cstdlib>
class Eg
{
	private:
		struct rotor
		{
			int right[26];
			int left[26];
		}rot[3];
		char strtext[100],strcode[100],startletters[3];
		int i,j,k,len,p,temp1,temp2,temp3;
	public:
		void gettext();
		void input_rotors();
		void getinitialletters();
	    void setinitialletters();
	    void encrypt();
		void printcode();
		void printrotors();
		
		void getcode();
		void decrypt();
		void printtext();
		void rotate_rotor();
	
	
};
void Eg::gettext()
{
	std::cout<<"enter text"<<std::endl;
	std::cin>>strtext;
	len=strlen(strtext);
	std::cout<<"length= "<<len<<std::endl;
}
void Eg::input_rotors()
{
	std::cout<<"enter rotor details"<<std::endl;
	for(j=0;j<3;++j)
	{
	
	for(i=0;i<=25;++i)
	{
		
	       rot[j].left[i]=i;
	   	  rot[j].right[i]=(i+1)%25;	
	}
	}	
}
void Eg::printrotors()
{
	std::cout<<"print rotor details"<<std::endl;
	for(j=0;j<3;++j)
	{
	
	for(i=0;i<=25;++i)
	{
	  std::cout<<" rotor "<<j<<" left  "<<rot[j].left[i]<<" right  "<<rot[j].right[i]<<std::endl;	
	}
	}      
}
void Eg::getinitialletters()
{
	std::cout<<"input 3 initial letters";
	std::cin>>startletters;
}
void Eg::setinitialletters()
{
  for(j=0;j<3;++j)
  {
	while(rot[j].right[0]!=startletters[j]-97)
	{
		rotate_rotor();
	}
  }
std::cout<<"rotors set to "<<rot[0].right[0]<<"     "<<rot[1].right[0]<<"   "<<rot[2].right[0]<<std::endl;	
}
void Eg::rotate_rotor()
{
	std::cout<<" rotor rotated "<<std::endl;
	for(i=0;i<=25;++i)
	{
		rot[j].right[i]=(rot[j].right[i]-1+25)%25;
		rot[j].left[i]=(rot[j].left[i]-1+25)%25;
	}
	std::cout<<"after rotation"<<rot[j].left[1]<<"is mapped to "<<rot[j].right[1]<<std::endl;
}
void Eg::printcode()
{
	std::cout<<"code=  "<<strcode<<std::endl;
}
void Eg::encrypt()
{
	input_rotors();
	getinitialletters();
	setinitialletters();
	gettext();
	printrotors();
	for(k=0;k<=len-1;++k)
	{
		std::cout<<"next character "<<strtext[k]<<"value= "<<strtext[k]-97<<std::endl;
		std::cout<<" mapping 1  ";
		p=0;
		temp1=0;
		while(p<=25 && temp1==0)
		{
			if(strtext[k]-97==rot[0].right[p])
			{
				temp1=rot[0].left[p];
				std::cout<<temp1<<" mapping 2  ";
			}
			++p;
		}
		p=0;
		temp2=0;
		while(p<=25 && temp2==0)
		{
			if(temp1==rot[1].right[p])
			{
				temp2=rot[1].left[p];
				std::cout<<temp2<<"mapping 3 ";
			}
			++p;
		}
		p=0;
		temp3=0;
		while(p<=25 && temp3==0)
		{
			if(temp2==rot[2].right[p])
			{
				strcode[k]=rot[2].left[p]+97;
				temp3=rot[2].left[p];
				std::cout<<strcode[k]<<std::endl;;
			}
			++p;
		}
		if(k<25)
		{
		 j=0;
		  rotate_rotor();}
		else if(k>25 && k<625)
		{
			j=1;
			rotate_rotor();
		}
		else if(k>625)
		{
			j=2;
			rotate_rotor();
		}
	} 
	printcode();
}
void Eg::getcode()
{
	std::cout<<"code entered";
}
void Eg::printtext()
{
	std::cout<<"text found= "<<strtext<<std::endl;
}
void Eg::decrypt()
{
	input_rotors();
	getinitialletters();
	setinitialletters();
	getcode();
	printrotors();
	for(k=0;k<=len-1;++k)
	{
		std::cout<<"next character "<<strcode[k]<<"value= "<<strcode[k]-97<<std::endl;
		std::cout<<" inverse mapping 1  ";
		p=0;
		temp1=0;
		while(p<=25 && temp1==0)
		{
			if(strcode[k]-97==rot[2].left[p])
			{
				temp1=rot[2].right[p];
				std::cout<<temp1<<" inverse mapping 2  ";
			}
			++p;
		}
		p=0;
		temp2=0;
		while(p<=25 && temp2==0)
		{
			if(temp1==rot[1].left[p])
			{
				temp2=rot[1].right[p];
				std::cout<<temp2<<" inverse mapping 3 ";
			}
			++p;
		}
		p=0;
		temp3=0;
		while(p<=25 && temp3==0)
		{
			if(temp2==rot[0].left[p])
			{
				strtext[k]=rot[0].right[p]+97;
				temp3=rot[0].right[p];
				std::cout<<strtext[k]<<std::endl;;
			}
			++p;
		}
		if(k<25)
		{
		 j=0;
		  rotate_rotor();}
		else if(k>25 && k<625)
		{
			j=1;
			rotate_rotor();
		}
		else if(k>625)
		{
			j=2;
			rotate_rotor();
		}
	}
	printtext();
}
int main()
{
	Eg e;
	e.encrypt();
	e.decrypt();
	
	return 0;
}
