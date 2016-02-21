// pet.c writted by Beeby. 07/28/2000
// modified by vikee 11/2000
// modified by jie 2/2001
// 增加了叫坐骑去攻击gongji
// 增加了教坐骑技能teach,only unarmed,parry,dodge can teach
// 增加了主人查看坐骑shape
#include <ansi.h>
#include <combat.h>
inherit NPC;
inherit F_SAVE;

private string SAVE_NAME="pet_save";
private static int can_save=1;


void create()
{       
      //          seteuid(getuid());
        set_name("宠物", ({"pet"}) );
           set("gender", "女性");
        set("race","野兽");
        set("age", 1);
        set("base_name","兔");
        set("attitude", "friendly");
        set("long","小家伙。\n");
        set("combat_exp", 100);
        set("daoxing",100);
        set("str",3);//力量
        set("cor",3);//凶性
        set("per",3);//体态
        set("spi",3);//灵性
        set("cps",3);//冷静
        set("con",3);//体质
        set("owner","dad");
        set("limbs", ({ "头部", "身体", "前脚", "後脚", "尾巴" }) );
          set("verbs", ({ "bite", "claw" }) );
        set("ride/msg", "骑");
        set("ride/dodge", 35);
        set_skill("unarmed",10);
        set_temp("apply/attack", 80);
        set_temp("apply/armor", 80);

        set("is_pet",1);

        setup();
}

void reset()
{
        if( !environment() ||  //mon 2/4/98
                ! find_living(query("owner")) )
        {
                destruct(this_object());
                return;
        }
}


void unconcious()
{
        return die();
}

string query_save_file()
{
        string id;
        id = query("owner");
        if( !id ) return 0;
        return sprintf(DATA_DIR"pet/%c/%s", id[0], id);
}

int save()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) ) {
                assure_file(file+ __SAVE_EXTENSION__);
                return save_object(file);
        }
        return 0;
}

int restore()
{
        string file;

        if( stringp(file = this_object()->query_save_file()) )
                return restore_object(file);
        return 0;
}

void die()
{       
        int i;
        object owner, *enemy;
        int gin,kee,sen,exp;
        
        exp = (int) query("combat_exp");
        gin = (int) query("max_gin");
        kee = (int) query("max_kee");
        sen = (int) query("max_sen");
        if(!environment()->query("no_death_penalty"))
        set("combat_exp",exp/10 * 9);
        set("eff_kee",kee);
        set("eff_gin",gin);
        set("eff_sen",sen);
        set("kee",kee);
        set("gin",gin);
        set("sen",sen);
        

        save(); 
        ::die();
}
void init()
{
        add_action("do_kill",({"kill","fight","steal"}));
        add_action("do_mount","mount");
        add_action("do_gongji","gongji");//叫坐骑去攻击
        add_action("do_teach","teach");// 向坐骑传授武功
        add_action("do_shape","shape");// 查看坐骑
}

int do_mount(string arg)
{
     object me=this_object(),who=this_player(),env;
     if(!arg) return 0;
     env = environment(who);
     if(present(arg,env)!=me) return 0;
     if(me->query("owner")==who->query("id")) 
     {
     who->set_temp("pet",1);
     return 0;
     }
     message_vision("$n左躲右闪，$N累得满头大汗也没骑上去。\n",who,me);
     
     return 1;
}


int do_kill(string arg)
{       
        object me,who;
        string name,verb,what,obj;
        if (!arg) return 0;
        verb=query_verb();
        me=this_player();
        
        if(verb=="steal") {
          if(sscanf(arg, "%s from %s", what, obj)!=2 ) 
            return 0;
          }
        else obj=arg;

        if(!objectp(who=present(obj,environment(me))) 
           || !living(who)) return 0;

        if(who==this_object()) {
          switch(verb) {
            case "kill":
              tell_object(environment(this_object()),
                who->query("name")+"拼命地哭了起来：主人，"+
                me->query("name")+"要杀我．．．快回来呀！\n");
              break;
            case "fight":

              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人，"+
                me->query("name")+"要抢我的糖吃．．．快回来呀！\n");
              break;
            case "steal":

              tell_object(environment(this_object()),
                who->query("name")+"哭了起来：主人，"+
                me->query("name")+"要偷吃我的糖！\n");
              break;
          }
        }
        command(verb);
        return 0;
}

void relay_emote(object ob, string verb)
{
        if( !userp(ob) ) return;

        switch(verb) {
        case "kick":
                command("say 主人～～，主人～～，"  + ob->query("name") + "踢我耶！");
                command("kick " + ob->query("id"));
                        break;
        case "slap":
                command("say 主人～～，主人～～，"  + ob->query("name") +
"打我耶，好痛啊～～～～");
                command("slap " + ob->query("id"));
                        break;
        case "hit":
                command("pain " + ob->query("id"));
                        break;
        case "bite":
                command("face " + ob->query("id"));
                        break;  
        case "papaya":
                command("pout");
                        break;  

                }
}

