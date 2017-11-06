#include<stdio.h>
#include<string.h>

void swap(char *a, char *b)
{
    char temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int reverse_string(char *str, int i, int j)
{
    char temp;

    while(i < j)
    {
	swap(&str[i], &str[j]);
	i++;j--;
    }

}

void reverse_word(char *str, int len)
{
    int i=0,j=1;
    while (j <= len)
    {
	if ((str[j] == ' ') || (str[j] == 0))
	{
	    reverse_string(str, i, j-1);
	    j++;
	    i=j;
	}
	else
	    j++;
    }
}
void remove_space(char *str, int i, int len)
{

    int j=0;

    while ((j < len) && (str[j] != 0))
    {
	while(str[j] == ' ')
	    j++;

	while((str[j] != ' ') && str[j])
	{
	    str[i] = str[j];
	    i++;j++;
	}

	if (str[j] == 0)
	{
	    if (str[i-1] == ' ')
		str[i-1] =  0;
	    else
		str[i] =  0;

	    return;
	}
	else{
	    str[i] = ' ';
	    i++;
	}
    }
}
int main()
{
    //char str[] = "    spider    l2l3        bng team  ";
    //char str[] = "   A man, a plan, a canal: Panama    ";
    //char str[] = "fwbpudnbrozzifml osdt    ulc jsx ";
    char str[] = "fddu	    xq l vy azs";
    //char str[] = "    ankrqzzcel  dyaiug y rkicv t";
    //char str[100] = "race a car";
    //char str[100] = "1a2";

    int len = strlen(str) ;
    int i=0,j=0;

    printf("%sZZZZ\n", str);
    /* Remove Extra space */
    remove_space(str, 0, len);

    /*Reverse whole string */
    len = strlen(str) ;
    reverse_string(str, 0, len-1);

    /*Rverse word by word */
    reverse_word(str, len);

    printf("%sXXXXX\n", str);

}
