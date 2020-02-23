#include <Windows.h>
#include <XFSCDM.H>
#include <common.h>
 #include "cdm/at_o2xfs_xfs_v3_20_cdm_ItemNumberList320IT.h"

static WFSCDMITEMNUMBERLIST ItemNumberList;
static WFSCDMITEMNUMBER ItemNumber[3];
static LPWFSCDMITEMNUMBER lppItemNumber[3];

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_120_cdm_ItemNumberList320IT_createDefault(JNIEnv *env, jobject obj) {
	ItemNumberList.usNumOfItemNumbers = 3;
	ItemNumberList.lppItemNumber = lppItemNumber;

	int index = 0;
	strncpy(ItemNumber[index].cCurrencyID, "EUR", 3);
	ItemNumber[index].ulValues = 100;
	ItemNumber[index].usRelease = 1;
	ItemNumber[index].ulCount = 1234;
	ItemNumber[index].usNumber = 4;
	lppItemNumber[index] = &ItemNumber[index];
	
	index++;
	strncpy(ItemNumber[index].cCurrencyID, "USD", 3);
	ItemNumber[index].ulValues = 10;
	ItemNumber[index].usRelease = 5;
	ItemNumber[index].ulCount = 100;
	ItemNumber[index].usNumber = 1;
	lppItemNumber[index] = &ItemNumber[index];

	index++;
	strncpy(ItemNumber[index].cCurrencyID, "GBP", 3);
	ItemNumber[index].ulValues = 1;
	ItemNumber[index].usRelease = 1;
	ItemNumber[index].ulCount = 10;
	ItemNumber[index].usNumber = 2;
	lppItemNumber[index] = &ItemNumber[index];

	return NewAddress(env, &ItemNumberList);
}
