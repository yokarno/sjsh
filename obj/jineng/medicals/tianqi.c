//ҩ��


#include <ansi.h>

inherit ITEM;

//int do_eat(string);
void init();
void create()
{
  set_name(RED "����" NOR, ({"tian qi","yao"}));
  set_weight(200);
  if (clonep())
    set_default_object(__FILE__);
  else {
    set("unit", "��");
    set("long", "���Ի�Ѫ���ٵĺ�ҩ�ġ�\n");
    set("value", 100);
    set("drug_type", "yaodan");
  }
  setup();
}


