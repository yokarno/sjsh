// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
#include <ansi.h>

inherit NPC;


void create()
{
        set_name("王府卫士", ({ "wei shi", "shi", "guard" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",

"这是位守护王府的卫士，身披铜甲，手执方天画戟。
他双目精光炯炯，警惕地巡视着四周的情形。\n");
        set("combat_exp", 160000);
        set("attitude", "heroism");
        set("str", 25);
        set("max_kee", 750);
        set("max_sen", 600);
        set("force", 400);
        set("max_force", 400);
        set("force_factor", 15);
//        set_skill("halberd", 60);
        set_skill("unarmed", 60);
//        set_skill("tianlong-halberd", 60);
        set_skill("parry", 60);
        set_skill("dodge", 60);
 //       map_skill("halberd", "tianlong-halberd");
//        map_skill("parry", "tianlong-halberd");
   set_skill("force", 50);
        setup();

//        carry_object("/d/obj/weapon/halberd/sanchaji")->wield();
        carry_object("/d/obj/armor/tongjia")->wear();
}


int accept_fight(object me)
{
        message_vision("王府卫士对$N大喝一声：你活得不耐烦了？王府前也敢胡闹！\n", me);
        me->apply_condition("killer", 100);
        kill_ob(me);
        return 1;
}

