//shushan2 by yushu@SHXY 2000.12
inherit ROOM;
void create ()
{
    set ("short","杂屋");
  set ("long", @LONG

道场内一间堆放杂物的小木屋，里面的摆设非常的简陋，里面有
一个男子正在劈柴烧水。这样的情形，很难让人将眼前这个男子
与幕末令敌人闻风散胆的千人斩绯村拔刀斋联系起来。
LONG);
   set("exits", ([      
              "south" : __DIR__"liangongshi",
  ]));
   set("objects", ([ 
      __DIR__"npc/jianxin" : 1,
       ]));

  setup();
}









