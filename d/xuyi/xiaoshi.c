inherit ROOM;

void create()
{
        set("short", "松木小室");
        set("long",@LONG 

这是一间整洁的小室。整堂全以松木制成，板门木柱，木料均不去皮，
天然质朴，和一路行来金碧辉煌的殿堂截然不同。室中有一个小蒲团，
简陋却透着庄严祥和的气氛。
LONG
        );
        set("exits", ([
                "southwest": __DIR__"zoulang2",
        ]));
        set("objects",([
     __DIR__"npc/master" : 1,
        ]));
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

