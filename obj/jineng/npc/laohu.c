// laofu.c 老虎

#include <ansi.h>;
int big_blowing();
inherit NPC;

void create()
{
        set_name("老虎", ({ "laohu", "tiger","hu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", @LONG
一只斑斓猛虎，雄伟极了。

         _.-'"''--..__.("\-''-'") 
 ('.__.-' (  *  ) .-'    ( @ _@' /{不要看不要看，今天没洗澡那！}     
  `-..-''.' _.'  (   _.  `(._Y_)/
         `. `._`--\  \_-.._`--'.._
          `-.!))  `.(il)   ''-.(li)



LONG);
        set("attitude", "aggressive");
        set("shen_type", -1);

        set("limbs", ({ "虎头", "虎身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 30000);
        set("neili",800);
        set("jiali",100);
        set("max_neili",800);
        set("jingli",500);
        set("max_jingli",500);

        set_temp("apply/attack", 20000);
        set_temp("apply/defense", 30000);
        set_temp("apply/armor", 1000);

        setup();

        set("chat_chance", 10);
        carry_object("/obj/jineng/medicals/hugu");
        set("chat_msg", ({
                "老虎在浚巡，吓得你大气都不敢出。\n",
                "老虎仰天长啸，声震山谷，黄叶纷坠。\n",
        }) );
}

void die()
{
 int i;
 object me,*inv;
 if(objectp(me=query_temp("last_damage_from") ))
        {
            inv = all_inventory(this_object());
            for(i=0; i<sizeof(inv); i++)
            {
                if (inv[i]->query("id")=="hugu" || inv[i]->query("id")=="hu gu")
                {
                   inv[i]->move(me);
                   message_vision("$n看到如此肥嫩的老虎,便掏出刀子割开虎肉,砍下了一块虎骨,赶忙塞到了口袋里。\n",this_object(),me);
         }
        }
  }
     destruct(this_object());
}

