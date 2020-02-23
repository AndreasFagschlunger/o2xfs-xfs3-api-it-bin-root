#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_IncompleteRetract330IT.h"

static WFSCDMINCOMPLETERETRACT IncompleteRetract;
static WFSCDMITEMNUMBER ItemNumber[2];
static LPWFSCDMITEMNUMBER lppItemNumber[2];

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_IncompleteRetract330IT_createDefault(JNIEnv *env, jobject obj) {
	IncompleteRetract.lpItemNumberList.usNumOfItemNumbers = 2;
	IncompleteRetract.lpItemNumberList.lppItemNumber = lppItemNumber;
	IncompleteRetract.usReason = WFS_CDM_IRRETRACTFAILURE;

	int index = 0;
	strncpy(ItemNumber[index].cCurrencyID, "EUR", 3);
	ItemNumber[index].ulValues = 100L;
	ItemNumber[index].usRelease = 1;
	ItemNumber[index].ulCount = 23;
	ItemNumber[index].usNumber = 2;
	lppItemNumber[index] = &ItemNumber[index];

	index++;
	strncpy(ItemNumber[index].cCurrencyID, "USD", 3);
	ItemNumber[index].ulValues = 10L;
	ItemNumber[index].usRelease = 2;
	ItemNumber[index].ulCount = 10;
	ItemNumber[index].usNumber = 3;
	lppItemNumber[index] = &ItemNumber[index];

	return NewAddress(env, &IncompleteRetract);
}
