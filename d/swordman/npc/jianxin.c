inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
         set_name("緋村劍心"NOR, ({"master jianxin", "jianxin","master"}));
       set("long",
"幕末时令人闻风散胆的千人斩拔刀斋，维新后便失去了踪影。取
而代之的是浪客剑心，坚持着不杀的信念，誓以手中之剑保护天
下弱小之人。\n");
         set("title", HIC"飛天禦劍流傳人"NOR);
       set("gender", "男性");
       set("age", 30);
       set("class", "swordman");
       set("attitude", "friendly");
       set("per", 30);
	set("int", 30);
       set("max_kee", 5000);
       set("max_sen", 5000);
       set("force", 8000);
       set("max_force", 4000);
       set("force_factor", 200);
       set("max_mana", 4000);
       set("mana", 8000);
       set("mana_factor", 200);
       set("combat_exp", 5000000);
       set("daoxing", 3000000);

       set_skill("literate", 300);
       set_skill("unarmed", 300);
       set_skill("dodge", 300);
       set_skill("force", 300);
       set_skill("parry", 300);
       set_skill("sword", 340);
       set_skill("spells", 300);
   set_skill("renshu", 280);
   set_skill("guixi-force", 280);
   set_skill("feitian-sword", 340);
   set_skill("fengyu-piaoxiang", 300);
   map_skill("spells", "renshu");
   map_skill("force", "guixi-force");
   map_skill("sword", "feitian-sword");
   map_skill("parry", "feitian-sword");
   map_skill("dodge", "fengyu-piaoxiang");
    set("inquiry", ([
	"天翔龙闪"     : "[天翔龙闪]招式过于狠毒，在下不会将它传于任何人的！",
                               ]) );

           set("chat_chance",2);
           set("chat_msg", ({
        WHT"剑心笑笑说道：师傅曾告诉我，剑是凶器，剑术是杀人术,不管用怎样堂皇的借口也掩盖不了这个事实。\n"NOR,
        WHT"剑心笑笑说道：熏小姐也曾说过，神谷活心流是救人剑，是绝不杀人的剑法。\n"NOR,
        WHT"剑心笑笑说道：相比师傅所说的,熏小姐的只是从未弄脏过自己的手的人说的玩笑话。\n"NOR,
        WHT"剑心笑笑说道：不过，在师傅的真话和熏小姐的玩笑话之间，我更喜欢熏小姐的玩笑话一些。\n"NOR,
        }));

        create_family("剑客联盟", 1, "弟子");
        setup();

       carry_object("/d/obj/cloth/zhanpao")->wear();
          carry_object("/u/peaceful/sword")->wield();
}

void attempt_apprentice(object ob)
{
 if (((int)ob->query("PKS") > 0 )) {
   command("say " + RANK_D->query_respect(ob) +"你杀心太重，不适合学习我的飞天御剑流。\n");
   return;
   }

 if (((int)ob->query("swordman/zhizhixiong"))) {
   command("say " + RANK_D->query_respect(ob) +"你不适合学习我的飞天御剑流。\n");
   return;
   }

 if (((int)ob->query("swordman/dead_perform"))) {
   command("say " + RANK_D->query_respect(ob) +"你不适合学习我的飞天御剑流。\n");
   return;
   }

 if (((int)ob->query("combat_exp") < 1200000 )) {
   command("say " + RANK_D->query_respect(ob) +"还是先打好基础再来。\n");
   return;
   }

   command("say 好，希望" + RANK_D->query_respect(ob) +"多加努力，用剑保护天下所有弱小之人。\n");
   command("recruit " + ob->query("id") );
   ob->set("title", WHT"飞天御剑流传人"NOR);
   ob->set("class", "swordman");
   return;
}
