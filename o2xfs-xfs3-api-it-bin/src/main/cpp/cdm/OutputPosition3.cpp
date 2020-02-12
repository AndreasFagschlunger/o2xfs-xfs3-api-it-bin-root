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
#include "cdm/at_o2xfs_xfs_v3_cdm_OutputPosition3IT.h"

static WFSCDMOUTPOS Position;
static WFSCDMDENOMINATION Denomination;
static ULONG Values[] = { 1, 2, 3};

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_OutputPosition3IT_createDefault(JNIEnv *env, jobject obj) {
	Position.fwPosition = WFS_CDM_POSFRONT;
	Position.fwShutter = WFS_CDM_SHTCLOSED;
	Position.fwPositionStatus = WFS_CDM_PSEMPTY;
	Position.fwTransport = WFS_CDM_TPOK;
	Position.fwTransportStatus = WFS_CDM_TPSTATEMPTY;

	return NewAddress(env, &Position);
}
