#include <stdio.h>

#define FIRST_XDU_PKT_OFFSET 128
#define FIRST_XDU_PD_OFFSET  16
#define xdu_size 512

int main()
{
    int used_xdus = 0, Q = 0, R = 0;
    int total_len = 1500;

    Q = (total_len + FIRST_XDU_PKT_OFFSET - FIRST_XDU_PD_OFFSET) / (xdu_size - FIRST_XDU_PD_OFFSET);
    R = (total_len + FIRST_XDU_PKT_OFFSET - FIRST_XDU_PD_OFFSET) % (xdu_size - FIRST_XDU_PD_OFFSET);
    used_xdus = Q + (R ? 1 : 0);

    printf("%d %d %d\n", Q, R, used_xdus);
    return 0;
}
