//changan city

inherit ROOM;

void create ()
{
        set ("short", "神谷道场正门");
        set ("long", @LONG

这里就是著名的神谷道场。在年轻的新一代馆主神谷熏的努力下，道
场的规模正日益的扩大着。
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
              "south" : __DIR__"dalu8",
                "north":__DIR__"dating",
        ]));

        set("objects", 
        ([ //sizeof() == 4
          "/d/swordman/npc/dizi" : 2,
          "/d/swordman/npc/miyan" : 1,
            "/d/swordman/npc/zhangmen" : 1,
        ]));


        set("no_clean_up", 0);
        setup();
}

