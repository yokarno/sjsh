// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "海边小道");
  set ("long", @LONG

这是沿着海边的一条小道，越往里去，道路越崎岖，两边山岩
突起，灌木丛生，你不由自主地加快步伐。

LONG);

  set("exits", ([
        "southeast"    : __DIR__"searoad2",
        "northup"    : __DIR__"searoad4",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

