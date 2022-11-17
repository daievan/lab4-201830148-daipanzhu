#include<iostream>
#include <string.h>
using namespace std;
char  file1[]="C:/Users/dai/Desktop/c++/.cpp/input/50A/file.txt";
char  file2[]="C:/Users/dai/Desktop/c++/.cpp/input/50A/file.txt";
void strpl(char *str, const char *old, const char *nes )
{	
	char *p = NULL;
	int len = 0;
	char newstr[64] = {0};
	p = strstr(str,old);
	len =  p - str;
	strncpy(newstr, str, len);
	strcat(newstr, nes);
	strcat(newstr,p+strlen(old)); 
	strcpy(str,newstr);
}

int main()
{   
    char A[12][10]={"21508887","21508898","21715601","29019948","30534178","31034693","33794240","36641065","45851050","138805414","142890373","164831265"};
	FILE* f1, * f2;
	int size1, size2;
	unsigned char buffer1[1024], buffer2[1024];
	for(int i=0;i<11;i++){
		//cout<<file1<<endl;
		if(i==0) strpl(file1, "file",A[i]);
		else strpl(file1, A[i-1],A[i]);
		//cout<<file1<<endl;
		for(int j=i+1;j<12;j++){
		if(j==1)  strpl(file2, "file",A[j]);
		else if(j==i+1) 	strpl(file2, A[11],A[j]);
		else strpl(file2, A[j-1],A[j]);
		f1 = fopen(file1, "rb+");
		f2 = fopen(file2, "rb+");
		int isTheSame= false;
		if (!f1)
			goto end;
		if (!f2)
			goto end;
		while (1)
		{
			size1 = fread(buffer1, 1, 1024, f1);
			size2 = fread(buffer2, 1, 1024, f2);
			if (size1 != size2)
			{
				goto end;
			}
			if (size1 < 1)
				break;
			for (int i = 0; i < size1; i++)
			{
				if (buffer1[i] != buffer2[i])
				{
					goto end;
				}
			}
		}
		isTheSame = true;
	end:
		if (f1)
			fclose(f1);
		if (f2)
			fclose(f2);
		//char ans[]="A[i] A[j]<<" "<<isTheSame<<endl;
        FILE *fp = NULL;
        fp = fopen("C:/Users/dai/Desktop/c++/.cpp/input/50A/judge-equal.txt", "a");
		fprintf(fp,"input/50A/");
        fprintf(fp,A[i]);
		fprintf(fp,".cpp");
		fprintf(fp,"\t");
		fprintf(fp,"input/50A/");
		fprintf(fp,A[j]);
		fprintf(fp,".cpp");
		fprintf(fp,"\t");
		fprintf(fp,"%d\n",isTheSame);
        fclose(fp);

		}
	}
    
	
}