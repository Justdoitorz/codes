#ifndef __O_DBG_H__
#define __O_DBG_H__

// Set current system's output func
#define Printf_z(...)		printf(__VA_ARGS__)

#ifdef DEBUG
#define Log_z(...) 			Printf_z(__VA_ARGS__)
#else
#define Log_z(...)
#endif


#define O_DEBUG_LEVEL_NONE			0
#define O_DEBUG_LEVEL_ASSERT		1
#define O_DEBUG_LEVEL_ERROR			2
#define O_DEBUG_LEVEL_WARNING		3
#define O_DEBUG_LEVEL_INFO			4


#if (O_DEBUG_LEVEL > O_DEBUG_LEVEL_NONE)
#define O_ASSERT
#endif

#if (O_DEBUG_LEVEL > O_DEBUG_LEVEL_ASSERT)
#define O_ERROR
#endif

#if (O_DEBUG_LEVEL > O_DEBUG_LEVEL_ERROR)
#define O_WARNING
#endif

#if (O_DEBUG_LEVEL > O_DEBUG_LEVEL_WARNING)
#define O_INFO
#endif


#ifdef O_ASSERT
#define Assert_z(condition)				if(!(condition))	                                            \
											Log_z("AST-> L%d(%s):condition err!\n", __LINE__, __FILE__)
#else
#define Assert_z(condition)
#endif

#ifdef O_ERROR
#define logErr_z(...)					(Log_z("ERR-> L%d(%s): ", __LINE__, __FILE__),    \
										 Log_z(__VA_ARGS__)                             )
#else
#define logErr_z(...)
#endif

#ifdef O_WARNING
#define logWarn_z(...)					(Log_z("WRN-> L%d(%s): ", __LINE__, __FILE__),    \
											Log_z(__VA_ARGS__)                             )
#else
#define logWarn_z(...)
#endif

#ifdef O_INFO
#define logInfo_z(...)					Log_z(__VA_ARGS__)
#else
#define logInfo_z(...)
#endif

#define logFunc_z()						logInfo_z("FUNC: %s\n", __func__)

#endif
