
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
       set_name("ｂｕｇ留言版", ({ "board" }) );
           set("location", "/d/wiz/entrance");
             set("board_id", "xlqy_ah");
          set("long",     "这是供巫师和玩家互相交流，共同促进三界神话发展的讨论板。\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
