#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_AllItemsInfo330IT.h"

static WFSCDMALLITEMSINFO AllItemsInfo;
static WFSCDMITEMINFOALL ItemsList[2];
static LPWFSCDMITEMINFOALL lppItemsList[2];
static LPWSTR lpszSerialNumber = L"123456789";
static LPSTR lpszImageFileName = "C:\\Temp\\test.jpg";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_AllItemsInfo330IT_createDefault(JNIEnv *env, jobject obj) {
	AllItemsInfo.usCount = 2;
	AllItemsInfo.lppItemsList = lppItemsList;

	int index = 0;
	ItemsList[index].usLevel = WFS_CDM_LEVEL_2;
	strncpy(ItemsList[index].cCurrencyID, "EUR", 3);
	ItemsList[index].ulValue = 10;
	ItemsList[index].usRelease = 2;
	ItemsList[index].lpszSerialNumber = NULL;
	ItemsList[index].lpszImageFileName = lpszImageFileName;
	ItemsList[index].wOnBlacklist = WFS_CDM_NOTONBLACKLIST;
	ItemsList[index].wItemLocation = WFS_CDM_LOCATION_CASHUNIT;
	ItemsList[index].usNumber = 2;
	lppItemsList[index] = &ItemsList[index];

	index++;
	ItemsList[index].usLevel = WFS_CDM_LEVEL_3;
	strncpy(ItemsList[index].cCurrencyID, "USD", 3);
	ItemsList[index].ulValue = 100;
	ItemsList[index].usRelease = 3;
	ItemsList[index].lpszSerialNumber = lpszSerialNumber;
	ItemsList[index].lpszImageFileName = NULL;
	ItemsList[index].wOnBlacklist = WFS_CDM_NOTONBLACKLIST;
	ItemsList[index].wItemLocation = WFS_CDM_LOCATION_CASHUNIT;
	ItemsList[index].usNumber = 2;
	lppItemsList[index] = &ItemsList[index];
	return NewAddress(env, &AllItemsInfo);
}
