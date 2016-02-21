//juanlian.c by peaceful

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

void juanlian_ok(object);
int perform(object me, object target)
{
        int damage;
              object weapon;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「珍珠倒卷帘」？\n");
        if(!me->is_fighting())
                return notify_fail("「珍珠倒卷帘」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 300 )
                return notify_fail("你的内力不够！\n");
          if((int)me->query("force") < 300 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 100 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
        if((int)me->query_skill("bawang-qiang", 1) < 100)
                return notify_fail("你的霸王枪法不够纯熟，使用这一招会有困难！\n");
         if(me->query_temp("no_juanlian"))
                        return notify_fail("刚用过绝招，体力还未恢复，等会儿再用吧！\n");
        me->delete("env/brief_message");
        target->delete("env/brief_message");
message_vision(HIC"\n$N将手中兵器一抖，由下而上翻将上来，一股大力向$n狂涌而至，如流沙河水，天幕倒垂！\n"NOR,me);

               me->set_temp("TP_perform", 5);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        me->delete_temp("TP_perform");

        me->receive_damage("sen", 50);
        me->add("force", -150);
        me->set_temp("no_juanlian",1);
                call_out("juanlian_ok",2+random(2),me);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
}
}
return 1;
}
void juanlian_ok(object me)
{ if (!me) return;
      me->delete_temp("no_juanlian");
}
