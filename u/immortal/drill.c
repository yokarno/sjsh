#include <ansi.h>
inherit ROOM;
void create ()
{
set ("short", HIW "练 功 房" NOR);
set ("long", @LONG

          冥  思  打  坐         修  真  养  性

LONG);
set("exits", ([
"east": __DIR__"parlour",
]));
set("no_clean_up", 1);
set("outdoors", 0);
set("sleep_room",1);
set("if_bed",1);
set("objects", ([
__DIR__"obj/rack": 1,
]) );
setup();
}
