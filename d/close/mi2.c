//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "乱阵花园");
        set ("long", @LONG
这是一个使用奇行遁甲的乱阵迷宫花园,可是这个迷宫不是很大,
一般难不倒来往的各路高手。
LONG);

        set("exits", 
        ([ //sizeof() == 4
           "east" :"/d/tianpeng/mi2",
           "west" :"/d/tianpeng/mi2",
           "north" :"/d/tianpeng/mi3",
           "south" :"/d/tianpeng/mi2",
           "southeast" :"/d/tianpeng/mi2",
           "northeast" :"/d/tianpeng/mi1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
