// 密林宝库 by Calvin

inherit ROOM;

void create()
{
  set ("short", "密林宝库");
  set ("long", @LONG
这里是密林的最秘密的地方---密林宝库,据说这里的宝贝都是女涡娘娘曾经使做的,
但是后来一直没怎么用过,日久天长也便忘了这些宝贝的存在。
LONG);

        set("exits", 
        ([ //sizeof() == 4
       "south" : "/d/milin/qy/u2",   
       "north" : "/d/milin/qy/u3",   
       "up" : "/d/milin/qy/u4",   
       "northeast" : "/d/milin/qy/u5",   
       "east" : "/d/milin/qy/u6",   
       "west" : "/d/milin/qy/u7",   
       "down" : "/d/milin/qy/u8",   
       "southeast" : "/d/milin/qy/u9",   
       "enter" : "/d/milin/qy/u10",   
]));

        set("objects", 
        ([ //sizeof() == 1
        "/d/milin/npc/long1" : 2, 
       "/d/npc/obj/whip" : 1,
        ]));

  set("no_clean_up", 1);

  setup();
}
