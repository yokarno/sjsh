// changan wusheng
// baiyu14.c

inherit ROOM;
#include <room.h>

void create ()
{
  set ("short", "���Ƕ�");
  set ("long", @LONG

���ں�����������������ڶ��ڻص���˿˿��ζ�������Ρ�
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast": __DIR__"huoyun"+sprintf("%d",random(20)),
  "north": __DIR__"huoyun15",
  "northwest": __DIR__"huoyun"+sprintf("%d",random(20)),
]));

  set("no_clean_up", 1);
  setup();
}
int clean_up()
{
      return 0;
}
