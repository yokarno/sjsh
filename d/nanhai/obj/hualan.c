// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */
 
inherit ITEM;

void create()
{
        set_name("竹编花篮", ({ "zhubian hualan", "hualan" }) );
        set_weight(500);
        set_max_encumbrance(500);
        set_max_items(1);
        if( clonep() ){
     object flower;
        seteuid(getuid());
        if(flower=new("/d/obj/flower/juhua"))
        flower->move(this_object());

        set_default_object(__FILE__);
      }  else {
                set("unit", "个");
                set("long", "这是一个用湘妃竹编成的花篮，里面插着美丽的菊花。\n");
     set("value", 5000);
        }
}

int is_container() { return 1; }

