//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵城心");
        set ("long", @LONG

这里是兰陵城的市中心,这的交通发达,路上来往游人特别的多.
再往南去就是皇宫了,西边是石头大街,据说走到头就是南海之滨了,
东面是雨花石路,这条路通往的地方很多 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/d/calvin/lanling/jie8",
                "south" : "/d/calvin/lanling/kingdadao1",
                "west" : "/d/calvin/lanling/stone1",
                "east" : "/d/calvin/lanling/yuhua",
                "down" : "/d/calvin/lanling/feixu",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//            "/u/calvin/其他/board" : 1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
 call_other("/obj/board/lanling_b","???");
        replace_program(ROOM);
}
