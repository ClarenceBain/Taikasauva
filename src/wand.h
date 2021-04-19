#ifndef WAND_H
#define WAND_H

#include <Windows.h>
#include <stdio.h>
#include <iostream>

std::string fast_projectile;
std::string mana_charge_speed;
std::string max_mana;
std::string reload_time_frames;
std::string item_recoil;
std::string swim_propel;
std::string wand_name;
std::string actions_per_shot;
std::string shuffle_when_empty;
std::string reload_time;
std::string capacity;
std::string fire_rate_wait;
std::string actions;
std::string perm_actions;
std::string wandScript;
std::string tempScript;
std::string mainScript =
"dofile(\"data/scripts/lib/utilities.lua\"); \n"
"dofile(\"data/scripts/gun/procedural/gun_action_utils.lua\")\n"
"dofile(\"data/scripts/gun/gun_actions.lua\")\n"
"dofile_once(\"data/scripts/gun/procedural/wands.lua\")\n"
" \n"
"function localplayer()\n"
"return EntityGetWithTag(\"player_unit\")[1];\n"
"end;\n"
" \n"
"function localplayerPos()\n"
"return EntityGetTransform(localplayer());\n"
"end;\n"
"function SetWandSprite(entity_id, ability_comp, item_file, offset_x, offset_y, tip_x, tip_y) --copied right from gun_proced\n"
" \n"
"if (ability_comp ~= nil) then\n"
"ComponentSetValue(ability_comp, \"sprite_file\", item_file)\n"
"end\n"
" \n"
"local sprite_comp = EntityGetFirstComponent(entity_id, \"SpriteComponent\", \"item\")\n"
"if (sprite_comp ~= nil) then\n"
"ComponentSetValue(sprite_comp, \"image_file\", item_file)\n"
"ComponentSetValue(sprite_comp, \"offset_x\", offset_x)\n"
"ComponentSetValue(sprite_comp, \"offset_y\", offset_y)\n"
"end\n"
" \n"
"local hotspot_comp = EntityGetFirstComponent(entity_id, \"HotspotComponent\", \"shoot_pos\")\n"
"if (hotspot_comp ~= nil) then\n"
"ComponentSetValueVector2(hotspot_comp, \"offset\", tip_x, tip_y)\n"
"end\n"
"end\n"
" \n"
"function randomWand()\n"
"wand = nil;\n"
"x = Random(0, 999);\n"
"for i, v in ipairs(wands) do\n"
"if i == x then\n"
"wand = v\n"
"return wand\n"
"end;\n"
"end;\n"
"end;\n"
" \n"
"function createGun(name,entity,fp,mcs,mm,maii,rf,irm,sraii,spa,tai,ugs,atca,atcap,apr,sdwe,rt,dc,frw,sd)\n"
"local px,py=localplayerPos();\n"
"local gun=EntityLoad(\"taikasauva/entities/blank_wand.xml\",px,py);\n"
"local gac=EntityGetComponent(gun,\"AbilityComponent\");\n"
"local ghc = EntityGetComponent(gun, \"HotspotComponent\");\n"
"local glc = EntityGetComponent(gun, \"LuaComponent\");\n"
"if gac~= nil then\n"
"for i, v in ipairs(gac) do\n"
"ComponentSetValue(v, \"entity_file\", entity);\n"
"ComponentSetValue(v, \"fast_projectile\", fp);\n"
"ComponentSetValue(v, \"mana_charge_speed\", mcs);\n"
"ComponentSetValue(v, \"mana_max\", mm);\n"
"ComponentSetValue(v, \"max_amount_in_inventory\", maii);\n"
"ComponentSetValue(v, \"reload_time_frames\", rf);\n"
"ComponentSetValue(v, \"item_recoil_max\", irm);\n"
"ComponentSetValue(v, \"shooting_reduces_amount_in_inventory\", sraii);\n"
"ComponentSetValue(v,\"swim_propel_amount\",spa);\n"
"ComponentSetValue(v,\"throw_as_item\",tai);\n"
"ComponentSetValue(v,\"ui_name\",name);\n"
"ComponentSetValue(v,\"use_gun_script\",ugs);\n"
"ComponentObjectSetValue(v,\"gun_config\",\"actions_per_round\",apr);\n"
"ComponentObjectSetValue(v,\"gun_config\",\"shuffle_deck_when_empty\",sdwe);\n"
"ComponentObjectSetValue(v,\"gun_config\",\"reload_time\",rt);\n"
"ComponentObjectSetValue(v,\"gun_config\",\"deck_capacity\",dc)\n"
"ComponentObjectSetValue(v,\"gunaction_config\",\"fire_rate_wait\",frw);\n"
"end;\n"
"end;\n"
"wand = randomWand();\n"
"SetWandSprite(gun, gac, wand.file, wand.grip_x, wand.grip_y, (wand.tip_x - wand.grip_x), (wand.tip_y - wand.grip_y));\n"
"for b, v in ipairs(atca) do\n"
"AddGunAction(gun, v);\n"
"end;\n"
"for pb, v in ipairs(atcap) do\n"
"AddGunActionPermanent(gun, v);\n"
"end;\n"
"if glc~= nil then\n"
"for i, v in ipairs(glc) do\n"
"ComponentSetValue(v, \"_enabled\", \"1\");\n"
"end;\n"
"end;\n"
"end;\n";
#endif