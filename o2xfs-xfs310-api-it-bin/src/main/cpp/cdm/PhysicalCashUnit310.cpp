#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_PhysicalCashUnit310IT.h"

static WFSCDMPHCU PhysicalCU;
static LPSTR lpPhysicalPositionName = "PhysicalPositionName";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_PhysicalCashUnit310IT_createDefault(JNIEnv *env, jobject obj) {
	PhysicalCU.lpPhysicalPositionName = lpPhysicalPositionName;
	strncpy(PhysicalCU.cUnitID, "EUR A", 5);
	PhysicalCU.ulInitialCount = 100;
	PhysicalCU.ulCount = 230;
	PhysicalCU.ulRejectCount = 1;
	PhysicalCU.ulMaximum = 2000;
	PhysicalCU.usPStatus = WFS_CDM_STATCUOK;
	PhysicalCU.bHardwareSensor = TRUE;
	PhysicalCU.ulDispensedCount = 56;
	PhysicalCU.ulPresentedCount = 55;
	PhysicalCU.ulRetractedCount = 0;

	return NewAddress(env, &PhysicalCU);
}
