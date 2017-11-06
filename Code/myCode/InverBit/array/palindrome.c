#include <stdio.h>
#include <string.h>

int palindrome(char *str)
{
    int i, j;
    for(i=0, j=strlen(str)-1; i<j;) {
	if(!isalnum(str[i])) {
	    i++;
	    continue;
	}
	if(!isalnum(str[j])) {
	    j--;
	    continue;
	}
	if(tolower(str[i]) != tolower(str[j]))
	    return 0;
	i++;
	j--;
    }
    return 1;
}

int main()
{
    //char str[100] = "A man, a plan, a canal: Panama";
    //char str[100] = "race a car";
    char str[100] = "1a2";
    int yn = 0;

    //printf("input string: ");
    //scanf("%s", str);

    yn = palindrome(str);
    printf("Input String \"%s\" is %s\n", str, yn?"palindrome" : "NOT a palindrome");

    return 0;
}
