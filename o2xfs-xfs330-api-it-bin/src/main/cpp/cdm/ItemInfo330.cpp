#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_ItemInfo330IT.h"

static WFSCDMITEMINFO ItemInfo;
static LPWSTR lpszSerialNumber = L"HD9083276112";
static WFSCDMSIGNATURE Signature;
static LPSTR lpData = "TEST";
static LPSTR lpszImageFileName = "C:\\Temp\\cash123456.jpg";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_ItemInfo330IT_createDefault(JNIEnv *env, jobject obj) {
	strncpy(ItemInfo.cCurrencyID, "EUR", 3);
	ItemInfo.ulValue = 100;
	ItemInfo.usRelease = 1;
	ItemInfo.lpszSerialNumber = lpszSerialNumber;
	ItemInfo.lpSignature = &Signature;
	ItemInfo.lpszImageFileName = lpszImageFileName;

	Signature.ulLength = strlen(lpData);
	Signature.lpData = lpData;
	
	return NewAddress(env, &ItemInfo);
}
