// weapond.c
// keenness 为兵器锋利度

#include <ansi.h>
#include <combat.h>

void remove_broken_weapon(object ob);
int sharpless(object obj);

mapping weapon_actions = ([
        "slash": ([
                "damage_type":  "割伤",
                "action":               "$N挥动$w，斩向$n的$l",
                "parry":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "slice": ([
                "damage_type":  "劈伤",
                "action":               "$N用$w往$n的$l砍去",
                "dodge":                20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "chop": ([
                "damage_type":  "劈伤",
                "action":               "$N的$w朝著$n的$l劈将过去",
                "parry":                -20,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "hack": ([
                "action":               "$N挥舞$w，对准$n的$l一阵乱砍",
                "damage_type":  "劈伤",
                "damage":               30,
                "dodge":                30,
                "post_action":  (: call_other, __FILE__, "fleshings_weapon" :),
                ]),
        "thrust": ([
                "damage_type":  "刺伤",
                "action":               "$N用$w往$n的$l刺去",
                "dodge":                15,
                "parry":                -15,
                ]),
        "pierce": ([
                "action":               "$N的$w往$n的$l狠狠地一捅",
                "damage_type":  "刺伤",
                "dodge":                -30,
                "parry":                -30,
                ]),
        "wave": ([
                "action":               "$N一扬$w，朝$n的$l一挥",
                "damage_type":  "鞭伤",
                "dodge":                -20,
                "parry":                30,
                ]),
        "whip": ([
                "action":               "$N将$w一扬，往$n的$l抽去",
                "damage_type":  "鞭伤",
                "dodge":                -20,
                "parry":                30,
                ]),
        "impale": ([
                "action":               "$N用$w往$n的$l直戳过去",
                "damage_type":  "刺伤",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "rake": ([
                "action":               "$N高举$w，往$n的$l死命一筑",
                "damage_type":  "筑伤",
                "dodge":                -15,
                "parry":                15,
                ]),
        "strike": ([
                "action":               "$N一个大舒臂抡起$w，对着$n的$l往下一砸",
                "damage_type":  "筑伤",
                "dodge":                -10,
                "parry":                -10,
                ]),
        "bash": ([
                "action":               "$N挥舞$w，往$n的$l用力一砸",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "crush": ([
                "action":               "$N高高举起$w，往$n的$l当头砸下",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "slam": ([
                "action":               "$N手握$w，眼露凶光，猛地对准$n的$l挥了过去",
                "damage_type":  "挫伤",
                "post_action":  (: call_other, __FILE__, "bash_weapon" :),
                ]),
        "throw": ([
                "action":               "$N将$w对准$n的$l射了过去",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
        "shoot": ([
                "action":               "$N弯弓搭箭，只听「嗖」的一声，$w已到$n的$l",
                "damage_type":  "刺伤",
                "post_action":  (: call_other, __FILE__, "throw_weapon" :),
                ]),
]);

varargs mapping query_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("verbs");

        // 4/27/98 mon changed following 4 "hit" to "impale"
        // as "hit" is not defined in weapon_actions.
        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }       
}

varargs mapping query_apply_action()
{
        string verb, *verbs;
        object me, wp1, wp2;

        verbs = previous_object()->query("apply/verbs");

        if( !pointerp(verbs) ) return weapon_actions["impale"];
        else {
                verb = verbs[random(sizeof(verbs))];
                if( !undefinedp(weapon_actions[verb]) ) return weapon_actions[verb];
                else return weapon_actions["impale"];
        }       
}

void throw_weapon(object me, object victim, object weapon, int damage)
{
        if( objectp(weapon) ) {
                if( (int)weapon->query_amount()==1 ) {
                        weapon->unequip();
                        tell_object(me, "\n你的" + weapon->query("name") + "用完了！\n\n");
                }
                weapon->add_amount(-1);
        }
}

void bash_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2;
              string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->query("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "cuprum" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                   case "silver" : z1=30 ;break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" :z1=40 ; break;
                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }   
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break ;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }   
                wap = (int)weapon->weight() / 500
                                          +z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                        +z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > 2 * wdp ) {
                        message_vision(HIW "$N只觉得手中" + ob->name() + "把持不定，脱手飞出！\n" NOR,
                                victim);
                        ob->unequip();
                        ob->move(environment(victim));
                        victim->reset_action();
                } else if( wap > wdp ) {
                        message_vision("$N只觉得手中" + ob->name() + "一震，险些脱手！\n",
                                victim);
                } else if( wap > wdp / 2 ) {
                        message_vision(HIW "只听见「啪」地一声，$N手中的" + ob->name()
                                + "已经断为两截！\n" NOR, victim );
                        ob->unequip();
                        ob->move(environment(victim));
                        ob->set("name", "断掉的" + ob->query("name"));
                        //ob->set("value", (int)ob->query("value") / 20);
                        ob->set("value", 0);
                        //so can't sell broken weapon.
                        //otherwise may have problem in pawn shop
                        //when the broken weapon disappeared.
                        ob->set("weapon_prop", 0);
                        ob->set("armor_prop", 0);
                        call_out("remove_broken_weapon",
                          random(300)+60,ob);
                        //added by mon 10/27/97
                        victim->reset_action();
                } else {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                }
        }
}

void fleshings_weapon(object me, object victim, object weapon, int damage)
{
        object ob;
        int wap, wdp, z1, z2, onfall;
              string sharp1, sharp2;
        if( objectp(weapon)
        &&      damage==RESULT_PARRY
        &&      ob = victim->query_temp("weapon") ) {
                  sharp1=weapon->quary("material");
                  switch (sharp1)
                  {case "wood" : z1=5 ; break;
                  case "iron" :  z1=10 ; break;
                  case "bronze" : z1=15 ; break;
                  case "steel" : z1=20 ; break;
                  case "blacksteel" : z1=25 ; break;
                  case "silver" : z1=30 ; break;
                  case "crimsonsteel" : z1=35 ; break;
                  case "purplegold" : z1=40 ; break;
                  case "diamond" : z1=200 ; break;
                  default : z1=0 ;break;
                   }   
                  sharp2=ob->query("material");
                  switch (sharp2)
                  {case "wood" :z2=5 ; break ;
                  case "iron" :  z2=10 ; break;
                  case "bronze" : z2=15 ; break;
                  case "steel" : z2=20 ; break;
                  case "blacksteel" : z2=25 ; break;
                  case "silver" : z2=30 ; break;
                  case "crimsonsteel" : z2=35 ; break;
                  case "purplegold" : z2=40 ; break;
                  case "diamond" : z2=200 ; break;
                  default : z2=0 ;break;
                   }   
                    if (z1> 50)
                       z1=50;
                   onfall=   (int)me->query("str")
                              -(int)victim->query("str");
                     if (onfall>20)
                           onfall=20;
                     else 
                        {if (onfall<0)
                            onfall=5;}
           {
                wap = (int)weapon->keenness()
                                          + z1
                        + (int)me->query("str");
                wdp = (int)ob->weight() / 500
                                          + z2
                        + (int)victim->query("str");
                wap = random(wap);
                if( wap > wdp / 2 ) 
                 {

                        if (ob->query("weapon_prop/damage")>20)
                             {
                                            message_vision(HIW "$N只听得手中" + ob->name() + "嘇啷地声，原来是被削断一节。\n" NOR, 
                              victim);
                              ob->unequip();
                              ob->add("weapon_prop/damage", -onfall);
                              ob->add("weight", -200);
                              ob->wield ();
                             }
                        else
                            {
                                            message_vision(HIW "$N只觉得手中" + ob->name() + "一轻，原来是被连根削断了?\n" NOR,
                              victim);
                              ob->unequip();
                              ob->move(environment(victim));
                              ob->set("name", "断掉的" + ob->query("name"));
                              ob->set("value", 0);
                              ob->set("weapon_prop", 0);
                              ob->set("armor_prop", 0);
                              call_out("remove_broken_weapon",
                              random(300)+60,ob);
                              victim->reset_action();
                            }
                                           
                } 
                  else     {
                        message_vision("$N的" + weapon->name() + "和$n的" + ob->name()
                                + "相击，冒出点点的火星。\n", me, victim);
                            }
          }  }
}


void remove_broken_weapon(object ob)
{
  if(ob && environment(ob)) {
    tell_object(environment(ob),
      "一阵微风吹过，"+ob->name()+"化为片片尘土，消失不见了。\n");
    destruct(ob);
  }
}


