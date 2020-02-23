#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_20_cdm_ItemNumber320IT.h"

static WFSCDMITEMNUMBER ItemNumber;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_120_cdm_ItemNumber320IT_createDefault(JNIEnv *env, jobject obj) {
	strncpy(ItemNumber.cCurrencyID, "EUR", 3);
	ItemNumber.ulValues = 100;
	ItemNumber.usRelease = 1;
	ItemNumber.ulCount = 1234;
	ItemNumber.usNumber = 4;
	return NewAddress(env, &ItemNumber);
}
