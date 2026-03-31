//file process function
#include"comment.h"

//void check_macro(sll *,char *s1);

void process_file(FILE *ip,FILE *op,sll **dptr)
{
    char s[100]="",ch=0;
    int len=0;

    while((fscanf(ip,"%s",s))!=EOF)
    {
        if(strstr(s,"//"))
        {
            //single line comment
            char temp[100];
            strcpy(temp, s);

            char *p = strstr(temp, "//");
            if(p) *p = '\0';

            if(strlen(temp) > 0)
            {
                check_macro(*dptr, temp);

                if(strchr(temp,';'))
                    fprintf(op,"%s\n", temp);
                else
                    fprintf(op,"%s ", temp);
            }

            // skip rest of line
            while((ch=fgetc(ip))!='\n' && ch!=EOF);

        }
        else if(strstr(s,"/*"))
        {
            // multi-line comment 

            char temp[100];
            strcpy(temp, s);

            char *p = strstr(temp, "/*");
            if(p) *p = '\0';

            // printing code before comment
            if(strlen(temp) > 0)
            {
                check_macro(*dptr, temp);

                if(strchr(temp,';'))
                    fprintf(op,"%s\n", temp);
                else
                    fprintf(op,"%s ", temp);
            }

            // Skip full block comment properly
            char prev=0;
            while((ch=fgetc(ip))!=EOF)
            {
                if(prev=='*' && ch=='/')
                    break;
                prev=ch;
            }
        }
        else if(strstr(s,"#include")||strstr(s,"#define"))
        {
            len=strlen(s);
            fseek(ip,-len,SEEK_CUR);
            ch=fgetc(ip);    
            header_inc(ip,op,dptr);
            continue;   
        }
        else
        {
            // spliting symbols manually
            char *semi = strchr(s, ';');
            char *brace1 = strchr(s, '{');
            char *brace2 = strchr(s, '}');

            // contains ';'
            if(semi)
            {
                *semi = '\0';   // spliting before ;

                check_macro(*dptr, s);
                fprintf(op, "%s", s);

                fprintf(op, ";\n");  // adding semicolon properly
            }
            // contains '{'
            else if(brace1)
            {
                *brace1 = '\0';

                check_macro(*dptr, s);
                fprintf(op, "%s", s);

                fprintf(op, "{\n");
            }
            // contains '}'
            else if(brace2)
            {
                *brace2 = '\0';

                check_macro(*dptr, s);
                fprintf(op, "%s", s);

                fprintf(op, "}\n");
            }
            else
            {
                check_macro(*dptr, s);
                fprintf(op, "%s ", s);
            }
        }
    }
}
