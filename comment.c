//comment removal file
#include "comment.h"

void comment_rem(FILE *ip,FILE *op,char first_char)
{
    char next=fgetc(ip);

    if(next=='/')
    {
        char ch;
        while((ch=fgetc(ip))!='\n' && ch!=EOF)
        {
            fputc(' ',op);
        }
        fputc('\n',op);
    }
    else if(next=='*')
    {
        char ch,prev=0;
        while((ch=fgetc(ip))!=EOF)
        {
            if(prev=='*' && ch=='/')
                break;

            fputc(' ',op);
            prev=ch;
        }

        if(prev=='*' && ch=='/')
        {
            fputc('\n',op);
        }
    }
    else
    {
        fputc(first_char,op);
        fputc(next,op);
    }
}