// Room: /d/mojie/shanfang.c
inherit ROOM;

void create()
{
  set ("short", "膳房");
  set ("long", @LONG
这是魔界的膳房，一个小妖正在烧饭。整个房间弥漫着饭菜香。
你可以要(serve) 些吃的喝的。
LONG);
   set("sleep_room",1);
   set("if_bed",1);
   set("no_get",1);
   set("no_fight",1);
   set("no_cast",1);
   set("no_flee",1);
  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"guodao4",
]));
        set("objects", 
        ([ //sizeof() == 1
  __DIR__"npc/baomo" :1,
  __DIR__"npc/yao" :1,
        ]));
  setup();
  replace_program(ROOM);
}
