:start
gen.exe
sol.exe
copy output.txt answer.txt
NAME.exe
fc output.txt answer.txt
if ERRORLEVEL 1 goto end
goto start
:end