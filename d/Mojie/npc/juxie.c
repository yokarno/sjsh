#include <ansi.h>
inherit NPC;
inherit F_MASTER;
string ask_go();

void create()
{
        set_name("巨蝎", ({"juxie"}));
        set("gender", "女性" );
        set("age", 33);
        set("title", "无天座下左护法");
        set("combat_exp", 1500000);
	set("daoxing", 1500000);
        set("long", "她是无天座下左护法，是无天必不可少的智囊团。
无天进军佛界的一切计策都是由她所出。她为人
阴险狡诈，诡计多端。\n");
        set("attitude", "peaceful");
	set("int", 25);
	set("class", "mo");
        create_family("魔界", 2, "弟子");
	
        set("eff_dx", 30000);
        set("nkgain", 200);

        set_skill("unarmed", 280);
        set_skill("dodge", 280);
        set_skill("parry", 280);
        set_skill("spells", 280);  
        set_skill("molianspells", 280);
        set_skill("literate", 280);
        set_skill("whip", 280);  
        set_skill("liudu-whip", 280);
        set_skill("shifo-zhi", 280);  
        set_skill("moshenbu", 280);
        set_skill("dodge", 280);  
        set_skill("force", 280);   
        set_skill("heilianforce", 280);

        map_skill("spells", "molianspells");
        map_skill("unarmed", "shifo-zhi");
        map_skill("force", "heilianforce");
        map_skill("whip", "liudu-whip");
        map_skill("parry", "liudu-whip");
        map_skill("dodge", "moshenbu");


        set("per", 30);
        set("max_kee", 2500);
        set("max_sen", 2500);
        set("force", 2500);
        set("max_force", 2500);
        set("force_factor", 50);
        set("mana", 2500);
        set("max_mana", 2500);
        set("mana_factor", 50);
        set("inquiry", ([
                "back" : (: ask_go :),
        ]) );


        setup();
        carry_object("/d/mojie/obj/tongjia")->wear();
        carry_object("/d/mojie/obj/ldwhip")->wield();
}

string ask_go()
{
        object who,me,room;
        
        who = this_player();
        me = this_object();
        write("巨蝎对你说道：你要回去吗？本护法现在就送你走！\n");
        write("巨蝎念了几句咒语，天下飞下一朵巨大的黑莲，你坐了上去.......\n");
        if(!( room = find_object("/d/city/center")) )
            room = load_object("/d/city/center");
        if(objectp(room))
            who->move(room);
        return "\n巨蝎念了几句咒语，天下飞下一朵巨大的黑莲，一个人坐了上去.......\n\n";
}


void attempt_apprentice(object ob, object me)
{
        if( (int)ob->query_skill("molianforce", 1) < 120 ) {
        command("say 这位" + RANK_D->query_respect(ob) + "对我魔道内功领会还不够深，现在收你也是勉为其难，不如作罢！\n");              
        return;
        }
        command("say 很好，" + RANK_D->query_respect(ob) +
"加入魔界以后多加努力，他日为杀如来做出你的贡献。\n");
        command("recruit " + ob->query("id") );
            ob->set("title", HIG"魔界左护法座下弟子"NOR);
	return;
}		

int recruit_apprentice(object ob)
{
        if( ::recruit_apprentice(ob) )
                ob->set("class", "mo");
}
