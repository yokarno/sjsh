// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

小路上铺满了白色的小碎石子。越往里走,地势越来越偏僻。

LONG);

  set("exits", ([
        "north"   : __DIR__"dalu10",
        "southeast"   : __DIR__"xiaolu2",
      ]));
  set("outdoors", __DIR__);

  setup();
}



