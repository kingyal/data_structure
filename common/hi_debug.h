#ifndef __HI_DEBUG_H__
#define __HI_DEBUG_H__

#include <stdio.h>

/* 指针判空 */
#define CHECK_NULL(ptr)                             \
 do {                                               \
        if (ptr == HI_NULL) {                       \
            HI_LOG_ERROR("ptr is NULL");            \
            return HI_FAILURE;                      \
        }                                           \
}while(0);                                          \

/*打印等级*/
#define HI_LOG(levle, fmt...) \
	do{ \
		printf("[%s][%s]:[%s]:[%d]", levle, __FILE__, __FUNCTION__, __LINE__); \
		printf(fmt); \
		printf("\n"); \
	}while(0)

#define HI_LOG_PRINTF(fmt...) \
	do{ \
		printf(fmt); \
	}while(0)

#define LOG_LEVEL 4  //打印级别控制的宏定义

#if(LOG_LEVEL == 0)
#define HI_LOG_FATAL(fmt...)
#define HI_LOG_ERROR(fmt...)
#define HI_LOG_WARN(fmt...)
#define HI_LOG_INFO(fmt...)
#define HI_LOG_DEBUG(fmt...)
#elif(LOG_LEVEL == 1)
#define HI_LOG_FATAL(fmt...) HI_LOG("FATAL", fmt)
#define HI_LOG_ERROR(fmt...)
#define HI_LOG_WARN(fmt...)
#define HI_LOG_INFO(fmt...)
#define HI_LOG_DEBUG(fmt...)
#elif(LOG_LEVEL == 2)
#define HI_LOG_FATAL(fmt...) HI_LOG("FATAL", fmt)
#define HI_LOG_ERROR(fmt...) HI_LOG("ERROR", fmt)
#define HI_LOG_WARN(fmt...)
#define HI_LOG_INFO(fmt...)
#define HI_LOG_DEBUG(fmt...)
#elif(LOG_LEVEL == 3)
#define HI_LOG_FATAL(fmt...) HI_LOG("FATAL", fmt)
#define HI_LOG_ERROR(fmt...) HI_LOG("ERROR", fmt)
#define HI_LOG_WARN(fmt...) HI_LOG("WARN", fmt)
#define HI_LOG_INFO(fmt...)
#define HI_LOG_DEBUG(fmt...)
#elif(LOG_LEVEL == 4)
#define HI_LOG_FATAL(fmt...) HI_LOG("FATAL", fmt)
#define HI_LOG_ERROR(fmt...) HI_LOG("ERROR", fmt)
#define HI_LOG_WARN(fmt...) HI_LOG("WARN", fmt)
#define HI_LOG_INFO(fmt...) HI_LOG("INFO", fmt)
#define HI_LOG_DEBUG(fmt...)
#elif(LOG_LEVEL == 5)
#define HI_LOG_FATAL(fmt...) HI_LOG("FATAL", fmt)
#define HI_LOG_ERROR(fmt...) HI_LOG("ERROR", fmt)
#define HI_LOG_WARN(fmt...) HI_LOG("WARN", fmt)
#define HI_LOG_INFO(fmt...) HI_LOG("INFO", fmt)
#define HI_LOG_DEBUG(fmt...) HI_LOG("DEBUG", fmt)
#endif

#endif