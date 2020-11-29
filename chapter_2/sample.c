#include <stdio.h>
#include "hi_type.h"
#include "hi_debug.h"
#include "linear_table.h"

sQlist g_sQlist;

void main()
{
	hi_u32 ret;
	hi_u32 i;
	hi_u32 addr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	// 初始化
	ret = sQlistInit(&g_sQlist);
	if (ret != HI_SUCCESS) {
		HI_LOG_ERROR("g_sQlist init failed");
		return;
	}

	// 初始化数据
	ret = sQlistInitData(&g_sQlist,  addr, 10);
	if (ret != HI_SUCCESS) {
		HI_LOG_ERROR("g_sQlist init data failed");
		return;
	}
	//输出
	ret = sQlistPrintf(&g_sQlist);
	if (ret != HI_SUCCESS) {
		HI_LOG_ERROR("g_sQlist printf failed");
		return;
	}

	// 添加第1个到第20个元素
	for (i = 1; i <= 20; i++) {
		ret = sQlistInsert(&g_sQlist, i, i);
		if (ret != HI_SUCCESS) {
			HI_LOG_ERROR("g_sQlist insert failed");
			return;
		}
	}
	
	//输出
	ret = sQlistPrintf(&g_sQlist);
	if (ret != HI_SUCCESS) {
		HI_LOG_ERROR("g_sQlist printf failed");
		return;
	}

	// 删除第10个到第1个元素
	for (i = 10; i >= 1; i--) {
		ret = sQlistdelete(&g_sQlist, i);
		if (ret != HI_SUCCESS) {
			HI_LOG_ERROR("g_sQlist delete failed");
			return;
		}
	}

	//输出
	ret = sQlistPrintf(&g_sQlist);
	if (ret != HI_SUCCESS) {
		HI_LOG_ERROR("g_sQlist printf failed");
		return;
	}

	//去初始化
	sQlistDeinit(&g_sQlist);

	return;
}
