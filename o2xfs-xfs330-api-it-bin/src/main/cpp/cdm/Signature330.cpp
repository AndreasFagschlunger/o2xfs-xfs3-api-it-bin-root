#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_Signature330IT.h"

static WFSCDMSIGNATURE Signature;
static LPSTR Data = "TEST";

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_Signature330IT_createDefault(JNIEnv *env, jobject obj) {
	Signature.ulLength = strlen(Data);
	Signature.lpData = Data;
	return NewAddress(env, &Signature);
}
