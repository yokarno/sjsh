#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "书 房" NOR);
set ("long", @LONG

          舞  文  弄  墨         读  书  识  字

LONG);
set("exits", ([
"south": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("objects", ([
__DIR__"obj/table": 1,
]) );
setup();
}
