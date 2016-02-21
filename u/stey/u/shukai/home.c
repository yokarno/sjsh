#include <ansi.h>
inherit ROOM;
void create()
{
   set("short",HIW "观蝶楼" NOR);
   set("long",@LONG
一座碧绿色小屋 三面环水 窗外一泓秋水，池边花树映水而红，灿若
云霞；池中零，残荷点点。湖边片地红花绿草，彩蝶纷飞。闲时俩人便在
湖中泛舟，赏莲；湖边戏碟。屋内门右侧是书架上面摆满了各种书，对湖
的一面开了一扇竹窗 窗前放着一架五弦琴，左侧有一张牙玉色的软榻(bed)，
屋中央摆了一张棋秤，上面还摆着棋局，彦清风正在陪菲菲下棋。好幸福
的一对。
LONG);
    set("exits",([
  "north" : "/u/shukai/workroom.c",
        ]));
      set("objects",([
               "/u/shukai/npc/ada" : 1,
               "/u/shukai/npc/baby" : 1,
                 ]));
  set("no_time",1);
        set("sleep_room",1);
        set("if_bed",1);
  set("alternative_die",1);
  set("valid_startroom", 1);
setup();
}
void init()
{
        add_action("do_dest", "cast");
        add_action("do_dest", "exert");
        add_action("do_back", "kissshukai");
        add_action("do_dest", "perform");
        add_action("do_dest", "bian");
        add_action("do_dest", "ji");
        add_action("do_dest", "throw");
        add_action("do_dest", "quit");
        add_action("do_dest", "home");
        add_action("do_dest", "punish");
        add_action("do_dest", "tojail");
        add_action("do_dest", "pop");
         add_action("do_dest", "nuke");
        add_action("do_dest", "shoot");
        add_action("do_dest", "go");
        add_action("do_dest", "goto");
        add_action("do_dest", "clone");
        add_action("do_dest", "fight");
        add_action("do_dest", "kill");
        add_action("do_dest", "dest");
        add_action("do_dest", "smash");

}

int do_back()
{

    this_player()->move("/d/city/kezhan");
    return 1;
}

int do_dest(string arg)
{
     return 1;
}
