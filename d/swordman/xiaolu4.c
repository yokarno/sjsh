// create by snowcat.c 12/8/1997

inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

小路上铺满了白色的小碎石子。越往里走,地势越来越偏僻。
小路的尽头可以看到一个石屋。

LONG);

  set("exits", ([
        "northwest"   : __DIR__"xiaolu3",
        "southup"   : __DIR__"shiwu",
      ]));
  set("outdoors", __DIR__);

  setup();
}



