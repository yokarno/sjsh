inherit ROOM;

void create()
{
  set ("short", "练功室");
  set ("long", @LONG

这里是神谷道场的练功室，几个道场弟子正拿着手中的长剑努力地练
习着剑术。
LONG);
        set("objects", ([
                __DIR__"npc/dizi": 4, 

                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "north" : __DIR__"muwu",
              "west":__DIR__"dating",
]));
  setup();
}

