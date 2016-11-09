#include<iostream>
#include<cstring>
#include<cmath>
class Rbn
{
	private:
		int i,j,len,key,n,p,q,a1,a2,b1,b2,C,P;
	public:
		void rabin_key_generation();
		void rabin_encryption();
	
		
		int multiplicative_inverse(int r1,int r2,int n);
		int chinese_remainder_theorem(int a,int b,int p,int q);
		void rabin_decryption();	
	
	
	
};
void Rbn::rabin_key_generation()
{
	std::cout<<"enter two prime nos of form 4*k+3 (k any integer)";
	std::cin>>p>>q;
	n=p*q;
	std::cout<<"private key=  "<<q<<"and  "<<n<<std::endl;
	std::cout<<"public key   "<<n<<std::endl;
	
}

void Rbn::rabin_encryption()
{
	std::cout<<"enter any integer to be encrypted";
	std::cin>>P;
	C=(P*P)%n;
	std::cout<<"encrypted integer=  "<<C<<std::endl;
	
}
void Rbn::rabin_decryption()
{
	int P1,P2,P3,P4;
	int temp1,temp2,temp3;
	std::cout<<"value of C  p  q"<<C<<"   "<<p<<"  "<<q<<"   "<<std::endl;
	temp1=C % p;
	temp2=(p+1)/4;
	temp3=pow(temp1,temp2);
	std::cout<<"value of temp1 temp2 temp3"<<temp1<<"  "<<temp2<<"  "<<temp3<<std::endl;
	a1=+(temp3 % p);
	a2=-(temp3 % p);
	a2=a2+p;
	
	temp1=C%q;
	temp2=(q+1)/4;
	temp3=pow(temp1,temp2);
	std::cout<<"value of temp1 temp2 temp3"<<temp1<<"   "<<temp2<<"   "<<temp3<<std::endl;
	b1=+(temp3 % q);
	b2=-(temp3 % q);
	b2=b2+q;
	std::cout<<"value of a1 a1 b1 b2 "<<a1<<"  "<<a2<<"  "<<b1<<"  "<<b2<<std::endl;
	P1=chinese_remainder_theorem(a1,b1,p,q);
	P2=chinese_remainder_theorem(a1,b2,p,q);
	P3=chinese_remainder_theorem(a2,b1,p,q);
	P4=chinese_remainder_theorem(a2,b2,p,q);
	P1=P1 % n;
	P2=P2 % n;
	P3=P3 % n;
	P4=P4 % n;
	std::cout<<" four possible decrypted nos are  "<<P1<<"   "<<P2<<"   "<<P3<<"   "<<P4;
}
int Rbn::multiplicative_inverse(int r1,int r2,int n)
{
	int r,q,t1,t2,t;
	t1=0;
	t2=1;
	std::cout<<" value of r1 r2 n"<<r1<<"   "<<r2<<"   "<<n<<std::endl;
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
	if(t1<0){t1=t1+n;}
    t1=t1 % n;
	return t1;
}
int Rbn::chinese_remainder_theorem(int a,int b,int p,int q)
{
	int M,M1,M2,y1,y2,X;
	M=p*q;
	M1=M/p;
	M2=M/q;
	std::cout<<"value of M M1 M2 "<<M<<"   "<<M1<<"    "<<M2<<std::endl;
	y1=multiplicative_inverse(p,M1,p);
	y2=multiplicative_inverse(q,M2,q);
	std::cout<<"value of y1 y2"<<y1<<"   "<<y2<<std::endl;
	X=a*M1*y1+b*M2*y2;
	return X;
	
}
int main()
{
	Rbn b;
	b.rabin_key_generation();
	b.rabin_encryption();
	b.rabin_decryption();
	return 0;
}

