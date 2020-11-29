#ifndef __HI_LINEAR_TABLE_H__
#define __HI_LINEAR_TABLE_H__

#include "hi_type.h"

#define LIST_INIT_SIZE 20  //分配的初始长度
#define LIST_INC_SIZE  5  //每次扩增的长度

typedef struct {
    hi_u32 *addr;  //数据起始地址
    hi_u32 len; // 有效数据长度
    hi_u32 listsize; // 当前分配的元素的存储容量，即链表整体长度
} sQlist;

/**************************************************
 * description: 
 *      线性链表的初始化。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      执行成功，返回HI_SUCCESS；
 *      执行失败，返回HI_FAILURE。
 * ************************************************/
hi_s32 sQlistInit(sQlist *L);

/**************************************************
 * description: 
 *      线性链表放入初始化数据。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针；
 *      param_2: 为输入的初始数据的首地址。
 * return:
 *      执行成功，返回HI_SUCCESS；
 *      执行失败，返回HI_FAILURE。
 * ************************************************/
hi_s32 sQlistInitData(sQlist *L,  hi_u32 *addr, hi_u32 len);

/**************************************************
 * description: 
 *      线性链表的去初始化。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      无
 * ************************************************/
hi_void sQlistDeinit(sQlist *L);

/**************************************************
 * description: 
 *      输出线性链表的数据。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      无
 * ************************************************/
hi_s32 sQlistPrintf(sQlist *L);

/**************************************************
 * description: 
 *      线性链表的插入操作。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针;
 *      param_2：为输入参数，要插入的位置;
 *      param_3：为输入参数，要插入的元素。
 * return:
 *      执行成功，返回HI_SUCCESS；
 *      执行失败，返回HI_FAILURE。
 * attention:
 *      param_2是要将新元素插入到第i个位置，i从1开始, 但链表中的元素下标从0开始。
 * ************hi_s32************************************/
hi_s32 sQlistInsert(sQlist *L, hi_u32 i, hi_u32 elem);

/**************************************************
 * description: 
 *      线性链表的删除操作。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针;
 *      param_2：为输入参数，要删除的位置;
 * return:
 *      执行成功，返回HI_SUCCESS；
 *      执行失败，返回HI_FAILURE。
 * attention:
 *      param_2是要删除第i个位置的元素，i从1开始, 但链表中的元素下标从0开始。
 * ************hi_s32************************************/
hi_s32 sQlistdelete(sQlist *L, int i);

#endif