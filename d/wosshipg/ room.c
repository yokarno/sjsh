#include <ansi.h>
inherit ROOM; 
void close_path(); 
void create()
{
set("short",HIC"花园"NOR);
set("long",

"这是一个不大但错落有致的花园,园中种的全是樱花树。\n" 
"似乎这儿总是春天三四月的气候,所以美丽的樱花盛开 \n" 
"着,不时有几朵粉红色的花瓣(flower)落下来,轻轻的打\n " 
"在你的身上,再加上沁人心脾的特有的北国之花的花香,\n" 
"你居然忘却了一切烦恼,留恋忘返于此了。\n" 
"园中的一块石头上刻着几个字:\n"
                  " "HIG" *************\n"NOR 
                     " "HIG"*"NOR+BLINK+HIR" 日"HIY" 月"HIC" 同"HIB" 辉 "NOR+HIG"*\n"NOR
                  " "HIG" *************\n"NOR 
); 

set("exits", ([ 
"down":"/d/city/kezhan", 
"go":"/d/wiz/wizroom",
"north":"/d/wiz/system", ])); 

set("item_desc", ([ 
"stone": HIG"这块刻着字的石头似乎可以移动(move)。\n"NOR, 
"flower" : MAG "希望你喜欢这朵樱花\n" NOR, ])); 

setup(); 

}

void init() 
{ 
add_action("do_move", "move"); 
} 

void close_path() 
{ 
if( !query("exits/enter") ) return;
message("vision", HIW"大石块重新归位，封住了密室入口。\n"NOR,this_object() ); 
delete("exits/enter"); 
} 

int do_move(string arg)
{
object me; 
me = this_player(); 
if( !arg || arg=="" ) return 0; 

if( arg=="stone" ) 
{ 
write(HIC"你用力推动大石块,\n"NOR);
if( (string) me->name() == "天使之泪" )
{
write(HIY"结果出现了一个入口。\n"NOR);
if( !query("exits/west") ) { 
set("exits/enter", __DIR__"workroom");
call_out("close_path", 3);
}
return 1; 
} 
else 
{ write(HIY"大石块纹丝不动。\n"NOR); 
message_vision( HIR "突然石块中涌出一阵紫灰色的烟雾，$N不由地深吸了一口气。\n\n\n" NOR,me);
if(!me->query_condition("moon_poison")) me->apply_condition("moon_poison",random(10)+10);
} 
return 1;
} 
write("你要移动什么？\n"); 
} 

