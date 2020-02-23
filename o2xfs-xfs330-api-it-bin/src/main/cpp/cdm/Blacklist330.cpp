#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_Blacklist330IT.h"

static WFSCDMBLACKLIST Blacklist;
static LPWSTR lpszVersion = L"1.0";
static WFSCDMBLACKLISTELEMENT BlacklistElements[2];
static LPWFSCDMBLACKLISTELEMENT lppBlacklistElements[2];
static LPWSTR SerialNumbers[2] = { L"S8H9231654", L"HD9083276112" };

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_Blacklist330IT_createDefault(JNIEnv* env, jobject obj) {
	Blacklist.lpszVersion = lpszVersion;
	Blacklist.usCount = 2;
	Blacklist.lppBlacklistElements = lppBlacklistElements;

	int index = 0;
	BlacklistElements[index].lpszSerialNumber = SerialNumbers[index];
	strncpy(BlacklistElements[index].cCurrencyID, "EUR", 3);
	BlacklistElements[index].ulValue = 20;
	lppBlacklistElements[index] = &BlacklistElements[index];

	index++;
	BlacklistElements[index].lpszSerialNumber = SerialNumbers[index];
	strncpy(BlacklistElements[index].cCurrencyID, "USD", 3);
	BlacklistElements[index].ulValue = 100;
	lppBlacklistElements[index] = &BlacklistElements[index];

	return NewAddress(env, &Blacklist);
}
