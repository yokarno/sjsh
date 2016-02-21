#include <ansi.h>
// bula and mon@xyj

inherit __DIR__"yaoguai.c";

// here should be this NPC specific skills.

void set_skills(int j, int level)
{
        object me=this_object();
        object weapon;

        me->set("title",HIW"��������"NOR);
        me->set_skill("unarmed", j);
        me->set_skill("dodge", j);
        me->set_skill("parry", j);
        me->set_skill("force", j);
        me->set_skill("spells", j);
 
        me->set_skill("sword", j);
        me->set_skill("baiyun-sword", j);
        me->set_skill("piaoxiang", j);
        me->set_skill("lingxiyizhi", j);
        me->set_skill("tianjijue", j);
        me->set_skill("wuji-force", j);

        me->map_skill("force", "wuji-force");
        me->map_skill("sword", "baiyun-sword");
        me->map_skill("parry", "baiyun-sword");
        me->map_skill("spells", "tianjijue");
        me->map_skill("dodge", "piaoxiang");
        me->map_skill("unarmed", "lingxiyizhi");

	set("chat_chance_combat", cast_chance(level));
        set("chat_msg_combat", ({
        (: perform_action,"sword", "feixian" :),
        (: cast_spell, "sword" :),
        (: exert_function, "xue" :),
        (: cast_spell, "freeze" :),
        }) );

        weapon=new("/d/obj/weapon/sword/changjian");
        weapon->move(me);
        carry_object("/d/obj/cloth/shoupiqun")->wear();
        command("wield all");
}
