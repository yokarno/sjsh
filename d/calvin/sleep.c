//兰陵 kz_sleeproom

inherit ROOM;
void create()
{
        set("short", "客栈睡房");
        set("long", @LONG
客栈的一间睡房，房间干干净净，一排大床，供客人们休息睡觉。
LONG);

        set("exits", ([
                "west" : "/d/calvin/kezhan",
            ]));

        set("sleep_room",1);
        set("if_bed",1);                             
        setup();
}
