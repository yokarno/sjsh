// 神话世界·西游记·版本４．５０
/* <SecCrypt CPL V3R05> */
 
// lancaihe.c...weiqi, 98.02.24.

inherit NPC;
void create()
{
   set_name("王神将", ({"wang shenjiang", "wang", "shenjiang"}));
   //set("title", "");
   set("gender", "男性" );
   set ("age", 40);
   set("per", 20);
   set("long", "王府的老家将，为王府立下赫赫战功。\n");
   set("class", "bonze");
   set("combat_exp", 120000);
   set("attitude", "peaceful");
   create_family("南海普陀山", 3, "弟子");
   set_skill("unarmed", 50);
   set_skill("dodge", 80); 
   set_skill("tianwei-shi", 80);
   set_skill("parry", 90); 
   set_skill("lianhuan-tui", 50);   
//   set_skill("halberd", 70);
//   set_skill("tianlong-halberd", 80);
   set_skill("force", 80);   
   set_skill("lotusforce", 80);   
   set_skill("literate", 70);
   set_skill("spells", 80);
   set_skill("buddhism", 80);
//   map_skill("halberd", "tianlong-halberd");
//   map_skill("parry", "tianlong-halberd");  
   map_skill("dodge", "tianwei-shi");    map_skill("unarmed", "lianhuan-tui");   map_skill("force", "lotusforce");
   map_skill("spells", "buddhism");

   set("max_kee", 500);
   set("max_sen", 500);
   set("force", 1000);
   set("max_force", 800);
   set("mana", 1600);
   set("max_mana", 800);   
   set("force_factor", 40);
   set("mana_factor", 40);

   setup();
   carry_object("/d/obj/cloth/linen")->wear();
   carry_object("/d/obj/armor/tongjia")->wear();
//   carry_object("/d/obj/weapon/halberd/huaji")->wield();
}

void attempt_apprentice(object ob)
{
   if( (string)ob->query("family/family_name")=="南海普陀山" )
   {
     if( (int)ob->query("family/generation") < 3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师叔见笑了。\n");
        else command("say 师姑见笑了。\n");
     }
     else if( (int)ob->query("family/generation") ==3  )
     {
        if ( (string)ob->query("gender") == "男性" ) command("say 师兄太客气了。\n");
        else command("say 师妹太客气了。\n");
     }
     else 
     {
        command("consider");
        command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "普陀山城护宫武士");
                else ob->set("title", "普陀山城护宫女史");
                     }
   }

   else
   {
     command("say 好，那我就勉为其难吧。\n");
     command("recruit " + ob->query("id") );
        if ( (string)ob->query("gender") == "男性" ) ob->set("title", "普陀山城护宫武士");
                else ob->set("title", "普陀山城护宫女史");
                   }

   return;
}

int recruit_apprentice(object ob)
{
   if( ::recruit_apprentice(ob) )
     ob->set("class", "bonze");
}

int accept_fight(object me)
{
        command("say 我为王府神将，岂能与你村野匹夫较艺！");
        return 0;
}


