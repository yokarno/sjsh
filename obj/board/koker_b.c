
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("哦麦噶的留言版", ({ "board" }) );
          set("location", "/u/koker/workroom");
          set("board_id", "koker_b");
          set("long",     "这是巫师哦麦噶为各位wiz能找到他而设置的白板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
