REM Copies the necessary files and folders to "4ed", compresses it to "f4_anto_win_x64.zip" and deletes "4ed"

mkdir 4ed

copy ..\4ed.exe .\4ed\
copy ..\4ed_app.dll .\4ed\
copy ..\custom_4coder.dll .\4ed\
copy ..\config.4coder .\4ed\

xcopy ..\audio_test .\4ed\audio_test\
xcopy ..\fonts .\4ed\fonts\
xcopy ..\themes .\4ed\themes\

pushd 4ed
call ..\zip.bat f4_anto_win_x64
move .\f4_anto_win_x64.zip ..\
popd

rd /s /q 4ed