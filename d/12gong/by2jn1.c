// by HAPP@YSZZ

inherit ROOM;

void create ()
{
        set ("short", "山路");
        set ("long", @LONG

这是走向戍宫的路上，只见前面可以看到奇特的戍宫耸立在佛陀峰上！
云雾中隐隐约约还可以看见山下的亥宫。
LONG);


        set("exits", ([
        "eastup"    :       __DIR__"by2jn2",
            "southdown"  :       __DIR__"baiyang",
        ]));

        set("outdoors", "12gong");
        setup();
}
