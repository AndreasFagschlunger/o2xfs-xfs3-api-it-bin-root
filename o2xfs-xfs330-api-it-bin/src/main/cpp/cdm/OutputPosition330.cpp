#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_OutputPosition330IT.h"

static WFSCDMOUTPOS Position;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_OutputPosition330IT_createDefault(JNIEnv *env, jobject obj) {
	Position.fwPosition = WFS_CDM_POSFRONT;
	Position.fwShutter = WFS_CDM_SHTOPEN;
	Position.fwPositionStatus = WFS_CDM_PSNOTEMPTY;
	Position.fwTransport = WFS_CDM_TPOK;
	Position.fwTransportStatus = WFS_CDM_TPSTATNOTEMPTY;
	Position.fwJammedShutterPosition = WFS_CDM_SHUTTERPOS_NOTJAMMED;
	return NewAddress(env, &Position);
}
