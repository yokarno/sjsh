// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "大路");
  set ("long", @LONG

这是一条宽阔笔直的官道，足可容得下十马并驰。往东直达
东瀛城内,往西隐约可以看到东瀛之滨。
LONG);

  set("exits", ([
        "west"    : __DIR__"gate",
        "east"    : __DIR__"dalu2",
      ]));
  set("outdoors",__DIR__"");
  setup();
}

