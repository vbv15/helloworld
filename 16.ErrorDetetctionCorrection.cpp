#include<iostream>
#include<cstdlib>
class Ed
{
	private:
		int hparity_mat[3][6],code_mat[8][6],message_mat[8][3],generator_mat[3][6];
		int standard_mat[8][8][6],htranspose_mat[6][3],temp[3][6],countone;
		int r[1][6],v[1][6],e[1][6],s[1][3],i,j,k,min,col,found;
	public:
		void getparitymatrix();
		void printgeneratormatrix();
		void printcodematrix();
		void inputmessagematrix();
		void inputcodevector();
		void inputreceivedvector();
		void printcodeweight();
		void findhtranspose();
		void printsyndrome();
		void printstandardarray();
		void finderror();
		void matrix_multiplication();
		int integerxor(int x,int y);
		
};
void Ed::getparitymatrix()
{
	std::cout<<"enter parity matrix";
	for(i=0;i<3;++i)
	{
		for(j=0;j<6;++j)
		{
			std::cin>>hparity_mat[i][j];
		}
	}
	std::cout<<"parity matrix"<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<6;++j)
		{
			std::cout<<hparity_mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Ed::printgeneratormatrix()
{
	for(i=0;i<3;++i)
	{
		for(j=3;j<6;++j)
		{
			if(i==j-3)
			 generator_mat[i][j]=1;
			 else
			 generator_mat[i][j]=0;
		}
	}
		for(i=0;i<3;++i)
	{
		for(j=0;j<3;++j)
		{
			generator_mat[j][i]=hparity_mat[i][j+3];
		}
	}
	std::cout<<"generator matrix"<<std::endl;
	for(i=0;i<3;++i)
	{
		for(j=0;j<6;++j)
		{
			std::cout<<generator_mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Ed::inputmessagematrix()
{
	message_mat[0][0]=0;message_mat[0][1]=0;message_mat[0][2]=0;
	message_mat[1][0]=0;message_mat[1][1]=0;message_mat[1][2]=1;
	message_mat[2][0]=0;message_mat[2][1]=1;message_mat[2][2]=0;
	message_mat[3][0]=0;message_mat[3][1]=1;message_mat[3][2]=1;
	message_mat[4][0]=1;message_mat[4][1]=0;message_mat[4][2]=0;
	message_mat[5][0]=1;message_mat[5][1]=0;message_mat[5][2]=1;
	message_mat[6][0]=1;message_mat[6][1]=1;message_mat[6][2]=0;
	message_mat[7][0]=1;message_mat[7][1]=1;message_mat[7][2]=1;
	std::cout<<"message matrix"<<std::endl;
	for(i=0;i<8;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<message_mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Ed::printcodematrix()
{
  for(k=0;k<8;++k)
  {
	for(i=0;i<3;++i)
	{
	   for(j=0;j<6;++j)
	   {
	   	 temp[i][j]=message_mat[k][i]*generator_mat[i][j];
	   	    	 
	   	
		   }
    }
    
	
    for(j=0;j<6;++j)
    {
    	countone=0;
    	for(i=0;i<3;++i)
    	{
    	  	if(temp[i][j]==1) ++countone;
		}
		if(countone==0 || countone % 2 == 0) code_mat[k][j]=0;
		else code_mat[k][j]=1;
	}
  }
  
	std::cout<<"code matrix"<<std::endl;
	for(i=0;i<8;++i)
	{
		for(j=0;j<6;++j)
		{
			std::cout<<code_mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Ed::printcodeweight()
{
	min=999;
	int w;
	for(i=0;i<8;++i)
	{
		w=0;
		for(j=0;j<6;++j)
		{
			if(code_mat[i][j]==1)++w;
		}
		if(w<min && w!=0){ min=w;  }
	}
	std::cout<<"minimum code weight=   "<<min<<std::endl;
}
void Ed::findhtranspose()
{
	for(i=0;i<6;++i)
	{
		for(j=0;j<3;++j)
		{
			htranspose_mat[i][j]=hparity_mat[j][i];
		}
	}
	std::cout<<"h transpose matrix"<<std::endl;
	for(i=0;i<6;++i)
	{
		for(j=0;j<3;++j)
		{
			std::cout<<htranspose_mat[i][j]<<" ";
		}
		std::cout<<std::endl;
	}
}
void Ed::inputcodevector()
{
	std::cout<<"enter 6 digit code vector 0/1"<<std::endl;
	for(i=0;i<6;++i)
	{
		std::cin>>v[0][i];
	}
}
void Ed::inputreceivedvector()
{
	std::cout<<"enter 6 digit received vector 0/1 not part of code matrix"<<std::endl;
	for(i=0;i<6;++i)
	{
		std::cin>>r[0][i];
	}
}
void Ed::printsyndrome()
{
	
		for(j=0;j<3;++j)
		{
			s[0][j]=0;
			for(k=0;k<6;++k)
			{
				s[0][j]=s[0][j]+r[0][k]*htranspose_mat[k][j];
				if(s[0][j]>1){ s[0][j]=1; 	}
			}
		}
	
	std::cout<<"syndrome=    "<<std::endl;
	
		for(j=0;j<3;++j)
		{
			std::cout<<s[0][j]<<"     ";
		}
	
}
void Ed::printstandardarray()
{
	for(i=0;i<8;++i)
	{
		for(j=0;j<6;++j)
		{
			standard_mat[0][i][j]=code_mat[i][j];
		}
	}
	for(k=1;k<7;++k)
	{	
			for(j=0;j<6;++j)
			{
				if((k-1)==j)
				    standard_mat[k][0][j]=1;
				else
				    standard_mat[k][0][j]=0;
			}
		
	}

    
	for(k=1;k<7;++k)
	{
	
	  for(i=1;i<8;++i)
    	{
	    	for(j=0;j<6;++j)
			{
				standard_mat[k][i][j]=integerxor(standard_mat[0][i][j],standard_mat[k][0][j]);
			}
		}
    }
    std::cout<<"enter 6 bit code for next coset head of next row not any of"<<std::endl;
    
    for(i=1;i<7;++i)
	{
		for(j=1;j<8;++j)
		{
			found=0;
			for(k=0;k<6;++k)
			{
				if(standard_mat[i][j][k]==1)
				{
					//std::cout<<"i= "<<i<<"j= "<<j<<"k= "<<k<<std::endl;
					//std::cout<<" standard= "<<standard_mat[i][j][k]<<" r= "<<r[0][k]<<" ";
					
				
					++found;
				}
				
				  
			}
			if(found==2)
			{ 
			         for(k=0;k<6;++k)
					 { 
					     std::cout<<standard_mat[i][j][k]<<" ";	
						 } 
						 std::cout<<std::endl;
			}
			
		}
		std::cout<<std::endl;
	}
	std::cout<<"enter 6 bit code  ";
    for(k=0;k<6;++k)
    {
    	std::cin>>standard_mat[7][0][k];
	}
	for(k=1;k<8;++k)
	{
	
	  for(i=1;i<8;++i)
    	{
	    	for(j=0;j<6;++j)
			{
				standard_mat[k][i][j]=integerxor(standard_mat[0][i][j],standard_mat[k][0][j]);
			}
		}
    }
    std::cout<<"standard array "<<std::endl;
	for(k=0;k<8;++k)
	{
		for(i=0;i<8;++i)
		{
			for(j=0;j<6;++j)
			{
				std::cout<<standard_mat[k][i][j];
			}
			std::cout<<" ";
		}
		std::cout<<std::endl;
	}
		
}
void Ed::finderror()
{
	for(i=1;i<8;++i)
	{
		for(j=1;j<8;++j)
		{
			found=0;
			for(k=0;k<6;++k)
			{
				if(standard_mat[i][j][k]==r[0][k])
				{
					//std::cout<<"i= "<<i<<"j= "<<j<<"k= "<<k<<std::endl;
					//std::cout<<" standard= "<<standard_mat[i][j][k]<<" r= "<<r[0][k]<<" ";
					
				
					++found;
				}
				
				  
			}
			
			if(found==6)
			{ 
				col=j; 
				std::cout<<"error found in col  "<<col;
				std::cout<<std::endl;
				for(int p=0;p<6;++p)
				{
					std::cout<<standard_mat[0][col][p]<<" ";
				}
				std::cout<<std::endl;
			}
			
			
		}
	}
	
}
int Ed::integerxor(int x,int y)
{
	int res = 0; // Initialize result
     
    // Assuming 32-bit Integer 
    for (int i = 31; i >= 0; i--)                     
    {
       // Find current bits in x and y
       bool b1 = x & (1 << i);
       bool b2 = y & (1 << i);
        
        // If both are 1 then 0 else xor is same as OR
        bool xoredBit = (b1 & b2) ? 0 : (b1 | b2);          
 
        // Update result
        res <<= 1;
        res |= xoredBit;
    }
    return res;
}


int main()
{
	Ed e;
	e.getparitymatrix();
	e.printgeneratormatrix();
	e.inputmessagematrix();
	e.printcodematrix();
	e.printcodeweight();
	e.inputcodevector();
	e.inputreceivedvector();
	e.printcodeweight();
	e.findhtranspose();
	e.printsyndrome();
	e.printstandardarray();
	e.finderror();
	
	
	
	
	
	return 1;
}
