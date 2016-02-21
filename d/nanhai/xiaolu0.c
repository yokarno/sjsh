// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by jing 7/24/2000
 
inherit ROOM;

void create ()
{
  set ("short", "小路");
  set ("long", @LONG

一条泥土和石块混杂的小路，西面一直走就到了蠙城。远远可以望见蠙城
的城门，上面旌旗迎风呼呼着响。东面羊肠小路曲曲折折，叫人不知道怎
么走。
LONG);

  set("exits", ([
        "west"   : __DIR__"dongmen",
        "southeast"   : __DIR__"milin1",
  "east" : __DIR__"xiaolu"+sprintf("%d",1+random(4)),
      ]));
  set("objects", ([
//        __DIR__"npc/people"   : 1,
      ]));
  set("outdoors", __DIR__);

  setup();
}

int valid_leave(object me, string dir)
{
   if(me->query_temp("nanhai/monster")) return 1;
//        if( wizardp(me)) return 1;

        if (dir == "southeast") {

        return notify_fail("忽然一阵阴风从密林里吹来，你不由自主地停下了脚步。\n");

        }   
        return ::valid_leave(me, dir);
}

