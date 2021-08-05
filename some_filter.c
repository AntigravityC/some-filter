#include "app_type.h"
#include "some_filter.h"


float average_filter(filter_t *filter,const int data,bool moving_enable)	
{
	int i;
	float sum = 0;
	if(!moving_enable){
		filter->buf[filter->index++ % filter->len] = data;
	}
	else{
		for(i = 0; i<filter->len-1; i++){
			filter->buf[i] = filter->buf[i+1];
		}

		filter->buf[filter->len-1] = data;
  	}

  	for(i = 0; i < filter->len; i++){
        sum += filter->buf[i];
  	}
  	return(sum / filter->len);		  
}

float mid_filter(filter_t *filter,const int data,bool moving_enable)
{
    int  temp_swap;
	int  temp_buf[filter->len];
    unsigned int i,j;

	if(!moving_enable){
		filter->buf[filter->index++ % filter->len] = data;
	}
	else{
		for(i = 0; i<filter->len-1; i++){
			filter->buf[i] = filter->buf[i+1];
		}

		filter->buf[filter->len-1] = data;
	}

    memcpy(temp_buf,filter->buf,filter->len * sizeof(int));

	for (j=0;j<filter->len-1;j++){
		for (i=0;i<filter->len-j-1;i++){
			if ( temp_buf[i]>temp_buf[i+1] ){
				temp_swap = temp_buf[i];
				temp_buf[i] = temp_buf[i+1]; 
				temp_buf[i+1] = temp_swap;
			}
		}
	}
    
	printf("%s \n",__FUNCTION__);
	print_int_buffer(temp_buf,filter->len);

	if(filter->len & 1){
		//printf("temp_buf[%d]: %.2f \n",filter->len/ 2,(float)temp_buf[filter->len / 2]);
		return (float)temp_buf[filter->len / 2];
	}
	else{
		//printf("(temp_buf[%d] + temp_buf[%d])/2 : %.2f \n",filter->len / 2-1,filter->len / 2,(float)(temp_buf[filter->len / 2] + temp_buf[filter->len / 2 + 1]) / 2);
	  	return (float)(temp_buf[filter->len / 2 -1 ] + temp_buf[filter->len / 2]) / 2;
	}
}

float lowpass_filter(float data,float k)
{
	static float result = 0;
	printf(" %s : result =  %.2f *  %.2f  + %.2f * %.2f  \n",__FUNCTION__,data,k,result,(1-k));	
	result =  data * k + result *(1-k)  ;
    return result;
}

float debounce(float data)
{
	static float result ,last_value = 0;

	printf(" last: %.2f   data %.2f    \n",result,data);

	result =  (data == last_value ? data : result);
 	last_value = data;
    return result;
}


float limit_filter(float data,float limit,bool limit_direction)  
{
   	static float  result ;
	printf(" last: %.2f   data %.2f    \n",result,data);

	if(!limit_direction){
		if(ABS(data - result) < limit){
			result = data;
		}
	}
	else{
		if(ABS(data - result) >= limit){
			result = data;
		}
	}

	return result;
}
