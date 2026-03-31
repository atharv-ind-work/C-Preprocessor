//main function file

#include"comment.h"

int main(int argc,char **argv)
{
    sll *headptr=0;

    if(argc!=2)
    {
        printf("\033[32mUSAGE\033[0m : ./pree file.c\n");
        return -1;
    }

    FILE *ip,*op;

    ip=fopen(argv[1],"r");
    if(ip==NULL)
    {
        printf("\033[31mERROR\033[0m : unable to open file %s\n",argv[1]);
        return -1;
    }

    char outname[100];
    strcpy(outname,argv[1]);

    char *dot=strchr(outname,'.');
    if(dot)
        strcpy(dot,".i");

    op=fopen(outname,"w");
    if(op==NULL)
    {
        printf("\033[31mERROR\033[0m : unable to create output file\n");
        return -1;
    }

    process_file(ip,op,&headptr);

    fclose(ip);
    fclose(op);

    return 0;
}