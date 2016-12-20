@echo off 
echo 正在清除项目垃圾文件，请稍等...... 
del /f /s /q /a 1.1.1\Debug\*.*
del /f /s /q /a common\Debug\*.*
del /f /s /q /a common\common\Debug\*.*
del /f /s /q /a maze\maze\Debug\*.*
del /f /s /q /a stack\stack\Debug\*.*
del /f /s /q /a expressions\expressions\Debug\*.*

echo 清除项目垃圾完成！ 
pause 