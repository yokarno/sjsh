// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "十字路口");
  set ("long", @LONG

这是蠙城内的主要商贸场所。形形色色的叫卖声在耳边此起彼伏，连绵不
绝。路上车水马龙，各色行人摩肩接踵，热闹非凡。这里偏于南方一隅，
风俗比之大唐天朝颇有不同，然而，民风淳朴，尤有过之。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jiedao0",
  "north" : __DIR__"center",
   "west" : __DIR__"jiedao5",
  "east" : __DIR__"jiedao4",
]));

  setup();
}


