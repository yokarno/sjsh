#include <ansi.h>
inherit NPC;

int give_me(object ob);
int create_guo(object ob);

void create()
{
       set_name(HIG"绿叶"NOR, ({"lv ye", "ye"}));

set("long","红叶的秘书。\n");
       set("gender", "女性");
       set("age", 18);
        set("title", HIR"红叶的秘书"NOR);
        set("per", 50);
        set("str", 35);
        set("con", 30);
        set("int", 20);
        set("max_kee", 1500);
        set("max_sen", 1000);
       set("attitude", "heroism");
       set("combat_exp", 700000);
  set("daoxing", 200000);
       set_skill("unarmed",100);
       set_skill("dodge",100);
        set_skill("hammer", 150);
        set_skill("parry", 150);
        set_skill("force", 100);
        set_skill("spells", 100);
        set("force", 800);
        set("max_force", 800);
        set("force_factor", 40);
        set("mana", 800);
        set("max_mana", 800);
        set("mana_factor", 40);
        set("inquiry", ([
                "人参果": (: give_me :),
                "guo": (: give_me :),
        ]) );
       setup();
     carry_object("d/obj/cloth/pinkskirt")->wear();
   //        carry_object("/u/repoo/obj/renshen-guo");
}
int give_me(object ob)
{
        object who, me,guo;
        who=this_player();
        me=this_object();
        guo=new("/u/repoo/obj/renshen-guo");

        if( who->query("rsgtemp_given")) {
                        message_vision(HIY"$N突然跳起，恶狠狠的瞪着$n说：要过了还要?\n"NOR, me, who);
                        command("hammer " + who->query("id"));
                        return 1;
                        }
        if( (int)who->query("age") < 16) {
                        message_vision(WHT"$N拍着$n的头说道：孩子，等你长大才会知道人参果是什么。\n"NOR, me, who);
                return 1;
                        }
       else
    {
       command("nod "+who->query("id"));
                message_vision(CYN"$N拿出一个人参果给$n。\n"NOR,me,who);
                who->set("rsgtemp_given", 1);
 who->set("name",HIR"红叶"NOR+HIY""NOR);
                guo->set("owner",who->query("id"));
                guo->move(who);
                return 1;
                }
}
