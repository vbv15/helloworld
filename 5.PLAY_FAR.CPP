#include<iostream>
#include<cstring>
class play_far
{
  public:
      char strcode[100],strtext[100],processtext[100];
     int len,i,j,k,temp;
     int freq[20];
	 int rowpos1,colpos1,rowpos2,colpos2,pos;
     char lettertext[30];
	 char key[6][6]={
	                  {'a','b','c','d','e'},
	                  {'f','g','h','i','k'},
	                  {'l','m','n','o','p'},
	                  {'q','r','s','t','u'},
	                  {'v','w','x','y','z'}
					  };


     void read_key();
     void read_text();
     void replace_duplicates();
     void find_rowcol_pos();
     void same_row();
     void same_col();
     void diag_rowcol();
     void encrypt();
     void print_code();
     void read_code();
     void analyse();



};
void play_far::read_key()
{

  len=0;

  std::cout<<"enter the key";
 /*for(i=1;i<=5;++i)
  {
   for(j=1;j<=5;++j)
   {
     std::cout<<"enter key for "<<i<<"  "<<j<<std::endl;
     std::cin>>key[i][j];
   }
  }*/
    
  std::cout<<"key is "<<std::endl;
  for(i=0;i<=4;++i)
  {
   for(j=0;j<=4;++j)
   {
     std::cout<<key[i][j]<<"   ";
   }
   std::cout<<std::endl;
  }
}
void play_far::read_text()
{
  std::cout<<"Enter text   "<<std::endl;
 std::cin>>strtext;
 len=strlen(strtext);

}
void play_far::replace_duplicates()
{
    if(len%2!=0)
    {
    	strtext[len]='x';
    	++len;
	}
    std::cout<<"length=  "<<len<<std::endl;
	 j=0;
  for(i=0;i<=len-1;++i)
 {
  if(strtext[i]==strtext[i+1])
  {
        processtext[j]=strtext[i];
        std::cout<<processtext[j]<<std::endl;
        ++j;
     	processtext[j]='x';
     	std::cout<<processtext[j]<<std::endl;
     	++j;
     	processtext[j]=strtext[i];
     	std::cout<<processtext[j]<<std::endl;
     	++i;++j;++len;
     	std::cout<<"length= "<<len<<"i=  "<<i<<std::endl;
   }
else
{
  processtext[j]=strtext[i];
  std::cout<<processtext[j]<<std::endl;
  ++j;
 }
}
 std::cout<<processtext;
 std::cout<<std::endl;
}
void play_far::find_rowcol_pos()
{
    for(j=0;j<=4;++j)
    {
       for(k=0;k<=4;++k)
       {
        if(pos==1)
        {
		
		if(processtext[i]==key[j][k])
		{
		  rowpos1=j;
		  colpos1=k;
		  std::cout<<"first char "<<processtext[i]<<"rowpos  "<<rowpos1<<"colpos  "<<colpos1<<std::endl;
		}
	
        if(processtext[i]=='j')
        {	    
    	rowpos1=2;colpos1=4;
    	std::cout<<"first char "<<processtext[i]<<"rowpos  "<<rowpos1<<"colpos  "<<colpos1<<std::endl;
	    }
   }
    else if(pos==2)	
	{
	    if(processtext[i+1]==key[j][k])
		{
		   rowpos2=j;
		   colpos2=k;
		   std::cout<<"second char "<<processtext[i+1]<<"rowpos  "<<rowpos2<<"colpos  "<<colpos2<<std::endl;
		}
       if(processtext[i+1]=='j')
       {
    	rowpos2=2;colpos2=4;
    	std::cout<<"second char "<<processtext[i+1]<<"rowpos  "<<rowpos2<<"colpos  "<<colpos2<<std::endl;
	   }
   } 
}
}
}
void play_far::same_col()
{
       processtext[i]=key[(rowpos1+1)%5][colpos1];
       processtext[i+1]=key[(rowpos2+1)%5][colpos2];
}
void play_far::same_row()
{
  processtext[i]=key[rowpos1][(colpos1+1)%5];
     processtext[i+1]=key[rowpos2][(colpos2+1)%5];
     
     
}
void play_far::diag_rowcol()
{
  processtext[i]=key[rowpos1][colpos2];
    processtext[i+1]=key[rowpos2][colpos1];
}
void play_far::encrypt()
{
  for(i=0;i<=len-1;++i)
  {
   pos=1;
   find_rowcol_pos();
   pos=2;
   find_rowcol_pos();
  if(rowpos1==rowpos2)
   {
      same_row();
   }
  else if(colpos1==colpos2)
  {
    same_col();
  }
  else if(rowpos1!=rowpos2 && colpos1!=rowpos2)
  {
       diag_rowcol();
    }
   ++i;
  }
}
void play_far::print_code()
{
  std::cout<<"code=  "<<processtext;
  strcpy(strcode,processtext);
  len=strlen(strcode);
}
void play_far::read_code()
{
  std::cout<<"enter code=   ";
  std::cin>>strcode;
}
void play_far::analyse()
{
   for(j=0;j<=(i/2)-1;++j)
   {
   	freq[j]=0;
   }
   for(i=0;i<=len-1;++i)
   {
   	k=i+2;
   	while(k<=len-1)
   	{
   		if(strcode[i]==strcode[k] && strcode[i+1]==strcode[k+1])
   		{
   			std::cout<<strcode[i]<<" "<<strcode[k]<<" "<<strcode[i+1]<<std::endl;
			std::cout<<" "<<strcode[k+1]<<" ik"<<i<<" "<<k<<std::endl;
   			++freq[i/2];
   			strcode[k]=k;
   			strcode[k+1]=k+1;
		   }       
        ++k;
	   }
     if(freq[i/2]!=0) ++freq[i/2];
    ++i;
   }
  for(i=0;i<=len-1;++i)
   {
   	std::cout<<"freq of "<<strcode[i]<<strcode[i+1]<<"is "<<freq[i/2]<<std::endl;
   	++i;
   }
}


 int main()
 {
  play_far p;
  p.read_key();
  p.read_text();
  p.replace_duplicates();
  p.encrypt();
  p.print_code();
  p.analyse();
    return 0;
 }
