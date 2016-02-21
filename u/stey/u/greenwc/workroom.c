// Room: /u/yudian/workroom.c
inherit ROOM;
void create ()
{
  set ("short", "风雪居");
  set ("long", @LONG

狂风怒号，飞雪漫天。
（屋子是漏的。）
屋子中间端坐一位美女，
哇，是张柏芝啊，快让她签名！
LONG);

     set("exits", ([
             "west" : __DIR__"bedroom",
             "up" : __DIR__"sleeproom",
               "east" : __DIR__"guestroom",
             "out" : __DIR__"guardroom",
         "kz" : "/d/city/kezhan",
           "wiz" : "/d/wiz/wizroom",
     ]));    
  set("outdoors", 0);
  set("valid_startroom", 1);
    set("objects", ([
        __DIR__"zhangbz" : 1,
            __DIR__"jing" : 1,
             __DIR__"banxian" : 1,
    ]));           
  setup();
}
