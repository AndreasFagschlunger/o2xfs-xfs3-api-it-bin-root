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
#include "cdm/at_o2xfs_xfs_v3_cdm_CashUnitInfo3IT.h"

static WFSCDMCUINFO cashUnitInfo;
static WFSCDMCASHUNIT cashUnits[6];
static LPWFSCDMCASHUNIT lppList[6];
static WFSCDMPHCU physicalCUs[6];
static LPWFSCDMPHCU lppPhysical[6];
static LPSTR physicalPositionNames[6] = {"COMPARTMENT1", "COMPARTMENT2", "SLOT1", "SLOT2", "SLOT3", "SLOT4"};

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_CashUnitInfo3IT_createDefault(JNIEnv *env, jobject obj) {
	cashUnitInfo.usTellerID = 0;
	cashUnitInfo.usCount = 6;
	cashUnitInfo.lppList = lppList;

	for(int i = 0; i < 6; i++) {
		lppList[i] = &cashUnits[i];
		lppPhysical[i] = &physicalCUs[i];
		cashUnits[i].lppPhysical = &lppPhysical[i];
	}

	int index = 0;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPERETRACTCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "99999", 5);
	strncpy(cashUnits[index].cCurrencyID, "   ", 3);
	cashUnits[index].ulValues = 0;
	cashUnits[index].ulInitialCount = 0;
	cashUnits[index].ulCount = 0;
	cashUnits[index].ulRejectCount = 0;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = 0;
	physicalCUs[index].ulCount = 0;
	physicalCUs[index].ulRejectCount = 0;
	physicalCUs[index].ulMaximum = 50;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	index++;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPEREJECTCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "99999", 5);
	strncpy(cashUnits[index].cCurrencyID, "   ", 3);
	cashUnits[index].ulValues = 0;
	cashUnits[index].ulInitialCount = 0;
	cashUnits[index].ulCount = 4;
	cashUnits[index].ulRejectCount = 0;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = 0;
	physicalCUs[index].ulCount = 4;
	physicalCUs[index].ulRejectCount = 0;
	physicalCUs[index].ulMaximum = 200;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	index++;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPEBILLCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "00001", 5);
	strncpy(cashUnits[index].cCurrencyID, "EUR", 3);
	cashUnits[index].ulValues = 10000;
	cashUnits[index].ulInitialCount = 100;
	cashUnits[index].ulCount = 98;
	cashUnits[index].ulRejectCount = 1;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = cashUnits[index].ulInitialCount;
	physicalCUs[index].ulCount = cashUnits[index].ulCount;
	physicalCUs[index].ulRejectCount = cashUnits[index].ulRejectCount;
	physicalCUs[index].ulMaximum = 2200;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	index++;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPEBILLCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "00002", 5);
	strncpy(cashUnits[index].cCurrencyID, "EUR", 3);
	cashUnits[index].ulValues = 5000;
	cashUnits[index].ulInitialCount = 100;
	cashUnits[index].ulCount = 98;
	cashUnits[index].ulRejectCount = 1;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = cashUnits[index].ulInitialCount;
	physicalCUs[index].ulCount = cashUnits[index].ulCount;
	physicalCUs[index].ulRejectCount = cashUnits[index].ulRejectCount;
	physicalCUs[index].ulMaximum = 2200;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	index++;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPEBILLCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "00003", 5);
	strncpy(cashUnits[index].cCurrencyID, "EUR", 3);
	cashUnits[index].ulValues = 2000;
	cashUnits[index].ulInitialCount = 100;
	cashUnits[index].ulCount = 98;
	cashUnits[index].ulRejectCount = 1;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = cashUnits[index].ulInitialCount;
	physicalCUs[index].ulCount = cashUnits[index].ulCount;
	physicalCUs[index].ulRejectCount = cashUnits[index].ulRejectCount;
	physicalCUs[index].ulMaximum = 2200;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	index++;
	cashUnits[index].usNumber = index + 1;
	cashUnits[index].usType = WFS_CDM_TYPEBILLCASSETTE;
	cashUnits[index].lpszCashUnitName = NULL;
	strncpy(cashUnits[index].cUnitID, "00004", 5);
	strncpy(cashUnits[index].cCurrencyID, "EUR", 3);
	cashUnits[index].ulValues = 1000;
	cashUnits[index].ulInitialCount = 100;
	cashUnits[index].ulCount = 98;
	cashUnits[index].ulRejectCount = 1;
	cashUnits[index].ulMinimum = 0;
	cashUnits[index].ulMaximum = 0;
	cashUnits[index].bAppLock = false;
	cashUnits[index].usStatus = WFS_CDM_STATCUOK;
	cashUnits[index].usNumPhysicalCUs = 1;

	physicalCUs[index].lpPhysicalPositionName = physicalPositionNames[index];
	strncpy(physicalCUs[index].cUnitID, cashUnits[index].cUnitID, 5);
	physicalCUs[index].ulInitialCount = cashUnits[index].ulInitialCount;
	physicalCUs[index].ulCount = cashUnits[index].ulCount;
	physicalCUs[index].ulRejectCount = cashUnits[index].ulRejectCount;
	physicalCUs[index].ulMaximum = 2200;
	physicalCUs[index].usPStatus = WFS_CDM_STATCUOK;
	physicalCUs[index].bHardwareSensor = false;

	return NewAddress(env, &cashUnitInfo);
}
