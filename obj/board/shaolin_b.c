// shaolin_b.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("戒律碑", ({ "board" }) );
        set("location", "/d/shaolin/gate.c");
        set("board_id", "shaolin_b");
        set("long", "这是一块石碑，上面密密麻麻地记着少林寺弟子所立的战功。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
