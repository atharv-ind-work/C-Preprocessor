//Header file inclusion

#include"comment.h"

//void header_comm(FILE *,FILE *);

void header_inc(FILE *ip,FILE *op,sll **dptr)
{
    char line[256]="";
    fgets(line,sizeof(line),ip);

    char filename[100];
    int i=0,j=0;

    //user header "file.h"
    if(strstr(line,"include"))
    {
        if(strchr(line,'"'))
        {
            while(line[i] && line[i]!='"') i++;
            i++;
            while(line[i] && line[i]!='"')
                filename[j++]=line[i++];
            filename[j]='\0';

            FILE *fp=fopen(filename,"r");
            if(fp)
            {
                header_comm(fp,op);
                fclose(fp);
                return;
            }
        }

        //system header file <file.h>
        else if(strchr(line,'<'))
        {
            while(line[i] && line[i]!='<') i++;
            i++;
            while(line[i] && line[i]!='>')
                filename[j++]=line[i++];
            filename[j]='\0';

            char fullpath[200]="C:/MinGW/include/";
            strcat(fullpath,filename);

            FILE *fp=fopen(fullpath,"r");
            if(fp)
            {
                header_comm(fp,op);
                fclose(fp);
                return;
            }
            else
            {
                printf("\033[31mERROR\033[0m :unable to open file\n");
                exit(0);
            }
        }
    }

    else if(strstr(line,"define"))
    {
        char name1[50]="",value1[50]="";
        i=0,j=0;

        // skip "#define"
        while(line[i] && line[i]!=' ') i++;
        while(line[i]==' ') i++;

        // read macro name
        while(line[i] && line[i]!=' ')
            name1[j++]=line[i++];
        name1[j]='\0';

        j=0;

        // skip spaces
        while(line[i]==' ') i++;

        // read macro value
        while(line[i] && line[i]!='\n')
            value1[j++]=line[i++];
        value1[j]='\0';

        add_end(dptr,name1,value1);
    }
    else
    {
        printf("\033[31mERROR\033[0m :File not found -header1.c\n");
    }
}

void header_comm(FILE *ip,FILE *op)
{
    char ch=0,prev=0,next=0;

    while((ch=fgetc(ip))!=EOF)
    {
        if(ch=='/')
        {
            next=fgetc(ip);

            if(next=='/')
            {
                while((ch=fgetc(ip))!='\n' && ch!=EOF)
                {
                    fputc(' ',op);
                }
                fputc('\n',op);
            }
            else if(next=='*')
            {
                while((ch=fgetc(ip))!=EOF)
                {
                    if(prev=='*'&&ch=='/')
                        break;

                    fputc(' ',op);
                    prev=ch;
                }
            }
            else
            {
                fputc(ch,op);
                fputc(next,op);
            }
        }
        else
        {
            fputc(ch,op);
        }
    }
}
