@echo OFF
title Objective-based experiments
echo Starting objective-based experiments
echo ------------------------------------
FOR /L %%x IN (0,1,9) do (
    echo Running experiment %%x
    start cmd.exe /c "start robogen-server 800%%x"
    start robogen-evolver 1 output%%x ..\projectSimulations\objective_based\evolConf%%x.txt
    echo Done
    
)