//
// Created by jmpews on 2018/6/14.
//

#ifndef HOOKZZ_INTERCEPTORARM64_H
#define HOOKZZ_INTERCEPTORARM64_H

#include "Interceptor.h"
#include "MemoryManager.h"
#include "ARM64Writer.h"
#include "ARM64Reader.h"
#include "ARM64Relocator.h"

class InterceptorBackend {
public:
  MemoryManager *mm;
  ARM64Relocator *relocatorARM64;
  ARM64AssemblerWriter *writerARM64;
  ARM64AssemblyReader *readerARM64;
public:
    void PrepareTrampoline(HookEntry *entry);

    void BuildForEnterTransferTrampoline(HookEntry *entry);

    void BuildForEnterTrampoline(HookEntry *entry);

    void BuildForDynamicBinaryInstrumentationTrampoline(HookEntry *entry);

    void BuildForLeaveTrampoline(HookEntry *entry);

    void BuildForInvokeTrampoline(HookEntry *entry);

    void ActiveTrampoline(HookEntry *entry);

};

typedef struct _ARM64HookFuntionEntryBackend {
    int limit_relocate_inst_size;
} ARM64HookEntryBackend;

#endif //HOOKZZ_INTERCEPTORARM64_H
