#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_ItemInfoAll330IT.h"

static WFSCDMITEMINFOALL ItemInfoAll;
static LPWSTR lpszSerialNumber = L"HD9083276112";
static LPSTR lpszImageFileName = "C:\\Temp\\cash123456.jpg";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_ItemInfoAll330IT_createDefault(JNIEnv *env, jobject obj) {
	ItemInfoAll.usLevel = WFS_CDM_LEVEL_2;
	strncpy(ItemInfoAll.cCurrencyID, "EUR", 3);
	ItemInfoAll.ulValue = 50;
	ItemInfoAll.usRelease = 1;
	ItemInfoAll.lpszSerialNumber = lpszSerialNumber;
	ItemInfoAll.lpszImageFileName = lpszImageFileName;
	ItemInfoAll.wOnBlacklist = WFS_CDM_ONBLACKLIST;
	ItemInfoAll.wItemLocation = WFS_CDM_LOCATION_CASHUNIT;
	ItemInfoAll.usNumber = 1;
	return NewAddress(env, &ItemInfoAll);
}
