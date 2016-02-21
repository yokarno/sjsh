// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "青石小道");
  set ("long", @LONG

一条青石小道由海滩延绵至此。道路两旁盛开着各种各样的野花，蜂飞蝶
舞，鸟语花香。在前面不远有一座城市，城门上写着“蠙城”两个烫金大
字，几个卫士守在门前，注视着来来往往的行人。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"path",
  "north" : __DIR__"nanmen",
]));

  setup();
}


