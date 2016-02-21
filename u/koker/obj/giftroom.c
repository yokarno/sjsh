//by koker@sjsh 2002

#include <ansi.h>
inherit ROOM;

void create ()
{
        set ("short", HIG"悲惨的世界"NOR);
        set ("long", @LONG

这里的一切都是黑的．在黑暗中，一束阳光透过墙上的一个小
洞投到地上．顺这这柱光线，你看到了一个硕大的箱子(box)．
LONG);

        set("exits", 
        ([ //sizeof() == 4
              "east" : "/u/koker/giftroom3",
        ]));

        set("objects", 
        ([ //sizeof() == 1
         "/u/koker/box.c" : 1,
        ]));

        set("no_clean_up", 0);
        set("no_kill", 1);
        set("no_cast", 1);
        set("no_fight", 1);
        set("no_perform", 1);
        set("no_move", 1);
        setup();
        replace_program(ROOM);
}
