//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后花园路");
        set ("long", @LONG
这是府邸花园的另外一条小路,这里幽兰可净,是个难得的好地方.
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "northwest" :"/d/tianpeng/sandong",
           "south" :"/d/tianpeng/hualu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
