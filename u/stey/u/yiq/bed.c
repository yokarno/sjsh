inherit ROOM;

#include <ansi.h>

void create()
{
          set("short",HIR "「"HIM "床" HIR "」" NOR);
        set("long", @LONG
这是衣青和澜舟的床，很舒适的大床。
LONG);

        set("exits", ([
                  "out" : "/u/yiq/love",
            ]));
       set("no_fight", 1);
   set("no_magic", 1);
       set("sleep_room",1);
       set("if_bed",1);

        setup();
}
