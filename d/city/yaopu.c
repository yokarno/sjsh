//changan city

#include <room.h>
#include <ansi.h>
inherit SELLYAO;
void create ()
{
        set ("short","回春药铺" );
        set ("long", @LONG

这是长安城一家老字号的药铺，相传原来的老板是皇宫中的御医，手
段可知一二。门口挂了一块牌子 (paizi)。药铺中的摆设也十分考究，
桌椅被勤快的伙计擦的干干净净。墙上挂满了别人送来的谢匾。
LONG);
        set("exits", 
        ([ //sizeof() == 4
                "west" : __DIR__"zhuque-s2",
                "east" : __DIR__"jishitang",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                __DIR__"npc/yang" : 1,
        ]));

set("item_desc", ([ /* sizeof() == 1 */
  "paizi" : "
本店有百年历史，信誉好。现收购天下各种名药
客官可以在这里：
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
    ＊	卖药(sell)		＊
    ＊	买药(buy) 用list查看。	＊
    ＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊
"]));

  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}


