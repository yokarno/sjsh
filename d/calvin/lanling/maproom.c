//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "地图之家");
        set ("long", @LONG

这是一家破旧的瓦房,本来早该拆掉的,可是由于这里的地图
走销很好,一时也没个地方搬,所以一直到现在还是这样的老
房子。这里的老板是个穷书生,据说本来他可以考上状元的
但是因为拿不出那100两黄金作为礼品,所以没被选上。
LONG);
        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
       "east" : "/d/calvin/lanling/jie5",
        ]));

        set("objects", 
        ([ //sizeof() == 1
               "/d/calvin/npc/mapman" : 1,
        ]));

//      set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
