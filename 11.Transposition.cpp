#include<iostream>
#include<cstring>
class Tr
{
	
   private:
         char strtext[100],strcode[100],strkey[100];
		 int i,j,k,len;
		 char str_mat[3][3],code_mat[3][3],temp[3][3];
		 int key_mat[3][3];
	public:
	
	      void gettext();
		  void puttextinmatrix();
		  void getkey();
		  void putkeyinmatrix();
		  void matrix_multiplication();
		  void encrypt();
		  void printcode();
		  
		  void getcode();
		  void putcodeinmatrix();
		  void getinversekey();
		  void putinversekeyinmatrix();
		  void inverse_multiplication();
		  void decrypt();
		  void printtext();	
	
};
void Tr::gettext()
{
	std::cout<<"enter  9 char text";
	std::cin>>strtext;
	len=strlen(strtext);
}
void Tr::puttextinmatrix()
{
	k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			str_mat[i][j]=strtext[k]-97;
			++k;
		}
	}
	std::cout<<"text matrix  "<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<str_mat[i][j]<<"  ";
		}
		std::cout<<std::endl;
	}
}
void Tr::getkey()
{
	std::cout<<"enter  9 char key";
	std::cin>>strkey;
}
void Tr::putkeyinmatrix()
{
	k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			key_mat[i][j]=strkey[k]-48;
			++k;
		}
	}
	std::cout<<"key matrix  "<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<key_mat[i][j]<<"  ";
		}
		std::cout<<std::endl;
	}
}
void Tr::matrix_multiplication()
{
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			code_mat[i][j]=0;
			for(k=0;k<3;++k)
			{
				code_mat[i][j]=(code_mat[i][j]+str_mat[i][k]*key_mat[k][j]);
			}
		}
	}
}
void Tr::printcode()
{
k=0;
	for(j=0;j<3;++j)
	{
		for(i=0;i<3;++i)
		{
			strcode[k]=code_mat[i][j]+97;
			++k;
		}
	}
	std::cout<<"code=   "<<strcode<<std::endl;	
}
void Tr::encrypt()
{
	gettext();
	puttextinmatrix();
	getkey();
	putkeyinmatrix();
	matrix_multiplication();
	printcode();
}
void Tr::getcode()
{
	std::cout<<"code entered ";
}
void Tr::putcodeinmatrix()
{
	k=0;
	for(j=0;j<3;++j)
	{
		for(i=0;i<3;++i)
		{
			code_mat[i][j]=strcode[k]-97;
			++k;
		}
	}
	std::cout<<"code matrix  "<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<code_mat[i][j]<<"  ";
		}
		std::cout<<std::endl;
	}
}
void Tr::getinversekey()
{
	std::cout<<"enter  9 char inverse key";
	std::cin>>strkey;
}
void Tr::putinversekeyinmatrix()
{
	k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			key_mat[i][j]=strkey[k]-48;
			++k;
		}
	}
	std::cout<<"inverse key matrix  "<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<key_mat[i][j]<<"  ";
		}
		std::cout<<std::endl;
	}
}
void Tr::inverse_multiplication()
{
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			str_mat[i][j]=0;
			for(k=0;k<3;++k)
			{
				str_mat[i][j]=(str_mat[i][j]+code_mat[i][k]*key_mat[k][j]);
			}
		}
	}
}
void Tr::printtext()
{
k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			strtext[k]=str_mat[i][j]+97;
			++k;
		}
	}
	std::cout<<"code=   "<<strtext<<std::endl;	
}
void Tr::decrypt()
{
	getcode();
	putcodeinmatrix();
	getinversekey();
	putinversekeyinmatrix();
	inverse_multiplication();
	printtext();
}

int main()
{
	Tr t;
	t.encrypt();
	t.decrypt();
	return 0;
}
