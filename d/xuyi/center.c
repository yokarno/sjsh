// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "中心广场");
  set ("long", @LONG

这里就是蠙城的中心，彩色石块铺成的大道向四方伸延。广场呈菱形，一
圈围的都是小贩，艺人，和看热闹的人。熙熙攘攘的人群中也少不了几个
跑江湖之人，很多新奇的事物在大唐是闻所未闻的。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"lukou",
  "north" : __DIR__"yujie",
  "east" : __DIR__"jiedao8",
  "west" : __DIR__"jiedao1",
]));

  setup();
}


