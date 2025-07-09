#include <unistd.h>
#include <string.h>
#include<stdlib.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

void print_it(int count)
{
    int i = 0;
    while(i<count)
    {
        write(1,"*",1);
        i++;
    }
}

void filter(char *s, char *filter)
{
    int filterlen = strlen(filter);
    char *pos;


    pos = memmem(s,strlen(s),filter,filterlen);

    while(*s)
    {
        if (pos == s)
        {
            print_it(filterlen);
            s += filterlen;
            pos = memmem(s,strlen(s),filter,filterlen);
        }
        else
        {
            write(1,s,1);
            s++;
        }
    }
}



char *ft_strdup(char *str)
{
    char *copy;
    copy = malloc(sizeof(char) * strlen(str));
    if (!copy)
        return NULL;
    int i =0;
    while(str[i])
    {
        copy[i] = str[i];
        i++;
    }
    copy[i] = '\0';
    return(copy);
}


char    *get_next_line(int fd)
{
    static int b_pos;
    static int b_read;
    static char buffer[BUFFER_SIZE];
    char line[70000];
    int i = 0;

    while(1)
    {
        if (b_pos >= b_read)
        {
            b_read = read(fd,buffer,BUFFER_SIZE);
            b_pos = 0;
            if (b_read < 1)
                break;
        }
        line[i++] = buffer[b_pos++];
        if(buffer[b_pos - 1] == '\n')
            break;
    }
    if (i == 0)
        return NULL;
    
    line[i] = '\0';
    return(ft_strdup(line));
}
int main(int argc,char **argv)
{
    if(argc != 2)
        return 1;


    char *s;
    s = get_next_line(0);

    while(s)
    {
        filter(s,argv[1]);
        free(s);
        s = get_next_line(0);
    }
}