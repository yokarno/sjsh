inherit NPC;

void create()
{
        set_name("伙计", ({"huoji"}));
        set("long", "一位小伙计,看上去只十来岁。\n");

        set("gender", "男性");
        set("attitude", "peaceful");
        set("class", "bonze");

        set("age", 10+random(10));
        set("combat_exp", 15000);
  set("daoxing", 30000);

        set("shen_type", 1);
        set("per", 35);
        set("max_kee", 380);
        set("max_gin", 300);
        set("force", 250);
        set("force_factor", 5);
        set_skill("force", 20+random(20));
        set_skill("unarmed", 20+random(20));
        set_skill("dodge", 20+random(20));
        set_skill("parry", 20+random(40));

        setup();
        carry_object("/d/obj/其他/菩提衫")->wear();

        setup();
}

int accept_fight(object me)
{
        command("say 好吧，砌搓技艺，点到为止！\n");
        return 1;
}
