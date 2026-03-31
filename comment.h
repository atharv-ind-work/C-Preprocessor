#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

typedef struct macro
{
	char name[51];
	char value[51];
	struct macro *next;
}sll;

//sll *headptr=0;

void comment_rem(FILE *,FILE *,char);
void header_inc(FILE *,FILE *,sll **);
void process_file(FILE *,FILE *,sll **);
void add_end(sll **pptr,char *name1,char *value1);
void check_macro(sll *,char *s1);
void header_comm(FILE *,FILE *);
