#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#include <stdint.h>

typedef struct callbacklist_s callbacklist_t;
typedef struct x86emu_s x86emu_t;

callbacklist_t* NewCallbackList();
void FreeCallbackList(callbacklist_t** callbacks);

x86emu_t* AddCallback(x86emu_t* emu, uintptr_t fnc, int nb_args, void* arg1, void* arg2, void* arg3, void* arg4);
x86emu_t* AddVariableCallback(x86emu_t* emu, int stsize, uintptr_t fnc, int nb_args, void* arg1, void* arg2, void* arg3, void* arg4);
x86emu_t* AddSmallCallback(x86emu_t* emu, uintptr_t fnc, int nb_args, void* arg1, void* arg2, void* arg3, void* arg4);
x86emu_t* AddSharedCallback(x86emu_t* emu, uintptr_t fnc, int nb_args, void* arg1, void* arg2, void* arg3, void* arg4);
x86emu_t* GetCallback1Arg(x86emu_t* emu, uintptr_t fnc, int nb_args, void* arg1);
x86emu_t* FreeCallback(x86emu_t* emu);
uint32_t RunCallback(x86emu_t* emu);
void SetCallbackArg(x86emu_t* emu, int arg, void* val);
void SetCallbackArgs(x86emu_t* emu, int nargs, ...);            // set args starting from 0
void SetCallbackNArgs(x86emu_t* emu, int N, int nargs, ...);    // set args starting from N
void* GetCallbackArg(x86emu_t* emu, int arg);
void SetCallbackNArg(x86emu_t* emu, int narg);
void SetCallbackAddress(x86emu_t* emu, uintptr_t address);
uintptr_t GetCallbackAddress(x86emu_t* emu);
int IsCallback(box86context_t* context, x86emu_t* cb);
uint32_t RunFunction(box86context_t *context, uintptr_t fnc, int nargs, ...);   // use a local stack from the stack of 128K

#endif //__CALLBACK_H__