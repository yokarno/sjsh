//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
inherit ROOM;

/*string* books = ({
        "daodejing-i",
        "daodejing-i2",
        "daodejing-i3",
});*/

void create()
{
        set("short", "经楼");
        set("long", @LONG
        这里是藏经阁，靠墙是一排书架，摆满了道教的典籍。中央有一个长方
形的大桌子，上面也堆满了书。一个道童正在整理书籍。
LONG
        );

        set("exits", ([
                "west" : __DIR__"square",
        ]));

        set("objects", ([
                __DIR__"npc/jiantong" : 1,
//              __DIR__"obj/"+books[random(sizeof(books))] : 1,
                __DIR__"obj/yijing" : 1,
        ]));

        setup();
        replace_program(ROOM);
}
