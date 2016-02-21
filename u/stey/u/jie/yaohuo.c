// yaohuo.c 妖火
#include <ansi.h>

inherit SSERVER;

void free(object target);

int cast(object me, object target)
{
	string msg;
	int success, ap, dp, ap2, ap3, dp2, dp3, damage;
	
	if( !target ) target = offensive_target(me);

	if((int)me->query_skill("spells") < 100 || (int)me->query_skill("pingtian-dafa",1) < 60)
		return notify_fail("你还没学会妖火。。。\n");

	if( !target
	||      !target->is_character()
	||      target->is_corpse()
	||      target==me)
		return notify_fail("你想对谁喷火？\n");  

	if( target->is_busy() )
		return notify_fail(target->name()+"已经够忙了。\n");

	if(target->query_temp("no_move"))
		return notify_fail(target->query("name")+"已经动弹不得了！\n");
	if((int)me->query("mana") < 200 )
		return notify_fail("你的法力不够！\n");

	if((int)me->query("sen") < 10 )
		return notify_fail("你无法集中精力！\n");

	me->add("mana", -100);
	me->receive_damage("sen", 20);

	msg = HIG
"$N凸腹鼓腮，咬破舌尖，张口一喷，一团碧磷磷的妖火直朝$n喷去！\n\n" 
NOR;

	success = 1;
	ap = me->query_skill("spells");
	ap = ap * ap * ap /12 ;
	ap += (int)me->query("daoxing");
	dp = target->query("daoxing");

//呵呵，看你怕不怕，比胆识
	ap2 = (int)me->query_cor();
	dp2 = (int)target->query_cor();


	ap3 = (int)me->query("mana");
	dp3 = (int)target->query("mana");
	if( random(ap + dp + 2500*(ap2+dp2)+200*(ap3+dp3)) < (dp+2500*dp2+200*dp3) ) success = 0;
// 哈哈，中招了，没这么简单，我pingtian-dafa高低，你惨的程度不一样
	if(success == 1 && (int)me->query_skill("pingtian-dafa",1) < 100){
		msg +=  HIR "$n看着$N那鄙陋相正想抢攻，不料一团碧火袭来，顿时手忙脚乱。\n" NOR;
		target->start_busy(2+random(2));
		if( living(target) ) target->kill_ob(me);
		
		
	}
	
	else if(success == 1 && (int)me->query_skill("pingtian-dafa",1) > 100){
// 难道就这么结束了，没呢！还有更厉害要你致命的！
// 不过得看我运气，就是福缘了		
		if(random(me->query("kar"))>18){
		msg +=  HIR "$n被妖火袭中，一股火毒直冲入脑髓、骨髓、血髓、脉髓。。。。\n" NOR;
		target->apply_condition("yaohuo_poison",((int)me->query_skill("pingtian-dafa",1)/5));
		target->start_busy(3+random(2));
		damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("pingtian-dafa",1);
                
                target->receive_damage("sen", damage);
                target->receive_wound("sen", damage/3);
		
		          
		}	    
		msg +=  HIR "$n一个不防，被妖火笼罩了全身。只听见$n在碧磷般的妖火中惨叫连连!\n" NOR;
		target->start_busy(1+random(2));
		damage = (int)me->query_skill("force", 1);
                damage = damage +  (int)me->query_skill("pingtian-dafa",1);
                
                target->receive_damage("sen", damage);
                target->receive_wound("sen", damage/3);
		if((int)me->query("mana") > 100 )
                me->add("mana", -100);
                if( living(target) ) target->kill_ob(me);
                me->start_busy(2+random(2));
                
	}
	
	else {
		msg +=  HIR "$n显然觑出$N这招的厉害，后掠三步，躲过了妖火！\n" NOR;	
		me->start_busy(2+random(2));
		if((int)me->query("mana") > 100 )
		me->add("mana", -100);        
        	if( living(target) ) target->kill_ob(me);
        	
        	
	} 
	
	message_vision(msg, me, target);

	return 1;
}



