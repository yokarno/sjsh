//kissess'留言板
//made by kissess on Mar 12,2002

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIY"追风工作台"NOR, ({ "board" }) );
        set("location", "/u/kissess/workroom");
        set("board_id", "kissess_bbs");
        set("long",     "这是巫师追风的工作台。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

