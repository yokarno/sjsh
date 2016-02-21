//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "兰陵城心");
        set ("long", @LONG

这里是兰陵城的市中心,这的交通发达,路上来往
游人特别的多.再往南去就是皇宫了,西边是石头
大街,据说走到头就是南海之滨了;东面是雨花石
路,这条路通往的地方很多 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                "north" : "/u/calvin/兰陵/地区/兰陵大街8",
                "south" : "/u/calvin/兰陵/地区/皇陵大道1",
                "west" : "/u/calvin/兰陵/地区/石头大街1",
                "east" : "/u/calvin/兰陵/地区/雨花石路",
                "down" : "/u/calvin/兰陵/地区/废墟",
        ]));

        set("objects", 
        ([ //sizeof() == 1
//          "/u/calvin/其他/board" : 1,
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
          call_other( "/u/calvin/其他/board", "???" );
        replace_program(ROOM);
}
