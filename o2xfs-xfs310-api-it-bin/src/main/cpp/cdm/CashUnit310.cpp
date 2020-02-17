#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_10_cdm_CashUnit310IT.h"

static WFSCDMCASHUNIT CashUnit;
static WFSCDMPHCU PhysicalCUs[2];
static LPWFSCDMPHCU lppPhysical[2];
static LPSTR PhysicalPositionName[] = { "BIN1", "BIN2" };

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_110_cdm_CashUnit310IT_createDefault(JNIEnv *env, jobject obj) {
	CashUnit.usNumber = 3;
	CashUnit.usType = WFS_CDM_TYPEBILLCASSETTE;
	CashUnit.lpszCashUnitName = NULL;
	strncpy(CashUnit.cUnitID, "EUR B", 5);
	strncpy(CashUnit.cCurrencyID, "EUR", 3);
	CashUnit.ulValues = 10;
	CashUnit.ulInitialCount = 1000;
	CashUnit.ulCount = 376;
	CashUnit.ulRejectCount = 6;
	CashUnit.ulMinimum = 0;
	CashUnit.ulMaximum = 0;
	CashUnit.bAppLock = false;
	CashUnit.usStatus = WFS_CDM_STATCUOK;
	CashUnit.usNumPhysicalCUs = 2;
	CashUnit.lppPhysical = lppPhysical;
	CashUnit.ulDispensedCount = 200;
	CashUnit.ulPresentedCount = 199;
	CashUnit.ulRetractedCount = 1;

	int index = 0;
	PhysicalCUs[index].lpPhysicalPositionName = PhysicalPositionName[index];
	strncpy(PhysicalCUs[index].cUnitID, CashUnit.cUnitID, 5);
	PhysicalCUs[index].ulInitialCount = 500;
	PhysicalCUs[index].ulCount = 0;
	PhysicalCUs[index].ulRejectCount = 1;
	PhysicalCUs[index].ulMaximum = 0;
	PhysicalCUs[index].usPStatus = WFS_CDM_STATCULOW;
	PhysicalCUs[index].bHardwareSensor = true;
	PhysicalCUs[index].ulDispensedCount = 100;
	PhysicalCUs[index].ulPresentedCount = 100;
	PhysicalCUs[index].ulRejectCount = 0;
	lppPhysical[index] = &PhysicalCUs[index];

	index++;
	PhysicalCUs[index].lpPhysicalPositionName = PhysicalPositionName[index];
	strncpy(PhysicalCUs[index].cUnitID, CashUnit.cUnitID, 5);
	PhysicalCUs[index].ulInitialCount = 500;
	PhysicalCUs[index].ulCount = 376;
	PhysicalCUs[index].ulRejectCount = 5;
	PhysicalCUs[index].ulMaximum = 0;
	PhysicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	PhysicalCUs[index].bHardwareSensor = true;
	PhysicalCUs[index].ulDispensedCount = 100;
	PhysicalCUs[index].ulPresentedCount = 99;
	PhysicalCUs[index].ulRejectCount = 1;
	lppPhysical[index] = &PhysicalCUs[index];

	return NewAddress(env, &CashUnit);
}
