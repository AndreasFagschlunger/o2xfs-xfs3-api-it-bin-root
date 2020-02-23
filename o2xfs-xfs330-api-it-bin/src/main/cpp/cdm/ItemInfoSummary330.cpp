#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_ItemInfoSummary330IT.h"

static WFSCDMITEMINFOSUMMARY ItemInfoSummary;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_ItemInfoSummary330IT_createDefault(JNIEnv *env, jobject obj) {
	ItemInfoSummary.usLevel = WFS_CDM_LEVEL_3;
	ItemInfoSummary.usNumOfItems = 3;
	return NewAddress(env, &ItemInfoSummary);
}
