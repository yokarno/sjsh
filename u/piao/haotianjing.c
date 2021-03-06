#include <mudlib.h>
#include <ansi.h>
#include <room.h>
#include <armor.h>
#include <command.h>
#include <net/dns.h>

inherit SHIELD;
inherit F_SAVE;
inherit F_AUTOLOAD;
inherit F_DAMAGE;
inherit F_UNIQUE;

int msgon = 1;
int ji(string arg);
int find(string arg);
int determine_success(object me, object victim);
int determine_cost(string var, int limit);
void remove_ding(object me, object victim);

void create()
{
	seteuid(getuid());

	set("long",@LONG
这峨嵋派最厉害的武器－浩天镜（find）。
LONG
);
	set("unit","具");
            set("value",1);             
       set("no_drop","这么好的宝物，扔了多可惜呀！\n");
       set("no_give","这么好的宝物，留着自己用吧！\n");
       set("no_sell", 1);
	set("is_monitored", 1);
	set("no_busy", 0);
	set("armor_prop/armor", 500);
	set_weight(1);
	setup();
}

void init()
{
	object me = this_player();

	seteuid(geteuid());
	if (!present(this_object(), me)) {
		if (environment(environment(me))) {
			write("你被一股神秘力量弹开了！\n");
			me->move(environment(environment(me)), 1);
		}
		return;
	}
        set_name (HIW"浩天镜"NOR, ({ "haotian jing", "haotian", "jing" }));

	if (me && present(this_object(), me)) {
		add_action("find", "find");
	}
}


int find(string arg)
{
	object where, target, me = this_player();
	object *ob;
	string msg;
	int i;

	if (!geteuid()) seteuid(getuid());
	if (arg) {
		if (target = LOGIN_D->find_body(arg)) {
			where = environment(target);
			if (!where) return notify_fail("他在虚无飘藐间。\n");
			"/cmds/std/look"->look_room(me, where);
			return 1;
		}
		else {
		ob = users();
		msg = "";
		for (i = 0; i < sizeof(ob); i++) {
			where = environment(ob[i]);
			if (!where)
				msg = sprintf("%s%14s(%-10s) %s\n",
					msg, ob[i]->name(1), ob[i]->query("id"),
					"??????????");
             return 1;
				
		}
	}
	write (msg);
	return 1;
}
}

int ji(string target)
{
    object victim,me=this_player();
    int damage,ratio,mykar=me->query_kar(), dingtime, condition;
    string msg, objname=this_object()->name();
    if (this_object()->query("in_use"))
        return notify_fail("现在的"+objname+"只是一面普通的防具。\n");
    if (!target)
	return notify_fail("你想用对谁用"+objname+"？\n");
    if (!objectp(victim=present(target, environment(me))))
	return notify_fail("这里没有 "+target+"。\n");
    if(!living(victim))
	return notify_fail("你的目标不是活物！\n");
    if(!me->is_fighting(victim))
	return notify_fail("只有战斗中才能祭"+objname+"。\n");  
    if(victim->query("no_move"))
	return notify_fail("对方已经无暇自顾了，有必要用"+objname+"么？\n");
    if( (int)me->query("mana") < 250)
	return notify_fail("你的法力不够了！\n");
    if( (int)me->query("sen") < 100)
	return notify_fail("你的精神无法集中！\n");
    msg="$N祭起"+objname+"，口中念念有词，\n";
    msg+=objname+"射出一道白光射向$n。\n";
    condition=determine_success(me, victim);
    switch(condition)
    {
      case 1:
        msg+=HIW"结果把$n被白光照住动弹不得了。\n" NOR;
        msg+=HIW"$n被"+objname+HIW"的法力定住了！\n"NOR;
	victim->set_temp("no_move", 1);
	dingtime=random((int)me->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	if (wizardp(me) && me->query("env/combat")=="verbose")
	    tell_object(me, GRN ""+victim->name()+"被定住了"+chinese_number(dingtime)+"秒。\n" NOR);
	this_object()->set("in_use", 1);
	call_out("remove_ding", dingtime, me, victim);
	break;
      case 0:
        msg+=HIY"$n伸手五指，大喝一声“看我浩天镜！”浩天镜白光一暗，收回$N手中。\n"NOR;
	break;
      case -1:
        msg+=HIY"$n伸手五指，大喝一声“收！”只见浩天镜反将$N照住了！\n"NOR;
	dingtime=random(victim->query("mana_factor")*4/5)+1;
	if (dingtime > 60) dingtime=60;
	me->set_temp("no_move");
	this_object()->set("in_use");
	call_out("remove_ding", dingtime, victim, me);
	break;
      case -2:
        msg+=HIY"$n伸手五指，大喝一声“看我浩天镜！”只见浩天镜白光一暗，收回$N手中。\n"NOR;
	this_object()->move(victim);
	break;
    }
    message_vision(msg,me,victim);
    me->add("mana", -determine_cost("mana", 250));
    me->add("sen", -determine_cost("sen", 50));
    return 1;
}

int determine_success(object me, object victim)
{
    int myspells, mydx, victimspells, victimdx;
    int ap, dp, attackfactor, condition;
    myspells=me->query_skill("spells")/10;
    mydx=me->query("daoxing")/1000;
    victimspells=victim->query_skill("spells")/10;
    victimdx=victim->query("daoxing")/1000;
    ap=(mydx+myspells*myspells*myspells/3)*me->query("sen")/me->query("max_sen");
    ap=ap*me->query_kar()/1000;
    dp=(victimdx+victimspells*victimspells*victimspells/3)*victim->query("sen")/victim->query("max_sen");
    dp=dp*victim->query_kar()/1000;
    attackfactor=random(ap+dp);
    if (attackfactor>dp/3) condition=1;
    else if (attackfactor>dp/6) condition=0;
    else if (attackfactor>dp/9) condition=-1;
    else condition=-2;
    return condition;
}

int determine_cost(string var, int limit)
{
    string variable="max_"+var;
    int cost;
    object me=this_player();
    cost=me->query(variable)/5;
    if(cost<limit) cost=limit;
    if(cost>me->query(var)) cost=me->query(var);
    return cost;
}

void remove_ding(object me, object victim)
{
    string msg=query("name")+HIW"白光一暗，$n挣脱了出来了。\n"NOR;
    this_object()->delete("in_use");
  if (!victim)
   {
    message_vision(msg, me);
    return;
   }

    if (living(victim))
        msg += HIW"$n挣脱了出来。\n"NOR;
    message_vision(msg, me, victim);
    victim->delete_temp("no_move");
    return;
}
