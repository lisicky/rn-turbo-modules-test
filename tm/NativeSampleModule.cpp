#include "NativeSampleModule.h"
// #include "react_native_haskell_shelley.h"
#include <stdint.h>

// C11
_Static_assert(sizeof (void*) == sizeof (uintptr_t),
               "TBD code needed to determine pointer size");

// C99 or later
#if UINTPTR_MAX == 0xFFFF
#define PTR16
#elif UINTPTR_MAX == 0xFFFFFFFF
#define PTR32
#elif UINTPTR_MAX == 0xFFFFFFFFFFFFFFFFu
#define PTR64
#else
#error TBD pointer size
#endif

_Static_assert(sizeof (void*) => sizeof (double),
               "Incorrect double size");

double voidPtrToDouble(void* ptr) {
    double d = 0;
    // Copy the size of void* (either 4 bytes or 8 bytes)
    memcpy(&d, &ptr, sizeof(void*));
    return d;
}

// Function to convert double to void* by reinterpreting bytes
void* doubleToVoidPtr(double d) {
    void* ptr = 0x00;
    // Copy the size of void* (either 4 bytes or 8 bytes)
    memcpy(&ptr, &d, sizeof(void*));
    return ptr;
}

namespace facebook::react {

    NativeSampleModule::NativeSampleModule(std::shared_ptr <CallInvoker> jsInvoker)
            : NativeSampleModuleCxxSpec(std::move(jsInvoker)) {}

    std::string NativeSampleModule::reverseString(jsi::Runtime &rt, std::string input) {
        return std::string(input.rbegin(), input.rend());
    }

    double NativeSampleModule::pointer_test1(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* i = (void*) 0x1234567890ABCDEF;
#else
        void* i = (void*) 0x90ABCDEF;
#endif

        return voidPtrToDouble(i);
    }

    double NativeSampleModule::pointer_test2(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0x1234567890ABCDEF;
        void* p2 = (void*) 0xFFFFFFFFFFFFFFFF;
#else
        void* p1 = (void*) 0x90ABCDEF;
        void* p2 = (void*) 0xFFFFFFFF;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 2");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test3(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0xFFFFFFFFFFFFFFFF;
        void* p2 = (void*) 0x0F0F0F0F0F0F0F0F;
#else
        void* p1 = (void*) 0xFFFFFFFF;
        void* p2 = (void*) 0x0F0F0F0F;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 3");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test4(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0x0F0F0F0F0F0F0F0F;
        void* p2 = (void*) 0xF0F0F0F0F0F0F0F0;
#else
        void* p1 = (void*) 0x0F0F0F0F;
        void* p2 = (void*) 0xF0F0F0F0;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 4");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test5(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0xF0F0F0F0F0F0F0F0;
        void* p2 = (void*) 0x0000000000000000;
#else
        void* p1 = (void*) 0xF0F0F0F0;
        void* p2 = (void*) 0x00000000;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 5");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test6(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0x0000000000000000;
        void* p2 = (void*) 0xFFFFFFFF00000000;
#else
        void* p1 = (void*) 0x00000000;
        void* p2 = (void*) 0xFFFF0000;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 6");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test7(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0xFFFFFFFF00000000;
        void* p2 = (void*) 0x00000000FFFFFFFF;
#else
        void* p1 = (void*) 0xFFFF0000;
        void* p2 = (void*) 0x0000FFFF;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 7");
        }
        return voidPtrToDouble(p2);
    }

    double NativeSampleModule::pointer_test8(jsi::Runtime &rt, double input) {
#ifdef PTR64
        void* p1 = (void*) 0x00000000FFFFFFFF;
        void* p2 = (void*) 0x00000000FFFFFFFF;
#else
        void* p1 = (void*) 0x0000FFFF;
        void* p2 = (void*) 0x0000FFFF;
#endif
        void *p_input = doubleToVoidPtr(input);
        if (p1 != p_input) {
            throw jsi::JSError(rt, "bad cast 8");
        }
        return voidPtrToDouble(p2);
    }

}// namespace facebook::react
