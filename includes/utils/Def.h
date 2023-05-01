#pragma once
#include <typeinfo>
#include <string>
#include <stdint.h>
#include <memory>
#include <algorithm>

//要求c++11
//#if __cplusplus < 201103L
//	#error "c++11 supported requested."
//#endif

//平台识别,如果识别不了平台，编译器则会输出报错，并终止编译
#define YT_OS							YT_OS_UNKNOWN
#define YT_OS_UNKNOWN					0x00000001
#define YT_OS_WINDOWS					0x00000002
#define YT_OS_WINCE					0x00000004
#define YT_OS_LINUX_X11				0x00000008
#define YT_OS_LINUX_ARM				0x00000010
#define YT_OS_MAC						0x00000020
#define YT_OS_IOS						0x00000040
#define YT_OS_ANDROID					0x00000080
#define YT_OS_QNX						0x00000100

//类UNIX下可使用g++ -dM -E - </dev/null命令查看编译器默认宏
#if defined(WIN32) || defined(_WIN32) || defined(_WIN64) || defined(_WINDOWS)	//windows
#undef	YT_OS
#define YT_OS		YT_OS_WINDOWS
#pragma warning(disable: 4251)
#if _MSC_VER < 1900
#error "you must build under vs2015 or later version"
#endif
#elif defined(WINCE)															//wince
#undef	YT_OS
#define YT_OS		YT_OS_WINCE
#elif defined(__ANDROID__) || (__Android__)										//android
#undef	YT_OS
#define YT_OS		YT_OS_ANDROID
#elif defined(__QNX__) || defined(__QNXNTO)										//qnx(gcc 5.4)
#undef	YT_OS
#define YT_OS		YT_OS_QNX
#elif defined(__ARM_ARCH)														//linux-arm，该值为几代表第几代，比如是7代表第7代v7
#undef	YT_OS
#define YT_OS		YT_OS_LINUX_ARM
#elif defined(linux) || defined(__linux__) || defined(__LINUX__)				//linux-x11
#undef	YT_OS
#define YT_OS		YT_OS_LINUX_X11
#elif defined(__IOS__) || defined(__Ios__) || defined(ios)						//ios（ios只能主动设置？）
#undef	YT_OS
#define YT_OS		YT_OS_IOS
#elif defined(__APPLE__) || defined(Mac) || defined(Apple)						//mac
#undef	YT_OS
#define YT_OS		YT_OS_MAC
#else
#error "!!!!!!!!!!Can not recognize the target platform type: have you configured an sopported platform ? check file 'core/Def.h' to confirm the Macro 'YT_OS'.!!!!!!!!!!"
#endif


//定义API导出宏
#if YT_OS == YT_OS_WINDOWS
#define YT_API					__declspec(dllexport)
#else
#define YT_API
#endif

namespace alertsCollection
{
	//获取开机以来的时钟滴答数（毫秒数）
	YT_API uint64_t getTickCount();

	//根据pid获取进程名
	YT_API std::string getProcessName(int pid);

}