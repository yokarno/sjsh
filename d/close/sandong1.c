//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "洞内");
        set ("long", @LONG
这里不是一个很大的山洞,但洞内环境还不错,优柔的境界像是仙境一般.
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "out" :"/d/tianpeng/sandong",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/calvin/tianpeng/zhu" :  1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