void relay_whisper(object me, string msg)
{
        if (me->query("id")!=query("owner"))
        {
                message_vision((string)this_object()->query("name")
                        + "疑惑地看着$N。\n", me);
                return;
        }

        if( strsrch(msg, "chat") != -1 ||
            strsrch(msg, "sldh") != -1 ||
            strsrch(msg, "es") != -1 ||
            strsrch(msg, "rumor") != -1 ||  
            strsrch(msg, "xyj") != -1 ||  
            strsrch(msg, "tell") != -1 ||
            strsrch(msg, "follow") != -1 ||
            strsrch(msg, "apprentice") != -1 ||
            strsrch(msg, "recruit") != -1 )
                return;

        if (msg)
        {
                remove_call_out ("relaying");
                call_out ("relaying", 1+random(3), msg);
        }
}

void relaying (string msg)
{
        command (msg);
}

int do_gongji(string arg)
{
          object me,obj,who;
       mapping action;
        me = this_player();
          who = this_object();
        if( environment(me)->query("no_fight") )
                return notify_fail("这里不准战斗。\n");

        if( !arg )
                return notify_fail("你想杀谁？\n");

        if(!objectp(obj = present(arg, environment(me))))
                return notify_fail("这里没有这个人。\n");

          if( !obj->is_character() || obj->is_corpse() )
                 return notify_fail("看清楚一点，那并不是活物。\n");
              if(who->query("owner")==me->query("id")) {
action=who->query("actions");
        if( !mapp(action) ) {
                who->reset_action();
                action=who->query("action");
                
        }
        message_vision(
        sprintf("$N对$n一指，对%s命令道：＂上！＂\n",this_object()->name()),me,obj);
        me->add("sen",-5);
//          add("sen",-10);
        kill_ob(obj);
           }
        return 1;
        
}

int do_teach(string arg)
{
         object me,who;
        int gin_cost,amount;
        int myskill, itskill;
        me = this_player();
          who = this_object();
        if(!myskill = me->query_skill(arg,1))
        return notify_fail("这项技能你好象还不会呢！\n");
        if(arg != "unarmed" && arg != "parry" && arg != "dodge")
        return notify_fail("它学不会这项技能的！\n");
          if(who->query("owner")==me->query("id")) {
        itskill = query_skill(arg,1);
        if(myskill <= itskill)
        return notify_fail(name()+"以嘲笑的目光望着你。\n");
        if((int)me->query("potential")-(int)me->query("learned_points") < 1)
        return notify_fail("你的潜能不够！\n");
        gin_cost = 100/ (int)me->query_int();
        if((int)me->query("gin") < gin_cost)
        return notify_fail("你显然太累了没有办法教！\n");
        me->receive_damage("gin",gin_cost);
        me->add("potential",-1);
        amount = (int)me->query_int() * (int)me->query_int()/100;
        message_vision(sprintf("$N不厌其烦地教$n「%s」。\n",to_chinese(arg)),me,this_object());
        
        improve_skill(arg,amount);
        message_vision(sprintf("$N似乎真的学会了一些「%s」！\n",to_chinese(arg)),this_object());
          }
        return 1;

}
string status_color(int current, int max)
{
        int percent;

        if( max>0 ) percent = current * 100 / max;
        else percent = 100;
        if( percent > 100 ) return HIC;
        if( percent >= 90 ) return HIG;
        if( percent >= 60 ) return HIY;
        if( percent >= 30 ) return YEL;
        if( percent >= 10 ) return HIR;
        return RED;
}
int do_shape(string arg)
{
          object me,who;
          me = this_player();
          who = this_object();
          if(who->query("owner")==me->query("id"))
           {       mapping my;
        string shape;
        int at_pt,pa_pt,do_pt;
        my = query_entire_dbase();
        printf("精：%s%3d/ %3d %s(%3d%%)"NOR"  气：%s%3d/ %3d %s(%3d%%)"NOR"  神：%s%3d/ %3d %s(%3d%%)\n"+NOR,
                status_color(my["gin"], my["eff_gin"]), my["gin"],my["eff_gin"],
                status_color(my["eff_gin"], my["max_gin"]),     my["eff_gin"] * 100 / my["max_gin"],
                status_color(my["kee"], my["eff_kee"]), my["kee"], my["eff_kee"],
                status_color(my["eff_kee"], my["max_kee"]),     my["eff_kee"] * 100 / my["max_kee"],
                status_color(my["sen"], my["eff_sen"]), my["sen"], my["eff_sen"],
                status_color(my["eff_sen"], my["max_sen"]),     my["eff_sen"] * 100 / my["max_sen"]
        );              
        printf("主人： %s\t\t经验： %d\t\t道行： %d\n",
        my["owner"], my["combat_exp"],my["daoxing"]
        );
        printf("灵性： %d\t\t体质： %d\t\t体态： %d\n",
        query_spi(), query_con(),query_per()
        );
        printf("凶性： %d\t\t力量： %d\t\t冷静： %d\n",
        query_cor(), query_str(),query_cps()
        );
        at_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_ATTACK);
        pa_pt= COMBAT_D->skill_power(this_object(), "unarmed", SKILL_USAGE_DEFENSE);
        do_pt= COMBAT_D->skill_power(this_object(), "dodge", SKILL_USAGE_DEFENSE);
        printf("攻击力： %d\t\t\t\t防御力： %d\n\n",
        at_pt+1, pa_pt/2+do_pt/2+1
        );
        printf("/cmds/usr/skillspet"->pet_skill(this_object()));
          }
        return 1;
}
