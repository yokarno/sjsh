// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */

//created by night 7/26/2000

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "南门");
  set ("long", @LONG

这是蠙城南门，一条小河绕城墙而过，城墙建在河北，由石块和土垒成，
高二丈五，厚达二丈，门上有重楼，驻有岗哨。城下三两个盔甲鲜明的军
士在一位将军的带领下四处巡查，瞪大了眼睛观察着来来往往的行人。青
石小道直向北延伸，通向城里。

LONG);

  set("objects", ([ /* sizeof() == 1 */
        __DIR__"npc/zhao" : 1,
        __DIR__"npc/weishi" : 4,
]));
  set("outdoors", 1);
  
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"path1",
  "north" : __DIR__"jiedao0",
]));

  set("valid_startroom", 1);
  setup();
//  call_other("/obj/board/xuyi_b", "???");

}
