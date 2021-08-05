#ifndef  __SOMEFILTER_H_
#define  __SOMEFILTER_H_

#include "app_type.h"

typedef struct 
{
	uint16_t len;
	uint16_t index;
	int *buf;
}filter_t;

#define FILTER_DEFINE(_name, _len) \
		static int __##_name##_buf[_len];	\
		filter_t _name = {			\
			.len	= _len,	\
			.index = 0,				\
			.buf	= __##_name##_buf,	\
		}

float average_filter(filter_t *filter,const int data,bool moving_enable);
float mid_filter(filter_t *filter,const int data,bool moving_enable);
float lowpass_filter(float data,float k);
float debounce(float data);
float limit_filter(float data,float limit,bool limit_direction);
#endif
