#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
    int ret = 0;
    srand((unsigned int)time(NULL));
    for(int i=0; i<50; i++)
    {
        ret = rand()%100+1;
        printf("%d ",ret);
        FILE *fp = NULL;
        fp = fopen("C:/Users/dai/Desktop/c++/test1.txt", "a");
        fprintf(fp,"%d\n",ret);
        fclose(fp);
    }
    return 0;
}