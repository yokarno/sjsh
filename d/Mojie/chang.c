// Room: /d/mojie/chang.c
inherit ROOM;

void create()
{
  set ("short", "灭法场");
  set ("long", @LONG
魔界灭法场乃是无天当年和三百佛门高僧斗法之地，话说如来圆寂，
众佛门弟子齐上魔界斩妖灭魔，无天借黑水之力将三百佛门弟子活
活淹死。所以这里便被无天称之为灭法场。自从无天再入三界之日
起，此地便成为佛门禁地。这里三面就被黑水环绕。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"guodao.c",
  "west" : __DIR__"yuan",
  "east" : __DIR__"yuan",
]));
        set("objects", 
        ([ //sizeof() == 1
                "/d/mojie/npc/bing" : 4,
        ]));
  setup();
  call_other("/obj/board/mojie_b", "???");
}
