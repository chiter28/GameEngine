
// HAZEL_API
#ifdef HZ_PLATFORM_WINDOWS

#if HZ_DYNAMIC_LINK
	#ifdef HZ_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
        #define HAZEL_API __declspec(dllimport)
	#endif
#else 
	#define HAZEL_API
#endif
#else 
	#error Hazel support only Windows
#endif



// ASSERT
#ifdef HZ_DEBUG
	#define HZ_ANABLE_ASSERTS
#endif

#ifdef HZ_ANABLE_ASSERTS
	#define HZ_ASSERT(x, ...) if(!(x)) { HZ_ERROR("ASSERT: {0}", __VA_ARGS__); __debugbreak(); }
	#define HZ_CORE_ASSERT(x, ...) if(!(x)) { HZ_CORE_ERROR("ASSERT: {0}", __VA_ARGS__); __debugbreak(); }
#else
	#define HZ_ASSERT(x, ...)
	#define HZ_CORE_ASSERT(x, ..
#endif


// BIT for EventCategory
#define BIT(x) 1 << x

// HZ_BIND_EVENT_FN (что бы сделать метод класа лямбда функцией для передачи её в качестве параментра другой функции(callback))
#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)