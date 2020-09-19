#!/bin/bash
echo "Starting objective_based experiments"
echo "------------------------------------"
num=0
echo "finishing experiment set 3"
	num=$((3 + 12))
	for x in {1..10}
	do
		echo "Running experiment 3:($x/10)."
		./robogen-server 80$num &>/dev/null &
		./robogen-evolver $RANDOM objectiveResults/complexityCost/Experiment3/objective_output3 ../projectSimulations/objective_based_cost/evolConf3.txt --save-all --complexity-cost
		echo "Experiment 3:($x/10) finished."
	done
	echo "Experiment set 3 finished..."
for i in {4..9} 
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