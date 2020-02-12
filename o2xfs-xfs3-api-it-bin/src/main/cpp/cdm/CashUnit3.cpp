/*
 * Copyright (c) 2017, Andreas Fagschlunger. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *   - Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *
 *   - Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */


#include <Windows.h>
#include <XFSCDM.H>
#include "common.h"
#include "cdm/at_o2xfs_xfs_v3_cdm_CashUnit3IT.h"

static WFSCDMCASHUNIT CashUnit;
static WFSCDMPHCU PhysicalCUs[2];
static LPWFSCDMPHCU lppPhysical[2];
static LPSTR PhysicalPositionName[] = { "BIN1", "BIN2" };

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_CashUnit3IT_createDefault(JNIEnv *env, jobject obj) {
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

	int index = 0;
	PhysicalCUs[index].lpPhysicalPositionName = PhysicalPositionName[index];
	strncpy(PhysicalCUs[index].cUnitID, CashUnit.cUnitID, 5);
	PhysicalCUs[index].ulInitialCount = 500;
	PhysicalCUs[index].ulCount = 0;
	PhysicalCUs[index].ulRejectCount = 1;
	PhysicalCUs[index].ulMaximum = 0;
	PhysicalCUs[index].usPStatus = WFS_CDM_STATCULOW;
	PhysicalCUs[index].bHardwareSensor = true;
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
	lppPhysical[index] = &PhysicalCUs[index];

	return NewAddress(env, &CashUnit);
}
