// lanling_b1.c

inherit BULLETIN_BOARD;

void create()
{
        set_name("兰陵客栈留言板", ({ "board" }) );
        set("location", "/d/calvin/kezhan2");
        set("board_id", "lanling_b1");
        set("long",     "这是一个供人留言记事的留言板。\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
