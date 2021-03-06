#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_Capabilities330IT.h"

static WFSCDMCAPS caps;
static LPSTR lpszExtra = "Key1=Value1\0Key2=Value2\0";
static DWORD lpdwSynchronizableCommands[] = { WFS_CMD_CDM_DISPENSE, WFS_CMD_CDM_PRESENT, WFS_CMD_CDM_REJECT, WFS_CMD_CDM_RETRACT, 0 };

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_Capabilities330IT_createDefault(JNIEnv *env, jobject obj) {
	caps.wClass = WFS_SERVICE_CLASS_CDM;
	caps.fwType = WFS_CDM_SELFSERVICEBILL;
	caps.wMaxDispenseItems = 40;
	caps.bCompound = false;
	caps.bShutter = true;
	caps.bShutterControl = false;
	caps.fwRetractAreas = WFS_CDM_RA_REJECT | WFS_CDM_RA_RETRACT | WFS_CDM_RA_TRANSPORT;
	caps.fwRetractTransportActions = WFS_CDM_PRESENT | WFS_CDM_RETRACT | WFS_CDM_REJECT;
	caps.fwRetractStackerActions = WFS_CDM_PRESENT | WFS_CDM_RETRACT | WFS_CDM_REJECT;
	caps.bSafeDoor = false;
	caps.bCashBox = false;
	caps.bIntermediateStacker = true;
	caps.bItemsTakenSensor = true;
	caps.fwPositions = WFS_CDM_POSFRONT;
	caps.fwMoveItems = WFS_CDM_FROMCU | WFS_CDM_TOTRANSPORT;
	caps.fwExchangeType = WFS_CDM_EXBYHAND;
	caps.lpszExtra = lpszExtra;
	caps.dwGuidLights[WFS_CDM_GUIDANCE_POSOUTNULL] = WFS_CDM_GUIDANCE_SLOW_FLASH | WFS_CDM_GUIDANCE_QUICK_FLASH | WFS_CDM_GUIDANCE_RED | WFS_CDM_GUIDANCE_GREEN;
	caps.dwGuidLights[WFS_CDM_GUIDLIGHTS_MAX] = WFS_CDM_GUIDANCE_SLOW_FLASH | WFS_CDM_GUIDANCE_MEDIUM_FLASH | WFS_CDM_GUIDANCE_CONTINUOUS;
	caps.bPowerSaveControl = false;
	caps.bPrepareDispense = true;
	caps.bAntiFraudModule = true;
	caps.dwItemInfoTypes = WFS_CDM_ITEM_IMAGEFILE | WFS_CDM_ITEM_SERIALNUMBER;
	caps.bBlacklist = TRUE;
	caps.lpdwSynchronizableCommands = lpdwSynchronizableCommands;

	return NewAddress(env, &caps);
}
