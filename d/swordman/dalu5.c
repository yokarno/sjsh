// created by snowcat 12/2/1997

inherit ROOM;

void create ()
{
  set ("short", "青石街道");
  set ("long", @LONG

拥挤的东瀛街道，道路由青色小石铺成。人声鼎沸，街景秀丽，令人
目不暇己。两边有不少行人来回匆匆走过。南面是一家颇具规模的客
栈,人潮涌进涌出,热闹极了。

LONG);

  set("exits", ([
        "west"    : __DIR__"dalu4",
        "east"    : __DIR__"dalu6",
        "south"   :__DIR__"kezhan",
      ]));
  set("outdoors",__DIR__"");
  set("objects", ([
        __DIR__"npc/people"    : 2,
      ]));

  setup();
}

