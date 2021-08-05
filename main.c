#include <pthread.h>
#include <unistd.h>
#include "app_type.h"
#include "some_filter.h"

#define BUF_LEN 1024

FILTER_DEFINE(average_filter_cb,4);
FILTER_DEFINE(mid_filter_cb,4);

//#define filter_use  (&average_filter_cb)
//#define filter_use  (&average_moving_filter_cb)
#define filter_use  (&mid_filter_cb)


static void *filter_thread_function(void *arg)
{
    while(1)
    {
        char string[BUF_LEN];
        int deal_buf[BUF_LEN];

        int len = (int)arg;
        int i;
        float result;

        for(i = 0; i<len ;i++){
            scanf("%d",&deal_buf[i]);

            //result = average_filter(filter_use,deal_buf[i],false);
            result = mid_filter(filter_use,deal_buf[i],false);
            //result = lowpass_filter(deal_buf[i],0.8);
            //result = debounce(deal_buf[i]);
            //result = limit_filter(deal_buf[i],10,false);
            //result = LIMIT(deal_buf[i],2,5);
        }

        print_int_buffer(filter_use->buf,filter_use->len);
        printf("filter result :%.2f\n", result);
    }
}

int main(int argc,char *argv[])
{
    pthread_t filter_thread;
    int len =  atoi(argv[1]);
    pthread_create(&filter_thread,NULL,filter_thread_function,(void*)len);
    pthread_join(filter_thread,NULL);
    
    return 0;
}
