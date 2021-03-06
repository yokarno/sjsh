// Room: /d/shaolin/shanmen.c
// Date: YZC 96/01/19

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "少林寺山门");
    set("long", @LONG
一个巨大的牌坊横架在两片山壁之间，牌坊正上方刻着三个
斗大的字：『少林寺』。字迹有些剥落，看上去年代久远。两位
三十来岁的僧人手持戒刀守在山门两侧。左侧立着一块石碑。
LONG );
    set("exits", ([ /* sizeof() == 4 */
            "eastup" : __DIR__"shijie8",
        "west" : __DIR__"shijie7",
    ]));
set("outdoors", 1);
        set("no_clean_up", 0);

        setup();
        replace_program(ROOM);
}

