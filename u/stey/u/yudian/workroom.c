// Room: /u/yudian/workroom.c
#include <ansi.h>
inherit ROOM;
void create ()
{
    set ("short", HIW"风雪居"NOR);
  set ("long", @LONG

狂风怒号，飞雪漫天。
（屋子是漏的。）
屋子中间端坐一位美女，
哇，是张柏芝啊，快让她签名！
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
               "up" : "/u/yushu/workroom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
         "kz" : "/d/city/kezhan",
           "wiz" : "/d/wiz/wizroom",
             "guest" : "/d/wiz/guest",
     ]));    
  set("outdoors", 0);
set("no_fight",1);
set("no_magic",1);
set("no_time",1);
  set("valid_startroom", 1);
      set("objects", ([
//            "/u/yudian/npc/zhinu" : 1,
            "/u/vikee/table" : 1,
//                 "/u/yudian/man" : 1,
      ]));     
//            __DIR__"/npc/zhangbz" : 1,
//                __DIR__"/npc/jing" : 1,
//                 __DIR__"/npc/banxian" : 1,
//      ]));           
  setup();
      call_other("/obj/board/yudian_b", "???");
}
