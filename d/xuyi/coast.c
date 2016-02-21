// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

inherit ROOM;

void create ()
{
  set ("short", "南赡部洲海岸");
  set ("long", @LONG

这里就是蠙城东南的海岸，地势险恶，怪石嶙峋。海潮一波一波地扑过
来，在礁石上击得粉碎，发出震耳欲聋的响声。海风呼啸着吹过，吹得
人的衣衫猎猎作响。
LONG);

  set("objects", ([ /* sizeof() == 1 */

]));
  set("outdoors", 1);
  set("dangerous", 1);  
  
  set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"milin4",
  "northwest" : "/d/changan/southseashore",
]));

  setup();
}

