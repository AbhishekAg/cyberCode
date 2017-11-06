#include <stdio.h>
int main() {
    int i;
    long x = 0x112A380; /* Value to play with */
    unsigned char *ptr = (char *) &x; /* Byte pointer */

    /* Observe value in host byte order */
    printf("x in hex: %x\n", x);
    printf("x by bytes: ");

    for (i=0; i < sizeof(long); i++)
	printf("%x\t", ptr[i]);
    printf("\n");

    /* Observe value in network byte order */
    x = htonl(x);
    printf("\nAfter htonl()\n");
    printf("x in hex: %x\n", x);
    printf("x by bytes: ");

    for (i=0; i < sizeof(long); i++)
	printf("%x\t", ptr[i]);
    printf("\n");
}
