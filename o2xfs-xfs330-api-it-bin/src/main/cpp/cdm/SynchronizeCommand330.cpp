#include <common.h>
#include <XFSCDM.H>
#include "cdm/at_o2xfs_xfs_v3_30_cdm_SynchronizeCommand330IT.h"

static WFSCDMSYNCHRONIZECOMMAND SynchronizeCommand;
static DWORD Position = WFS_CDM_POSFRONT;

JNIEXPORT jbyteArray JNICALL Java_at_o2xfs_xfs_v3_130_cdm_SynchronizeCommand330IT_createDefault(JNIEnv *env, jobject obj) {
	SynchronizeCommand.dwCommand = WFS_CMD_CDM_PRESENT;
	SynchronizeCommand.lpCmdData = &Position;
	return NewAddress(env, &SynchronizeCommand);
}
