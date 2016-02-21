//Cracked by Roath
//【蜀山剑派】dhxy-evil 2000.7.5
#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIC"剑圣"NOR, ({ "jian sheng", "sheng", "swordsman" }));
        set("title","");
        set("long", 
"蜀山剑派掌门人，满头白发的老人，两眼相当有神。\n");

        set("gender", "男性");
        set("age", 65);
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 40);
        set("con", 30);
        set("per", 20);
        set("class","swordsman");
        
        set("kee", 4000);
        set("max_kee", 4000);
        set("sen", 3000);
        set("max_sen", 3000);
        set("force", 8000);
        set("max_force", 5000);
        set("max_mana",5000);
        set("mana",8000);
        set("force_factor", 100);
        set("mana_factor", 100);
        set("combat_exp", 3000000);
        set("daoxing", 5000000);

        set_skill("spells",170);
        set_skill("force", 180);
        set_skill("dodge", 150);
        set_skill("parry", 160);
        set_skill("sword", 200);
        set_skill("zixia-shengong", 180);
        set_skill("sevensteps", 170);
        set_skill("hunyuan-zhang", 160);
        set_skill("literate", 140);
        set_skill("unarmed", 160);
        set_skill("mindsword", 200);
        set_skill("shushan-jianfa", 200);
        set_skill("taoism",170);
        map_skill("spells", "taoism");
        map_skill("dodge", "sevensteps");
        map_skill("force", "zixia-shengong");
        map_skill("parry", "mindsword");
        map_skill("sword", "mindsword");
        map_skill("unarmed", "hunyuan-zhang");


        create_family("蜀山剑派", 4, "掌门人");

        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "sword","xindong" :),
                (: cast_spell, "jianshen" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );
   add_temp("apply/damage", 135);
   add_temp("apply/attack", 135);
   add_temp("apply/dodge", 135);
   add_temp("apply/spells", 100);
   add_temp("apply/armor", 150);
   add_temp("apply/armor_vs_force",250);
   add_temp("apply/armor_vs_spells",250);
  set("inquiry", ([
        "leave": (: expell_me :),
        ]) );
        setup();
        
        carry_object("/d/obj/cloth/jinpao")->wear();
        carry_object("/d/obj/weapon/sword/qingfeng")->wield();
}
void attempt_apprentice(object ob)
{        
	if (ob->query_skill("sword",1) < 130) {
        command("say 我蜀山剑派，最注重御剑术的修行，依我看" + RANK_D->query_respect(ob) + "是不是该多下下苦功呢？");
                return ;
        }
        if ((int)ob->query_int() < 35) {
        command("say 依我看" + RANK_D->query_respect(ob) + "的资质似乎不适合学我蜀山剑派武功？");
                return;
        }
        
        if (ob->query("shushan/ask_zuidao_go")) {
        if (ob->query("nyj/shushan")!="done"){
                command("say " + RANK_D->query_respect(ob) + "，你既然要违背门规去镇妖塔，还想我跟我剑圣学蜀山剑派武功？");
                return;
        }
        command("say 天意，真是天意！");
        
        }
        command("say 好吧，我就收下你了。");
        command("recruit " + ob->query("id"));
        ob->set("class", "swordsman");
        ob->set("title","剑圣传人");
}
string expell_me(object me)
{
  me=this_player();
  if((string)me->query("family/family_name")=="蜀山剑派")
    {
      me->set_temp("betray", 1);
      command("sigh");
      return ("按我蜀山门规，却须受罚，你可愿意(agree)？");
    }
  return ("我不知道！");
}
void init()
{
  add_action("do_agree", "agree");
}
int do_agree(string arg)
{
  if(this_player()->query_temp("betray"))
    {
      message_vision("$N答道：弟子愿意。\n\n", this_player());
      command("say 那你便去吧。。。或者这是天意！");
      this_player()->add("betray/count", 1);
      this_player()->add("betray/shushan", 1);
      this_player()->delete_skill("taoism");
      this_player()->delete_skill("zixia-shengong");
      this_player()->delete_skill("shushan-jianfa");
      this_player()->delete_skill("canxin-jian");
      this_player()->delete_skill("dugu-jiujian");
      this_player()->delete_skill("yirubian");
      message_vision("剑圣在$N的头上怕了一下，$N顿时觉得若有所失。\n\n", this_player());
      this_player()->delete("family");
      this_player()->set("title", "蜀山叛徒");
      this_player()->save();
      return 1;
    }
  return 0;
}
