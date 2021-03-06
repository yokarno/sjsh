// 布玛 by Calvin

#include <ansi.h>
inherit NPC;
string ask_me();
void create()
{
   set_name(HIM"布玛"NOR, ({"bu ma","bu","ma","tianshen"}));
   set("title", HIW"灵月仙子"NOR);
   set("gender", "女性");
   set("long", "龙珠的守卫者。\n");
   set("attitude", "peaceful");
   set("combat_exp", 2000000);
   create_family("五庄观", 1, "祖师");
      set("age", 3000);
      set("per", 40);
        set("str", 30);
        set("int", 30);
        set("cor", 30);
        set("cps", 30);
        set("con", 30);
   set("class", "xian");
   set("rank_info/respect", "灵月仙子");
   set("max_kee", 5000);
   set("max_sen", 5000);
   set("force", 2400);
   set("max_force", 2400);
   set("force_factor", 40);
   set("max_mana", 2400);
   set("mana",2400);
   set("mana_factor", 50);

   set_skill("spells", 350);
   set_skill("taiyi", 350);
   set_skill("force",350);
   set_skill("zhenyuan-force",350);
   set_skill("parry", 350);
   set_skill("dodge", 350);
   set_skill("baguazhen", 350);
   set_skill("unarmed", 350);
   set_skill("wuxing-quan", 350);
   set_skill("sword",350);
   set_skill("xiaofeng-sword",350);
   set_skill("blade",350);
   set_skill("yange-blade",350);

   map_skill("spells", "taiyi");
   map_skill("force", "zhenyuan-force");
   map_skill("dodge", "baguazhen");
   map_skill("unarmed", "wuxing-quan");
   map_skill("sword", "xiaofeng-sword");
   map_skill("blade", "yange-blade");

        set("inquiry", ([
     "name"     : "小仙灵月仙子是也。\n",
     "here"     : "此乃灵月天也。\n",
        ]));

   set("time", 1);
   setup();
//        carry_object("/d/zj/weapon/lingyue")->wield();
      carry_object("/d/zj/armor/lingyue")->wear();   
      carry_object("/d/zj/armor/kui")->wear();   
//    carry_object("/d/penglai/npc/obj/bag");
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="五庄观" )
   {
     if( (int)ob->query("family/generation") < 1  )
     {
        command("say 不敢当，不敢当。\n");
     }
     else if( (int)ob->query("family/generation") ==1  )
     {
        command("say 呵呵，是" + ob->query("family/master_name") + "的徒弟啊,那我就不客气了。\n");
        command("recruit " + ob->query("id") );
     }
     else 
     {
        if( ob->query_skill("taiyi", 1) >= 200 )
        {
          command("say 好，有出息，这个徒弟我收下了。\n");
          command("recruit " + ob->query("id") );
        }
        else
        {
          command("say 我们仙家最看重仙法，你还得在这方面下苦功。\n");
        }
     }
  }
   else
   {
     command("say 好，不过你还是先找八仙他们练一些入门的功夫吧。\n");
   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "xian");
}
