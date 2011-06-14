@echo off
IF "%D2TM_HOME%"=="" goto D2TM_HOME_NOT_SET
cd %D2TM_HOME%
cls
echo.
echo Prepare binary package (./bin) of D2TM. 
echo.
echo Will copy "Dune 2.exe" from the Default dir created by Eclipse CDT.
echo Will copy DLL files from dll/mingw32
echo.
echo 1. Removing bin directory
rd /S /Q bin
echo 2. Creating new bin directory
mkdir bin
echo 3. Creating campaign directory
mkdir bin\campaign
mkdir bin\campaign\atreides
mkdir bin\campaign\ordos
mkdir bin\campaign\harkonnen
mkdir bin\campaign\maps
mkdir bin\campaign\maps\seed
mkdir bin\campaign\briefings
echo 4. Copying campaign files
copy resources\campaign\atreides\*.* bin\campaign\atreides
copy resources\campaign\ordos\*.* bin\campaign\ordos
copy resources\campaign\harkonnen\*.* bin\campaign\harkonnen
copy resources\campaign\maps\*.* bin\campaign\maps
copy resources\campaign\maps\seed\*.* bin\campaign\maps\seed
copy resources\campaign\briefings\*.* bin\campaign\briefings
copy resources\campaign\info.txt bin\campaign\info.txt

echo 5. Creating new data directory
mkdir bin\data
xcopy /I /D /E "resources/data" "../bin/data"

echo 6. Copying to data
copy resources\data\*.fon bin\data\font
copy resources\data\*.ttf bin\data\font

copy resources\data\*.ttf bin\data

echo 7. Copying scenes
copy resources\data\scenes\*.* bin\data\scenes

echo 8. Create save game directories
mkdir bin\save
mkdir bin\save\atreides
mkdir bin\save\harkonnen
mkdir bin\save\ordos
mkdir bin\save\skirmish
echo 9. Create skirmish directory
mkdir bin\skirmish
copy resources\skirmish\*.ini bin\skirmish
echo 10. Copying dll files
copy resources\dll\*.* bin
echo 11. Copy executable from
copy Release\*.exe bin
echo 12. Copy game rules file (game.ini)
copy resources\game.ini bin
echo 13. Copy txt files
copy resources\*.txt bin
goto FINISHED_SUCCESS

:D2TM_HOME_NOT_SET
echo.
echo ERROR
echo You must define an environmental variable D2TM_HOME and point it to your dune2themaker repository main dir, ie c:\projects\dune2themaker\
goto FINISHED_NOTSUCCESS

:FINISHED_NOTSUCCESS
echo Finished with errors.
goto END

:FINISHED_SUCCESS
cd bin
echo Done.

:END
pause