
// HAZEL_API
#ifdef HZ_PLATFORM_WINDOWS
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
        #define HAZEL_API __declspec(dllimport)
	#endif
#else 
	#error Hazel support only Windows
#endif // HZ_PLATFORM_WINDOWS


// ASSERT
#ifdef HZ_ANABLE_ASSERTS
	#define HZ_ASSERT(x, ...) if(!(x)) { HZ_ERROR("ASSERT: {0}", _VA_ARGS__); debugbrake(); }
	#define HZ_CORE_ASSERT(x, ...) if(!(x)) { HZ_CORE_ERROR("ASSERT: {0}", _VA_ARGS__); debugbrake(); }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ...)
#endif // HZ_ANABLE_ASSERTS



// BIT for EventCategory
#define BIT(x) 1 << x