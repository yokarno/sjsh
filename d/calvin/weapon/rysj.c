// 日月神剑 by Calvin
#include <ansi.h>
#include <dbase.h>
#include <weapon.h>
inherit SWORD;
inherit F_UNIQUE;
int do_wield(string arg);
int do_unwield(string arg);

object offensive_target(object me);
void create()
{
        set_name(HIW"日月神剑"NOR, ({"ryue sword", "sword"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long", "一把天地灵气炼就的神兵利器。\n");
                set("value", 30000);
                set("no_sell", 1);
                set("no_drop", 1);
                set("no_give", 1);
                set("material", "blacksteel");
                set("sheenness", 20);
                set("wield_msg", "$N念动心诀...「唰」地一声飞出一把$n在$N面前来回飞舞。\n");
                set("unequip_msg", "$N念动心诀...只见$N面前飞舞的$n化为一屡青光飞入$N腰间的剑鞘。\n");
        set("weapon_prop/int", 2);
        }

        init_sword(120);
        setup();

}

void init()
{
        add_action("do_wield","wield");
        add_action("do_unwield", "unwield");
        unique::init();
}
object offensive_target(object me)
{
        int sz;
        object *enemy;

        enemy = me->query_enemy();
        if( !enemy || !arrayp(enemy) ) return 0;

        sz = sizeof(enemy);
        if( sz > 4 ) sz = 4;

        if( sz > 0 ) return enemy[random(sz)];
        else return 0;
}

int do_wield (string arg)
{
  object me = this_player();
  object sword = this_object();
  string name = sword->query("name");
  string msg;

if(arg!="all"&&arg != "wuchen jian" )
    return notify_fail("你要装备什么？\n");
  msg = "$N拿起一把"+name+"，你眼前一亮。\n"; 
  sword->set("wield_msg",msg);
remove_call_out("conditions");
call_out("conditions",1,me,sword);
  return 0;
}
int do_unwield (string arg)
{
  object me = this_player();
  object sword = this_object();
  string name = sword->query("name");
  string msg;

if ( arg!= "all" && arg != "wuchen jian")
    return notify_fail("你要卸下什么？\n");

  msg = "$N将"+name+"收了回去……\n"; 
  sword->set("unwield_msg",msg);
remove_call_out("conditions");
  return 0;
}
void conditions(object who,object ob)
{
     object target;
     int ap,dp,damage;
     string msg;

string type;
type = ob->query("armor_type");
if( who->query_temp("armor/" + type) && ob->query("equipped")!="worn")
return;
  if( who->is_fighting())
     {
        target = offensive_target(who);
  if( ! target ) return ;      
 if( ! present( target,environment(who)) ) return ;    
        msg = HIW"日月神剑化作一屡青光飞舞而出,在方圆三米内来回周转。\n"NOR;

                ap = 10000000;
                dp = target->query("combat_exp");

                if( random(ap + dp) > dp )
                 {
                        damage = 600+random(500);
                        damage -= (int)target->query("max_mana") / 10 + random((int)target->query("eff_sen") / 10);
                        damage -= random((int)target->query("mana_factor"));

                        if( damage > 0 ) 
                        {
                                msg += HIC "结果$n躲避不及，被灵月仙剑穿心而过，伤势颇为惨重。\n" NOR;
                                target->receive_damage("sen", damage*2);
                                target->receive_wound("sen", damage);
                                target->receive_damage("kee", damage*2);
                                target->receive_wound("kee", damage);
                        } 
            else
                msg += HIC "\n谁知$n硬接一剑，毫发无伤。\n" NOR;   
                }
                else
                        msg += "但是被$n躲开了。\n";
                message_vision(msg, who, target); 
        }
call_out("conditions",7,who,ob);
}
mixed hit_ob(object me, object victim, int damage_bonus)
{
        int pro;
        int dam;
        int damage;
        pro = (int) victim->query_temp("apply/armor_vs_spells");
        dam = (int) me->query("force");

        damage = (int) me->query("force_factor");
        if(dam > pro)
        {
        victim->receive_damage("sen",damage*2);
        victim->receive_damage("kee",damage*2);
        victim->start_busy(1);
        return HIW "日月神剑剑身上时青时红,一闪一闪。\n" NOR;
        }
}

