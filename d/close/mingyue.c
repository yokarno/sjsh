//tianpei 天篷
//by calvin and leox 共同开发
//版权所有,未经许可不得翻录

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "明月堂");
        set ("long", @LONG
这里是天蓬元帅府的明月堂,是众弟子开坛讲经,研讨琐事的地方。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
           "west" :"/d/tianpeng/sleep",
           "south" :"/d/leox/tianpeng/zoulang5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
       "/d/tianpeng/npc/tang" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
