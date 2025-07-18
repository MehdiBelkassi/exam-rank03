#include<stdio.h>

void solve(char *str,char *buff,int rm,int open,int s,int b)
{
    if (!str[s])
    {
        if (open == 0&& rm == 0)
        {
            buff[b] = '\0';
            puts(buff);
        }
        return;
    }

    if (rm > 0)
    {
        buff[b] = ' ';
        solve(str,buff,rm-1,open,s+1,b+1);
    }

    if (str[s] == '(')
    {
        buff[b] = '(';
        solve(str,buff,rm,open+1,s+1,b+1);
    }
    else if (str[s] == ')')
    {
        if (open >0)
        {
            buff[b] = ')';
            solve(str,buff,rm,open-1,s+1,b+1);
        }
    }
    else
    {
        buff[b] = str[s];
        solve(str,buff,rm,open,s+1,b+1);
    }
}

int rmclcl(char *str)
{
    int i = -1, close =0,open =0;
    while(str[++i])
    {
        if (str[i] == '(')
            open++;
        else if(str[i] == ')')
            close++;
    }

    if ((open - close) < 0)
        return ((open - close) * (-1));
    return ((open - close)); 
}


int main(int argc,char **argv)
{
    if (argc !=2)
        return 1;

    int len = 0;
    while(argv[1][len])
        len++;
    
    char buff[len+1];
    int rm = rmclcl(argv[1]);
    solve(argv[1],buff,rm,0,0,0);
}