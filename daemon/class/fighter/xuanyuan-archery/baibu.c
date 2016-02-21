//chaofeng.c yushu 2000.10.25

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;

        string msg;
        int ii,req,num_anqi,num_hit,max_hit,hitt,damage,op,opfa,remain;
        string anqi_type,b_unit;

   int wound=0;

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
           return notify_fail("你要攻击谁？\n");
        
      weapon = me->query_temp("weapon");
 req=(int)me->query_skill("archery", 1)+(int)me->query_skill("xuanyuan-archery", 1);


      if (weapon)  
        {
        if (weapon->query("anqi/allow") != 1) num_anqi=0;
        else num_anqi=weapon->query("anqi/now");
        }

        if (me->query_skill_mapped("force")!="lengquan-force")
                 return notify_fail("百步穿杨必须以上好的内功做基础。\n");
        if(req < 150)
              return notify_fail("你功夫有效等级不到150！\n");
      if(req < 150 && weapon->query("anqi/now") ==0)
             return notify_fail("你没有箭可以用了！\n");
       if (me->query("force")<200)
       return notify_fail("你内力不继，无法拉开强弓。\n");

 if (me->query_temp("baibu_busy")) return notify_fail("搭弓射箭需要时间呀。\n");
         me->add("force", -300);

        if(num_anqi <=0) 
            { anqi_type="弦音"; damage=me->query("force_factor")+10; }
        else if (req < 150)
           { anqi_type=weapon->query("anqi/type"); damage=me->query_temp("apply/damage");}
        else 
            { anqi_type=weapon->query("anqi/type")+"和着弦音";
             damage=me->query_temp("apply/damage")+me->query("force_factor")+10;}
         
       msg = HIW"只见$N手中"+weapon->query("name")+HIW"形如满月，跳跃着耀眼的光芒，无数"
                  +anqi_type+HIW"有如闪电般向$n扑来！\n" NOR;

         if (num_anqi > 5 || num_anqi == 0) max_hit=5;
        else max_hit=weapon->query("anqi/now");

        num_hit=random(max_hit/2)+(max_hit/2);

        if (!target->is_fighting(me)) opfa=30;
        else opfa=15;

        if (target->query("combat_exp")  !=0 ) 
               op= me->query("combat_exp")*opfa/target->query("combat_exp");
        else op=10;
        hitt=0;	
        for (ii=1;ii<=num_hit;ii++)  
          {if (op > random(100)) hitt++;}


 if (weapon->query("anqi/type")=="震天箭") b_unit="支";
        else b_unit="根";
        if (weapon->query("anqi/now") != 0) remain=weapon->query("anqi/now")-num_hit;
        else remain=0;
        weapon->set("anqi/now",remain);
        if (weapon->query("anqi/now") == 0) 
          {weapon->delete("anqi/type");  weapon->set("long",weapon->query("orilong"));}
        else weapon->set("long",weapon->query("orilong")+"里面已经装了"
           +chinese_number(weapon->query("anqi/now"))+b_unit+weapon->query("anqi/type")+"，想拆掉用uninstall。\n"); 

        if (hitt==0)
	  {
           msg += HIW "$n连忙将身体一侧，闪过了飞来的箭。\n"NOR;
           message_vision(msg, me, target);
           me->start_busy(random(3));
           if(!target->is_busy())
               target->start_busy(random(3));
	  }
        else 
          {
	   damage=damage*hitt;
           target->receive_damage("kee",damage,me);
    if (random(damage)>target->query_temp("apply/armor"))  {
       target->receive_wound("kee",damage-target->query_temp("apply/armor"),me);
       wound=1;
  }
 msg += HIW "$n躲闪不及，身上被"+chinese_number(hitt)+HIW "射中了"+anqi_type+"！\n"NOR;
           message_vision(msg, me, target);
       me->start_busy(random(2));
     COMBAT_D->report_status(target,wound);
           if(!target->is_busy())
           target->start_busy(random(5));
           }
 msg = HIW "$n对着$N笑到道：小子，基础还没有打好就来这里丢人现眼?看我怎么收拾你！\n" NOR;     
        message_vision(msg, me, target);
        target->kill_ob(me);
me->set_temp("baibu_busy",1);
    call_out("remove_effect",3+random(5),me);
        return 1;
}

void remove_effect(object me) {
  if (!me) return;
 me->delete_temp("baibu_busy");
}
