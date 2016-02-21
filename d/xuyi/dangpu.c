// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */
 
#include <room.h>
inherit HOCKSHOP;

void create ()
{
  set ("short", "杨记当铺");
  set ("long", @LONG

这是一家以买卖公平著称的当铺，一个五尺高的柜台挡在你的面前，柜台
上摆着一个牌子(sign)，柜台后坐着杨老板，一双精明的眼睛上下打量着
你。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"jiedao8",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "sign" : "
本当铺财力雄厚，童叟无欺，欢迎惠顾，绝对保密。
客官可以在这里：
   ●=======================●
   ||  典当(pawn)           ||   
   ||  卖断(sell)           ||
   ||  估价(value)          ||
   ||  赎回(retrieve stamp) ||
   ||  购买(buy) 用list查看 ||
   ●=======================●

各种货物，铜钱、银两、黄金、银票一概通用。

"]));
  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/pablo" : 1,
]));
  set("no_clean_up", 1);

  setup();
}

int clean_up()
{
      return 0;
}

