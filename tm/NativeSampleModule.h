#pragma once

#if __has_include(<React-Codegen/AppSpecsJSI.h>) // CocoaPod headers on Apple
#include <React-Codegen/AppSpecsJSI.h>
#elif __has_include("AppSpecsJSI.h") // CMake headers on Android
#include "AppSpecsJSI.h"
#endif

#include <memory>
#include <string>

namespace facebook::react {

    class NativeSampleModule : public NativeSampleModuleCxxSpec<NativeSampleModule> {
    public:
        NativeSampleModule(std::shared_ptr <CallInvoker> jsInvoker);

        std::string reverseString(jsi::Runtime &rt, std::string input);

        double pointer_test1(jsi::Runtime &rt, double input);

        double pointer_test2(jsi::Runtime &rt, double input);

        double pointer_test3(jsi::Runtime &rt, double input);

        double pointer_test4(jsi::Runtime &rt, double input);

        double pointer_test5(jsi::Runtime &rt, double input);

        double pointer_test6(jsi::Runtime &rt, double input);

        double pointer_test7(jsi::Runtime &rt, double input);

        double pointer_test8(jsi::Runtime &rt, double input);

    };

} // namespace facebook::react
