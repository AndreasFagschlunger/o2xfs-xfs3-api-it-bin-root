#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_PrepareDispense310IT.h"

static WFSCDMPREPAREDISPENSE PrepareDispense;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_PrepareDispense310IT_createDefault(JNIEnv *env, jobject obj) {
	
	PrepareDispense.wAction = WFS_CDM_START;
	
	return NewAddress(env, &PrepareDispense);
}
