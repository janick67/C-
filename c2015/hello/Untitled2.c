#include<stdio.h>


int main(int argc , char *argv[])
{
int i="7";
int x= static_cast < char > (i);
printf("%c",x);

}




int send(const char* mes)
{
    printf(mes);
    return 0;
}
