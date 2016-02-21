//shulin 兰陵

inherit ROOM;

void create ()
{
        set ("short", "皇陵大道");
        set ("long", @LONG

这里是通往兰陵皇宫的唯一大路,也是兰陵最为宽阔的路.
路的两边青树绿藤,鸟语花香,好不美丽.这条路上每年的
正月初一老百姓们被禁止走动,而且路面干净.因为这天
皇帝要通过这巡游兰陵城 ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 8
                 "north" : "/d/lanling/兰陵城心",
                "south" : "/d/calvin/lanling/kingdadao2",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("outdoors", "changan");
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
