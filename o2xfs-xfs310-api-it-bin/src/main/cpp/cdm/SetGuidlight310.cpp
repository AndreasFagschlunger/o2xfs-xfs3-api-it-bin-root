#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_SetGuidlight310IT.h"

static WFSCDMSETGUIDLIGHT SetGuidLight;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_SetGuidlight310IT_createDefault(JNIEnv *env, jobject obj) {
	SetGuidLight.wGuidLight = WFS_CDM_GUIDANCE_POSOUTFRONT;
	SetGuidLight.dwCommand = WFS_CDM_GUIDANCE_MEDIUM_FLASH | WFS_CDM_GUIDANCE_GREEN;

	return NewAddress(env, &SetGuidLight);
}
