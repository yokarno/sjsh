// NPC 密林

inherit NPC;

void create()
{
       set_name("密林隐士", ({"yinshi"}));
       set("long", "密林深处隐居的无名人士.\n");
       set("title", "密林百姓");
       set("gender", "男性");
        set("combat_exp", 100000);
        set("daoxing", 30000000);
       set("age", 45);
       set("attitude", "friendly");
       set("shen_type", 1);
       set_skill("unarmed", 120);
        setup();
       add_money("gold", 1);
}
