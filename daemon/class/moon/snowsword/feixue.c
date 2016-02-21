#include <ansi.h>

inherit SSERVER;

int perform(object me, object target)
{
        object weapon;
        string str;
        int snowsword,moonforce,moondance,ini_damage_apply,times,damage;
   string desc_msg="";
  int sword_level;
        
        snowsword = (int)me->query_skill("snowsword", 1);
        moonforce = (int)me->query_skill("moonforce", 1);
        moondance = (int)me->query_skill("moondance", 1);
       
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展「飞雪连天」？\n");

        if(!me->is_fighting())
                return notify_fail("「飞雪连天」只能在战斗中使用！\n");
        
        
        sword_level=(int)(snowsword/80);
        if( snowsword < 80)
                return notify_fail("你的风回雪舞剑法级别还不够，使用这一招会有困难！\n");

        if(me->query("family/family_name") != "月宫")
                return notify_fail("[飞雪连天]是月宫不传之密！\n");
        
        if( moonforce < 80)
                return notify_fail("你的圆月心法修为不够，使用这一招会有困难！\n");
        
        if( moondance < 80)
                return notify_fail("你的冷月凝香舞级别还不够，使用这一招会有困难！\n");
                
        if( me->query("force_factor") > 0)
                return notify_fail("「飞雪连天」绝技重招不重力。加力出招怎能剑走轻灵？\n");
        
        if( time()-(int)me->query_temp("feixue_end") < 10 )
                return notify_fail("绝招用多就不灵了！\n");
   if ( sword_level <= 1 ) desc_msg = "" ; else
       desc_msg = chinese_number(sword_level);
  if ( sword_level > 9 ) desc_msg = "百";
        ini_damage_apply = me->query_temp("apply/damage");
        
        message_vision(HIW"\n$N轻叱一声，脚尖一点，身体急速上旋，在半空中一个折腰。
同时手腕轻抖，剑光闪动幻作雪花落叶飞向$n。\n"NOR,me,target);
        damage=1;
        //飞雪四式        
        message_vision(HIC"\n$N同时使出风回雪舞剑的飞雪四式 ，在半空中压向$n。\n"NOR,me,target);
        
        me->set_temp("WX_perform", 5);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        if (damage < 1) me->add_temp("apply/damage",30);
        me->set_temp("WX_perform", 6);  
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon")); 
        
        if (damage < 1) {me->add_temp("apply/damage",30);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 7);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        
        if (damage < 1) {me->add_temp("apply/damage",30);}
                else    {me->set_temp("apply/damage",ini_damage_apply);}
        me->set_temp("WX_perform", 8);
        damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

        //连天四式
        if( snowsword > 119 && moonforce > 119 && moondance > 119 )
            {
            	message_vision(HIC"\n$N身体向上飘出，凌空踏步，反手就刺出了四剑。\n"NOR,me);
                
                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 9);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
             
                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 10);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 11);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                if (damage < 1) {me->add_temp("apply/damage",30);}
                    else    {me->set_temp("apply/damage",ini_damage_apply);}
                me->set_temp("WX_perform", 12);
                damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

              }
      
           //飞雪连天
           if( snowsword > 179 && moonforce >179  && moondance > 179 )
               {
               	    message_vision(HIC"\n$N从天而降，长剑变为万朵雪花从天而落，夹着一股寒风扑向$n。\n"NOR,me,target);
               	    
                    if (damage < 1) {me->add_temp("apply/damage",30);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 13);
                    damage=COMBAT_D->do_attack(me, target, me->query_temp("weapon"));

                     if (damage < 1) {me->add_temp("apply/damage",90);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 14);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                    
                    if (damage < 1) {me->add_temp("apply/damage",90);}
                         else    {me->set_temp("apply/damage",ini_damage_apply);}
                    me->set_temp("WX_perform", 15);
                    COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
                     if (target->query("eff_kee")<0 || !living(target))  
                       {str=target->name()+"被"+me->name()+"用月宫绝招「飞雪连天」杀死了。听说尸体被分割成了"+desc_msg+"十块了！";
//                     message("channel:rumor",HIM"【月宫仙子】某人："+str+"\n"NOR,users());
	               }
	          }
	                
        me->delete_temp("WX_perform");
        me->set_temp("apply/damage",ini_damage_apply);
        

        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }

         me->set_temp("feixue_end",time());
        return 1;
}

