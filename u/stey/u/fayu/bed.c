// bed : /u/fayu/bed.c
inherit ROOM;
void create ()
{
set ("short",  "床上");
set ("long", @LONG
     这里是黑儿和晶莹的床，
     床上铺满了百合
     洁白洁白的，香气吟人。
LONG);

set("exits", ([
"out" : "/u/fayu/bedroom.c",
]));  
set("no_fight",1);
set("sleep_room", 1);
set("valid_startroom", 1);
set("no_clean_up", 0);
       setup();
}
