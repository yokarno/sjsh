// 神话世界·西游记（世纪）
// Room: /d/xuyi/xiaolu.c

inherit ROOM;

void create ()
{
  set ("short", "羊肠小路");
  set ("long", @LONG
  
山路顺着山势起伏，道路很窄，凸凹不平，岔道密布，风吹过树木洒洒之
声不断传来，让人为之一寒。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "west" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "south" : __DIR__"xiaolu"+sprintf("%d",random(15)),
  "east" : __DIR__"xiaolu"+sprintf("%d",random(15)),
]));

  setup();
}

void init()
{
  add_action("do_fly", "fly");
}


int do_fly (string arg)
{
  object me;
  me = this_player();

  message_vision("$N奋力向上一跳，“扑通”掉了下来，看来没有起飞的地方。\n", me);
  tell_object(me,"还是慢慢走吧……\n");
  return 1;
}

