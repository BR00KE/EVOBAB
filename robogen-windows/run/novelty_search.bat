@echo OFF
title Novelty search experiments
echo Starting novelty search experiments
echo ------------------------------------
FOR /L %%x IN (0,1,9) do (
    echo Running experiment %%x
    start cmd.exe /c "start robogen-server 800%%x"
    start robogen-evolver 1 output ..\projectSimulations\novelty_search\evolConf%%x.txt
    echo Done
    
)