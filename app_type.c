#include "app_type.h"


void print_buffer(uint8_t *buf,uint16_t len) 
{
    for(int i = 0; i<len; i++){
        printf("%d ",buf[i]);
    }
     printf("\n");
}

void print_int_buffer(int *buf,uint16_t len) 
{
    for(int i = 0; i<len; i++){
        printf("%d ",buf[i]);
    }   
     printf("\n");
}


int strsep_deal(char *string ,uint8_t *buf)
{
    char *running;
    char *token;
    uint8_t i,j;
    running = string;

    for(i=0;(token = strsep (&running," "))!=NULL;i++){
        //buf[i] = atoi(token);
        //sscanf(token,"%x",&buf[i]);
        sscanf(token,"%d",&buf[i]);
    }

    /*for(uint8_t j=0;j<i;j++){
        printf("%d\n",buf[j] );
    }*/
    return i;
}
