inherit ROOM;

void create()
{
  set ("short", "练功室");
  set ("long", @LONG

这里是神谷道场的大厅，几个道场弟子正拿着手中的长剑努力地练
习着剑术，一位二十岁左右的少女正在从旁指导着他们。
LONG);
        set("objects", ([
                __DIR__"npc/xun": 1, 
                __DIR__"npc/dizi": 2, 

                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"wuguan",
        "east" : __DIR__"liangongshi",
              "west":__DIR__"xiuxishi",
]));
  setup();
}

