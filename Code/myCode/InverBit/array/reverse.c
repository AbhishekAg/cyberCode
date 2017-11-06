#if 1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Xreverse(char *A, int len)
{
    int i, j, tmp;
    for(i=0, j=len-1; i<j; i++, j--) {
	tmp = A[i];
	A[i] = A[j];
	A[j] = tmp;
    }
}

char *reverse(char *A)
{
    int i, j, tmp;
    char *base;
    char *end;
    char *newStr, *newptr;
    char *old = A;

    //Remove leading spaces
    while(isspace((unsigned char)*A)) ++A;

    if(*A == 0) //End of string reached
	return;

    //Remove trailing spaces
    end = A + strlen(A) -1;
    while(end > A && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0'; //Adding null

    newStr = (char *)malloc(strlen(A)*sizeof(char));
    newptr = newStr;
    Xreverse(A, strlen(A));

    //Reverse words and remove spaces in between words
    base = A;
    end = A;
    j = strlen(end);
    for(i=0; i<=j; i++) {
	if(*end == '\0') {
	   Xreverse(base, end-base);
	   strncpy(newptr, base, end-base);
	   newptr = newptr+(end-base);
	   *newptr++ = '\0';
	   strcpy(old,newStr);
	   free(newStr);
	   return old;
	} else if(isspace((unsigned char)*end)) {
	    Xreverse(base, end-base);
	    strncpy(newptr, base, end-base);
	    newptr = newptr+(end-base);
	    *newptr++ = ' ';
            while(isspace((unsigned char)*end)) end++;
	    base = end;
	}
	end++;
    }
    strcpy(old,newStr);
    free(newStr);
    return old;
}

int main()
{
    char *new;
    //char str[100] = "   A man, a plan, a canal: Panama    ";
    //char str[] = "fwbpudnbrozzifml osdt    ulc jsx ";
    //char str[] = "fddu xq l vy azs";
    char str[] = "    ankrqzzcel  dyaiug y rkicv t";
    //char str[100] = "race a car";
    //char str[100] = "1a2";

    printf("%s\n", str);
    new = reverse(str);
    printf("%s\n", new);
    printf("%s\n", str);

    return 0;
}
#else
#include<stdio.h>

/* function prototype for utility function to
 *   reverse a string from begin to end  */
void reverse(char *begin, char *end);

/*Function to reverse words*/
void reverseWords(char *s)
{
    char *word_begin = s;
    char *temp = s; /* temp is for word boundry */

    /*STEP 1 of the above algorithm */
    while( *temp )
    {
	temp++;
	if (*temp == '\0')
	{
	    reverse(word_begin, temp-1);
	}
	else if(*temp == ' ')
	{
	    reverse(word_begin, temp-1);
	    word_begin = temp+1;
	}
    } /* End of while */

    /*STEP 2 of the above algorithm */
    reverse(s, temp-1);
}

/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
 *   begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
	temp = *begin;
	*begin++ = *end;
	*end-- = temp;
    }
}

/* Driver function to test above functions */
int main()
{
    //char s[] = "i like this program very much";
    //char s[] = "fwbpudnbrozzifml osdt  ulc jsx";
    char s[] = "     fwbpudnbrozzifml osdt  ulc jsx kxorifrhubk ouhsuhf  sswz qfho dqmy  sn myq igjgip iwfcqq ";
    char *temp = s;
    reverseWords(s);
    printf("%s", s);
    getchar();
    return 0;
}
#endif
