#ifndef HIDUMPER_H
#define HIDUMPER_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

uint64_t OH_Hidumper_GetPss(const int pid);

#ifdef __cplusplus
}
#endif


#endif