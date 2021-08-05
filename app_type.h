#ifndef APP_TYPE_H_
#define APP_TYPE_H_

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define uint8_t __uint8_t
#define uint16_t __uint16_t
#define uint32_t __uint32_t

#define  MAX(a,b) ((a) > (b) ? (a) : (b))
#define  MIN(a,b) ((a) < (b) ? (a) : (b))
#define  LIMIT(value,min,max) (MIN(max, MAX(min,value)))

#define  ABS(x) ( (x)>(0) ? (x): (-x) )

//#define PRINT_BUFFER(buf,len)  \
do {\
    for(int _print_i = 0; _print_i<len; _print_i++){\
        printf("%d ",buf[_print_i]);\
    }\
     printf("\n");\
}while (0);\

void print_buffer(uint8_t *buf,uint16_t len);
void print_int_buffer(int *buf,uint16_t len);
int strsep_deal(char *string ,uint8_t *buf);

#endif
