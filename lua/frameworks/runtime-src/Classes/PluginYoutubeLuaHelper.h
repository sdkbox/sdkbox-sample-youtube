
#ifndef __PLUGIN_YOUTUBE_LUA_HELPER_H__
#define __PLUGIN_YOUTUBE_LUA_HELPER_H__

#ifdef __cplusplus
extern "C" {
#endif
#include "tolua++.h"
#ifdef __cplusplus
}
#endif

TOLUA_API int register_all_PluginYoutubeLua_helper(lua_State* L);

#endif
