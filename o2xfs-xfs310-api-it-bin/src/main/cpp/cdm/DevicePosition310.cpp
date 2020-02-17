#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_DevicePosition310IT.h"

static WFSCDMDEVICEPOSITION DevicePosition;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_DevicePosition310IT_createDefault(JNIEnv *env, jobject obj) {
	
	DevicePosition.wPosition = WFS_CDM_DEVICENOTINPOSITION;
	
	return NewAddress(env, &DevicePosition);
}
