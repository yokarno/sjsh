
inherit ROOM;
#include <ansi.h>

void create()
{
          set("short",HIR "「"HIM "软香塌" HIR "」" NOR);
        set("long", @LONG

  这是玉皇大帝曾经睡过的床，
后来送给了西王母，
后来送给了嫦娥，
在绿无常和雨点结婚的那天，天庭召开了一次政治局扩大会议，最终决定将这张床作为礼物送给雨点。
LONG
        );
        
        set("exits", ([
                  "out": "/u/yudian/sleeproom",
            ]));
	set("no_fight", 1);
	set("no_magic", 1);
       set("sleep_room",1);
       set("if_bed",1);
                                              
        setup();
}

