#ifndef noitaLua_H
#define noitaLua_H
#include "wand.h"

const uintptr_t noita_base = 0x00400000;
const uintptr_t lua_base = (uintptr_t)GetModuleHandleA("lua51.dll");

#define n_pcall (lua_base + 0x71F0);
#define n_gettop (lua_base + 0x6E20);
#define n_loadstring (lua_base + 0x29C20);

typedef struct lua_State lua_State;
typedef int(__cdecl* noita_pcall)(lua_State* L, int nargs, int nresults, int errfunc);
typedef int(__cdecl* noita_loadstring)(lua_State* L, const char* s);
typedef int(__cdecl* noita_gettop)(lua_State* L);

noita_pcall pcall = (noita_pcall)n_pcall;
noita_loadstring loadstring = (noita_loadstring)n_loadstring;
noita_gettop gettop = (noita_gettop)n_gettop;
lua_State* lua = nullptr;


int __cdecl n_gettopH(lua_State* L)
{
	lua = L;
	return gettop(L);
}

void execute()
{
	if (lua != nullptr)
	{
		loadstring(lua, tempScript.c_str());
		pcall(lua, 0, -1, 0);
	}
}

#endif