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
#include "cdm/at_o2xfs_xfs_v3_cdm_MixTable3IT.h"

static WFSCDMMIXTABLE mixTable;
static LPSTR szName = "Test";
static ULONG ulMixHeader[3] = {10, 20, 50};
static WFSCDMMIXROW mixRows[2];
static LPWFSCDMMIXROW lpMixRows[2];
static USHORT usMixture[2][3] = { {1, 2, 1}, {3, 2, 1} };

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_cdm_MixTable3IT_createDefault(JNIEnv *env, jobject obj) {
	mixTable.usMixNumber = 1;
	mixTable.lpszName = szName;
	mixTable.usRows = 2;
	mixTable.usCols = 3;
	mixTable.lpulMixHeader = ulMixHeader;
	mixTable.lppMixRows = lpMixRows;

	mixRows[0].ulAmount = 100;
	mixRows[0].lpusMixture = usMixture[0];
	lpMixRows[0] = &mixRows[0];

	mixRows[1].ulAmount = 150;
	mixRows[1].lpusMixture = usMixture[1];
	lpMixRows[1] = &mixRows[1];

	return NewAddress(env, &mixTable);
}
