#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
class DES
{
	public:
		int leftBlock[32],rightBlock[32],inBlock[64],outBlock[32],T[32],T1[32],T2[32],T3[32];
		int keyWithParties[32],cipherKey[48],leftKey[32],rightKey[32];
		int RoundKeys[16][64],plainBlock[64],initialPermutationTable[8][8],finalPermutationTable[8][8];
		int substitutionTable[8][4][16],expansionPermutationTable[8][8],straightPermutationTable[8][8];
		int parityDropTable[8][8];
		int roKey[48],cipherBlock[64],buffer;
		int shiftTable[16],preRoundKey[64],keyCompressionTable[8][8];
		int i,j,round,k,p,q;
		
		

		void Cipher(int plainBlock[64],int RoundKeys[16][64],int cipherBlock[64]);
		void permute(int r,int c,int plainBlock[64],int leftBlock[32],int permutaionTable[8][8]);
		void split(int n,int m,int inBlock[64],int leftBlock[32],int rightBlock[32]);
		void mixer(int leftBlock[32],int rightBlock[32],int RoundKeys[16][64]);
		void combine(int n,int m,int leftBlock[32],int rightBlock[32],int outBlock[64]);
		void copydata(int n,int rightBlock[32],int T1[32]);
		void functn(int T1[48],int RoundKeys[16][64],int T2[48]);
		void exclusiveOR(int n,int leftBlock[48],int T1[48],int T2[48]);
		void substitute(int T1[32],int T2[32],int substitutionTable[8][4][16]);
		void swapper(int leftBlock[32],int rightBlock[32]);
		void key_generator(int keyWithParties[64],int RoundKeys[16][64],int shiftTable[16]);
		void shiftLeft(int leftBlock[32],int shiftValue);
		void initialiseTables();
		void printCipherBlock();
		int integerxor(int x,int y);
			
	
};
int DES::integerxor(int x,int y)
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
void DES::Cipher(int plainBlock[64],int RoundKeys[16][64],int cipherBlock[64])
{
  permute(64,64,plainBlock,inBlock,initialPermutationTable);
  split(64,32,inBlock,leftBlock,rightBlock);
  for(round=1;round<=16;++round)
  {
  	mixer(leftBlock,rightBlock,RoundKeys);
  	if(round!=16) swapper(leftBlock,rightBlock);
  }
  combine(32,64,leftBlock,rightBlock,outBlock);
  permute(64,64,outBlock,cipherBlock,finalPermutationTable);
	  
}
void DES::mixer(int leftBlock[32],int rightBlock[32],int RoundKeys[16][64])
{
	copydata(32,rightBlock,T1);
	functn(T1,RoundKeys,T2);
	exclusiveOR(32,leftBlock,T2,T3);
	copydata(32,T3,rightBlock);
}
void DES::swapper(int leftBlock[32],int rightBlock[32])
{
	copydata(32,leftBlock,T);
	copydata(32,rightBlock,leftBlock);
	copydata(32,T,rightBlock);
}
void DES::functn(int T1[48],int RoundKeys[16][64],int T2[48])
{
	permute(32,48,inBlock,T1,expansionPermutationTable);
	for(p=0;p<48;++p)
	{
		roKey[p]=RoundKeys[round][p];
}	
	exclusiveOR(48,T1,roKey,T2);
	substitute(T2,T3,substitutionTable);
	permute(32,32,T3,outBlock,straightPermutationTable);
	
}
void DES::substitute(int T1[32],int T2[32],int substitutionTable[8][4][16])
{
	int i;
	for(i=1;i<=8;++i)
	{
		int row=2*inBlock[i*6+1]+inBlock[i*6+6];
		int col=8*inBlock[i*6+2]+4*inBlock[i*6+3]+2*inBlock[i*6+4]+inBlock[i+6+5];
		int value=substitutionTable[i][row][col];
		
		outBlock[i*4+1]=value/8;
		outBlock[i*4+2]=value/4;
		outBlock[i*4+3]=value/2;
		outBlock[i*4+4]=value;
	}
}
void DES::key_generator(int keyWithParties[64],int RoundKeys[16][64],int shiftTable[16])
{
	permute(64,56,keyWithParties,cipherKey,parityDropTable);
	split(56,28,cipherKey,leftKey,rightKey);
	for(round=1;round<16;++round)
	{
		shiftLeft(leftKey,shiftTable[round]);
		shiftLeft(rightKey,shiftTable[round]);
		combine(28,56,leftKey,rightKey,preRoundKey);
		permute(56,48,preRoundKey,RoundKeys[round],keyCompressionTable);
		
	}
	
}
void DES::permute(int r,int c,int plainBlock[64],int leftBlock[32],int permutationTable[8][8])
{
	j=1;k=1;
	
	while(j<64)
	{
	for(p=0;p<8;++p)
	{
		for(q=0;q<8;++q)
		{
			if(permutationTable[p][q]==plainBlock[j])
			{
				leftBlock[k]=p*8+q;
				++k;
				
			}
		}
	}
	
	++j;
}


}
void DES::copydata(int n,int rightBlock[32],int T1[32])
{
	for(p=0;p<32;++p)
	{
		T1[p]=rightBlock[p];
	}
}
void DES::shiftLeft(int leftBlock[32],int shiftValue)
{
	for(p=0;p<32;++p)
	{
		if(shiftValue=='1')
		{
			leftBlock[31]=leftBlock[0];
			leftBlock[p]=leftBlock[p+1];
			
		}
		if(shiftValue=='2')
		{
			leftBlock[31]=leftBlock[0];
			leftBlock[30]=leftBlock[1];
			leftBlock[p]=leftBlock[p+2];
			
		}
	}

}
void DES::exclusiveOR(int n,int leftBlock[48],int T1[48],int T2[48])
{
	
	for(p=0;p<n;++p)
	{
		T2[p]=integerxor(leftBlock[p],T1[32]);
		
	}

}
void DES::initialiseTables()
{
	
   for(p=0;p<8;++p)
   {
   	for(q=0;q<8;++q)
   	{
   		
   		initialPermutationTable[p][q]=rand()%64+1;
   		finalPermutationTable[p][q]=rand()%64+1;
   		
	   }
	   }
	   	
	   for(p=0;p<64;++p)
	   {
	   	keyWithParties[p]=(rand()%64);
	   
	   }
	   for(p=0;p<16;++p)
	   {
	   	for(q=0;q<48;++q)
	   	{
	   		RoundKeys[p][q]=0;
		   }
	   }
	  
	   for(p=0;p<16;++p)
	   {
	   	shiftTable[p]=rand()%2+1;
	   	
	   }
	   
}
void DES::split(int n,int m,int inBlock[64],int leftBlock[32],int rightBlock[32])
{

	for(p=0;p<64;++p)
   {
   	if(p<32)
   	{
   		leftBlock[p]=inBlock[p];
	   }
	if(p>32)
	{
		rightBlock[p-32]=inBlock[p];
	}
	   }
	  
}
void DES::combine(int n,int m,int leftBlock[32],int rightBlock[32],int outBlock[64])
{

	for(p=0;p<64;++p)
   {
   	if(p<32)
   	{
   		outBlock[p]=leftBlock[p];
	   }
	if(p>32)
	{
		outBlock[p]=rightBlock[p-32];
	}
	   }
	   
	   
}
void DES::printCipherBlock()
{
	std::cout<<" cipher output "<<std::endl;
	for(p=0;p<64;++p)
	{
		std::cout<<cipherBlock[p]<<"  ";
	}
}
int main()
{
	
	DES d;
	d.initialiseTables();
	d.key_generator( d.keyWithParties,d.RoundKeys,d.shiftTable);
	d.Cipher(d.plainBlock,d.RoundKeys,d.cipherBlock);
	d.printCipherBlock();
	
	
	
	return 1;
}
