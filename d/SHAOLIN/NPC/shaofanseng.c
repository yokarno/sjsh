// worker.c

inherit NPC;
#include <ansi.h>

void create()
{
set_name("烧饭僧", ({
		"shaofan seng",
		"shaofan",
		"seng",
	}));
        set("gender", "男性" );
        create_family("少林寺", 10, "弟子");
        set("title", HIG"少林寺"NOR);
        set("age", 23);
	set("class", "bonze");
	set("attitude", "peaceful");
set("long",
		"这是位胖胖的中年僧人，大概是因为长年烧饭作菜的缘故，才如此发福的吧。\n"
	);
        set("combat_exp", 30);
        setup();
}

