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
#include "cdm/at_o2xfs_xfs_v3_cdm_TellerUpdate3IT.h"

static WFSCDMTELLERUPDATE TellerUpdate;
static WFSCDMTELLERDETAILS TellerDetails;
static WFSCDMTELLERTOTALS TellerTotals[2];
static LPWFSCDMTELLERTOTALS lppTellerTotals[3];

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_TellerUpdate3IT_createDefault(JNIEnv *env, jobject obj) {
	TellerUpdate.usAction = WFS_CDM_CREATE_TELLER;
	TellerUpdate.lpTellerDetails = &TellerDetails;

	TellerDetails.usTellerID = 1;
	TellerDetails.ulInputPosition = WFS_CDM_POSINFRONT;
	TellerDetails.fwOutputPosition = WFS_CDM_POSBOTTOM;
	TellerDetails.lppTellerTotals = lppTellerTotals;

	strncpy(TellerTotals[0].cCurrencyID, "EUR", 3);
	TellerTotals[0].ulItemsReceived = 0;
	TellerTotals[0].ulItemsDispensed = 0;
	TellerTotals[0].ulCoinsReceived = 0;
	TellerTotals[0].ulCoinsDispensed = 123;
	TellerTotals[0].ulItemsReceived = 0;
	TellerTotals[0].ulItemsDispensed = 0;
	lppTellerTotals[0] = &TellerTotals[0];

	strncpy(TellerTotals[1].cCurrencyID, "USD", 3);
	TellerTotals[1].ulItemsReceived = 0;
	TellerTotals[1].ulItemsDispensed = 0;
	TellerTotals[1].ulCoinsReceived = 0;
	TellerTotals[1].ulCoinsDispensed = 1000;
	TellerTotals[1].ulItemsReceived = 0;
	TellerTotals[1].ulItemsDispensed = 0;
	lppTellerTotals[1] = &TellerTotals[1];
	
	lppTellerTotals[2] = NULL;

	return NewAddress(env, &TellerUpdate);
}
