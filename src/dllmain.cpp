#include "pch.h"
#include "noitaLua.h"
#include "console.h"
#include <iostream>
#include "tramp.h"

DWORD WINAPI Main(LPVOID lpParam)
{
    double temp = 0;
    init(L"Taikasauva - Noita's Bestfriend");
    gettop = (noita_gettop)tramp((char*)gettop, (char*)n_gettopH);
LOOP:
    tempScript = "";
    wandScript = "";
    if (lua != nullptr)
    {
        std::cout << "\n" << std::endl;
        std::string yon;
        std::string file;
        std::cout << "Would you like to load a wand? (y/n) ";
        std::cin >> yon;
        if (yon == "y" || yon == "Y")
        {
            displayFiles();
            std::cout << "File: ";
            std::cin >> file;
            openFile("taikasauva\\" + file);
            tempScript = mainScript + wandScript;
            execute();
            std::cout << " " << std::endl;
            std::cout << "Wand loaded successfully!" << std::endl;
            goto LOOP;
        }
        else if (yon == "n" || yon == "N")
        {
            std::cout << "Wand Name: ";
            std::cin >> wand_name;
            std::cout << "Fast Projectiles? (0/1): ";
            std::cin >> fast_projectile;
            std::cout << "Mana Charge Speed: ";
            std::cin >> mana_charge_speed;
            std::cout << "Max Mana: ";
            std::cin >> max_mana;
            std::cout << "Recharge Time (frames): ";
            std::cin >> reload_time_frames;
            std::cout << "Recoil: ";
            std::cin >> item_recoil;
            std::cout << "Swim Propel: ";
            std::cin >> swim_propel;
            std::cout << "Actions (\"ACTION_NAME\"): ";
            std::cin >> actions;
            std::cout << "Permanent Actions: ";
            std::cin >> perm_actions;
            std::cout << "Actions Per Shot: ";
            std::cin >> actions_per_shot;
            std::cout << "Shuffle? (0/1): ";
            std::cin >> shuffle_when_empty;
            std::cout << "Recharge Time: ";
            std::cin >> reload_time;
            std::cout << "Wand Capacity: ";
            std::cin >> capacity;
            std::cout << "Cast Delay: ";
            std::cin >> fire_rate_wait;
            wandScript = "createGun(\"" + wand_name + "\",\"\",\"" + fast_projectile + "\",\"" + mana_charge_speed + "\",\"" + max_mana + "\",\"1\",\"" + reload_time_frames + "\",\"" + item_recoil + "\",\"0\",\"" + swim_propel + "\",\"0\",\"1\",{" + actions + "},{" + perm_actions + "},\"" + actions_per_shot + "\",\"" + shuffle_when_empty + "\",\"" + reload_time + "\",\"" + capacity + "\",\"" + fire_rate_wait + "\");\n";
            tempScript = mainScript + wandScript;
            execute();
            std::cout << "Would you like to save this wand? (y/n) ";
            std::cin >> yon;
            if (yon == "y" || yon == "Y")
            {
                std::ofstream wand("taikasauva\\" + wand_name + ".tai");
                wand << "createGun(\"" + wand_name + "\",\"\",\"" + fast_projectile + "\",\"" + mana_charge_speed + "\",\"" + max_mana + "\",\"1\",\"" + reload_time_frames + "\",\"" + item_recoil + "\",\"0\",\"" + swim_propel + "\",\"0\",\"1\",{" + actions + "},{" + perm_actions + "},\"" + actions_per_shot + "\",\"" + shuffle_when_empty + "\",\"" + reload_time + "\",\"" + capacity + "\",\"" + fire_rate_wait + "\");";
                wand.close();
                std::cout << " " << std::endl;
                std::cout << "Wand saved!" << std::endl;
                goto LOOP;
            }
            else if (yon == "n" || yon == "N")
            std::cout << " " << std::endl;
            std::cout << "Wand created successfully!" << std::endl;
            goto LOOP;
        }
    }
    else
    {
        goto LOOP;
    }
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  dwReason,
                       LPVOID lpReserved
                     )
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hModule);
        CreateThread(NULL, 0, Main, NULL, 0, NULL);
        break;
    }
    return TRUE;
}
