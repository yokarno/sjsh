//by koker@SJSH and thanks pote

#include <ansi.h>
void done(object me);
//inherit F_YAO;
int main(object me, string arg)
{
        object ob;
        object ob1, ob2,ob3,ob4,ob5,ob6;
        int lv;
        lv=me->query_skill("medical",1);

        seteuid(getuid());

        if( me->is_busy() )
        return notify_fail("你正忙着呢。\n");

        if( !arg )
        return notify_fail("你要制什么药？\n");
        
        if( me->is_fighting() )
        return notify_fail("你正在战斗，制什么药啊？\n");

        if(me->query("sen")<=50)
	return notify_fail("你现在太累了，休息休息吧！\n");

        if(me->query("force")<50) 
	return notify_fail("你的真气不够，不能做什么了。\n");
        
        if( me->is_busy() || me->query_temp("pending/exercising"))
        return notify_fail("你正忙着呢，没时间制药。\n");
//制作的药品
     switch (arg)
      {
case "jinchuang":
        ob1 = present("hong hua", me) ;
        ob2 = present("tian qi", me) ;
        if (!ob1 || !ob2)
              return notify_fail("你的药材不齐全。\n");
        if( lv < 20 )
        return notify_fail("你的医术不足制出金疮药。\n");
        ob1->set("done", 1);
        ob2->set("done", 1);
done(me);
        ob=new("/obj/jineng/obj2/jinchuang.c");
        ob->move(me);
        me->add("sen",-20);
        me->add("force",-50);
        me->start_busy(1);

        break;

case "hunyuandan":
        ob1 = present("hu gu", me) ;
        ob2 = present("du huo", me) ;
        if (!ob1 || !ob2)
              return notify_fail("你的药材不齐全。\n");
        if( lv < 25 )
        return notify_fail("你的医术不足制出混元丹。\n");
        ob1->set("done", 1);
        ob2->set("done", 1);
done(me);
        ob=new("/obj/jineng/obj2/hunyuandan.c");
        ob->move(me);
        me->add("sen",-20);
        me->add("force",-50);
        me->start_busy(1);

        break;

       default:   notify_fail("你没有能力制这种药。\n");       
        }
        return 1;
}

void done(object me)
{
        int i;
        object *inv; 
               inv = deep_inventory(me);
                for(i=0; i<sizeof(inv); i++) {
                        if (inv[i]->query("done"))
                        destruct(inv[i]);
                }
message_vision( HIC "只见$N驱真气于药材之上，不多会药材便消失了。\n" NOR,me);
                me->start_busy(1);
return;
}
