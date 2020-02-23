#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_GetAllItemsInfo330IT.h"

static WFSCDMGETALLITEMSINFO GetAllItemsInfo;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_GetAllItemsInfo330IT_createDefault(JNIEnv *env, jobject obj) {
	GetAllItemsInfo.usLevel = WFS_CDM_LEVEL_2;
	return NewAddress(env, &GetAllItemsInfo);
}
