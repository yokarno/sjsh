// jianglidan1.c 奖励丹
#include <ansi.h>
inherit ITEM;
int do_eat(string);
void init();
void init()
{
if (!wizardp(this_player())) {
set("no_get", "嘿嘿，做梦吧! \n");
  set("no_drop","这么宝贵的东西，哪能乱扔! \n");
}
add_action("do_eat", "eat");
}
void create()
{
set_name(HIG "pk丹" NOR, ({"pk dan", "dan"}));
set_weight(20);
if (clonep())
set_default_object(__FILE__);
else {
set("unit", "粒");
 set("long", "一粒PK丹，吃了能恢复功力,是难得的灵丹妙药!\n");
set("value", 100);
}
set("is_monitored", 1);
    call_out("announce",random(10),this_player());
setup();
}
int do_eat(string arg)
{
object victim = this_player();
/*
if( (int)victim->query("combat_exp")+(int)victim->query("daoxing") > 0 )
{
message_vision(HIG "\n$N吃下一粒奖励丹,忽然感到一阵倒胃，就差没把肠子也给吐出来!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
*/
if (!id(arg))
return notify_fail("你要吃什么？\n");
 victim->set("combat_exp", 10000);
if( (int)victim->query("potential") > (int)victim->query("learned_points"))
victim->add("potential",
(int)victim->query("potential") - (int)victim->query("learned_points")+10000 );
victim->skill_death_recover();
  victim->set("daoxing",5000000);
    victim->set("max_force",5000);
  victim->set("max_mana",5000);
 victim->set("maximum_mana",5000);
 victim->set("maximum_force",5000);
victim->set("combat_exp",4000000);
victim->set("force",10000);
victim->set("mana",10000);
victim->save();
if( userp(victim) ) log_file("RECOVER", sprintf("%s(%s) Got recovered on %s.\n", victim->name(1), geteuid(victim), ctime(time()) ) );
 message_vision(WHT "\n$N吃下一粒PK丹,渐渐地一股内息流遍全身,顿时精神大震,倍感舒适!\n\n" NOR, victim);
destruct(this_object());
return 1;
}
void announce(object who)
{
    if(!this_object()) return;
    if(!who) return;
    CHANNEL_D->do_channel(this_object(), "system", 
            who->query("name")+"得到了"+name()+"！\n");
}
