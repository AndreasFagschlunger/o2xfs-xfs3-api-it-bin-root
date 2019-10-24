#include <Windows.h>
#include <XFSCDM.H>
#include "../../public/cdm/at_o2xfs_xfs_v3_cdm_Capabilities3IT.h"
#include <common.h>

static LPSTR lpszExtra = "Key1=Value1\0Key2=Value2\0";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_Capabilities3IT_createDefault(JNIEnv *env, jobject obj) {
	LPWFSCDMCAPS caps = (LPWFSCDMCAPS) malloc(sizeof(WFSCDMCAPS));
	caps->wClass = WFS_SERVICE_CLASS_CDM;
	caps->fwType = WFS_CDM_SELFSERVICEBILL;
	caps->wMaxDispenseItems = 40;
	caps->bCompound = false;
	caps->bShutter = true;
	caps->bShutterControl = false;
	caps->fwRetractAreas = WFS_CDM_RA_REJECT | WFS_CDM_RA_RETRACT | WFS_CDM_RA_TRANSPORT;
	caps->fwRetractTransportActions = WFS_CDM_PRESENT | WFS_CDM_RETRACT | WFS_CDM_REJECT;
	caps->fwRetractStackerActions = WFS_CDM_PRESENT | WFS_CDM_RETRACT | WFS_CDM_REJECT;
	caps->bSafeDoor = false;
	caps->bCashBox = false;
	caps->bIntermediateStacker = true;
	caps->bItemsTakenSensor = true;
	caps->fwPositions = WFS_CDM_POSFRONT;
	caps->fwMoveItems = WFS_CDM_FROMCU | WFS_CDM_TOTRANSPORT;
	caps->fwExchangeType = WFS_CDM_EXBYHAND;
	caps->lpszExtra = lpszExtra;
	return NewAddress(env, &caps);
}