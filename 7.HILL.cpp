#include<iostream>
#include<cstring>
#include<cctype>
#include<cmath>
class hl
{
  private:
      char strcode[100],strtext[100],strkey[100];
     int len,i,j,m,n,keylength,k,d,d2;
     char lettertext[30],key[3][3],t_mat[3][3],c_mat[3][3],k_mat[3][3];
	 int temp[3][3],r1,r2,t1,t2,q,r,t,tmp[3][3];

public:
    void gettext();
    void puttext_in_matrix();
    void getkey();
    void putkey_in_matrix();
    void matrix_multiplication();
    void encrypt();
    void printcode();
    void getcode();
    void putcode_in_matrix();
    void find_determinant();
    void determinant_inverse();
    void find_cofactor_matrix();
    void find_transpose();
    void inversematrix_multiplication();
    void printtext();
    void decrypt();


};
void hl::gettext()
{
	std::cout<<"enter text of 9 letters";
	std::cin>>strtext;
	len=strlen(strtext);
 } 
 void hl::puttext_in_matrix()
{
	
	k=0;
	if(len>9)
	{
		std::cout<<"insufficient matrix space ";
	}
	else
	{
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				if(k<len)
				{
					t_mat[i][j]=strtext[k]-97;
					++k;
				}
				else
				{
					t_mat[i][j]='x'-97;
				}
			}
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<"text matrix "<<t_mat[i][j]+97;
		}
		std::cout<<std::endl;
	}
}
void  hl::getkey()
{
	std::cout<<"enter key of 9 letters";
	std::cin>>strkey;
	keylength=strlen(strkey);
}
void hl::putkey_in_matrix()
{

	if(keylength>9)
	{
		std::cout<<"insufficient matrix size";
		
	}
	else
	{
		k=0;
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				if(k<keylength)
				{
					k_mat[i][j]=strkey[k]-97;
					++k;
				}
				else
				{
					k_mat[i][j]='x'-97;
				}
			}
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<"key matrix "<<k_mat[i][j]+97;
		}
		std::cout<<std::endl;
	}
}
void hl::matrix_multiplication()
{
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			c_mat[i][j]=0;
			for(k=0;k<3;++k)
			{
				c_mat[i][j]=(c_mat[i][j]+t_mat[i][k]*k_mat[k][j])%26;
			}
            
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<"code matrix  "<<c_mat[i][j]+97;
		}
		std::cout<<std::endl;
	}
}
void hl::printcode()
{
	k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			strcode[k]=c_mat[i][j]+97;
			++k;
		}
	}
	std::cout<<"code=   "<<strcode<<std::endl;
}
void hl::encrypt()
{
	gettext();
	puttext_in_matrix();
	getkey();
	putkey_in_matrix();
	matrix_multiplication();
	printcode();
}

void  hl::getcode()
{
	std::cout<<"code copied from encrypt result";
}
void hl::putcode_in_matrix()
{
	
	k=0;
	if(len>9)
	{
		std::cout<<"insufficient matrix space ";
	}
	else
	{
		for(i=0;i<3;++i)
		{
			for(j=0;j<3;++j)
			{
				if(k<len)
				{
					c_mat[i][j]=strcode[k]-97;
					++k;
				}
				else
				{
					c_mat[i][j]='x'-97;
				}
			}
		}
	}
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<"code matrix"<<c_mat[i][j]+97;
		}
		std::cout<<std::endl;
	}
}
void hl::find_determinant()
{
   temp[0][0]=k_mat[1][1]*k_mat[2][2]-k_mat[2][1]*k_mat[1][2];
   temp[0][1]=k_mat[1][0]*k_mat[2][2]-k_mat[2][0]*k_mat[1][2];
   temp[0][2]=k_mat[1][0]*k_mat[2][1]-k_mat[2][0]*k_mat[1][1];
   d=(k_mat[0][0]*temp[0][0]-k_mat[0][1]*temp[0][1]+k_mat[0][2]*temp[0][2]);
   std::cout<<"det before mod"<<d;
   if(d<0)
   {
   	d=-(d);
   	d=d%26;
   	d=26-d;
   }
   else
   {
      d=d%26;
  }
   
   std::cout<<"determinant= "<<d;
}


void hl::determinant_inverse()
{
 r1=26;
 r2=d;
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
   if(r1==1) d2=t1;
   if(d2<0){ d2=d2+26; }
   std::cout<<"inverse determinant=   "<<d2<<std::endl;
 
}
void hl::find_cofactor_matrix()
{
   temp[0][0]=(k_mat[1][1]*k_mat[2][2]-k_mat[2][1]*k_mat[1][2]);
   temp[0][1]=-(k_mat[1][0]*k_mat[2][2]-k_mat[2][0]*k_mat[1][2]);
   temp[0][2]=(k_mat[1][0]*k_mat[2][1]-k_mat[2][0]*k_mat[1][1]);
   temp[1][0]=-(k_mat[0][1]*k_mat[2][2]-k_mat[2][1]*k_mat[0][2]);
   temp[1][1]=(k_mat[0][0]*k_mat[2][2]-k_mat[2][0]*k_mat[0][2]);
   temp[1][2]=-(k_mat[0][0]*k_mat[2][1]-k_mat[2][0]*k_mat[0][1]);
   temp[2][0]=(k_mat[0][1]*k_mat[1][2]-k_mat[1][1]*k_mat[0][2]);
   temp[2][1]=-(k_mat[0][0]*k_mat[1][2]-k_mat[1][0]*k_mat[0][2]);
   temp[2][2]=(k_mat[0][0]*k_mat[1][1]-k_mat[1][0]*k_mat[0][1]);
}

/*
   Transpose of a square matrix, do it in place
*/
void hl::find_transpose()
{

   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         tmp[i][j] = temp[j][i];
      }
   }
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         temp[i][j] = tmp[i][j];
      }
   }
   for (i=0;i<3;i++) {
      for (j=0;j<3;j++) {
         if(temp[i][j]<0)
         {
         	temp[i][j]=-(temp[i][j]);
         	temp[i][j]=temp[i][j]%26;
         	temp[i][j]=26-temp[i][j];
		 }
		 else
		 {
		 	temp[i][j]=temp[i][j]%26;
		 }
      }
   }
   std::cout<<"inverse matrix "<<std::endl;
   for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			temp[i][j]=(temp[i][j]*d2)%26;
			std::cout<<temp[i][j]<<"   ";
		}
		std::cout<<std::endl;
	}
}
void hl::inversematrix_multiplication()
{
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			t_mat[i][j]=0;
			for(k=0;k<3;++k)
			{
				t_mat[i][j]=(t_mat[i][j]+c_mat[i][k]*temp[k][j])%26;
			}
		}
	}
}
void hl::printtext()
{
	k=0;
	for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			strtext[k]=t_mat[i][j]+97;
			++k;
		}
	}
	std::cout<<"text=   "<<strtext<<std::endl;
}
void hl::decrypt()
{
	getcode();
	putcode_in_matrix();
	find_determinant();
	determinant_inverse();
	find_cofactor_matrix();
	find_transpose();
	inversematrix_multiplication();
	printtext();
}
 int main()
 {
  hl h;
  h.encrypt();
  h.decrypt();
  return 0;
 }
