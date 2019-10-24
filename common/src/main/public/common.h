#ifndef COMMON_H
#define COMMON_H

#include <Windows.h>
#include <jni.h>

jbyteArray NewAddress(JNIEnv* env, LPVOID address);

#endif