// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// under2.c

inherit ROOM;

void create ()
{
  set ("short", "海底");
  set ("long", @LONG

这里水色浑浊不清，视野很小。头顶是墨色的深蓝，一点光芒也没有。
LONG);

  set("objects", ([ /* sizeof() == 2 */
  __DIR__"npc/shuiyuan" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"island",
]));
        setup();
}

