#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
num=0
echo "experiment set 6"
num=$((6 + 12))
for x in {1..10}
do
	echo "Running experiment 6:($x/10)."
	./robogen-server 80$num &>/dev/null &
	./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment6/objective_output6 ../projectSimulations/objective_based_cost/evolConf6.txt --save-all --complexity-cost
	echo "Experiment 6:($x/10) finished."
done
echo "Experiment set 6 finished..."
