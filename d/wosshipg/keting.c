#include <ansi.h>
inherit ROOM;
void create ()
{
 set ("short", HIW "客厅" NOR);
set ("long", @LONG

这里是铁马冰河入梦来的客厅

LONG);
set("exits", ([
"bk": "/d/wosshipg/workroom",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("objects", ([
"/u/immortal/obj/cabinet": 1,]));
setup();
}
