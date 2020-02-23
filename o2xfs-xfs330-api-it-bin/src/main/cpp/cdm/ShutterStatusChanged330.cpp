#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_ShutterStatusChanged330IT.h"

static WFSCDMSHUTTERSTATUSCHANGED ShutterStatusChanged;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_ShutterStatusChanged330IT_createDefault(JNIEnv *env, jobject obj) {
	ShutterStatusChanged.fwPosition = WFS_CDM_POSFRONT;
	ShutterStatusChanged.fwShutter = WFS_CDM_SHTCLOSED;
	return NewAddress(env, &ShutterStatusChanged);
}
