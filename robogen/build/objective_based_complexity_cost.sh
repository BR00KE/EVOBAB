#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
num=0
echo "finishing experiment set 4"
	num=$((4 + 12))
	for x in {7..10}
	do
		echo "Running experiment 4:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment4/objective_output4 ../projectSimulations/objective_based_cost/evolConf4.txt --save-all --complexity-cost
		echo "Experiment 4:($x/10) finished."
	done
	echo "Experiment set 4 finished..."
for i in {5..6} 
do
	echo "Running experiment set $i"
	num=$(($i + 12))
	for x in {1..10}
	do
		echo "Running experiment $i:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment$i/objective_output$i ../projectSimulations/objective_based_cost/evolConf$i.txt --save-all --complexity-cost
		echo "Experiment $i:($x/10) finished."
	done
	echo "Experiment set $i finished..."
done
echo "Successfully completed all experiments"