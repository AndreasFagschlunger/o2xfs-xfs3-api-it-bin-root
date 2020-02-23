#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_BlacklistElement330IT.h"

static WFSCDMBLACKLISTELEMENT BlacklistElement;
static LPWSTR lpszSerialNumber = L"S8H9231654";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_BlacklistElement330IT_createDefault(JNIEnv *env, jobject obj) {
	BlacklistElement.lpszSerialNumber = lpszSerialNumber;
	strncpy(BlacklistElement.cCurrencyID, "GBP", 3);
	BlacklistElement.ulValue = 500;
	return NewAddress(env, &BlacklistElement);
}
