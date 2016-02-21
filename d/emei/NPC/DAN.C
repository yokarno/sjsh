
// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
string expell_me(object me);
string ask_mieyao(object me);
string ask_cancel();

void create()
{
       set_name("������", ({"danchen zi", "danchen", "zi","master"}));
       set("long","����ɽ�ڶ�����������ܳ�������֮һ��\n");
       set("title", WHT"�����ɴ�ʦ��"NOR);
       set("gender", "����");
       set("age", 30);
       set("class", "xian");
       set("attitude", "friendly");
       set("rank_info/respect", "�����");
       set("per", 40);
	set("int", 30);
       set("max_kee", 3000);
       set("max_sen", 3000);
       set("sen", 3000);
       set("kee", 3000);
       set("max_gin", 600);
       set("max_force", 2000);
       set("max_mana", 2000);
       set("mana", 2000);
       set("force", 2000);
       set("force_factor", 100);
       set("mana_factor", 60);
       set("combat_exp", 1800000);
       set("daoxing", 1800000);
       set("eff_dx", 200000);
       set("nkgain", 350);
       set_skill("unarmed", 200);
       set_skill("literate", 200);
       set_skill("dodge", 200);
       set_skill("force", 200);
       set_skill("parry", 200);
       set_skill("sword", 200);
       set_skill("spells", 200);
       set_skill("emeiforce", 200);
       set_skill("zhutian-bu", 200);
       set_skill("tianlei-sword", 200);
       set_skill("mahayana", 200);
       set_skill("jinding-zhang", 200);
       map_skill("dodge", "zhutian-bu");
       map_skill("force", "emeiforce");
       map_skill("spells", "mahayana");
       map_skill("unarmed", "jinding-zhang");
       map_skill("sword", "tianlei-sword");
       map_skill("unarmed", "jinding-zhang");

       create_family("������", 2, "����");
 
        set("inquiry", ([
    "Ѫħ": (: ask_mieyao :),
     "��ɽ": (: expell_me :),
     "leave": (: expell_me :),
      "cancel": (: ask_cancel :),
]) );
setup();

        carry_object("/d/emei/obj/jiazhou")->wear();
        carry_object("/d/emei/obj/shoes")->wear();
        
}

void attempt_apprentice(object ob)
{
         if (((int)ob->query("combat_exp") < 1000000 )) 
        { 
             command("say " + RANK_D->query_respect(ob) + "����ѧ��Ϊ���������Щ��ѧ�ط�������������\n"); 
              return;
        }

        if(((int)ob->query_skill("huifeng-sword",1) > 1))
        {
              command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ȷ�����ѧ�Ľ��������ܰ���Ϊʦ��");
              return;
        }

        if(((int)ob->query_skill("tianji-sword",1) > 1))
        {
               command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ȷ�����ѧ�Ľ��������ܰ���Ϊʦ��");
              return;
        }

        if(((int)ob->query_skill("leiyan-sword",1) > 1))
        {
               command("say ��λ" + RANK_D->query_respect(ob) + "���㻹���ȷ�����ѧ�Ľ��������ܰ���Ϊʦ��");
              return;
        }


	 command("say �ã�ϣ��" + RANK_D->query_respect(ob) + "���Ŭ���������Ƕ��ҷ�����\n");
        command("recruit " + ob->query("id"));
        ob->set("title", WHT"���������Ŵ�ʦ��"NOR);
}


string expell_me(object me)
{       me=this_player();
        if((string)me->query("family/family_name")=="������") {
                command("say �����ִ����ɽ������Ϊ���Ҵ�ʦ��ȴ�м��仰˵��");
                me->set_temp("betray", 1);
     command("say �Ҷ���ɽ���������ɣ��ɼ����ڡ����й�����ɽ��ɽ�棡");
                return ("����Ҫ��ɽ��ȴ����ɽ��ͷ������Ը��(agree)?");
        }
        return ("���˲�֪��");
}
void init()
{
      ::init();
      add_action("do_agree", "agree");
      add_action("do_fuming","fuming");
}

int do_agree(string arg)
{
        if(this_player()->query_temp("betray")) {
                message_vision("$N���������Ը�⡣\n\n", this_player());
     this_player()->add("betray/count", 1);
     this_player()->add("betray/emei", 1);
                command("say �����Ҷ���ɽ����ס�㣬�����ɽȥ�ɣ�");
this_player()->set("combat_exp", this_player()->query("combat_exp")*80/100);
                this_player()->delete("family");
                this_player()->set("daoxing", this_player()->query("daoxing")*80/100);
                this_player()->delete("class");
                this_player()->delete_skill("tianji-sword");
                this_player()->delete_skill("tianlei-sword");
                this_player()->delete_skill("emeiforce");
                this_player()->delete_skill("leiyan-sword");
                this_player()->set("title","��ͨ����");
                this_player()->set("faith",0);
                this_player()->save();
                command("say ��Ӵ���Ҳ�������Ƕ���ɽ���ˣ���������ɽ�ɡ�����\n");
                this_player()->move("/d/city/center");
                tell_room( environment(this_player()),"ֻ����ž��һ����һ���˴Ӷ���ɽ�ϵ������������ص�ˤ���˵��ϡ�\n", ({this_player()}));
                return 1;
                }
        return 0;
}

string ask_mieyao(object me)
{
    me=this_player();
    if((string)me->query("family/family_name")=="������") {
    tell_room(environment(me),"������������һָ����ʱһ����â�����\n");
    return "/d/obj/mieyao"->query_yao(me);
    }
    return ("���˲�֪��");
}

