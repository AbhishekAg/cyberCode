#include <stdio.h>

#define uint32_t int

/* Varants of ROUNDUP that preserve datatype */
#define ALIGN_UP(val, align)                              \
    ({                                                 \
        uint32_t _val = (uint32_t) (val);         \
        uint32_t _mask = (uint32_t) (align) - 1;  \
        (typeof (val)) ((_val + _mask) & ~_mask); \
    })
#define ALIGN_DOWN(val, align)                            \
    ({                                                 \
        uint32_t _val = (uint32_t) (val);         \
        uint32_t _mask = (uint32_t) (align) - 1;  \
        (typeof (val)) (_val & ~_mask);           \
    })

int main()
{
    int val, align, opt;
    printf("Input Value: ");
    scanf("%d", &val);
    printf("Input align: ");
    scanf("%d", &align);

    while(1) {
	printf("Enter option: ");
	scanf("%d", &opt);
	switch(opt) {
	    case 1:
	      printf("ALIGN UP value: %d\n", ALIGN_UP(val, align));
	      break;
	    case 2:
	      printf("ALIGN DOWN value: %d\n", ALIGN_DOWN(val, align));
	      break;
	    default:
	      break;
	}
    }
    return 0;
}
