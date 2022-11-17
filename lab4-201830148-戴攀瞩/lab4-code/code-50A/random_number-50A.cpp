#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{
    int ret1 = 0;
    int ret2 = 0;
    srand((unsigned int)time(NULL));
    for(int i=0; i<50; i++)
    {
        ret1 = rand()%16+1;
        ret2 = rand()%16+1;
        printf("%d %d\n",ret1,ret2);
        FILE *fp = NULL;
        fp = fopen("C:/Users/dai/Desktop/c++/test2.txt", "a");
        fprintf(fp,"%d\n",ret1);
        fprintf(fp,"%d\n",ret2);
        fclose(fp);
    }
    return 0;
}