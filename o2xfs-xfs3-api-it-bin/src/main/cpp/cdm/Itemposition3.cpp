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
#include "cdm/at_o2xfs_xfs_v3_cdm_Itemposition3IT.h"

static WFSCDMITEMPOSITION ResetIn;
static WFSCDMRETRACT RetractArea;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_Itemposition3IT_createDefault(JNIEnv *env, jobject obj) {
	ResetIn.usNumber = 1;
	ResetIn.lpRetractArea = &RetractArea;
	ResetIn.fwOutputPosition = WFS_CDM_POSFRONT;
	
	RetractArea.fwOutputPosition = WFS_CDM_POSFRONT;
	RetractArea.usRetractArea = WFS_CDM_RA_RETRACT;	
	RetractArea.usIndex = 1;

	return NewAddress(env, &ResetIn);
}

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_Itemposition3IT_createRetractAreaNull(JNIEnv* env, jobject obj) {
	ResetIn.usNumber = 1;
	ResetIn.lpRetractArea = NULL;
	ResetIn.fwOutputPosition = WFS_CDM_POSFRONT;
	return NewAddress(env, &RetractArea);
}