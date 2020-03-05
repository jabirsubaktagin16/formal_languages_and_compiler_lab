/* Question: A C source program with single and multiple line comments is given.
As the first step toward compilation you need to remove the comments and white space 
(extra spaces, tabs and newline characters). Develop a program that takes as input 
file the given source program and produces a filtered file as stated above. The 
program must also display both the files.*/

#include <stdio.h>
void check_input(char) ;
void multiline_comment();
void single_comment () ;
void white_space(char);
FILE *fp, *fp2;
int main(void)
{
    char c;
    fp = fopen ("input.c","r") ;
    fp2 = fopen ("output.txt","w") ;

    while((c=fgetc(fp))!=EOF)
    {
        check_input(c);
    }
    fclose(fp);
    fclose(fp2);
    fp2 = fopen("output.txt","r");
    while((c=fgetc(fp2))!=EOF)
		printf("%c",c);
    fclose(fp2);

    return 0;
}
void check_input(char c)
{
    char d;

    if( c == '/')
    {
        if((d=fgetc(fp))=='*')
            multiline_comment();
        else if( d == '/')
        {
            single_comment();
        }
        else
        {
            fputc(c,fp2);
            fputc(d,fp2);
        }
    }
    else
        white_space(c);
}
void multiline_comment()
{
    char d,e;
    while((d=fgetc(fp))!=EOF)
    {
        if(d=='*')
        {
            e=fgetc(fp);
            if(e=='/')
                return;
        }
    }
}
void single_comment()
{
    char d,e;

    while((d=fgetc(fp))!=EOF)
    {
        if(d=='\n')
            return;
    }
}
void white_space(char c)
{
    char d;
    if(c==' ')
    {
       d=fgetc(fp);
       fputc(d,fp2);
    }
    if(c=='\n')
        fputc(' ',fp2);
    if((c!=' ') && (c!='\n') && (c!='\t'))
        fputc(c,fp2);
}
