//by yxm@hxxt.hz
inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short", BLK"黑暗之渊"NOR);
  set ("long", @LONG
[1;31m这里就是通往阿修罗界之路,一条通向死亡,[2;37;0m
[1;31m通向痛苦,通向罪恶的黑暗之路.[2;37;0m
[1;31m四周魔气森森,让人不寒而栗![2;37;0m
LONG);
  set("exits", ([ /* sizeof() == 4 */
"enter" : "/u/tianlin/阿修罗界/lu2",
]));
  setup();
}
