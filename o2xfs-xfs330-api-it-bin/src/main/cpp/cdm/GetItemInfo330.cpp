#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_GetItemInfo330IT.h"

static WFSCDMGETITEMINFO GetItemInfo;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_GetItemInfo330IT_createDefault(JNIEnv *env, jobject obj) {
	GetItemInfo.usLevel = WFS_CDM_LEVEL_3;
	GetItemInfo.usIndex = 1;
	GetItemInfo.dwItemInfoType = WFS_CDM_ITEM_IMAGEFILE | WFS_CDM_ITEM_SIGNATURE;
	return NewAddress(env, &GetItemInfo);
}
