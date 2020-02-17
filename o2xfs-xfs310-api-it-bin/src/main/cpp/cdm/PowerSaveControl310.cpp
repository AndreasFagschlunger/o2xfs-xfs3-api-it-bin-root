#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_PowerSaveControl310IT.h"

static WFSCDMPOWERSAVECONTROL PowerSaveControl;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_PowerSaveControl310IT_createDefault(JNIEnv *env, jobject obj) {

	PowerSaveControl.usMaxPowerSaveRecoveryTime = 10;
	
	return NewAddress(env, &PowerSaveControl);
}
