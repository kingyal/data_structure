/**************************************************
 * author: kingyal
 * time: 2020-11-22
 * description: 数据结构线性表的顺序表的代码实现，包含初始化，去初始化，插入，删除，打印等操作
 * ************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hi_type.h"
#include "hi_debug.h"
#include "linear_table.h"

/**************************************************
 * description: 
 *      线性链表的初始化，初始化为空表。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      执行成功，返回HI_SUCCESS；
 *      执行失败，返回HI_FAILURE。
 * ************************************************/
hi_s32 sQlistInit(sQlist *L) {
    int len;

    CHECK_NULL(L);

    len = LIST_INIT_SIZE * sizeof(hi_u32);
    L->addr = malloc(len);
    if (L->addr == HI_NULL) {
        HI_LOG_ERROR("L->addr malloc failed");
        return HI_FAILURE;
    }

    memset(L->addr, 0, len);

    L->len = 0;  // 实际存储的有效数据长度为0
    L->listsize = LIST_INIT_SIZE;  //最大有效数据长度

    return HI_SUCCESS;
}

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
hi_s32 sQlistInitData(sQlist *L,  hi_u32 *addr, hi_u32 len) {
    int i;
    hi_u32 *tmp_addr;

    CHECK_NULL(L);
    if (L->len != 0) {
        HI_LOG_ERROR("table is not first init, it should use sQlistInsert to insert data");
        return HI_FAILURE;
    }

    // 判断L的空间是否足够
    while(len >= L->listsize) {
        tmp_addr = realloc(L->addr, (L->listsize + LIST_INC_SIZE) * sizeof(hi_u32));
        if (L->addr == HI_NULL) {
            HI_LOG_ERROR("L->addr malloc failed");
            return HI_FAILURE;
        }
        L->addr = tmp_addr;
        L->listsize += LIST_INC_SIZE;
    }

    for (i = 0; i < len; i++) {
        L->addr[i] = addr[i];
    }
    L->len = len;

    return HI_SUCCESS;
}

/**************************************************
 * description: 
 *      线性链表的去初始化。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      无
 * ************************************************/
hi_void sQlistDeinit(sQlist *L) {

    if (L == HI_NULL) {
        return;
    }

    if (L->addr == HI_NULL) {
        return;
    }

    free(L->addr);
}

/**************************************************
 * description: 
 *      输出线性链表的数据。
 * parament:
 *      param_1：为输入参数，要申请的线性链表实例指针。
 * return:
 *      无
 * ************************************************/
hi_s32 sQlistPrintf(sQlist *L) {
    hi_u32 i;
    CHECK_NULL(L);

    if (LOG_LEVEL < 4) {
        HI_LOG_ERROR("LOG_LEVEL is too low, it should be greater than or equal to 4");
        return HI_SUCCESS;
    }

    if (L->len <= 0) {
        HI_LOG_INFO("L is empty table, please add element!");
        return HI_SUCCESS;
    }

    for (i =0 ; i < L->len; i++) {
        HI_LOG_PRINTF("----");
    }
    HI_LOG_PRINTF("\n");

    HI_LOG_PRINTF("the index  : \n");
    for (i =0 ; i < L->len; i++) {
        HI_LOG_PRINTF("%-4d", i);
    }
    HI_LOG_PRINTF("\n");

    HI_LOG_PRINTF("the element: \n");
    for (i =0 ; i < L->len; i++) {
        HI_LOG_PRINTF("%-4d", L->addr[i]);
    }
    HI_LOG_PRINTF("\n");

    for (i =0 ; i < L->len; i++) {
        HI_LOG_PRINTF("----");
    }
    HI_LOG_PRINTF("\n");

    return HI_SUCCESS;
}

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
hi_s32 sQlistInsert(sQlist *L, hi_u32 i, hi_u32 elem) {
    hi_u32 *tmp_addr = HI_NULL;
    hi_u32 *p, *q;

    CHECK_NULL(L);

    // 判断位置i是否合法
    if (i < 1 || i > L->len) {
        HI_LOG_ERROR("i is between 1 and %d", L->len);
        return HI_FAILURE;
    }

    // 判断L是否已经存满，若已经存满，则需要添加新空间
    if (L->len == L->listsize) {
        tmp_addr = realloc(L->addr, (L->listsize + LIST_INC_SIZE) * sizeof(hi_u32));
        if (L->addr == HI_NULL) {
            HI_LOG_ERROR("L->addr malloc failed");
            return HI_FAILURE;
        }
        L->addr = tmp_addr;
        L->listsize += LIST_INC_SIZE;
    }

    // 插入新元素
    p = &(L->addr[i-1]);
    for (q = &(L->addr[L->len - 1]); q >= p; q--) {
        *(q+1) = *(q);
    }
    L->addr[i-1] = elem;
    L->len++;

    return HI_SUCCESS;
}

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
hi_s32 sQlistdelete(sQlist *L, int i) {
    hi_u32 *tmp_addr = HI_NULL;
    hi_u32 *p = HI_NULL, *q = HI_NULL;

    CHECK_NULL(L);

    // 判断位置i是否合法
    if (i < 1 || i > L->len) {
        HI_LOG_ERROR("element index is between 1 and %d", L->len);
        return HI_FAILURE;
    }

    // 插入新元素

    for (p = &(L->addr[i-1]), q = &(L->addr[L->len - 1]); q != p; p++) {
        *(p) = *(p+1);
    }
    L->len--;

    return HI_SUCCESS;
}



