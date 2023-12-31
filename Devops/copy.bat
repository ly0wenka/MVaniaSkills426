@echo off
set "source=D:\MyProjects\UnrealProjects\L\AssetsProject"
set "destination=D:\MyProjects\UnrealProjects\L\MVaniaSkills426"

xcopy "%source%\Content\ProceduralBiomes" "%destination%\Content\ProceduralBiomes" /E /I
xcopy "%source%\Content\OrcaGamesFullAnimBundle" "%destination%\Content\OrcaGamesFullAnimBundle" /E /I
xcopy "%source%\Content\InfinityBladeIceLands" "%destination%\Content\InfinityBladeIceLands" /E /I
xcopy "%source%\Content\ParagonCountess\Characters" "%destination%\Content\ParagonCountess\Characters" /E /I
xcopy "%source%\Content\ParagonCountess\FX" "%destination%\Content\ParagonCountess\FX" /E /I
xcopy "%source%\Content\ParagonShinbi\FX" "%destination%\Content\ParagonShinbi\FX" /E /I
xcopy "%source%\Content\ParagonShinbi\Characters" "%destination%\Content\ParagonShinbi\Characters" /E /I
xcopy "%source%\Content\ParagonMorigesh\Characters" "%destination%\Content\ParagonMorigesh\Characters" /E /I
xcopy "%source%\Content\ParagonMorigesh\FX" "%destination%\Content\ParagonMorigesh\FX" /E /I
xcopy "%source%\Content\ParagonMorigesh\Audio" "%destination%\Content\ParagonMorigesh\Audio" /E /I
xcopy "%source%\Content\ParagonAurora\Characters" "%destination%\Content\ParagonAurora\Characters" /E /I
xcopy "%source%\Content\ParagonAurora\FX" "%destination%\Content\ParagonAurora\FX" /E /I
xcopy "%source%\Content\ParagonAurora\Audio" "%destination%\Content\ParagonAurora\Audio" /E /I
xcopy "%source%\Content\InfinityBladeFireLands" "%destination%\Content\InfinityBladeFireLands" /E /I
xcopy "%source%\Content\InfinityBladeGrassLands" "%destination%\Content\InfinityBladeGrassLands" /E /I
xcopy "%source%\Content\InfinityBladeEffects" "%destination%\Content\InfinityBladeEffects" /E /I
xcopy "%source%\Content\SoulCity" "%destination%\Content\SoulCity" /E /I
xcopy "%source%\Content\SoulCave" "%destination%\Content\SoulCave" /E /I
xcopy "%source%\Content\Magic___Spell_Sounds_PRO" "%destination%\Content\Magic___Spell_Sounds_PRO" /E /I
xcopy "%source%\Content\StarterContent" "%destination%\Content\StarterContent" /E /I

echo Files copied successfully!
pause
