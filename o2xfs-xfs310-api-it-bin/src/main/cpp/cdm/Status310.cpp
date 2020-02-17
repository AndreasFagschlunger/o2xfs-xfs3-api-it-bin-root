#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_Status310IT.h"

static WFSCDMSTATUS status;
static WFSCDMOUTPOS position;
static LPWFSCDMOUTPOS lppPositions[2];
static LPSTR lpszExtra = "Key1=Value1\0Key2=Value2\0";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_Status310IT_createDefault(JNIEnv *env, jobject obj) {
	status.fwDevice = WFS_CDM_DEVONLINE;
	status.fwDispenser = WFS_CDM_DISPOK;
	status.fwIntermediateStacker = WFS_CDM_ISEMPTY;
	status.fwSafeDoor = WFS_CDM_DOORCLOSED;
	status.lppPositions = lppPositions;
	status.lpszExtra = lpszExtra;
	status.dwGuidLights[WFS_CDM_GUIDANCE_POSOUTBOTTOM] = WFS_CDM_GUIDANCE_CONTINUOUS | WFS_CDM_GUIDANCE_SLOW_FLASH | WFS_CDM_GUIDANCE_MEDIUM_FLASH;
	status.wDevicePosition = WFS_CDM_DEVICEINPOSITION;
	status.usPowerSaveRecoveryTime = 0;

	position.fwPosition = WFS_CDM_POSFRONT;
	position.fwShutter = WFS_CDM_SHTCLOSED;
	position.fwPositionStatus = WFS_CDM_PSEMPTY;
	position.fwTransport = WFS_CDM_TPOK;
	position.fwTransportStatus = WFS_CDM_TPSTATEMPTY;
	lppPositions[0] = &position;

	lppPositions[1] = NULL;

	return NewAddress(env, &status);
}
