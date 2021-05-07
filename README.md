## Taikasauva

Taikasauva is a simple wand creator for the game Noita, and was made for the purpose of
spawning wands without enabling mods in the games settings.

Taikasauva was built around loading the script from .tai files, but also includes a wand
creator without the use of .tai files (albeit barebones and not flashy).

![Photo](https://github.com/ClarenceBain/Taikasauva/blob/main/Photos/photo1.png)
![Photo2](https://github.com/ClarenceBain/Taikasauva/blob/main/Photos/photo2.png)

### Prerequisites

You will need:
* Noita which can be purchased [here.](https://store.steampowered.com/app/881100/Noita/)
* Some sort of .DLL injector, I personally just use [Cheat Engine.](https://www.cheatengine.org/)

### Installation & Usage

1. Download the files [here.](https://github.com/ClarenceBain/Taikasauva/Latest)
2. Move the "taikasauva" folder to Noita's directory
  * Should be somewhere along the lines of C:\Program Files (x86)\Steam\steamapps\common\Noita\
3. Move the taikasauva.dll to a location of your liking
4. Start Noita
5. Inject the .DLL into Noita
6. Have fun!

## Features

Taikasauva was made with the idea of it being for wand creation, and it was built around that
original idea.

What can be done with Taikasauva extends wand creation since .tai files barebones
essentially are .lua files.
So this section will consist of "intended" and "unintentional" uses.

### Intended Features

* Create a wand to be spawned whenever in-game without the use of enabling mods
* Save & Load custom wands/created wands
* Save the wand currently in-hand to a file (todo!)

### Unintentional Features

* Run any lua script from within a .tai file using the load feature and the lua api
  * Most features in the lua lua_api_documentation will work, some will not.
  * C:\Program Files (x86)\Steam\steamapps\common\Noita\tools_modding\lua_api_documentation.txt

## License

Distributed under the MIT License. See [LICENSE](https://github.com/ClarenceBain/Taikasauva/LICENSE) for more information.

## Acknowledgements
* [Dark Byte](https://github.com/cheat-engine) for cheat engine.
* [Nolla Games](https://nollagames.com/) for their game.
* [Rake](https://github.com/GH-Rake) for the [detour & tramp hook.](https://guidedhacking.com/threads/simple-x86-c-trampoline-hook.14188/)
