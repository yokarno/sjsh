//兰陵

inherit ROOM;

void create ()
{
        set ("short", "功成名就纪念馆");
        set ("long", @LONG

刚一进门就看见满堂的夕日高手,这里到处是一片乱杂
高手们到处都有,时而见些躺着的,时而见些坐着的,还
有些则是到处走动不停着的... ...墙上有用金字刻着
的一些奇怪文字和图样,可能是他们曾经练就的武功,
而他们都是曾经经历了多少苦难才得到今天的正果的,
不过有朝一日这也会有你的身影的.  ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
          "west" : "/d/calvin/lanling/jie5",
          "east" : "/d/calvin/lanling/npcroom1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
 call_other("/obj/board/lanling_b2","???");
        replace_program(ROOM);
}
