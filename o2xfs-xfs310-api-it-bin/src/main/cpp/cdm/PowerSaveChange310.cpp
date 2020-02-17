#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_PowerSaveChange310IT.h"

static WFSCDMPOWERSAVECHANGE PowerSaveChange;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_PowerSaveChange310IT_createDefault(JNIEnv *env, jobject obj) {

	PowerSaveChange.usPowerSaveRecoveryTime = 5;
	
	return NewAddress(env, &PowerSaveChange);
}
