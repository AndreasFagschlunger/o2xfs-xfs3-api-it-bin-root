#include "common.h"

jbyteArray NewAddress(JNIEnv* env, LPVOID address) {
	jbyteArray result = env->NewByteArray(sizeof(address));
	if (result != NULL) {
		env->SetByteArrayRegion(result, 0, env->GetArrayLength(result), (jbyte*) &address);
	}
	return result;
}